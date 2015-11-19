<%-- 
    Document   : index
    Created on : 16/09/2015, 09:27:19
    Author     : Sérgio Henrique
--%>

<%@page import="java.math.BigInteger"%>
<%@page import="java.text.DateFormat"%>
<%@page import="java.util.Date"%>
<%@page import="java.text.Format"%>
<%@page import="java.text.SimpleDateFormat"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <body>
    <head>
    <form action="index.jsp" method="get">
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    
    <img src=".\imagens\ETB.jpg" height="150" width="500"><p>
         <%
            
            long data = session.getCreationTime();
            Date agora = new Date(data);
            Format formato = new 
            SimpleDateFormat("EEEE, dd 'de' MMMM 'de' yyyy");
            String data1 = formato.format(agora); 
           
        %>
           <h3>  <%= data1 %><%--Imprime Data por Extenso--%></h3>
        
        <%
            
            long hora = session.getCreationTime();
            Date agora1 = new Date(hora);
            Format formato1 = new 
            SimpleDateFormat("HH");
            String hora1 = formato1.format(agora1);
            int horaInt = Integer.parseInt(hora1);  
          
            String saudacao = "";
            if (horaInt >=0 && horaInt <12){
                saudacao = "Bom dia!!!";
            }
            else if (horaInt >=12  && horaInt <18){
                saudacao = "Boa tarde!!!";
            }
            else {
                saudacao = "Boa noite!!!";
            }
           
        %>
        <h3><%= saudacao%><h3>

        
       <form>
            Nome:
            <input type="text" name="nome"/><p>
            Digite um número: 
            <input type="text" name="numero"/><p>
            <input type="button" name="enviar" value="Enviar"/>
            <%
            String nome = request.getParameter("nome");
            String numero = request.getParameter("numero");

            %>
         
            
          


           
        </form> 
        
        
       
      </body> 
</html>          
         



          
    

