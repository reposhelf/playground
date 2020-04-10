package org.myroniuk.tutorial.jsp.utils;

import java.io.IOException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.jsp.JspWriter;

public class CookieUtils {

	public static void demoUserCookie(HttpServletRequest request,
			HttpServletResponse response, JspWriter out) throws IOException {
		boolean found = false;
		
		// Get an array of Cookies associated with this domain
		Cookie[] cookies = request.getCookies();
		if (cookies != null && cookies.length > 0) {
			String userName = null;
			String lastLoginDateTime = null;
			out.println("<h3>Cookies:</h3>");
			
			for (int i = 0; i < cookies.length; i++) {
				out.println(cookies[i].getName() + " : "
						+ cookies[i].getValue() + "<br>");
				
				if (cookies[i].getName().equals("userName")) {
					userName = cookies[i].getValue();
				} else if (cookies[i].getName().equals("lastLoginDatetime")) {
					lastLoginDateTime = cookies[i].getValue();
				}
			}
			
			if (userName != null) {
				found = true;
				out.println("<h4>Last login info:</h4>");
				out.println("User Name: " + userName + "<br>");
				out.println("Last Login Date Time: " + lastLoginDateTime
						+ "<br>");
			}
		}
		
		if (!found) {
			out.println("<h3>No cookies founds! "
					+ "Write some cookies into client computer</h3>");
			
			// Storing user information in cookies
			// for example userName.
			// Simulation Cookie stored on a user's computer, as soon as
			// the user login is successful
			String userName = "someUserName";
			
			Cookie cookieUserName = new Cookie("userName", userName);
			
			DateFormat df = new SimpleDateFormat("dd-MM-yyyy HH:mm:ss");
			Date now = new Date();
			
			String lastLoginDateTime = df.format(now);
			lastLoginDateTime = lastLoginDateTime.replaceAll(" ", "__");
			
			Cookie cookieLoginDateTime = new Cookie("lastLoginDatetime", lastLoginDateTime);
			
			// Sets the maximum age in seconds for this cookie. (24h)
			cookieUserName.setMaxAge(24 * 60 * 60);
			
			// Sets the maximum age in seconds for this cookie. (24h)
			cookieLoginDateTime.setMaxAge(24 * 60 * 60);
			
			// Store in the user's computer
			response.addCookie(cookieUserName);
			
			// Store in the user's computer
			response.addCookie(cookieLoginDateTime);
		}
	}
}
