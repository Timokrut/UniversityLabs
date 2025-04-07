import java.util.LinkedList;

public class SparseMatrix implements IMatrix {
    private int rows;
    private int cols;
    private LinkedList<NonZeroElement> elements;

    private static class NonZeroElement {
        int row;
        int col;
        int value;

        NonZeroElement(int row, int col, int value) {
            this.row = row;
            this.col = col;
            this.value = value;
        }        
    }   

    public SparseMatrix(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        this.elements = new LinkedList<>();        
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
        for (NonZeroElement el : elements) {
            if (el.row == row && el.col == col) {
                return el.value;
            }
        }
        return 0;
    }

    @Override 
    public void setElement(int row, int col, int value) {
        elements.removeIf(el -> el.row == row && el.col == col);

        if (value != 0) {
            elements.add(new NonZeroElement(row, col, value));
        }
    }

    @Override 
    public IMatrix add(IMatrix other) {
        if (this.getRows() != other.getRows() || this.getColumns() != other.getColumns()) {
            throw new RuntimeException("Matrix dimensions should be same for addition");
        }
        SparseMatrix res = new SparseMatrix(rows, cols);

        for (NonZeroElement el : elements) {
            res.setElement(el.row, el.col, el.value);
        }

        for (int i = 0; i < this.getRows(); i++) {
            for (int j = 0; j < this.getColumns(); j++) {
                int otherValue = other.getElement(i, j);
                if (otherValue != 0) {
                    int curValue = res.getElement(i, j);
                    res.setElement(i, j, curValue + otherValue);
                }
            }
        }

        return res;
    }

    @Override 
    public IMatrix multiply(IMatrix other) {
        if (this.getColumns() != other.getRows()) {
            throw new RuntimeException("Matrix dimensions must agree for multipication");
        }

        SparseMatrix res = new SparseMatrix(this.getRows(), other.getColumns()); 
        for (NonZeroElement el : elements) {
            for (int j = 0; j < other.getColumns(); j++) {
                int otherValue = other.getElement(el.col, j);
                if (otherValue != 0) {
                    int currentValue = res.getElement(el.row, j);
                    res.setElement(el.row, j, currentValue + el.value * otherValue);
                }
            }
        }

        return res;
    } 

    // TODO -> OBJ obj
    @Override 
    public boolean equals(IMatrix other) {
        if (this.getRows() != other.getRows() || this.getColumns() != other.getColumns()) {
            return false;
        }

        // TODO IS INSTANCE OF
        

        // TODO ?
        for (NonZeroElement el : elements) { 
            if (el.value - other.getElement(el.row, el.col) == 0) {
                return false;
            } 
        }

        for (int i = 0; i < this.getRows(); i++) {
            for (int j = 0; j < this.getColumns(); j++) {
                int otherValue = other.getElement(i, j);
                if (otherValue != 0 && getElement(i, j) == 0) { 
                    return false;
                }
            }
        }
        return true;
    }

    @Override 
    public String toString(IMatrix other) {
        return "";
    }
}
