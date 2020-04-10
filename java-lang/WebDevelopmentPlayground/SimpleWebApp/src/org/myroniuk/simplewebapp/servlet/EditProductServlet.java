package org.myroniuk.simplewebapp.servlet;

import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.myroniuk.simplewebapp.beans.Product;
import org.myroniuk.simplewebapp.utils.*;

@WebServlet(urlPatterns = {"/editProduct"})

public class EditProductServlet extends HttpServlet {

	private static final long serialVersionUID = 1L;
	
	public EditProductServlet() {
		super();
	}
	
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws IOException, ServletException {
		Connection connection = MyUtils.getStoredConnection(request);
		String code = request.getParameter("code");
		String errorString = null;
		Product product = null;
		
		try {
			product = DBUtils.findProduct(connection, code);
		} catch (SQLException e) {
			e.printStackTrace();
			errorString = e.getMessage();
		}
		
		if (errorString != null && product == null) {
			response.sendRedirect(request.getContextPath() + "/productList");
			return;
		}
		
		request.setAttribute("errorString",errorString);
		request.setAttribute("product", product);
		
		RequestDispatcher dispatcher = this.getServletContext()
				.getRequestDispatcher("/WEB-INF/views/editProductView.jsp");
		dispatcher.forward(request, response);
	}
	
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws IOException, ServletException {
		this.doGet(request, response);
	}
}
