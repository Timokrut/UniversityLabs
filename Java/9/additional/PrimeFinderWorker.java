import java.util.List;
import java.util.ArrayList;

public class PrimeFinderWorker implements Runnable {
    private final TaskQueue taskQueue;
    private final int workerId;
    
    public PrimeFinderWorker(TaskQueue taskQueue, int workerId) {
        this.taskQueue = taskQueue;
        this.workerId = workerId;
    }
    
    @Override
    public void run() {
        taskQueue.registerWorker();
        
        try {
            while (true) {
                MyTask task = taskQueue.pop();
                
                if (task == null) {
                    break;
                }
                
                List<Integer> primes = findPrimesInRange(task.getStart(), task.getEnd());
                task.setAnswers(primes);
                taskQueue.pushResult(task);
            }
        } finally {
            taskQueue.unregisterWorker();
        }
    }
    
    private List<Integer> findPrimesInRange(int start, int end) {
        List<Integer> primes = new ArrayList<>();
        for (int num = start; num <= end; num++) {
            if (isPrime(num)) {
                primes.add(num);
            }
        }
        return primes;
    }
    
    private boolean isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }
}

