package org.myroniuk.simplewebapp.utils;

import java.sql.Connection;

import javax.servlet.ServletRequest;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.myroniuk.simplewebapp.beans.UserAccount;

public class MyUtils {
	
	private static final String ATT_NAME_CONNECTION = 
			"ATTRIBUTE_FOR_CONNECTION";
	private static final String ATT_NAME_USER_NAME = 
			"ATTRIBUTE_FOR_STORE_USER_NAME_IN_COOKIE";
	
	// Store connection in request attribute.
	// (Information stored only exists during requests)
	public static void storeConnection(ServletRequest request,
			Connection connection) {
		request.setAttribute(ATT_NAME_CONNECTION, connection);
	}
	
	// Get the Connection object has been stored in one attribute of the request.
	public static Connection getStoredConnection(ServletRequest request) {
		return (Connection) request.getAttribute(ATT_NAME_CONNECTION);
	}
	
	// Store user info in session
	public static void storeLoginedUser(HttpSession session,
			UserAccount loginedUser) {
		session.setAttribute("loginedUser", loginedUser);
	}
	
	// Get the user info stored in session
	public static UserAccount getLoginedUser(HttpSession session) {
		return (UserAccount) session.getAttribute("loginedUser");
	}
	
	// Store info in Cookie
	public static void storeUserCookie(HttpServletResponse response,
			UserAccount user) {
		System.out.println("Store user cookie");
		Cookie cookieUserName = new Cookie(ATT_NAME_USER_NAME,
				user.getUserName());
		cookieUserName.setMaxAge(24 * 60 * 60);
		response.addCookie(cookieUserName);
	}
	
	// Get info from Cookie
	public static String getUserNameInCookie(HttpServletRequest request) {
		Cookie[] cookies = request.getCookies();
		if (cookies != null) {
			for (Cookie cookie : cookies) {
				if (ATT_NAME_USER_NAME.equals(cookie.getName()))
					return cookie.getValue();
			}
		}
		return null;
	}
	
	// Delete cookie
	public static void deleteUserCookie(HttpServletResponse response) {
		Cookie cookieUserName = new Cookie(ATT_NAME_USER_NAME, null);
		cookieUserName.setMaxAge(0);
		response.addCookie(cookieUserName);
	}
}
