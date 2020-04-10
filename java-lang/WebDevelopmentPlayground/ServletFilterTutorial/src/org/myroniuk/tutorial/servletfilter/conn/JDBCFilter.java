package org.myroniuk.tutorial.servletfilter.conn;

import java.io.IOException;
import java.sql.Connection;

import javax.servlet.Filter;
import javax.servlet.FilterConfig;
import javax.servlet.FilterChain;
import javax.servlet.annotation.WebFilter;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;

@WebFilter("/*")

public class JDBCFilter implements Filter {
	
	public JDBCFilter() {
	}
	
	@Override
	public void init(FilterConfig config) throws ServletException {
	}
	
	@Override
	public void destroy() {
	}

	@Override
	public void doFilter(ServletRequest request, ServletResponse response,
			FilterChain chain) throws IOException, ServletException {
		
		HttpServletRequest req = (HttpServletRequest) request;
		
		String servletPath = req.getServletPath();
		
		// Only open Connection for special request
		// (For example: servlet, jsp, ...)
		
		// Avoid open connection for the common request.
		// (For example: css, image, javascript, ...)
		if (servletPath.contains("/specialPath1")
				|| servletPath.contains("/specialPath2")) {
			Connection conn = null;
			try {
				conn = ConnectionUtils.getConnection();
				conn.setAutoCommit(false);
				MyUtils.storeConnection(request, conn);
				chain.doFilter(request, response);
				conn.commit();
			} catch (Exception e) {
				ConnectionUtils.rollbackQuietly(conn);
				throw new ServletException();
			} finally {
				ConnectionUtils.closeQuietly(conn);
			}
		} else {
			chain.doFilter(request, response);
		}
	}
}
