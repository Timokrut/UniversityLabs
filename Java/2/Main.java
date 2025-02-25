
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

        // for (int i = 0; i < 10; i++) {
        //     System.out.println(matrix);
        //     matrix = matrix.product(pow);
        // }

        Matrix m1 = new Matrix(3);
        Matrix m2 = new Matrix(3);

        int counter = 1;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m1.setElement(i, j, counter);
                counter++;
            }
        } 

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m2.setElement(i, j, counter);
                counter++;
            }
        } 
    
        System.out.println(m1);
        m1.doMiracleDiag(0);
        System.out.println(m1);

        System.out.println(m2);
        m2.doMiracleDiag(1);
        System.out.println(m2);
    }
}
