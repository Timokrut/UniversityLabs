package org.mycompany.matrixlib;

import org.mycompany.matrixlib.exceptions.MatrixException;

public final class SquareMatrix extends Matrix {
    public SquareMatrix(int size) throws MatrixException {
        super(size, size);
        for (int i = 0; i < size; i++) {
            this.arr[i][i] = 1;
        }
    }

    @Override
    public SquareMatrix sum(Matrix other) throws MatrixException {
        if (!(other instanceof SquareMatrix) || this.rows != other.rows) {
            throw new MatrixException("Both matrices must be square and of the same size for addition");
        }

        Matrix result = super.sum(other);
        SquareMatrix squareResult = new SquareMatrix(this.rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                squareResult.arr[i][j] = result.arr[i][j];
            }
        }
        return squareResult;
}}

