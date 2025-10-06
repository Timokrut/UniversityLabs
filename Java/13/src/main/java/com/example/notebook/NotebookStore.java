package com.example.notebook;

import java.io.*;
import java.util.*;
import javax.servlet.ServletContext;
import java.nio.charset.StandardCharsets;
import java.util.concurrent.ConcurrentHashMap;

public class NotebookStore {
    private final Map<String, List<String>> data = new ConcurrentHashMap<>();

    public Map<String, List<String>> snapshot() {
        Map<String, List<String>> copy = new ConcurrentHashMap<>();
        for (Map.Entry<String, List<String>> e : data.entrySet()) {
            copy.put(e.getKey(), new ArrayList<>(e.getValue()));
        }
        return Collections.unmodifiableMap(copy);
    }

    public void addUser(String username) {
        data.computeIfAbsent(username, k -> Collections.synchronizedList(new ArrayList<>()));
    }

    public void addPhone(String username, String phone) {
        addUser(username);
        data.get(username).add(phone);
    }

    public void loadFromResource(ServletContext context, String resourcePath) {
        if (resourcePath == null) return;
        try (InputStream is = context.getResourceAsStream(resourcePath)) {
            if (is == null) return;
            try (BufferedReader br = new BufferedReader(new InputStreamReader(is, StandardCharsets.UTF_8))) {
                String line;
                while ((line = br.readLine()) != null) {
                    line = line.trim();
                    if (line.isEmpty() || line.startsWith("#")) continue;
                    String[] parts = line.split("\\|", 2);
                    String name = parts[0].trim();
                    addUser(name);
                    if (parts.length > 1) {
                        String[] phones = parts[1].split(",");
                        for (String p : phones) {
                            String phone = p.trim();
                            if (!phone.isEmpty()) addPhone(name, phone);
                        }
                    }
                }
            }
        } catch (IOException ignored) {
        }
    }
}

