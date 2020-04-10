package org.myroniuk.tutorial.servlet;

import java.io.IOException;
import java.util.Enumeration;

import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.ServletContext;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = {"/other/exampleInfo"})

public class ExampleInfoServlet extends HttpServlet {

	private static final long serialVersionUID = 1L;
	
	public ExampleInfoServlet() {
		super();
	}
	
	@Override
	protected void doGet(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {
		ServletOutputStream out = response.getOutputStream();
		
		out.println("<style> span {color:blue;} </style>");
		
		String requestURL = request.getRequestURL().toString();
		out.println("<br><span>requestURL:</span>");
		out.println(requestURL);
		
		String requestURI = request.getRequestURI();
		out.println("<br><span>requestURI:</span>");
		out.println(requestURI);
		
		String contextPath = request.getContextPath();
		out.println("<br><span>contextPath:</span>");
		out.println(contextPath);
		
		String servletPath = request.getServletPath();
		out.println("<br><span>servletPath:</span>");
		out.println(servletPath);
		
		String queryString = request.getQueryString();
		out.println("<br><span>queryString:</span>");
		out.println(queryString);
		
		String param1 = request.getParameter("text1");
		out.println("<br><span>getParameter text1:</span>");
		out.println(param1);
		
		String param2 = request.getParameter("text2");
		out.println("<br><span>getParameter text2:</span>");
		out.println(param2);
		
		// Server Infos
		out.println("<br><br><b>Server info:</b>");
		
		String serverName = request.getServerName();
		out.println("<br><span>serverName:</span>");
		out.println(serverName);
		
		int serverPort = request.getServerPort();
		out.println("<br><span>serverPort:</span>");
		out.println(serverPort + "");
		
		// Client Infos
		out.println("<br><br><b>Client info:</b>");
		
		String remoteAddr = request.getRemoteAddr();
		out.println("<br><span>remoteAddr:</span>");
		out.println(remoteAddr);
		
		String remoteHost = request.getRemoteHost();
		out.println("<br><span>remoteHost:</span>");
		out.println(remoteHost);
		
		int remotePort = request.getRemotePort();
		out.println("<br><span>remotePort:</span>");
		out.println(remotePort + "");
		
		String remoteUser = request.getRemoteUser();
		out.println("<br><span>remoteUser:</span>");
		out.println(remoteUser);
		
		// Header Infos
		out.println("<br><br><b>Headers:</b>");
		
		Enumeration<String> headers = request.getHeaderNames();
		while (headers.hasMoreElements()) {
			String header = headers.nextElement();
			out.println("<br><span>" + header + "</span>:"
					+ request.getHeader(header));
		}
		
		// Servlet Context Info
		out.println("<br><br><b>Servlet Context info:</b>");
		ServletContext servletContext = request.getServletContext();
		
		// Location of web application on hard disk
		String realPath = servletContext.getRealPath("");
		out.println("<br><span>realPath:</span>");
		out.println(realPath);		
	}
	
	@Override
	protected void doPost(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {
		this.doGet(request, response);
	}
}
