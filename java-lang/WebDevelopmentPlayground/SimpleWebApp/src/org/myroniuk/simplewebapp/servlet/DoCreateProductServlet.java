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

@WebServlet(urlPatterns = {"/doCreateProduct"})

public class DoCreateProductServlet extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
	
	public DoCreateProductServlet() {
		super();
	}
	
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws IOException, ServletException {
		Connection connection = MyUtils.getStoredConnection(request);
		String code = request.getParameter("code");
		String name = request.getParameter("name");
		String priceStr = request.getParameter("price");
		float price = 0;
		try {
			price = Float.parseFloat(priceStr);
		} catch (Exception e) {
		}
		Product product = new Product(code, name, price);
		String errorString = null;
		
		// Product ID is the string literal [a-zA-Z0-9]
		// with at least one character
		String regex = "\\w+";
		if (code == null || !code.matches(regex)) {
			errorString = "Product Code invalid";
		}
		
		if (errorString == null) {
			try {
				DBUtils.insertProduct(connection, product);
			} catch (SQLException e) {
				e.printStackTrace();
				errorString = e.getMessage();
			}
		}
		request.setAttribute("errorString", errorString);
		request.setAttribute("product", product);
		
		if (errorString != null) {
			RequestDispatcher dispatcher = this.getServletContext()
					.getRequestDispatcher("/WEB-INF/views/"
							+ "createProductView.jsp");
			dispatcher.forward(request, response);
		} else {
			response.sendRedirect(request.getContextPath() + "/productList");
		}
	}
	
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws IOException, ServletException {
		this.doGet(request, response);
	}
}
