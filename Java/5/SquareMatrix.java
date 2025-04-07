public class SquareMatrix extends UsualMatrix {
    public SquareMatrix(int size) {
        super(size, size);
        for (int i = 0; i < size; i++) {
            data[i][i] = 1;
        }
    }
   
    @Override 
    public IMatrix multiply(IMatrix other) {
        if (this.getRows() != other.getRows() || this.getColumns() != other.getColumns()) {
            throw new RuntimeException("Square matrices must be same size for multpiplication");
        }
        
        return super.multiply(other);
    }

    @Override 
    public IMatrix add(IMatrix other) {
        if (this.getRows() != other.getRows() || this.getColumns() != other.getColumns()) {
            throw new RuntimeException("Square matrices must be same size for addition");
        }
        return super.add(other);
    }
} 
