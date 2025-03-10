import org.mycompany.exceptions.MatrixException;
import org.mycompany.matrix.Matrix;
import org.mycompany.matrix.SquareMatrix;
import org.mycompany.matrix.TwoOfFourMatrix2;

public class Main {
    public static void main(String[] args) {
        try {
            // Matrix matrix1 = new Matrix(2, 3);
            // matrix1.setElement(0, 0, 1);
            // matrix1.setElement(0, 1, 2);
            // matrix1.setElement(0, 2, 3);
            // matrix1.setElement(1, 0, 4);
            // matrix1.setElement(1, 1, 5);
            // matrix1.setElement(1, 2, 6);
            //
            // Matrix matrix2 = new Matrix(2, 3);
            // matrix2.setElement(0, 0, 7);
            // matrix2.setElement(0, 1, 8);
            // matrix2.setElement(0, 2, 9);
            // matrix2.setElement(1, 0, 10);
            // matrix2.setElement(1, 1, 11);
            // matrix2.setElement(1, 2, 12);
            //
            // Matrix sum = matrix1.sum(matrix2);
            // System.out.println("Sum of matrices:");
            // System.out.println(sum);
            //
            // SquareMatrix squareMatrix1 = new SquareMatrix(2);
            // SquareMatrix squareMatrix2 = new SquareMatrix(2);
            //
            // SquareMatrix sumSquare = squareMatrix1.sum(squareMatrix2);
            // System.out.println("Sum of square matrices:");
            // System.out.println(sumSquare);

            int[][] data = {
            {1, 2, 1, 2},
            {3, 4, 3, 4},
            {5, 6, 5, 6},
            {7, 8, 7, 8}
            };

            int[][] data2 = {
            {5, 6, 5, 6},
            {7, 8, 8, 7},
            {1, 2, 1, 2},
            {3, 4, 3, 4}
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

            System.out.println("\nmatrix[100][100]");
            System.out.println(matrix.getElement(100, 100));

        } catch (MatrixException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
