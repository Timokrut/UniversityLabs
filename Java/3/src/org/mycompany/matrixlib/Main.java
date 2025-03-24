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

            System.out.println("=============================");

            Matrix BaseMatrix = new Matrix(4, 4);
            SquareMatrix SquareMatrix = new SquareMatrix(4); 

            System.out.println("Initial BaseMatrix:\n" + BaseMatrix);
            System.out.println("Initial SquareMatrix:\n" + SquareMatrix);
            System.out.println("Initial TwoOfFourMatrix2:\n" + matrix);

            System.out.println("TwoOfFourMatrix2 + Matrix");
            Matrix result = new Matrix(4, 4);
            result = matrix.sum(BaseMatrix);
            System.out.println("Result:\n" + result);

            System.out.println("TwoOfFourMatrix2 * Matrix");
            Matrix result1 = new Matrix(4, 4);
            result1 = matrix.product(BaseMatrix);
            System.out.println("Result:\n" + result1);

            System.out.println("TwoOfFourMatrix2 + SquareMatrix");
            Matrix result2 = new Matrix(4, 4); result2 = matrix.sum(SquareMatrix);
            System.out.println("Result:\n" + result2);

            System.out.println("TwoOfFourMatrix2 * SquareMatrix");
            Matrix result3 = new Matrix(4, 4);
            result3 = matrix.product(SquareMatrix);
            System.out.println("Result:\n" + result3);

            System.out.println("Matrix * SquareMatrix");
            Matrix result4 = new Matrix(4, 4);
            result4 = BaseMatrix.product(SquareMatrix);
            System.out.println("Result:\n" + result4);

            System.out.println("Matrix + SquareMatrix");
            Matrix result5 = new Matrix(4, 4);
            result5 = BaseMatrix.sum(SquareMatrix);
            System.out.println("Result:\n" + result5);


            System.out.println("===========================");
            int[][] evenInput = {
                {1, 2, 3, 1, 2},
                {3, 4, 5, 3, 3}, 
                {6, 7, 8, 6, 7},
                {9, 10, 11, 9, 10}, 
                {12, 13, 14, 12, 13},
            };
            TwoOfFourMatrix2 oddMatrix = new TwoOfFourMatrix2(evenInput); 
            Matrix baseOddMatrix = new Matrix(5, 5);
            SquareMatrix squareOddMatrix = new SquareMatrix(5); 

            // Odd TwoOfFourMatrix2 example
            System.out.println(oddMatrix);
              
            Matrix result6 = new Matrix(5, 5);
            result6 = oddMatrix.sum(baseOddMatrix);
            System.out.println(result6);

            Matrix result7 = new Matrix(5, 5);
            result7 = oddMatrix.sum(squareOddMatrix);
            System.out.println(result7);

        } catch (MatrixException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
