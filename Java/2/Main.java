
public class Main {
    public static void main(String[] args) {
        Matrix matrix = new Matrix(2);        
        matrix.setElement(0, 1, 1);    
        matrix.setElement(1, 0, 1);    
        matrix.setElement(1, 1, 0);    

        Matrix pow = new Matrix(2);
        pow.setElement(0, 1, 1);    
        pow.setElement(1, 0, 1);    
        pow.setElement(1, 1, 0);    

        System.out.println(matrix);

        for (int i = 0; i < 10 - 1; i++) {
            matrix = matrix.product(pow);
            System.out.println(matrix);
        }
    }
}
