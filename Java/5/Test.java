public class Test {
    public static void main(String[] args) {
        int size = 1000;
        int nonZeroElements = 1000;
        
        UsualMatrix usual1 = new UsualMatrix(size, size);
        UsualMatrix usual2 = new UsualMatrix(size, size);
        
        System.out.println("Randomize usual matrices");
        usual1.fillRandom(nonZeroElements);
        usual2.fillRandom(nonZeroElements);

        SparseMatrix sparse1 = new SparseMatrix(size, size);
        SparseMatrix sparse2 = new SparseMatrix(size, size);

        System.out.println("Randomize sparse matrices");
        sparse1.fillRandom(nonZeroElements);
        sparse2.fillRandom(nonZeroElements);

        System.out.println("Testing usual matrix addition...");
        long startTime = System.currentTimeMillis();
        IMatrix usualAdd = usual1.add(usual2);
        long endTime = System.currentTimeMillis();
        System.out.println("Usual addition time: " + (endTime - startTime) + " ms");

        System.out.println("Testing sparse matrix addition...");
        startTime = System.currentTimeMillis();
        IMatrix sparseAdd = sparse1.add(sparse2);
        endTime = System.currentTimeMillis();
        System.out.println("Sparse addition time: " + (endTime - startTime) + " ms");

        System.out.println("Testing usual matrix multiplication...");
        startTime = System.currentTimeMillis();
        IMatrix usualMult = usual1.multiply(usual2);
        endTime = System.currentTimeMillis();
        System.out.println("Usual multiplication time: " + (endTime - startTime) + " ms");

        System.out.println("Testing sparse matrix multiplication...");
        startTime = System.currentTimeMillis();
        IMatrix sparseMult = sparse1.multiply(sparse2);
        endTime = System.currentTimeMillis();
        System.out.println("Sparse multiplication time: " + (endTime - startTime) + " ms");
    }
}

// public class Main {
//     public static void main(String[] args) {
//         int size = 1000;
//         int nonZeroElements = 1000;
//         
//         // UsualMatrix usual1 = new UsualMatrix(size, size);
//         // UsualMatrix usual2 = new UsualMatrix(size, size);
//     
//         
//
//         // System.out.println("Randomize matrix");
//         //
//         // usual1.fillRandom(nonZeroElements);
//         // usual2.fillRandom(nonZeroElements);
//
//         SparseMatrix sparse1 = new SparseMatrix(size, size);
//         SparseMatrix sparse2 = new SparseMatrix(size, size);
//
//         System.out.println("Randomize matrix");
//
//         sparse1.fillRandom(nonZeroElements);
//         sparse2.fillRandom(nonZeroElements);
//
//         
//         // for (int i = 0; i < size; i++) {
//         //     for (int j = 0; j < size; j++) {
//         //         sparse1.setElement(i, j, usual1.getElement(i, j));
//         //         sparse2.setElement(i, j, usual2.getElement(i, j));
//         //     }
//         // }
//
//         System.out.println("Testing addition...");
//         // IMatrix usualAdd = usual1.add(usual2);
//         IMatrix sparseAdd = sparse1.add(sparse2);
//
//         // System.out.println("Addition results equal: " + usualAdd.equals(sparseAdd));
//         
//         System.out.println("Testing multiplication...");
//
//         // IMatrix usualMult = usual1.multiply(usual2);
//         IMatrix sparseMult = sparse1.multiply(sparse2);
//
//         // System.out.println("Multiplication results equal: " + usualMult.equals(sparseMult));
//     }
//
// }
