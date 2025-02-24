
public class Matrix {
    public int[][] arr;

    public Matrix(int matrix_size) {
        arr = new int[matrix_size][matrix_size];

        for (int row = 0; row < arr.length; row++) {
            for (int column = 0; column < arr[0].length; column++) {
                if (row == column) {
                    arr[row][column] = 1;
                }
            }
        }
    }

    public Matrix sum(Matrix other) {
        Matrix result = new Matrix(arr.length);

        for (int row = 0; row < arr.length; row++) {
            for (int column = 0; column < arr[0].length; column++) {
                    result.arr[row][column] = arr[row][column] + other.arr[row][column];
            }
        }

        return result;
    }


    public Matrix product(Matrix other) {
        Matrix result = new Matrix(arr.length);

        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length; j++) {
                result.arr[i][j] = 0;
                for (int k = 0; k < arr.length; k++) {
                    result.arr[i][j] += arr[i][k] * other.arr[k][j]; 
                }
            }
        }

        return result;
    } 

    public void setElement(int row, int column, int value) {
        arr[row][column] = value;
    }

    public int getElement(int row, int column) {
        return arr[row][column];
    }

    @Override
    public String toString() {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) {
                result.append(arr[i][j]).append(" ");
            }
            result.append('\n');
        }
        return result.toString();
    } 
}
