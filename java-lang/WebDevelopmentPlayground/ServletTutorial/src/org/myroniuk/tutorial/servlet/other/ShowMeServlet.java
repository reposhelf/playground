package org.myroniuk.tutorial.servlet.other;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.myroniuk.tutorial.beans.Constants;

@WebServlet("/showMe")

public class ShowMeServlet extends HttpServlet {

	private static final long serialVersionUID = 1L;
	
	@Override
	protected void doGet(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {
		// Get value of Attribute (sent from forward page)
		String value =(String) request
				.getAttribute(Constants.ATTRIBUTE_USER_NAME_KEY);
		
		ServletOutputStream out = response.getOutputStream();
		out.println("<html>");
		out.println("<body>");
		
		out.println("<h3>Text of ShowMeServlet</h3>");
		out.println(value);
		
		out.println("</body>");
		out.println("</html>");
	}
	
	@Override
	protected void doPost(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {
		this.doGet(request, response);
	}
}
