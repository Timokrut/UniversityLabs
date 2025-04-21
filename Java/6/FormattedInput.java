import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class FormattedInput {
    public static Object[] scanf(String format) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.print("Ввод пользователя: ");
            String input = scanner.nextLine();
            try {
                return sscanf(format, input);
            } catch (IllegalArgumentException e) {
                System.out.println("Ошибка ввода. Пожалуйста, повторите ввод.");
            }
        }
    }

    public static Object[] sscanf(String format, String in) {
        String regex = format.replace("%d", "(\\d+)")
                            .replace("%f", "([+-]?\\d+\\.?\\d*)")
                            .replace("%s", "(\\S+)")
                            .replace("%c", "(.)")
                            .replace(" ", "\\s+");
        regex = "^" + regex + "$";

        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(in.trim());

        if (!matcher.find()) {
            throw new IllegalArgumentException("Ввод не соответствует формату");
        }

        String[] formatSpecifiers = format.split("\\s+");
        Object[] result = new Object[formatSpecifiers.length];

        for (int i = 0; i < formatSpecifiers.length; i++) {
            String specifier = formatSpecifiers[i];
            String value = matcher.group(i + 1);
            
            try {
                switch (specifier) {
                    case "%d":
                        result[i] = Integer.parseInt(value);
                        break;
                    case "%f":
                        result[i] = Double.parseDouble(value);
                        break;
                    case "%s":
                        result[i] = value;
                        break;
                    case "%c":
                        if (value.length() != 1) {
                            throw new IllegalArgumentException();
                        }
                        result[i] = value.charAt(0);
                        break;
                    default:
                        throw new IllegalArgumentException("Неизвестный спецификатор формата");
                }
            } catch (Exception e) {
                throw new IllegalArgumentException("Ошибка парсинга значения для " + specifier);
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Object[] vals = scanf("%d %s %c %f");
        for (Object val : vals) {
            System.out.println(val + " (" + val.getClass().getSimpleName() + ")");
        }
    }
}
