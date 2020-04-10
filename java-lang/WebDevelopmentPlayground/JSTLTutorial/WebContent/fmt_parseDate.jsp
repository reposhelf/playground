<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>fmt:parseDate example</title>
  </head>
  <body>
    <h2>fmt:parseDate example</h2>
    
    <!-- a Date time string -->
    <c:set var="dateTimeString" value="18-08-2017 20:28" />
    <h4>
      dateTimeString:
      <c:out value="${dateTimeString}" />
    </h4>
    
    <!-- Parsing a date time string, and store in a variable type of java.util.Date -->
    <fmt:parseDate value="${dateTimeString}" type="both" var="parsedDateTime" pattern="dd-MM-yyyy HH:mm" />
    
    <p>
      The date time after parsing:
      <c:out value="${parsedDateTime}" />
    </p>
    <br>
    <p>
      Date only:
      <fmt:formatDate value="${parsedDateTime}" pattern="dd-MM-yyyy" />
    </p>

  </body>
</html>