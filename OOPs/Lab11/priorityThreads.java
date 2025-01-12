public class priorityThreads {
    public static void main(String[] args) {
        CountRunnable runnable1 = new CountRunnable("Thread 1");
        CountRunnable runnable2 = new CountRunnable("Thread 2");
        runnable1.getThread().setPriority(Thread.MIN_PRIORITY); 
        runnable2.getThread().setPriority(Thread.MAX_PRIORITY);
        try {
            Thread.sleep(2000); 
            runnable1.getThread().interrupt();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        try {
            runnable1.getThread().join();
            runnable2.getThread().join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Main thread finished.");
    }
}
class CountRunnable implements Runnable {
    private Thread thread;

    public CountRunnable(String name) {
        thread = new Thread(this, name);
        thread.setPriority(Thread.MIN_PRIORITY);
        thread.start();
    }
    public void run() {
        try {
            for (int i = 1; i <= 5; i++) {
                System.out.println(thread.getName() + ": " + i);
                Thread.sleep(1000); }
                }
                catch (InterruptedException e) {
                    System.out.println(thread.getName() + " was interrupted.");
                }
    }
    public Thread getThread() {
        return thread;
    }
}
