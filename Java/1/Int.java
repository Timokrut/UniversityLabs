public class Int {
    private int value;

    public Int() {
        this.value = 0;
    }

    public void increment() {
        this.value++;    
    }

    public void decrement() {
        this.value--;
    }

    public void add(Int number) {
        this.value += number.value;
    }

    public void substract(Int number) {
        number.value -= number.value;
    } 

    public String toString() {
        return Integer.toString(this.value);
    }

    public int get(Int number) {
        return number.value;
    }
}

