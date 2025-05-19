import java.util.Random;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        int itemCount = 25; 
        int[] weights = generateRandomArray(itemCount, 1, 20);
        int[] values = generateRandomArray(itemCount, 5, 50);
        int capacity = 100; 

        Knapsack k = new Knapsack(weights, values, capacity);

        System.out.println("Statring tests...");
        long startTime1 = System.currentTimeMillis();
        int result1 = MultithreadedKnapsack.solveKnapsack(k, 1);
        long endTime1 = System.currentTimeMillis();
        System.out.println("1 thread: " + result1 + ", Elapsed time = " + (endTime1 - startTime1) + " ms");

        long startTime4 = System.currentTimeMillis();
        int result4 = MultithreadedKnapsack.solveKnapsack(k, 4);
        long endTime4 = System.currentTimeMillis();
        System.out.println("4 threads: " + result4 + ", Elapsed time = " + (endTime4 - startTime4) + " ms");
    }

    private static int[] generateRandomArray(int size, int min, int max) {
        Random rand = new Random();
        int[] arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = rand.nextInt(max - min + 1) + min;
        }
        return arr;
    }
}
