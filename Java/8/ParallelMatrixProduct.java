public class ParallelMatrixProduct {
    private int threadsCount;

    public ParallelMatrixProduct(int threadsCount) {
        this.threadsCount = threadsCount;
    } 

    public IMatrix product(IMatrix a, IMatrix b) {
        if (a.getColumns() != b.getRows()) {
            throw new RuntimeException("Matrix dimensions must agree for multiplication");
        }

        IMatrix result = new UsualMatrix(a.getRows(), b.getColumns());
        Thread[] threads = new Thread[Math.min(threadsCount, a.getRows())];

        int rowsPerThread = a.getRows() / threads.length;
        int remainingRows = a.getRows() % threads.length;

        int startRow = 0;
        for (int i = 0; i < threads.length; i++) {
            int endRow = startRow + rowsPerThread + (i < remainingRows ? 1 : 0);
            
            threads[i] = new Thread(new MatrixMultiplier(a, b, result, startRow, endRow));
            threads[i].start();

            startRow = endRow;
        }

        try {
            for (Thread thread : threads) {
                thread.join();
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            System.err.println("Thread was interrupted");
        }

        return result;
    }

    private static class MatrixMultiplier implements Runnable {
        private final IMatrix a;
        private final IMatrix b;
        private final IMatrix result;
        private final int startRow;
        private final int endRow;

        public MatrixMultiplier(IMatrix a, IMatrix b, IMatrix result, int startRow, int endRow) {
            this.a = a;
            this.b = b;
            this.result = result;
            this.startRow = startRow;
            this.endRow = endRow;
        }

        @Override 
        public void run() {
            for (int i = startRow; i < endRow; i++) {
                for (int j = 0; j < b.getColumns(); j++) {
                    int sum = 0;
                    for (int k = 0; k < a.getColumns(); k++) {
                        sum += a.getElement(i, k) * b.getElement(k, j);
                    }
                    result.setElement(i, j, sum);
                }
            }
        }
    }

}

    
