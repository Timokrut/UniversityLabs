import java.util.ArrayList;
import java.util.List;

public class PrimeFinderWorker implements Runnable {
    private final TaskQueue taskQueue;

    public PrimeFinderWorker(TaskQueue taskQueue) {
        this.taskQueue = taskQueue;
    }

    @Override
    public void run() {
        try {
            while (true) {
                MyTask task = taskQueue.pop();
                if (task == null) break;

                List<Integer> primes = findPrimesInRange(task.getStart(), task.getEnd());
                task.addAnswers(primes);
                taskQueue.pushResult(task);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private List<Integer> findPrimesInRange(int start, int end) {
        List<Integer> primes = new ArrayList<>();
        for (int i = start; i <= end; i++) {
            if (isPrime(i)) {
                primes.add(i);
            }
        }
        return primes;
    }

    private boolean isPrime(int number) {
        if (number < 2) return false;
        for (int i = 2; i <= Math.sqrt(number); i++) {
            if (number % i == 0) return false;
        }
        return true;
    }
}
