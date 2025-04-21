import java.util.ArrayList;

class ArrayListStack implements IStack {
    private ArrayList<Integer> list = new ArrayList<>();

    @Override 
    public void push(int item) {
        list.addFirst(item);
    }

    @Override 
    public int pop() {
        if (list.isEmpty()) {
            throw new RuntimeException("Stack is emtpy");
        }

        return list.removeLast();
    }

    @Override 
    public int length() {
        return list.size();
    }

    @Override 
    public boolean equals(IStack other) {
        if (other == null || this.length() != other.length()) {
            return false;
        }
        // listiterator
        //
        //
        
        return true;
    }

    @Override 
    public String toString() {
        return list.toString();
    }
}
