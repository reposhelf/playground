<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
    
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>c:url,c:param example</title>
</head>
<body>

  <h2>c:url,c:param example</h2>
  
  <c:url var="myUrl" value="www.example.com/page.jsp" >
    <c:param name="color" value="red" />
    <c:param name="background" value="blue" />
  </c:url>
  
  <c:out value="${myUrl}" />

</body>
</html>