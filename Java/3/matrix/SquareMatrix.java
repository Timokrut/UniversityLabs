package matrix;

import exceptions.MatrixException;

public class SquareMatrix extends Matrix {
    public SquareMatrix(int size) {
        super(size, size);
        for (int i = 0; i < size; i++) {
            this.setElement(i, i, 1);
        }
    }

    @Override
    public SquareMatrix sum(Matrix other) {
    if (!(other instanceof SquareMatrix) || this.getRows() != other.getRows()) {
        throw new MatrixException("Both matrices must be square and of the same size for addition");
    }

    Matrix result = super.sum(other);
    SquareMatrix squareResult = new SquareMatrix(this.getRows());
    for (int i = 0; i < this.getRows(); i++) {
        for (int j = 0; j < this.getColumns(); j++) {
            squareResult.setElement(i, j, result.getElement(i, j));
        }
    }
    return squareResult;
}}

