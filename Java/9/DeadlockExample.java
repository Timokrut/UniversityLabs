public class DeadlockExample {
    private static final Object lock1 = new Object();
    private static final Object lock2 = new Object();

    public static void main(String[] args) {
        Thread thread1 = new Thread(() -> {
            synchronized (lock1) {
                System.out.println("Thread 1: holds lock1");
                
                try {
                    Thread.sleep(1000); 
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                
                System.out.println("Thread 1: waits lock2");
                synchronized (lock2) {
                    System.out.println("Thread 1: holds lock1 and lock2");
                }
            }
        });

        Thread thread2 = new Thread(() -> {
            synchronized (lock2) {
                System.out.println("Thread 2: holds lock2");
                
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                
                System.out.println("Thread 2: waits lock1");
                synchronized (lock1) {
                    System.out.println("Thread 2: holds lock2 and lock1");
                }
            }
        });

        thread1.start();
        thread2.start();
    }
}
