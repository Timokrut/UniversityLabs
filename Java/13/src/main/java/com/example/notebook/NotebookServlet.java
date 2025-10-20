package com.example.notebook;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import java.util.Map;

public class NotebookServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String action = req.getParameter("action");
        if (action == null) action = "list";
        resp.setCharacterEncoding("UTF-8");
        resp.setContentType("text/html; charset=UTF-8");
        PrintWriter out = resp.getWriter();

        NotebookStore store = (NotebookStore) getServletContext().getAttribute("store");

        if ("addUser".equals(action)) {
            out.println("<html><body>");
            out.println("<h3>Добавить пользователя</h3>");
            out.println("<form method='post'>");
            out.println("<input type='hidden' name='action' value='addUser' />");
            out.println("Имя: <input type='text' name='username' /> ");
            out.println("Группы:<br/>");
            out.println("<label><input type='checkbox' name='group' value='colleagues'/> Коллеги</label><br/>");
            out.println("<label><input type='checkbox' name='group' value='family'/> Семья</label><br/>");
            out.println("<label><input type='checkbox' name='group' value='friends'/> Друзья</label><br/><br/>");
            out.println("<button type='submit'>Submit</button>");
            out.println("</form>");
            out.println("<p><a href='?'>Назад</a></p>");
            out.println("</body></html>");
            return;
        }

        if ("addPhone".equals(action)) {
            out.println("<html><body>");
            out.println("<h3>Добавить телефон</h3>");
            out.println("<form method='post'>");
            out.println("<input type='hidden' name='action' value='addPhone' />");
            out.println("Имя: <input type='text' name='username' /> ");
            out.println("Телефон: <input type='text' name='phone' /> ");
            out.println("<button type='submit'>Submit</button>");
            out.println("</form>");
            out.println("<p><a href='?'>Назад</a></p>");
            out.println("</body></html>");
            return;
        }

        if ("list".equals(action) || action == null) {
            Group currentGroup = Group.fromParam(req.getParameter("group"));

            out.println("<html><body>");
            out.println("<h3>Записная книжка</h3>");

            out.println("<p>");
            for (Group g : Group.values()) {
                String link = "?group=" + g.name().toLowerCase();
                out.println("<a href='" + link + "'>" + g.getDisplayName() + "</a> ");
            }
            out.println("</p>");

            out.println("<p><a href='?action=addUser'>Добавить пользователя</a> | <a href='?action=addPhone'>Добавить телефон</a></p>");

            Map<String, List<String>> snapshot = store.getUsersByGroup(currentGroup);
            out.println("<ul>");
            for (Map.Entry<String, List<String>> e : snapshot.entrySet()) {
                out.println("<li><b>" + escape(e.getKey()) + ":</b> " + String.join(", ", e.getValue()) + "</li>");
            }
            out.println("</ul>");
            out.println("</body></html>");
            return;
        }

        Map<String, List<String>> snapshot = store.snapshot();
        out.println("<html><body>");
        out.println("<h3>Записная книжка</h3>");
        out.println("<p><a href='?action=addUser'>Добавить пользователя</a> | <a href='?action=addPhone'>Добавить телефон</a></p>");
        out.println("<ul>");
        for (Map.Entry<String, List<String>> e : snapshot.entrySet()) {
            out.println("<li><b>" + escape(e.getKey()) + ":</b> " + String.join(", ", e.getValue()) + "</li>");
        }
        out.println("</ul>");
        out.println("</body></html>");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String action = req.getParameter("action");
        NotebookStore store = (NotebookStore) getServletContext().getAttribute("store");
        if ("addUser".equals(action)) {
            String username = trim(req.getParameter("username"));
            if (username != null && !username.isEmpty()) {
                String[] groupParams = req.getParameterValues("group");
                if (groupParams != null) {
                    Group[] groups = new Group[groupParams.length];
                    for (int i = 0; i < groupParams.length; i++) {
                        groups[i] = Group.fromParam(groupParams[i]);
                    }
                    store.addUser(username, groups);
                } else {
                    store.addUser(username, Group.ALL);
                }
            }
            resp.sendRedirect(req.getContextPath() + "/");
            return;
        }
        if ("addPhone".equals(action)) {
            String username = trim(req.getParameter("username"));
            String phone = trim(req.getParameter("phone"));
            if (username != null && !username.isEmpty() && phone != null && !phone.isEmpty()) {
                store.addPhone(username, phone);
            }
            resp.sendRedirect(req.getContextPath() + "/");
            return;
        }
        resp.sendRedirect(req.getContextPath() + "/");
    }

    private static String trim(String s) {
        return s == null ? null : s.trim();
    }

    private static String escape(String s) {
        return s == null ? "" : s.replace("&", "&amp;").replace("<", "&lt;").replace(">", "&gt;");
    }
}
