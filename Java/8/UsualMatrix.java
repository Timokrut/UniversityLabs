import java.util.Random;

public class UsualMatrix {
    protected int[][] data;
    protected int rows;
    protected int cols;

    public UsualMatrix(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        this.data = new int[rows][cols];
    }

    public int getRows() {
        return rows;
    }

    public int getColumns() {
        return cols;
    }

    public int getElement(int row, int col) {
        return data[row][col];
    }
    
    public void setElement(int row, int col, int value) {
        data[row][col] = value;
    }

    public UsualMatrix add(UsualMatrix other) {
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
   
    public UsualMatrix multiply(UsualMatrix other) {
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
    
    public boolean equals(UsualMatrix other) {
        if (this.getRows() != other.getRows() || this.getColumns() != other.getColumns()) {
            return false;
        }

        for (int i = 0; i < this.getRows(); i++) {
            for (int j = 0; j < this.getColumns(); j++) {
                if (this.getElement(i, j) != other.getElement(i, j)) {
                    return false;
                }
            }
        }

        return true;
    }

    public void fillRandom() {
        Random random = new Random();
        for (int i = 0; i < this.getRows(); i++) {
            for (int j = 0; j < this.getColumns(); j++) {
                this.setElement(i, j, random.nextInt(100));
            }
        }
    }

    @Override 
    public String toString() {
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
