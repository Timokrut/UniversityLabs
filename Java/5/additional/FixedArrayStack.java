class FixedArrayStack implements IStack {
    private int[] array;
    private int top = -1;
    
    public FixedArrayStack(int capacity) {
        array = new int[capacity];
    }

    @Override 
    public void push(int item) {
        if (top == array.length - 1) {
            throw new RuntimeException("Stack is full");
        }
        array[++top] = item;
    }

    @Override 
    public int pop() {
        if (top == -1) {
            throw new RuntimeException("Stack is emtpy");
        }
        return array[top--];
    }

    @Override 
    public int length() {
        return top + 1;
    }

    @Override 
    public boolean equals(IStack other) {
        if (other == null || this.length() != other.length()) {
            return false;
        }

        // 
        //
        //
        return true;
    }

    @Override 
    public String toString() {
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < array.length; i++) {
            sb.append(array[i]);
            if (i < top) {
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }
}
