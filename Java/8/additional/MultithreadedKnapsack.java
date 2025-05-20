import java.util.ArrayList;        
import java.util.List;

public class MultithreadedKnapsack {
    public static int solveKnapsack(Knapsack k, int threadNum) throws InterruptedException {
        int combinations = 1 << k.weights.length;
        int range = combinations / threadNum;

        List<KnapsackSolver> solvers = new ArrayList<>();
        List<Thread> threads = new ArrayList<>();

        for (int i = 0; i < threadNum; i++) {
            int start = i * range;
            int end = (i == threadNum - 1) ? combinations : (i + 1) * range;

            KnapsackSolver solver = new KnapsackSolver(start, end, k);
            solvers.add(solver);
            Thread thread = new Thread(solver);
            threads.add(thread);
            thread.start();
        }

        for (Thread thread : threads) {
            thread.join();
        }

        int max = 0;
        for (KnapsackSolver solver : solvers) {
            int profit = solver.getMaxProfit();
            if (profit > max) {
                max = profit;
            }
        }
        return max; 
    }
}
