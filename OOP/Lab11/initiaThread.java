import java.util.*;

class ThreadType1 extends Thread{
    public void run()
    {
        System.out.println("Thread by inheriting Thread Class");
    }
}
class ThreadType2 implements Runnable{
    public void run(){
        System.out.println("Thread implementing Runnable");
    }
    // public ThreadType2(){
        
    // }
}
public class initiaThread{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice = 0;
        do{
            System.out.println("Menu:");
            System.out.println("1. Create thread using Runnable");
            System.out.println("2. Create thread by extending Thread class");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    Thread runnableThread = new Thread(new ThreadType2());
                    runnableThread.start();
                    break;
                case 2:
                    ThreadType1 threadClassThread = new ThreadType1();
                    threadClassThread.start();
                    break;
                case 3:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 3);
        sc.close();
    }
}