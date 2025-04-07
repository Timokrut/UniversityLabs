public class UsualMatrix implements IMatrix {
    protected int[][] data;
    protected int rows;
    protected int cols;

    public UsualMatrix(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        this.data = new int[rows][cols];
    }

    @Override 
    public int getRows() {
        return rows;
    }

    @Override 
    public int getColumns() {
        return cols;
    }

    @Override 
    public int getElement(int row, int col) {
        return data[row][col];
    }
    
    @Override 
    public void setElement(int row, int col, int value) {
        data[row][col] = value;
    }

    @Override 
    public IMatrix add(IMatrix other) {
        if (this.getRows() != other.getRows() || this.getColumns() != other.getColumns()) {
            throw new RuntimeException("Matrix dimensions must be same for addition");
        }

        UsualMatrix res = new UsualMatrix(this.getRows(), this.getColumns());
        for (int i = 0; i < this.getRows(); i++) {
            for (int j = 0; j < this.getColumns(); j++) {
                res.setElement(i, j, this.getElement(i, j) + other.getElement(i, j));
            }
        }
        return res;
    }
   
    @Override 
    public IMatrix multiply(IMatrix other) {
        if (this.getColumns() != other.getRows()) {
            throw new RuntimeException("Matrix dimensions must agree for multiplication");
        }

        UsualMatrix res = new UsualMatrix(this.getRows(), this.getRows());

        for (int i = 0; i < this.getRows(); i++) {
            for (int j = 0; j < other.getColumns(); j++) {
                int sum = 0;
                for (int k = 0; k < this.getColumns(); k++) {
                    sum += this.getElement(i, k) * other.getElement(k, j);
                }
                res.setElement(i, j, sum);
            }
        }
        return res;
    }
    
    // TODO -> obj
    @Override 
    public boolean equals(IMatrix other) {
        if (rows != other.getRows() || cols != other.getColumns()) {
            return false;
        }

        // TODO IS INSTANCE
            
        for (int i = 0; i < this.getRows(); i++) {
            for (int j = 0; j < this.getColumns(); j++) {
                if (this.getElement(i, j) != other.getElement(i, j)) {
                    return false;
                }
            }
        }

        return true;
    }

    @Override 
    public String toString(IMatrix matrix) {
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < this.getRows(); i++) {
            for (int j = 0; j < this.getColumns(); j++) {
                sb.append(this.getElement(i, j)).append(" ");        
            }
            sb.append("\n");
        }  

        return sb.toString();
    }
}
