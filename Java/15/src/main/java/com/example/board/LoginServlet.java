package com.example.board;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.*;
import java.util.Map;

@WebServlet("/login")
public class LoginServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        resp.setContentType("text/html; charset=UTF-8");
        PrintWriter out = resp.getWriter();

        out.println("<!DOCTYPE html><html><head><title>Enter</title>");
        out.println("<link rel='stylesheet' href='style.css'></head><body>");
        out.println("<h2>Enter</h2>");
        out.println("<form method='post' action='login'>");
        out.println("Login: <input type='text' name='username'><br>");
        out.println("Password: <input type='password' name='password'><br>");
        out.println("<input type='submit' value='Enter'></form>");
        out.println("<a class='link' href='board'>Back</a>");
        out.println("</body></html>");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException, ServletException {
        String username = req.getParameter("username");
        String password = req.getParameter("password");

        Map<String, String> users = (Map<String, String>) getServletContext().getAttribute("users");

        if (users != null && users.containsKey(username) && users.get(username).equals(password)) {
            HttpSession session = req.getSession();
            session.setAttribute("user", username);
            resp.sendRedirect("board");
        } else {
            resp.setContentType("text/html; charset=UTF-8");
            PrintWriter out = resp.getWriter();
            out.println("<html><body>");
            out.println("<p style='color:red;'>Wrong login or password</p>");
            out.println("<a class='link' href='login'>Try again</a>");
            out.println("</body></html>");
        }
    }
}
