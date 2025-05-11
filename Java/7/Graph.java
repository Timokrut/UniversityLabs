import java.io.*;
import java.util.*;

public class Graph {
    private HashMap<String, List<String>> adjacencyList;

    public Graph() {
        this.adjacencyList = new HashMap<>();
    }

    public void addEdge(String from, String to) {
        adjacencyList.putIfAbsent(from, new ArrayList<>());
        adjacencyList.get(from).add(to);
    }

    public void removeEdge(String from, String to) {
        List<String> edges = adjacencyList.get(from);
        if (edges != null) {
            edges.remove(to);
            if (edges.isEmpty()) {
                adjacencyList.remove(from);
            }
        }
    }

    public void saveToBinaryFile(String filename) throws IOException {
        try (DataOutputStream dos = new DataOutputStream(new FileOutputStream(filename))) {
            dos.writeInt(adjacencyList.size());
            for (Map.Entry<String, List<String>> entry : adjacencyList.entrySet()) {
                dos.writeUTF(entry.getKey());
                dos.writeInt(entry.getValue().size());
                for (String neighbor : entry.getValue()) {
                    dos.writeUTF(neighbor);
                }
            }
        }
    }

    public void loadFromBinaryFile(String filename) throws IOException {
        adjacencyList.clear();
        try (DataInputStream dis = new DataInputStream(new FileInputStream(filename))) {
            int size = dis.readInt();
            for (int i = 0; i < size; i++) {
                String node = dis.readUTF();
                int edges = dis.readInt();
                List<String> neighbors = new ArrayList<>();
                for (int j = 0; j < edges; j++) {
                    neighbors.add(dis.readUTF());
                }
                adjacencyList.put(node, neighbors);
            }
        }
    }

    public void saveToTextFile(String filename) throws IOException {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
            for (Map.Entry<String, List<String>> entry : adjacencyList.entrySet()) {
                writer.write(entry.getKey() + ":" + String.join(",", entry.getValue()));
                writer.newLine();
            }
        }
    }

    public void loadFromTextFile(String filename) throws IOException {
        adjacencyList.clear();
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(":");
                if (parts.length == 2) {
                    String[] neighbors = parts[1].split(",");
                    adjacencyList.put(parts[0], new ArrayList<>(Arrays.asList(neighbors)));
                }
            }
        }
    }

    @Override
    public String toString() {
        return "Graph: " + adjacencyList.toString();
    }
}
