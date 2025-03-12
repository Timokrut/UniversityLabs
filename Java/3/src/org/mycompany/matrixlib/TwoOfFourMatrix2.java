package org.mycompany.matrixlib;

import org.mycompany.matrixlib.exceptions.MatrixException;


public final class TwoOfFourMatrix2 extends Matrix {
    public TwoOfFourMatrix2(int[][] fullMatrix) throws MatrixException {
        super(fullMatrix.length, fullMatrix[0].length / 2); 
        columns *= 2;
        if (rows % 2 != 0 || columns % 2 != 0) {
            throw new MatrixException("Matrix dimensions must be even");
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns / 2; j++) {
                arr[i][j] = fullMatrix[i][j];
            }
        }
    }

    @Override
    public int getElement(int row, int column) throws MatrixException {
        if (row < 0 || row >= rows || column < 0 || column >= columns) {
            throw new MatrixException("Index out of bounds");
        }

        if (column >= columns / 2) {
            return arr[row][column - columns / 2];
        }

        return arr[row][column];
    }

    @Override
    public void setElement(int row, int column, int value) throws MatrixException {
        if (row < 0 || row >= rows || column < 0 || column >= columns) {
            throw new MatrixException("Index out of bounds");
        }

        if (column >= columns / 2) {
            arr[row][column - columns / 2] = value;
        } else {
            arr[row][column] = value;
        }
    }
}
