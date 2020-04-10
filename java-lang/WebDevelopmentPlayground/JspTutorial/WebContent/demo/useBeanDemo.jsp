<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Use Bean</title>
</head>
<body>

  <jsp:useBean id="helloBean" class="org.myroniuk.tutorial.jsp.beans.HelloBean"></jsp:useBean>
  
  <h3>Say Hello:</h3>
  <jsp:getProperty property="hello" name="helloBean"/>
  
  <!-- Set property name for helloBean -->
  <jsp:setProperty property="name" value="JSP" name="helloBean"/>
  
  <h3>Say Hello after setName</h3>
  <jsp:getProperty property="hello" name="helloBean"/>

</body>
</html>