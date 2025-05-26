import java.util.LinkedList;

public class TaskQueue {
    private final LinkedList<MyTask> tasks = new LinkedList<>();
    private final LinkedList<MyTask> results = new LinkedList<>();
    private boolean isFinished = false;
    private int activeWorkers = 0;
    
    public synchronized void registerWorker() {
        activeWorkers++;
    }
    
    public synchronized void unregisterWorker() {
        activeWorkers--;
        if (activeWorkers == 0) {
            notifyAll();
        }
    }
    
    public synchronized MyTask pop() {
        while (tasks.isEmpty()) {
            if (isFinished) {
                return null;
            }
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                return null;
            }
        }
        
        MyTask task = tasks.removeFirst();
        return task;
    }
    
    public synchronized void push(MyTask task) {
        tasks.addLast(task);
        notifyAll();
    }
    
    public synchronized void pushResult(MyTask task) {
        results.addLast(task);
        notifyAll();
    }
    
    public synchronized void finish() {
        isFinished = true;
        notifyAll();
    }
    
    public synchronized void showResults() {
        for (MyTask task : results) {
            System.out.print("Prime numbers in range [" + task.getStart() + ", " + task.getEnd() + "]: ");
            System.out.println(task.getAnswers());
        }
    }
}
