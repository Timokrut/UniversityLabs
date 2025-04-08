import java.util.LinkedList;
import java.util.ListIterator;

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
        ListIterator<NonZeroElement> it = elements.listIterator();
        while (it.hasNext()) {
            NonZeroElement el = it.next();
            if (el.row == row && el.col == col) {
                it.remove();
            }
        }

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

    @Override 
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }

        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }
        SparseMatrix other = (SparseMatrix) obj;

        if (this.getRows() != other.getRows() || this.getColumns() != other.getColumns()) {
            return false;
        }

        for (NonZeroElement el : other.elements) { 
            if (el.value - this.getElement(el.row, el.col) != 0) {
                return false;
            } 
        }

        for (NonZeroElement el : elements) { 
            if (el.value - other.getElement(el.row, el.col) != 0) {
                return false;
            } 
        }

        return true;
    }

    public void fillRandom(int nonZeroElements) {
        if (nonZeroElements > rows * cols) {
            throw new RuntimeException("Too many non-zero elements for matrix size");
        }

        elements.clear();
        
        for (int n = 0; n < nonZeroElements; n++) {
            int i, j;
            do {
                i = (int) (Math.random() * rows);
                j = (int) (Math.random() * cols);
            } while (getElement(i, j) != 0);
            
            setElement(i, j, (int) Math.random() * 100);
        }
    }

    @Override 
    public String toString(IMatrix other) {
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
