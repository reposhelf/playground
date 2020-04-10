<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt" %>
    
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>fmt:formatDate example</title>
  </head>
  <body>
    <h2>fmt:formatDate example</h2>
    <c:set var="now" value="<%=new java.util.Date()%>" />
    
    <p>
      Time (fmt:dormatDate type='time')
      <strong>
        <fmt:formatDate value="${now}" type="time" />
      </strong>
    </p>
    
    <p>
      Date (fmt:dormatDate type='date')
      <strong>
        <fmt:formatDate value="${now}" type="date" />
      </strong>
    </p>
    
    <p>
      Date, Time (fmt:dormatDate type='both')
      <strong>
        <fmt:formatDate value="${now}" type="both" />
      </strong>
    </p>
    
    <p>
      Date, Time Sort (fmt:dormatDate type='time' dateStyle='short')
      <strong>
        <fmt:formatDate value="${now}" type="both" dateStyle="short" />
      </strong>
    </p>
    
    <p>
      Date, Time Medium (fmt:dormatDate type='time' dateStyle='medium')
      <strong>
        <fmt:formatDate value="${now}" type="both" dateStyle="medium" timeStyle="medium" />
      </strong>
    </p>
    
    <p>
      Date, Time Long (fmt:dormatDate type='time' dateStyle='long')
      <strong>
        <fmt:formatDate value="${now}" type="both" dateStyle="long" timeStyle="long" />
      </strong>
    </p>
    
    <p>
      Date, Time (fmt:dormatDate pattern='dd-MM-yyyy HH:mm:ss')
      <strong>
        <fmt:formatDate value="${now}" pattern="dd-MM-yyyy HH:mm:ss" />
      </strong>
    </p>
    
    <!-- Store in variable -->
    <fmt:formatDate value="${now}" pattern="dd-MM-yyyy HH:mm:ss" var="nowString"/>
    <p>
      Now String (dd-MM-yyyy HH:mm:ss)
      <strong>
        <c:out value="${nowString}" />
      </strong>
    </p>
   

  </body>
</html>