import java.util.*;
public class timeManipulation
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the time 1:");
        Time t1 = new Time(sc.nextInt(),sc.nextInt(),sc.nextInt());
        System.out.println("Enter the time 2:");
        Time t2 = new Time(sc.nextInt(),sc.nextInt(),sc.nextInt());
        t1.display();
        t2.display();
        Time add = addition(t1,t2);
        add.display();
        sc.close();
    }
    static Time addition(Time n1, Time n2)
    {
        Time add = new Time();
        add.seconds = (n1.seconds + n2.seconds)%60;
        add.mins = (n1.mins + n2.mins + (n1.seconds + n2.seconds)/60)%60;
        add.hours = (n1.hours + n2.hours + ((n1.mins + n2.mins + (n1.seconds + n2.seconds)/60)/60));
        // System.out.println("\n\nThe time is:");
        // System.out.printf("%02d:%02d:%02d",add.hours, add.mins,add.seconds);
        return add;
    }
}
class Time{
    int mins, hours, seconds;
    Time()
    {
        mins = 0;
        hours = 0;
        seconds = 0;
    }
    Time(int hours, int mins, int seconds){
        this.mins = mins;
        this.hours = hours;
        this.seconds = seconds;
    }
    void display()
    {
        System.out.printf("The time is:\n%02d:%02d:%02d\n\n",hours, mins,seconds);
    }
}