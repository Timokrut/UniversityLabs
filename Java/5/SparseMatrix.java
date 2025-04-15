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

        
        if (other instanceof SparseMatrix) {
            SparseMatrix otherSparse = (SparseMatrix) other;
            for (NonZeroElement el : otherSparse.elements) {
                int current = res.getElement(el.row, el.col);
                res.setElement(el.row, el.col, current + el.value); 
            }
        } else {
            for (int i = 0; i < this.getRows(); i++) {
                for (int j = 0; j < this.getColumns(); j++) {
                    int otherValue = other.getElement(i, j);
                    if (otherValue != 0) {
                        int curValue = res.getElement(i, j);
                        res.setElement(i, j, curValue + otherValue);
                    }
                }
            }
        }
        return res;
    }

    @Override
    public IMatrix multiply(IMatrix other) {
        if (this.getColumns() != other.getRows()) {
            throw new RuntimeException("Matrix dimensions must agree");
        }

        SparseMatrix res = new SparseMatrix(this.getRows(), other.getColumns());
        
        if (other instanceof SparseMatrix) {
            SparseMatrix otherSparse = (SparseMatrix) other;
            for (NonZeroElement elA : this.elements) {
                for (NonZeroElement elB : otherSparse.elements) {
                    if (elA.col == elB.row) {
                        int current = res.getElement(elA.row, elB.col);
                        res.setElement(elA.row, elB.col, current + elA.value * elB.value);
                    }
                }
            }
        } else {
            for (NonZeroElement elA : this.elements) {
                for (int j = 0; j < other.getColumns(); j++) {
                    int otherVal = other.getElement(elA.col, j);
                    if (otherVal != 0) {
                        int current = res.getElement(elA.row, j);
                        res.setElement(elA.row, j, current + elA.value * otherVal);
                    }
                }
            }
        }
        
        return res;
    }

    @Override 
    public boolean equals(IMatrix other) {
        if (this.getRows() != other.getRows() || this.getColumns() != other.getColumns()) {
            return false;
        }

        for (NonZeroElement el : elements) { 
            if (el.value != other.getElement(el.row, el.col)) {
                return false;
            } 
        }

        for (int i = 0; i < this.getRows(); i++) {
            for (int j = 0; j < this.getColumns(); j++) {
                if (other.getElement(i, j) != 0 && this.getElement(i, j) == 0) {
                    return false;
                }
            }
        }

        return true;
    }

    @Override
    public void fillRandom(int nonZeroElements) {
        if (nonZeroElements > this.getRows() * this.getColumns()) {
            throw new RuntimeException("Too many non-zero elements for matrix size");
        }

        elements.clear();
        
        for (int n = 0; n < nonZeroElements; n++) {
            int i, j;
            do {
                i = (int) (Math.random() * this.getRows());
                j = (int) (Math.random() * this.getColumns());
            } while (this.getElement(i, j) != 0);
            
            this.setElement(i, j, (int) (Math.random() * 1000));
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
