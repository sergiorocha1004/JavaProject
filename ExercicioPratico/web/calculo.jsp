<%-- 
    Document   : solicita
    Created on : 16/09/2015, 20:15:12
    Author     : Sérgio Henrique
--%>
<%@page import="java.text.DateFormat"%>
<%@page import="java.util.Date"%>
<%@page import="java.text.Format"%>
<%@page import="java.text.SimpleDateFormat"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <%int numeroInt = Integer.parseInt("numero"); %> 
        <%-- Função para o cálculo do fatorial --%>
        <%
            int fatorial= 0; 
                while (numeroInt > 1){ 
                fatorial = fatorial *(numeroInt-1); numeroInt--; 
                } 
%>
<%= numeroInt %>

    </body
</html>