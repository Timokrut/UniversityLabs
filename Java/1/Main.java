
public class Main {
    public static void main(String[] args) {
        Int number = new Int();
        Int incrementor = new Int();
        
        incrementor.increment();
        System.out.println(incrementor);
            
        for (int i = 0; i < 1000; i++) {
            number.add(incrementor);
        }

        System.out.println(number.toString());
    }
}
