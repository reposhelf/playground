package org.myroniuk.simplewebapp.filter;

import java.sql.Connection;
import java.io.IOException;
import java.util.Collection;
import java.util.Map;

import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRegistration;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;

import org.myroniuk.simplewebapp.conn.ConnectionUtils;
import org.myroniuk.simplewebapp.utils.MyUtils;

@WebFilter(filterName = "jdbcFilter", urlPatterns = {"/*"})

public class JDBCFilter implements Filter {

	public JDBCFilter() {
	}
	
	@Override
	public void init(FilterConfig config) throws ServletException {
	}
	
	@Override
	public void destroy() {
	}
	
	// Check the target of the request is a servlet?
	private boolean needJDBC(HttpServletRequest request) {
		System.out.println("JDBC Filter");
		/*
		 * Servlet URL-pattern: /spath/*
		 */
		// ==> /spath
		String servletPath = request.getServletPath();
		// ==> /abc/mnp
		String pathInfo = request.getPathInfo();
		
		String urlPattern = servletPath;
		
		if (pathInfo != null) {
			urlPattern = servletPath + "/*";
		}
		
		// Key: servletName
		// Value: ServletRegistartion
		Map<String, ? extends ServletRegistration> servletRegistrations = 
				request.getServletContext().getServletRegistrations();
		
		// Collection of all servlets in your webapp
		Collection<? extends ServletRegistration> values = servletRegistrations
				.values();
		for (ServletRegistration sr : values) {
			Collection<String> mappings = sr.getMappings();
			if (mappings.contains(urlPattern))
				return true;
		}
		return false;
	}
	
	@Override
	public void doFilter(ServletRequest request, ServletResponse response,
			FilterChain chain) throws IOException, ServletException {
		HttpServletRequest req = (HttpServletRequest) request;

		/*
		 * Only open connections for the special requests need connection.
		 * (For example, the path of the Servlet, JSP...)
		 * 
		 * Avoid open connection for common requests
		 * (For example: image, css, javascript...)
		 */
		if (this.needJDBC(req)) {
			System.out.println("Open Connection for: " + req.getServletPath());
			
			Connection connection = null;
			try {
				connection = ConnectionUtils.getConnection();
				connection.setAutoCommit(false);
				
				MyUtils.storeConnection(request, connection);
				
				chain.doFilter(request, response);
				
				connection.commit();
			} catch (Exception e) {
				e.printStackTrace();
				ConnectionUtils.rollbackQuietly(connection);
				throw new ServletException();
			} finally {
				ConnectionUtils.closeQuietly(connection);
			}
		} else {
			chain.doFilter(request, response);
		}
	}

}
