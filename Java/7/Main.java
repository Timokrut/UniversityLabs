import java.io.*;

public class Main {
    public static void main(String[] args) {
        Settings settings = new Settings();
        
        settings.put("volume", 80);
        settings.put("brightness", 50);
        settings.put("width", 1920);
        settings.put("height", 1080);

        
        try {
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
            
            

            Settings readFromBig = new Settings();
            for (int i = 0; i < 100; i++) {
                readFromBig.put("volume" + Integer.toString(i), i);
            }

            Settings readFromBig2 = new Settings();
            for (int i = 0; i < 100; i++) {
                readFromBig2.put("volume" + Integer.toString(i), i);
            }

            readFromBig.saveToTextFile("s.text");
            readFromBig2.saveToBinaryFile("s2.text");

        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}


// Создайте класс для хранения графа с методами для записи/чтения его из текстового/бинарного файлов
