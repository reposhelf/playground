<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
    
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>c:remove example</title>
</head>
<body>

  <h2>c:remove example</h2>
  
  <c:set scope="request" var="greeting" value="Hello every body" />
  <c:out value="Greeting: ${greeting}" />
  
  <br><br>
  
  <c:remove scope="request" var="greeting" />
  <c:out value="${'After remove:'}" />
  <br>
  <c:out value="Greeting: ${greeting}" />

</body>
</html>