package edu.lab13.notebook;

import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;
import javax.servlet.annotation.WebListener;

@WebListener
public class AppInitializer implements ServletContextListener {
    @Override
    public void contextInitialized(ServletContextEvent sce) {
        String path = sce.getServletContext().getInitParameter("contactsFile");
        NotebookStore store = new NotebookStore();
        store.loadFromResource(sce.getServletContext(), path);
        sce.getServletContext().setAttribute("store", store);
    }

    @Override
    public void contextDestroyed(ServletContextEvent sce) {
        // nothing
    }
}


