package com.example.board;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.*;
import java.util.Map;

@WebServlet("/admin")
public class AdminServlet extends HttpServlet {
    
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        HttpSession session = req.getSession(false);
        String username = (session != null) ? (String) session.getAttribute("user") : null;

        resp.setContentType("text/html; charset=UTF-8");
        PrintWriter out = resp.getWriter();

        out.println("<html><head><link rel='stylesheet' href='style.css'></head><body>");
        out.println("<h1>Admin Panel</h1>");

        if (username == null || !username.equals("admin")) {
            out.println("<p>Access denied</p>");
            out.println("<a href='board'>Back to board</a>");
            out.println("</body></html>");
            return;
        }

        Map<String, String> users = (Map<String, String>) getServletContext().getAttribute("users");

        out.println("<p class='link'><a href='board'>Back to board</a></p>");
        out.println("<h3>Users list:</h3>");
        out.println("<form method='POST' action='deleteUser'>");
        out.println("<table border='1' cellpadding='5'>");
        out.println("<tr><th>Username</th><th>Action</th></tr>");

        for (String user : users.keySet()) {
            if (user.equals("admin")) continue;
            out.println("<tr>");
            out.println("<td>" + user + "</td>");
            out.println("<td><button type='submit' name='userToDelete' value='" + user + "'>Delete</button></td>");
            out.println("</tr>");
        }

        out.println("</table>");
        out.println("</form>");
        out.println("</body></html>");
    }
}
