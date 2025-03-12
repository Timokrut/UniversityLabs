package org.mycompany.matrixlib;

import org.mycompany.matrixlib.exceptions.MatrixException;

public class Matrix {
    protected final int[][] arr;
    protected final int rows;
    protected int columns;

    public Matrix(int rows, int columns) throws MatrixException {
        if (rows <= 0 || columns <= 0) {
            throw new MatrixException("Matrix dimensions must be positive");
        }
        this.rows = rows;
        this.columns = columns;
        arr = new int[rows][columns]; 
    }

    public void setElement(int row, int column, int value) throws MatrixException {
        if (row < 0 || row >= rows || column < 0 || column >= columns) {
            throw new MatrixException("Index out of bounds");
        }
        arr[row][column] = value;
    }

    public int getElement(int row, int column) throws MatrixException {
        if (row < 0 || row >= rows || column < 0 || column >= columns) {
            throw new MatrixException("Index out of bounds");
        }
        return arr[row][column];
    }

    public Matrix sum(Matrix other) throws MatrixException {
        if (this.rows != other.rows || this.columns != other.columns) {
            throw new MatrixException("Matrices must have the same dimensions for addition");
        }

        Matrix result = new Matrix(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                result.setElement(i, j, this.getElement(i, j) + other.getElement(i, j));
            }
        }

        return result;
    }

    public final Matrix product(Matrix other) throws MatrixException {
        if (this.columns != other.rows) {
            throw new MatrixException("Can't multiply this matrix");
        }
        Matrix result = new Matrix(this.rows, other.columns);
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < other.columns; j++) {
                int sum = 0;
                for (int k = 0; k < this.columns; k++) {
                    sum += this.getElement(i, k) * other.getElement(k, j);
                }
                result.setElement(i, j, sum);
            }
        }
        return result;
    }

    @Override
    public final boolean equals(Object obj) {
        if (this == obj){
            return true;
        } 

        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }        

        Matrix other = (Matrix) obj;
        if (this.rows != other.rows || this.columns != other.columns) {
            return false;
        }        
    
        try {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    if (this.getElement(i, j) != other.getElement(i, j)) {
                        return false;
                    }
                }
            }
            return true;
        } catch (MatrixException e) {
            throw new RuntimeException("Unexpected error in getElement/setElement");
        }
    }

    @Override
    public final String toString() {
        StringBuilder sb = new StringBuilder();
        try {
            for (int row = 0; row < this.rows; row++) {
                for (int col = 0; col < this.columns; col++) {
                    sb.append(this.getElement(row, col)).append(" ");
                }
                sb.append("\n");
            }
            return sb.toString(); 
        } catch (MatrixException e) {
            throw new RuntimeException("Unexpected error in getElement/setElement");
        } 
    } 

}

