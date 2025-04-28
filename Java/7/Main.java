import java.io.*;

public class Main {
    public static void main(String[] args) {
        Settings settings = new Settings();
        
        settings.put("volume", 80);
        settings.put("brightness", 50);
        settings.put("contrast", 30);
        
        try {
            settings.saveToBinaryFile("settings.bin");
            settings.saveToTextFile("settings.txt");
            
            Settings loadedFromBinary = new Settings();
            loadedFromBinary.loadFromBinaryFile("settings.bin");
            System.out.println("Loaded from binary: " + loadedFromBinary);
            
            Settings loadedFromText = new Settings();
            loadedFromText.loadFromTextFile("settings.txt");
            System.out.println("Loaded from text: " + loadedFromText);
            
            System.out.println("Are equal: " + settings.equals(loadedFromBinary));
            
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
