import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Settings settings = new Settings();
        // 
        // settings.put("volume", 80);
        // settings.put("brightness", 50);
        // settings.put("width", 1920);
        // settings.put("height", 1080);

        
        // try {
            // settings.saveToBinaryFile("settings.bin");
            // settings.saveToTextFile("settings.txt");
            // 
            // Settings loadedFromBinary = new Settings();
            // loadedFromBinary.loadFromBinaryFile("settings.bin");
            // System.out.println("Loaded from binary: " + loadedFromBinary);
            // 
            // Settings loadedFromText = new Settings();
            // loadedFromText.loadFromTextFile("settings.txt");
            // System.out.println("Loaded from text: " + loadedFromText);
            // 
            // System.out.println("Are equal: " + settings.equals(loadedFromBinary));
            
        // } catch (IOException e) {
        //     System.out.println("Error: " + e.getMessage());
        // }
            
        Graph graph = new Graph();

        graph.addEdge("A", "B");
        graph.addEdge("A", "C");
        graph.addEdge("B", "C");
        graph.addEdge("C", "A");
        System.out.println("Graph after adding edges: " + graph);

        // graph.removeEdge("A", "B");
        // System.out.println("Graph after removing edge A -> B: " + graph);
        //
        // graph.removeEdge("A", "C");
        // System.out.println("Graph after removing edge A -> C: " + graph);

        try {
            graph.saveToTextFile("graph.txt");
            graph = new Graph(); 
            graph.loadFromTextFile("graph.txt");
            System.out.println("Graph loaded from text file: " + graph);
        } catch (Exception e) {
            System.out.println("Error with text file: " + e.getMessage());
        }

        try {
            graph.saveToBinaryFile("graph.bin");
            graph = new Graph();
            graph.loadFromBinaryFile("graph.bin");
            System.out.println("Graph loaded from binary file: " + graph);
        } catch (Exception e) {
            System.out.println("Error with binary file: " + e.getMessage());
        }

    }
}


// Создайте класс для хранения графа с методами для записи/чтения его из текстового/бинарного файлов
