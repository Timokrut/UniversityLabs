package org.mycompany.matrixlib;

import org.mycompany.matrixlib.exceptions.MatrixException;
import org.mycompany.matrixlib.Matrix;
import org.mycompany.matrixlib.SquareMatrix;
import org.mycompany.matrixlib.TwoOfFourMatrix2;

public class Main {
    public static void main(String[] args) {
        try {

            int[][] data = {
            {1, 2, 1, 2},
            {3, 4, 3, 4},
            {5, 6, 5, 6},
            {7, 8, 7, 8}
            };

            TwoOfFourMatrix2 matrix = new TwoOfFourMatrix2(data);

            System.out.println("matrix");
            System.out.println(matrix);

            System.out.println("matrix[0][0]");
            System.out.println(matrix.getElement(0, 0));
            
            System.out.println("\nmatrix[0][2]");
            System.out.println(matrix.getElement(0, 2));
            
            System.out.println("\nmatrix[3][1]");
            System.out.println(matrix.getElement(3, 1));
            
            System.out.println("\nmatrix[3][3]");
            System.out.println(matrix.getElement(3, 3));

            System.out.println("\ninsert 10 to matrix[1][1]");
            matrix.setElement(1, 1, 10);

            System.out.println("\nmatrix");
            System.out.println(matrix);

            System.out.println("matrix[1][1]");
            System.out.println(matrix.getElement(1, 1));
            
            System.out.println("\nmatrix[1][3]");
            System.out.println(matrix.getElement(1, 3));

            // System.out.println("\nmatrix[100][100]");
            // System.out.println(matrix.getElement(100, 100));

            Matrix matrix2 = new Matrix(4, 4);
            SquareMatrix matrix3 = new SquareMatrix(4); 
           

            matrix.sum(matrix2);
            matrix.sum(matrix3);

            matrix.product(matrix2);
            matrix.product(matrix3);


        } catch (MatrixException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
