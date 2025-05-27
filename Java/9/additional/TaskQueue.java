import java.util.LinkedList;
import java.util.List;
import java.util.Collections;

public class TaskQueue {
    private final LinkedList<MyTask> tasks = new LinkedList<>();
    private final LinkedList<MyTask> results = new LinkedList<>();
    private boolean isFinished = false;

    public synchronized MyTask pop() {
        while (tasks.isEmpty()) {
            if (isFinished) return null;
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                return null;
            }
        }
        return tasks.removeFirst();
    }

    public synchronized void push(MyTask task) {
        tasks.addLast(task);
        notifyAll();
    }

    public synchronized void pushResult(MyTask task) {
        results.addLast(task);
    }

    public synchronized void finish() {
        isFinished = true;
        notifyAll();
    }

    public synchronized void showResults() {
        for (MyTask task : results) {
            System.out.printf("Prime numbers in range [%d, %d]: %s%n",
                    task.getStart(), task.getEnd(), task.getAnswers());
        }
    }
}
