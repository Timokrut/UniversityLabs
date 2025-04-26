import java.io.*;
import java.nio.charset.Charset;

public class EncodingConverter {
    public static void main(String[] args) {
        if (args.length != 4) {
            System.out.println("Use: \"java EncodingConverter <inputFile> <outputFile> <inputEncoding> <outputEncoding>\"");
            System.exit(1);
        }

        String inputFile = args[0];
        String outputFile = args[1];
        String inputEncoding = args[2];
        String outputEncoding = args[3];

        try {
            if (!Charset.isSupported(inputEncoding)) {
                throw new UnsupportedEncodingException("Unsupported input encoding: " + inputEncoding);
            }

            if (!Charset.isSupported(outputEncoding)) {
                throw new UnsupportedEncodingException("Unsupported output encoding: " + outputEncoding);
            }

            convertEncoding(inputFile, outputFile, inputEncoding, outputEncoding);
            System.out.println("Convertation succesfully finished");
        } catch (IOException e) {
            System.err.println("Error while converting: " + e.getMessage());
        }
    }

    private static void convertEncoding(String inputFile, String outputFile, String inputEncoding, String outputEncoding) throws IOException {
        try (InputStreamReader isr = new InputStreamReader(new FileInputStream(inputFile), inputEncoding);
			 BufferedReader reader = new BufferedReader(isr);
			 OutputStreamWriter osw = new OutputStreamWriter(new FileOutputStream(outputFile), outputEncoding);
			 BufferedWriter writer = new BufferedWriter(osw)) {
                String line;
                while ((line = reader.readLine()) != null) {
                    writer.write(line);
                    writer.newLine();
            }
		}
    }
}
