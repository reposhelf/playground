<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
    
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>c:choose,c:when,c:otherwise example</title>
</head>
<body>

  <h2>c:chooce,c:when,c:otherwise example</h2>
  
  <c:choose>
    <c:when test="${param.color=='red'}">
      <p style="color: red">RED COLOR</p>
    </c:when>
    
    <c:when test="${param.color=='blue'}">
      <p style="color: blue">BLUE COLOR</p>
    </c:when>
    
    <c:otherwise>
      <p>OTHER COLOR</p>
    </c:otherwise>
  </c:choose>

</body>
</html>