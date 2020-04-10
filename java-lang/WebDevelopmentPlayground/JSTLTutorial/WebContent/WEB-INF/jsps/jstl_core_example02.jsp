<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
    
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>JSTL Core Tags Example 02</title>
</head>
<body>

  <h3>Departments and Employees</h3>
  
  <c:forEach items="${departments}" var="dept" >
    <!-- Check if collection is not null or not empty -->
    <c:if test="${not empty dept.employees}">
      <h3>${dept.deptName}</h3>
        <ul>
          <c:forEach items="${dept.employees}" var="emp" >
            <li>
              ${emp.empName} - (${emp.job})
            </li>
          </c:forEach>
        </ul>
    </c:if>
  </c:forEach>

</body>
</html>