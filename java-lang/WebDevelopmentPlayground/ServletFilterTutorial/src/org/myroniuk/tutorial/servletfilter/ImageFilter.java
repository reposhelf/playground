package org.myroniuk.tutorial.servletfilter;

import java.io.IOException;
import java.io.File;

import javax.servlet.Filter;
import javax.servlet.FilterConfig;
import javax.servlet.FilterChain;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebFilter;
import javax.servlet.annotation.WebInitParam;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebFilter(urlPatterns = {"*.jpg", "*.png", "*.gif"},
initParams = {
		@WebInitParam(name = "notFoundImage",
				value = "/images/image-not-found.png")
		}
)

public class ImageFilter implements Filter {
	
	private String notFoundImage;
	
	public ImageFilter() {
	}
	
	@Override
	public void init(FilterConfig config) throws ServletException {
		this.notFoundImage = config.getInitParameter("notFoundImage");
	}
	
	@Override
	public void destroy() {
	}

	@Override
	public void doFilter(ServletRequest request, ServletResponse response,
			FilterChain chain) throws IOException, ServletException {
		HttpServletRequest req = (HttpServletRequest) request;

		// ==> /images/path/my-image.png
		// ==> /path1/path2/iage.pngs
		String servletPath = req.getServletPath();
		
		// the path of the root directory of the webapp (WebContent)
		String realRootPath = req.getServletContext().getRealPath("");
		
		// Real path of image
		String imageRealPath = realRootPath + servletPath;
		
		File file = new File(imageRealPath);
		
		if (file.exists()) {
			chain.doFilter(request, response);
		} else {
			HttpServletResponse resp = (HttpServletResponse) response;
			
			// ==> /ServletFilterTutorial + /images/not-found-image.png
			resp.sendRedirect(req.getContextPath() + this.notFoundImage);
//			req.getServletContext().getRequestDispatcher(this.notFoundImage).forward(req, resp);
		}
	}
}
