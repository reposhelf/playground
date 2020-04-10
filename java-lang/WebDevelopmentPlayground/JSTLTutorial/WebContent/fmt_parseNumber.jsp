<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>fmt:parseNumber example</title>
  </head>
  <body>
    <h2>fmt:parseNumber example</h2>
    
    <!-- a String in currency format -->
    <c:set var="accountBalance" value="$12345.6789" />
    
    <h4>Input <c:out value="${accountBalance}" /></h4>
    
    <fmt:parseNumber var="parsedNumber" type="currency" parseLocale="en_US" value="${accountBalance}" />
    
    <p>Account Balance: <c:out value="${parsedNumber}" /></p>
    
    <!-- integerOnly="true" : Specifies whether only the integer part of the value is parsed -->
    <fmt:parseNumber var="parsedNumber" type="currency" integerOnly="true" parseLocale="en_US"
      value="${accountBalance}"/>
      
    <p>Account Balance (without cents): <c:out value="${parsedNumber} "/></p>    
    
  </body>
</html>