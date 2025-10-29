package com.example.board;

import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.*;
import java.util.Map;

@WebServlet("/deleteUser")
public class DeleteUserServlet extends HttpServlet {
    
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        HttpSession session = req.getSession(false);
        String currentUser = (session != null) ? (String) session.getAttribute("user") : null;

        if (currentUser == null || !currentUser.equals("admin")) {
            resp.sendRedirect("board");
            return;
        }

        String userToDelete = req.getParameter("userToDelete");
        if (userToDelete != null) {
            Map<String, String> users = (Map<String, String>) getServletContext().getAttribute("users");
            users.remove(userToDelete);
            System.out.println("User deleted: " + userToDelete);
        }

        resp.sendRedirect("admin");
    }
}
