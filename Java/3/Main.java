import matrix.Matrix;
import matrix.SquareMatrix;
import exceptions.MatrixException;

public class Main {
    public static void main(String[] args) {
        try {
            Matrix matrix1 = new Matrix(2, 3);
            matrix1.setElement(0, 0, 1);
            matrix1.setElement(0, 1, 2);
            matrix1.setElement(0, 2, 3);
            matrix1.setElement(1, 0, 4);
            matrix1.setElement(1, 1, 5);
            matrix1.setElement(1, 2, 6);

            Matrix matrix2 = new Matrix(2, 3);
            matrix2.setElement(0, 0, 7);
            matrix2.setElement(0, 1, 8);
            matrix2.setElement(0, 2, 9);
            matrix2.setElement(1, 0, 10);
            matrix2.setElement(1, 1, 11);
            matrix2.setElement(1, 2, 12);

            Matrix sum = matrix1.sum(matrix2);
            System.out.println("Sum of matrices:");
            System.out.println(sum);

            SquareMatrix squareMatrix1 = new SquareMatrix(2);
            SquareMatrix squareMatrix2 = new SquareMatrix(2);

            SquareMatrix sumSquare = squareMatrix1.sum(squareMatrix2);
            System.out.println("Sum of square matrices:");
            System.out.println(sumSquare);

        } catch (MatrixException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
