package org.myroniuk.tutorial.servlet.session;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.myroniuk.tutorial.beans.Constants;
import org.myroniuk.tutorial.beans.UserInfo;

@WebServlet("/login")

public class LoginServlet extends HttpServlet {

	private static final long serialVersionUID = 1L;
	
	public LoginServlet() {
	}
	
	@Override
	protected void doGet(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {
		
		// Get HttpSession object
		HttpSession session = request.getSession();
		
		// Suppose a user has successfully logged
		UserInfo loginedInfo = new UserInfo("Tom", 5, "USA");
		
		// Storing user information in Session under 1 attribute
		// You can retrieve user information in Session
		session.setAttribute(Constants.SESSION_USER_KEY, loginedInfo);
		
		ServletOutputStream out = response.getOutputStream();
		
		out.println("<html>");
		out.println("<head><title>Session example</title></head>");
		
		out.println("<body>");
		out.println("<h3>You are logined, info stored in session</h3>");
		
		out.println("<a href='userInfo'>View User info</a>");
		out.println("</body>");
		out.println("</html>");
	}
}
