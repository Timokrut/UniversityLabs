public class Int {
    private int value;

    public Int(int value) {
        this.value = value;
    }

    public void increment() {
        value++;    
    }

    public void decrement() {
        value--;
    }

    public void add(Int number) {
        value += number.value;
    }

    public void substract(Int number) {
        number.value -= number.value;
    } 

    @Override
    public String toString() {
        return Integer.toString(value);
    }

    public Int powerUsingAddition(int exponent) {
        if (exponent == 0) {
            return new Int(1);
        }
        Int result = new Int(value);
        for (int i = 1; i < exponent; i++) {
            Int temp = new Int(0);
            for (int j = 0; j < value; j++) {
                temp.value = temp.value + result.value;
            }
            result = temp;
        }
        return result;
    }
}
