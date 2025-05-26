import java.util.ArrayList;
import java.util.List;

public class PrimeNumberFinder {
    public static void main(String[] args) {
        TaskQueue taskQueue = new TaskQueue();
        taskQueue.push(new MyTask(1, 100));
        taskQueue.push(new MyTask(101, 200));
        taskQueue.push(new MyTask(201, 300));
        taskQueue.push(new MyTask(301, 400));
        taskQueue.finish();
        
        int threadCount = 4;
        List<Thread> threads = new ArrayList<>();
        
        for (int i = 0; i < threadCount; i++) {
            Thread thread = new Thread(new PrimeFinderWorker(taskQueue, i+1));
            threads.add(thread);
            thread.start();
        }
        
        for (Thread thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
        
        taskQueue.showResults();
    }
}

