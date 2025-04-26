import java.util.Scanner;
import java.util.ArrayList;

public class FormattedInput {
    public static Object[] scanf(String format) {
        try (Scanner scanner = new Scanner(System.in)) {
            while (true) {
                System.out.print("Enter data: ");
                String input = scanner.nextLine();
                try {
                    return sscanf(format, input);
                } catch (IllegalArgumentException e) {
                    System.out.println("Input failed: " + e.getMessage() + ". Try again.");
                }
            }
        }
    }

    public static Object[] sscanf(String format, String input) throws IllegalArgumentException {
        String[] formatSpecifiers = format.split(" ");
        String[] inputParts = input.split(" ");

        if (inputParts.length < formatSpecifiers.length) {
            throw new IllegalArgumentException("Not enough arguments provided");
        }

        Object[] result = new Object[formatSpecifiers.length];
        int inputIndex = 0;

        for (int i = 0; i < formatSpecifiers.length; i++) {
            String specifier = formatSpecifiers[i];
            
            if (inputIndex >= inputParts.length) {
                throw new IllegalArgumentException("Not enough input values for format");
            }

            try {
                switch (specifier) {
                    case "%d":
                        result[i] = Integer.parseInt(inputParts[inputIndex]);
                        inputIndex++;
                        break;
                    case "%f":
                        result[i] = Double.parseDouble(inputParts[inputIndex]);
                        inputIndex++;
                        break;
                    case "%s":
                        result[i] = inputParts[inputIndex];
                        inputIndex++;
                        break;
                    case "%c":
                        if (inputParts[inputIndex].length() != 1) {
                            throw new IllegalArgumentException("Expecting one symbol for %c");
                        }
                        result[i] = inputParts[inputIndex].charAt(0);
                        inputIndex++;
                        break;
                    case "%a":
                        result[i] = parseArray(inputParts, inputIndex);
                        inputIndex = inputParts.length; 
                        break;
                    default:
                        throw new IllegalArgumentException("Wrong format specifier: " + specifier);
                }
            } catch (NumberFormatException e) {
                throw new IllegalArgumentException("Wrong format for: " + specifier);
            }
        }

        return result;
    }

    private static int[] parseArray(String[] inputParts, int startIndex) {
        ArrayList<Integer> numbers = new ArrayList<>();
        
        for (int i = startIndex; i < inputParts.length; i++) {
            try {
                numbers.add(Integer.parseInt(inputParts[i]));
            } catch (NumberFormatException e) {
                continue;
            }
        }

        if (numbers.isEmpty()) {
            throw new IllegalArgumentException("No integers found for %a");
        }

        int[] array = new int[numbers.size()];
        for (int i = 0; i < array.length; i++) {
            array[i] = numbers.get(i);
        }
        return array;
    }

    public static void main(String[] args) {
        System.out.println("Testing with format: %d %s %c %f %a");
        Object[] vals = scanf("%d %s %c %f %a");
        for (Object val : vals) {
            if (val instanceof int[]) {
                System.out.print("Int array: ");
                for (int num : (int[]) val) {
                    System.out.print(num + " ");
                }
                System.out.println();
            } else {
                System.out.println(val + " (" + val.getClass().getSimpleName() + ")");
            }
        }
    }
}
