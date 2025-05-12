public  class Main {
    public static void main(String[] args) {
        int size = 1000;
        IMatrix matrix1 = new UsualMatrix(size, size);
        IMatrix matrix2 = new UsualMatrix(size, size);
        
        matrix1.fillRandom();
        matrix2.fillRandom();

        long startTime = System.currentTimeMillis();
        IMatrix resultSingle = matrix1.multiply(matrix2);
        long endTime = System.currentTimeMillis();
        System.out.println("Single threaded multiplication time: " + (endTime - startTime) + " ms");
    
        ParallelMatrixProduct parallelMultiplier = new ParallelMatrixProduct(4);
        startTime = System.currentTimeMillis();
        IMatrix resultParallel = parallelMultiplier.product(matrix1, matrix2);
        endTime = System.currentTimeMillis();
        System.out.println("Multi threaded multiplication time: " + (endTime - startTime) + " ms");

        System.out.println(resultSingle.equals(resultParallel));
    }
}
