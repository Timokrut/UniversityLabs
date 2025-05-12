public interface IMatrix {
    int getRows();
    int getColumns();
    int getElement(int row, int col);
    void setElement(int row, int col, int val);
    IMatrix add(IMatrix other);
    IMatrix multiply(IMatrix other);
    boolean equals(IMatrix matrix);
    void fillRandom(); 
    String toString();
}
