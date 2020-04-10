package org.myroniuk.jstltutorial.servlets;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.RequestDispatcher;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.myroniuk.jstltutorial.beans.Dept;
import org.myroniuk.jstltutorial.utils.DBUtils;

@WebServlet("/jstlCoreExample02")

public class JstlCoreEx02Servlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	
	public JstlCoreEx02Servlet() {
		super();
	}
	
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws IOException, ServletException {
		List<Dept> list = DBUtils.queryDepartments();
		
		request.setAttribute("departments", list);
		
		RequestDispatcher dispatcher = request.getServletContext()
				.getRequestDispatcher("/WEB-INF/jsps/jstl_core_example02.jsp");
		
		dispatcher.forward(request, response);
	}
	
	@Override
	protected void doPost(HttpServletRequest request,
			HttpServletResponse response) throws IOException, ServletException {
		this.doGet(request, response);
	} 
}
