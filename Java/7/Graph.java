import java.io.*;
import java.util.*;

public class Graph {
    private HashMap<Integer, List<Integer>> adjacencyList;

    public Graph() {
        this.adjacencyList = new HashMap<>();
    }

    public void addVertex(int vertex) {
        adjacencyList.put(vertex, new ArrayList<>());
    }

    public void addEdge(int source, int destination) {
        addVertex(source);
        addVertex(destination);
        adjacencyList.get(source).add(destination);
    }

    public List<Integer> getAdjacentVertices(int vertex) {
        return adjacencyList.getOrDefault(vertex, Collections.emptyList());
    }

    public void saveToBinaryFile(String filename) throws IOException {
        try (DataOutputStream dos = new DataOutputStream(new FileOutputStream(filename))) {
            dos.writeInt(adjacencyList.size()); 
            for (Map.Entry<Integer, List<Integer>> entry : adjacencyList.entrySet()) {
                // write values
                }
            }
        }
    }

    public void loadFromBinaryFile(String filename) throws IOException {
        adjacencyList.clear();
        try (DataInputStream dis = new DataInputStream(new FileInputStream(filename))) {
            int vertexCount = dis.readInt();
            for (int i = 0; i < vertexCount; i++) {
                // read values
            }
        }
    }

    public void saveToTextFile(String filename) throws IOException {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
            for (Map.Entry<Integer, List<Integer>> entry : adjacencyList.entrySet()) {
                // write values
            }
        }
    }

    public void loadFromTextFile(String filename) throws IOException {
        adjacencyList.clear();
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = reader.readLine()) != null) {
                // read values
            }
        }
    }

    @Override
    public boolean equals(Object other) {
        if (this == other){
            return true;
        } 
        if (other == null || this.getClass() != other.getClass()) {
            return false;
        }
        Graph graph = (Graph) other;
        return adjacencyList.equals(graph.adjacencyList);
    }

    @Override
    public int hashCode() {
        return Objects.hash(adjacencyList);
    }

    @Override
    public String toString() {
        ...
    }

    public static void main(String[] args) {
        ...
    }
}
