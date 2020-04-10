<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<%@ page import="java.util.Random, java.text.*" %>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Java In HTML</title>
</head>
<body>

  <%
    Random random = new Random();
    
    // Returns a random number (0, 1 or 2)
    int randomInt = random.nextInt(3);
    
    if (randomInt == 0) {
  %>
  
  <h1>Random value = <%=randomInt%></h1>
  
  <%
    } else if (randomInt == 1) {
  %>
  
  <h2>Random value = <%=randomInt%></h2>
  
  <%
    } else {
  %>
  
  <h3>Random value = <%=randomInt%></h3>
  
  <%
    }
  %>
  
  <a href="<%=request.getRequestURI()%>">Try Again</a>

</body>
</html>