package com.example.notebook;

import java.io.*;
import java.util.*;
import javax.servlet.ServletContext;
import java.nio.charset.StandardCharsets;
import java.util.concurrent.ConcurrentHashMap;

public class NotebookStore {
    private final Map<String, List<String>> data = new ConcurrentHashMap<>();
    private final Map<String, Set<Group>> userGroups = new ConcurrentHashMap<>();

    public Map<String, List<String>> snapshot() {
        Map<String, List<String>> copy = new ConcurrentHashMap<>();
        for (Map.Entry<String, List<String>> e : data.entrySet()) {
            copy.put(e.getKey(), new ArrayList<>(e.getValue()));
        }
        return Collections.unmodifiableMap(copy);
    }

    public void addUser(String username, Group... groups) {
        data.computeIfAbsent(username, k -> Collections.synchronizedList(new ArrayList<>()));
        userGroups.computeIfAbsent(username, k -> ConcurrentHashMap.newKeySet());
        for (Group g : groups) {
            if (g != null && g != Group.ALL)
                userGroups.get(username).add(g);
        }
    }

    public void addPhone(String username, String phone) {
        addUser(username, Group.ALL);
        data.get(username).add(phone);
    }

    public void addGroup(String username, Group group) {
        addUser(username, group);
    }

    public Map<String, List<String>> getUsersByGroup(Group group) {
        if (group == Group.ALL) return snapshot();

        Map<String, List<String>> filtered = new LinkedHashMap<>();
        for (String name : data.keySet()) {
            Set<Group> groups = userGroups.get(name);
            if (groups != null && groups.contains(group)) {
                filtered.put(name, new ArrayList<>(data.get(name)));
            }
        }
        return filtered;
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
                    // Формат: Имя | телефоны | группы (через запятую)
                    String[] parts = line.split("\\|");
                    String name = parts[0].trim();
                    addUser(name, Group.ALL);
                    if (parts.length > 1) {
                        String[] phones = parts[1].split(",");
                        for (String p : phones) {
                            String phone = p.trim();
                            if (!phone.isEmpty()) addPhone(name, phone);
                        }
                    }
                    if (parts.length > 2) {
                        String[] groupNames = parts[2].split(",");
                        for (String g : groupNames) {
                            Group group = Group.fromParam(g.trim().toLowerCase());
                            if (group != Group.ALL)
                                addGroup(name, group);
                        }
                    }
                }
            }
        } catch (IOException ignored) {
        }
    }
}

