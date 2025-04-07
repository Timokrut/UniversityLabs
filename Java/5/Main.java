public class Main {
    public static void main(String[] args) {
        int size = 1000;
        int nonZeroElements = 1000;
        
        // Create and fill usual matrices
        UsualMatrix usual1 = new UsualMatrix(size, size);
        UsualMatrix usual2 = new UsualMatrix(size, size);
        
        // Create and fill sparse matrices with same data
        SparseMatrix sparse1 = new SparseMatrix(size, size);
        SparseMatrix sparse2 = new SparseMatrix(size, size);
        
        // Copy data from usual matrices to sparse
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int val1 = usual1.getElement(i, j);
                int val2 = usual2.getElement(i, j);
                if (val1 != 0) sparse1.setElement(i, j, val1);
                if (val2 != 0) sparse2.setElement(i, j, val2);
            }
        }
        
        // Test addition
        System.out.println("Testing addition...");
        IMatrix usualAdd = usual1.add(usual2);
        IMatrix sparseAdd = sparse1.add(sparse2);
        System.out.println("Addition results equal: " + usualAdd.equals(sparseAdd));
        
        // Test multiplication
        System.out.println("Testing multiplication...");
        IMatrix usualMult = usual1.multiply(usual2);
        IMatrix sparseMult = sparse1.multiply(sparse2);
        System.out.println("Multiplication results equal: " + usualMult.equals(sparseMult));

        return; 
    }
}
