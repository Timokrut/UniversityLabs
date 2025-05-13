public  class Main {
    public static void main(String[] args) {
        int size = 1000;
        UsualMatrix matrix1 = new UsualMatrix(size, size);
        UsualMatrix matrix2 = new UsualMatrix(size, size);
        
        matrix1.fillRandom();
        matrix2.fillRandom();

        long startTime = System.currentTimeMillis();
        UsualMatrix resultSingle = matrix1.multiply(matrix2);
        long endTime = System.currentTimeMillis();
        System.out.println("Single threaded multiplication time: " + (endTime - startTime) + " ms");
    
        ParallelMatrixProduct parallelMultiplier = new ParallelMatrixProduct(8);
        startTime = System.currentTimeMillis();
        UsualMatrix resultParallel = parallelMultiplier.product(matrix1, matrix2);
        endTime = System.currentTimeMillis();
        System.out.println("Multi threaded multiplication time: " + (endTime - startTime) + " ms");

        System.out.println(resultSingle.equals(resultParallel));
    }
}
