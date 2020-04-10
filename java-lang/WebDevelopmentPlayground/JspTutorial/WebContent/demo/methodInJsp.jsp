<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Method In JSP</title>
</head>
<body>

  <%!
    public int sum(int a, int b) {
	    return a + b;
    }
  %>
  
  <h1>
    1 + 2 = <%=sum(1, 2)%>
  </h1>

</body>
</html>