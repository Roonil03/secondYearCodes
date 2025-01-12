import java.util.*;

class SharedCounter {
    private int count = 0;

    public synchronized void incrementSynchronizedMethod() {
        count++;
        System.out.println("Count (Synchronized Method): " + count);
    }

    public void incrementSynchronizedStatement() {
        synchronized (this) {
            count++;
            System.out.println("Count (Synchronized Statement): " + count);
        }
    }
}

class CounterThread extends Thread {
    private SharedCounter sharedCounter;
    private boolean useSynchronizedMethod;

    public CounterThread(SharedCounter sharedCounter, boolean useSynchronizedMethod) {
        this.sharedCounter = sharedCounter;
        this.useSynchronizedMethod = useSynchronizedMethod;
    }

    public void run() {
        for (int i = 0; i < 5; i++) {
            if (useSynchronizedMethod) {
                sharedCounter.incrementSynchronizedMethod();
            } else {
                sharedCounter.incrementSynchronizedStatement();
            }
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}

public class syncThreads {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        SharedCounter sharedCounter = new SharedCounter();

        System.out.println("Select synchronization method:");
        System.out.println("1. Synchronized Method");
        System.out.println("2. Synchronized Statement");
        System.out.print("Enter your choice: ");
        int choice = scanner.nextInt();

        CounterThread thread1 = new CounterThread(sharedCounter, choice == 1);
        CounterThread thread2 = new CounterThread(sharedCounter, choice == 1);

        thread1.start();
        thread2.start();

        try {
            thread1.join();
            thread2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Main thread finished.");
        scanner.close();
    }
}
