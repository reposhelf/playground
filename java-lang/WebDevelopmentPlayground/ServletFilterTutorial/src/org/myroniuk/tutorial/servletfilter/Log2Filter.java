package org.myroniuk.tutorial.servletfilter;

import java.io.IOException;

import javax.servlet.Filter;
import javax.servlet.FilterConfig;
import javax.servlet.FilterChain;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;

public class Log2Filter implements Filter {
	
	private String logFile;
	
	public Log2Filter() {
	}
	
	@Override
	public void init(FilterConfig config) throws ServletException {
		this.logFile = config.getInitParameter("logFile");
		System.out.println("Log file " + this.logFile);
	}
	
	@Override
	public void destroy() {
		System.out.println("Log2Filter destroy!");
	}

	@Override
	public void doFilter(ServletRequest request, ServletResponse response,
			FilterChain chain) throws IOException, ServletException {
		if (this.logFile != null) {
			// Write to log file
			this.logToFile(this.logFile);
		}
		
		chain.doFilter(request, response);
	}
	
	private void logToFile(String fileName) {
		// Write to log file
		System.out.println("Write to file " + this.logFile);
	}

}
