package org.myroniuk.simplewebapp.filter;

import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;

import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;

import org.myroniuk.simplewebapp.beans.UserAccount;
import org.myroniuk.simplewebapp.utils.*;

@WebFilter(filterName = "cookieFilter", urlPatterns = {"/*"})

public class CookieFilter implements Filter {

	public CookieFilter() {
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
		HttpSession session = req.getSession();
		
		UserAccount userInSession = MyUtils.getLoginedUser(session);
		
		if (userInSession != null) {
			session.setAttribute("COOKIE_CHECKED", "CHECKED");
			chain.doFilter(request, response);
			return;
		}
		
		// Connection was created in JDBCFilter
		Connection connection = MyUtils.getStoredConnection(request);
		
		// Flag check cookie
		String checked = (String) session.getAttribute("COOKIE_CHECKED");
		if (checked == null && connection != null) {
			String userName = MyUtils.getUserNameInCookie(req);
			try {
				UserAccount user = DBUtils.findUser(connection, userName);
				MyUtils.storeLoginedUser(session, user);
			} catch (Exception e) {
				e.printStackTrace();
			}
			session.setAttribute("COOKIE_CHECKED", "CHECKED");
		}
		chain.doFilter(request, response);
	}

}
