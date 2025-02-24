public class Main {
    public static void main(String[] args) {
        Int number = new Int(0);
        Int incrementor = new Int(0);
       
        for (int i = 0; i < 50; i++) {
            incrementor.increment();
        }
            
        for (int i = 0; i < 20; i++) {
            number.add(incrementor);
        }

        System.out.println(number);

        // Additional task
        
        Int num = new Int(3);
        int exponent = 4;
        Int result = num.powerUsingAddition(exponent);
        System.out.println(result);
    }
}
