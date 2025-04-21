public class Main {
    public static int reverse(IStack stack, int value) {
        String strValue = Integer.toString(value);
        for (int i = 0; i < strValue.length(); i++) {
            char c = strValue.charAt(i);
            stack.push(Character.getNumericValue(c));
        }

        int reversedValue = 0;
        int multiplier = 1;
        
        while (stack.length() > 0) {
            reversedValue = reversedValue * 10 + stack.pop();
        }

        return reversedValue;
    }

    public static void main(String[] args) {

        // 1. LinkedListStack
        IStack linkedListStack = new LinkedListStack();
        int value1 = 12345;
        int reversed1 = reverse(linkedListStack, value1);
        System.out.println("LinkedListStack: " + value1 + " -> " + reversed1);
        
        // 2. ArrayListStack
        IStack arrayListStack = new ArrayListStack();
        int value2 = 67890;
        int reversed2 = reverse(arrayListStack, value2);
        System.out.println("ArrayListStack: " + value2 + " -> " + reversed2);
        
        // 3. FixedArrayStack (enough memory)
        IStack fixedArrayStack = new FixedArrayStack(10); 
        int value3 = 13579;
        int reversed3 = reverse(fixedArrayStack, value3);
        System.out.println("FixedArrayStack: " + value3 + " -> " + reversed3);

        // 4. FixedArrayStack (not enough memory)
        try {
            IStack smallStack = new FixedArrayStack(3);
            reverse(smallStack, 12345);
        } catch (RuntimeException e) {
            System.out.println("Expected exception: " + e.getMessage());
        }
    }
}
