<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Form Processing</title>
</head>
<body>

  <h3>Parameter values:</h3>
  <%
    String userName = request.getParameter("userName");
    String password = request.getParameter("password");
    String firstName = request.getParameter("firstName");
    String lastName = request.getParameter("lastName");
    String gender = request.getParameter("gender");
    
    String[] addresses = request.getParameterValues("address");
  %>
  
  User name: <%=userName%><br>
  Password: <%=password%><br>
  First name: <%=firstName%><br>
  Last name: <%=lastName%><br>
  
  Gender: <%=gender%><br>
  
  <%
    if (addresses != null) {
    	for (String addr : addresses) {
  %>
        Address: <%=addr%><br>
   <% } } %>

</body>
</html>