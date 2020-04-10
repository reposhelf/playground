<%@ page import="org.myroniuk.tutorial.jsp.utils.CookieUtils" %>

<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Cookie Demo</title>
</head>
<body>

  <%
    CookieUtils.demoUserCookie(request, response, out);
  %>
  
  <a href="">Try Again!</a>

</body>
</html>