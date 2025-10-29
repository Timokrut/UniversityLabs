package com.example;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import java.io.*;
import java.util.*;

public class TwoLevelListServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        response.setContentType("text/html; charset=UTF-8");

        String filePath = getServletContext().getRealPath("/data.txt");
        List<Category> categories = parseFile(filePath);

        PrintWriter out = response.getWriter();
        out.println("<!DOCTYPE html>");
        out.println("<html lang='ru'><head><meta charset='UTF-8'><title>Двухуровневый список</title>");
        out.println("<link rel='stylesheet' href='style.css'>");
        out.println("<script src='script.js' defer></script>");
        out.println("</head><body>");
        out.println("<h2>Двухуровневый список</h2>");
        out.println("<ol>");

        int id = 0;
        for (Category c : categories) {
            out.printf("<li>%s <span id='btn-%d' class='toggle' onclick='toggleList(%d)'>[+]</span>%n",
                    c.name, id, id);
            out.printf("<ul id='list-%d' class='hidden'>%n", id);
            for (String sub : c.items) {
                out.printf("<li>%s</li>%n", sub);
            }
            out.println("</ul></li>");
            id++;
        }

        out.println("</ol>");
        out.println("</body></html>");
    }

    private List<Category> parseFile(String path) throws IOException {
        List<Category> list = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(path), "UTF-8"))) {
            Category current = null;
            String line;
            while ((line = br.readLine()) != null) {
                if (line.startsWith("* ")) {
                    if (current != null) list.add(current);
                    current = new Category(line.substring(2).trim());
                } else if (line.startsWith("    * ")) {
                    if (current != null) current.items.add(line.substring(6).trim());
                }
            }
            if (current != null) list.add(current);
        }
        return list;
    }

    static class Category {
        String name;
        List<String> items = new ArrayList<>();

        Category(String name) {
            this.name = name;
        }
    }
}
