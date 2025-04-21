import java.util.LinkedList;

class LinkedListStack implements IStack {
    private LinkedList<Integer> list = new LinkedList<>();

    @Override 
    public void push(int item) {
        list.addFirst(item);
    }

    @Override 
    public int pop() {
        if (list.isEmpty()) {
            throw new RuntimeException("Stack is emtpy");
        }
        return list.removeFirst();
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
        // listiter
        //
        return true;
    }

    @Override 
    public String toString() {
        return list.toString();
    }
}
