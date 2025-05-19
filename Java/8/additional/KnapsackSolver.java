public class KnapsackSolver implements Runnable {
    private final int start;
    private final int end;
    private final Knapsack knapsack;
    private int maxProfit = 0;

    public KnapsackSolver(int start, int end, Knapsack knapsack) {
        this.start = start;
        this.end = end;
        this.knapsack = knapsack;
    }

    @Override 
    public void run() {
        for (int i = start; i < end; i++) {
            int currentWeight = 0;
            int currentValue = 0;
            for (int j = 0; j < knapsack.weights.length; j++) {
                if ((i & (1 << j)) > 0) {
                    currentWeight += knapsack.weights[j];
                    currentValue += knapsack.values[j];
                }
            }
            if (currentWeight <= knapsack.capacity) {
                maxProfit = Math.max(maxProfit, currentValue);
            }
        }
    }

    public int getMaxProfit() {
        return maxProfit;
    }
    
}
