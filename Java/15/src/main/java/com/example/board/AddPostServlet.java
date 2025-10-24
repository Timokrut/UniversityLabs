package com.example.board;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.*;
import java.util.List;

@WebServlet("/addpost")
public class AddPostServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        HttpSession session = req.getSession(false);
        if (session == null || session.getAttribute("user") == null) {
            resp.sendRedirect("login");
            return;
        }

        resp.setContentType("text/html; charset=UTF-8");
        PrintWriter out = resp.getWriter();
        out.println("<!DOCTYPE html><html><head><title>Add post</title>");
        out.println("<link rel='stylesheet' href='style.css'></head><body>");
        out.println("<h2>Add post</h2>");
        out.println("<form method='post' action='addpost'>");
        out.println("Title:<br><input type='text' name='title' required><br>");
        out.println("Text:<br><textarea name='text' rows='5' cols='40' required></textarea><br>");
        out.println("<input type='submit' value='Place'></form>");
        out.println("<a class='link' href='board'>Back</a>");
        out.println("</body></html>");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        HttpSession session = req.getSession(false);
        if (session == null || session.getAttribute("user") == null) {
            resp.sendRedirect("login");
            return;
        }

        String title = req.getParameter("title");
        String text = req.getParameter("text");
        String author = (String) session.getAttribute("user");

        List<Post> posts = (List<Post>) getServletContext().getAttribute("posts");
        posts.add(new Post(title, text, author));

        resp.sendRedirect("board");
    }
}
