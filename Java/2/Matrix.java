
public class Matrix {
    private int[][] arr;
    private int size;

    public Matrix(int matrixSize) {
        arr = new int[matrixSize][matrixSize];
        size = matrixSize;

        for (int row = 0; row < size; row++) {
            for (int column = 0; column < size; column++) {
                if (row == column) {
                    arr[row][column] = 1;
                }
            }
        }
    }

    public Matrix sum(Matrix other) {
        Matrix result = new Matrix(size);

        for (int row = 0; row < size; row++) {
            for (int column = 0; column < size; column++) {
                    result.arr[row][column] = arr[row][column] + other.arr[row][column];
            }
        }

        return result;
    }

    public Matrix product(Matrix other) {
        Matrix result = new Matrix(size);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.arr[i][j] = 0;
                for (int k = 0; k < size; k++) {
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
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.append(arr[i][j]).append(" ");
            }
            result.append('\n');
        }
        return result.toString();
    } 
    
    public void doMiracleDiag(int type) {
        if (type == 0) {
            for (int i = 0; i < size; i++) {
                for (int j = i + 1; j < size; j++) {
                    int temp = arr[i][j];
                    arr[i][j] = arr[j][i];
                    arr[j][i] = temp;
                }
            }
        } else if (type == 1) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size - i - 1; j++) {
                    int temp = arr[i][j];
                    arr[i][j] = arr[size - 1 - j][size - 1 - i];
                    arr[size - 1 - j][size - 1 - i] = temp;
                }
            }
        } else {
            System.out.println("Invalid type");
        }
    }
}
