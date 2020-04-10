<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt" %>

<!--
If the user has used one language on a page,
variable 'language' in 'session' scope, its value will stored in user session,
and the web site will be displayed in that language,
if the parameters of the page does not specify different values for it.
-->
<c:if test="${not empty param.language}">
  <c:set var="language" value="${param.language}" scope="session" />
</c:if>

<fmt:setLocale value="${language}" />

<fmt:setBundle basename="org.myroniuk.jstltutorial.bundles.MyBundle" />
    
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>fmt:bundle example</title>
  </head>
  <body>
    <h2>fmt:bundle example</h2>
    <form action="">
      <table border="0">
        <tr>
          <td>
            <fmt:message key="login.label.userName"/>
          </td>
          <td>
            <input type="text" name="userName" />
          </td>
        </tr>
        
        <tr>
          <td>
            <fmt:message key="login.label.password" />
          </td>
          <td>
            <input type="text" name="passeord" />
          </td>
        </tr>
      </table>
      
      <input type="submit" value="submit" />
    </form>

  </body>
</html>