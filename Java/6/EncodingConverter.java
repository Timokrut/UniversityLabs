import java.io.*;

public class EncodingConverter {
    public static void main(String[] args) {
        if (args.length != 4) {
            System.out.println("Использование: java EncodingConverter <inputFile> <outputFile> <inputEncoding> <outputEncoding>");
            System.exit(1);
        }

        String inputFile = args[0];
        String outputFile = args[1];
        String inputEncoding = args[2];
        String outputEncoding = args[3];

        try {
            convertEncoding(inputFile, outputFile, inputEncoding, outputEncoding);
            System.out.println("Конвертация завершена успешно");
        } catch (IOException e) {
            System.err.println("Ошибка при конвертации: " + e.getMessage());
        }
    }

    private static void convertEncoding(String inputFile, String outputFile, 
                                      String inputEncoding, String outputEncoding) throws IOException {
        try (BufferedReader reader = new BufferedReader(
                new InputStreamReader(new FileInputStream(inputFile), inputEncoding));
             BufferedWriter writer = new BufferedWriter(
                new OutputStreamWriter(new FileOutputStream(outputFile), outputEncoding))) {
            
            String line;
            while ((line = reader.readLine()) != null) {
                writer.write(line);
                writer.newLine();
            }
        }
    }
}
