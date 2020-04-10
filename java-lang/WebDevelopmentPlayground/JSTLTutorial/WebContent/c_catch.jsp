<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
    
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>c:catch example</title>
</head>
<body>

  <h2>c:catch example</h2>
  
  <c:catch var="ex">
    <%
      int a = 100 / 0;
    %>
  </c:catch>
  
  <c:if test="${ex != null}">
    <c:out value="Exception: ${ex}" />
    <br>
    <c:out value="Message: ${ex.message}" />
  </c:if>

</body>
</html>