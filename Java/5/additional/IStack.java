public interface IStack {
    void push(int item);
    int pop();
    int length();
    boolean equals(IStack other);
    String toString();
}
