package com.example.board;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.*;
import java.util.*;

@WebServlet("/board")
public class BoardServlet extends HttpServlet {
    private Map<String, String> users = new HashMap<>();
    private List<Post> posts = Collections.synchronizedList(new ArrayList<>());

    @Override
    public void init() throws ServletException {
        try (InputStream inputStream = getServletContext().getResourceAsStream("/users.txt")){
            if (inputStream == null) {
                throw new ServletException("File users.txt not found");
            }

            try (BufferedReader br = new BufferedReader(new InputStreamReader(inputStream))) {
                String line;
                while ((line = br.readLine()) != null) {
                    String[] parts = line.split(":");
                    if (parts.length == 2) {
                        users.put(parts[0].trim(), parts[1].trim());
                    }
                }
            } 
        } catch (IOException e) {
            throw new ServletException("Error reading users.txt", e);
        }
        getServletContext().setAttribute("users", users);
        getServletContext().setAttribute("posts", posts);
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        resp.setContentType("text/html; charset=UTF-8");
        PrintWriter out = resp.getWriter();

        HttpSession session = req.getSession(false);
        String user = (session != null) ? (String) session.getAttribute("user") : null;

        out.println("<!DOCTYPE html><html><head><title>Notice board</title>");
        out.println("<link rel='stylesheet' href='style.css'></head><body>");
        out.println("<h2>Notice board</h2>");

        if (user == null) {
            out.println("<a class='link' href='login'>Enter</a>");
        } else {
            out.printf("Hello, <b>%s</b> | <a class='link' href='addpost'>Add post</a> | <a class='link' href='logout'>Exit</a>", user);
            if (user.equals("admin")) {
                out.println(" | <a class='link' href='admin'>Admin panel</a>");
            }
        }

        out.println("<hr>");
        List<Post> posts = (List<Post>) getServletContext().getAttribute("posts");
        if (posts.isEmpty()) {
            out.println("<p>No posts yet.</p>");
        } else {
            Collections.reverse(posts);
            for (Post p : posts) {
                out.printf("<div class='post'><div class='post-title'>%s</div>", p.getTitle());
                out.printf("<div class='post-text'>%s</div>", p.getText());
                out.printf("<div><small>Author: %s | %s</small></div></div><hr>", p.getAuthor(), p.getTimestamp());
            }
            Collections.reverse(posts);
        }

        out.println("</body></html>");
    }
}
