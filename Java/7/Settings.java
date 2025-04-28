import java.io.*;
import java.net.Proxy;
import java.util.Map; 
import java.util.HashMap; 
import java.util.Objects;

public class Settings {
    private HashMap<String, Integer> settingsMap; 

    public Settings() {
        this.settingsMap = new HashMap<>();
    }

    public void put(String name, int value) {
        settingsMap.put(name, value);
    }

    public int get(String name) {
        return settingsMap.getOrDefault(name, 0);
    }

    public void delete(String name) {
        settingsMap.remove(name);
    }

    public void saveToBinaryFile(String filename) throws IOException {
        try (DataOutputStream dos = new DataOutputStream(new FileOutputStream(filename))) {
            dos.writeInt(settingsMap.size());
            for (Map.Entry<String, Integer> entry : settingsMap.entrySet()) {
                dos.writeUTF(entry.getKey());
                dos.writeInt(entry.getValue());
            }
        }
    }

    public void loadFromBinaryFile(String filename) throws IOException {
        settingsMap.clear();
        try (DataInputStream dis = new DataInputStream(new FileInputStream(filename))) {
            int size = dis.readInt();
            for (int i = 0; i < size; i++) {
                String key = dis.readUTF();
                int value = dis.readInt();
                settingsMap.put(key, value);
            }
        } 
    }

    public void saveToTextFile(String filename) throws IOException {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
            for (Map.Entry<String, Integer> entry : settingsMap.entrySet()) {
                writer.write(entry.getKey() + "=" + entry.getValue());
                writer.newLine();
            }
        }
    }

    public void loadFromTextFile(String filename) throws IOException {
        settingsMap.clear();
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split("=");
                if (parts.length == 2) {
                    settingsMap.put(parts[0], Integer.parseInt(parts[1]));
                }
            }
        }
    }
    
    @Override 
    public boolean equals(Object other) {
        if (this == other) {
            return true;
        }

        if (other == null || this.getClass() != other.getClass()) { 
            return false;
        }
        Settings settings = (Settings) other;
        return settingsMap.equals(settings.settingsMap);
    }

    @Override 
    public String toString() {
        return "Settings {" + settingsMap + "}";
    }

    @Override 
    public int hashCode() {
        return Objects.hash(settingsMap);
    }
}
