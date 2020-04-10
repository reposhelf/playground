<%@ page import="java.util.Date, java.text.*" %>

<%
  Date now = new Date();
  DateFormat df = new SimpleDateFormat("dd-MM-yyyy HH:mm:ss SSS");
%>

<h2>Current Time:</h2>
<%=df.format(now)%>