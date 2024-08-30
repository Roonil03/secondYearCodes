import java.util.*;
public class studentresult {
    public static void main(String[] args) {
        Result ref = new Result();
        ref.store();
        ref.totaling();
        ref.highestMarks();
        ref.highestTotal();
    }
}
class Result{
    int marks[][] = new int[3][3];
    int total[] = new int[3];
    void totaling()
    {
        for(int i = 0; i< total.length; i++)
        {
            total[i] = 0;
            for(int j = 0; j<marks.length; j++)
            {
                total[i] += marks[i][j];
            }
        }
    }
    void store()
    {
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i<marks.length;i++)
        {
            System.out.println("Enter the marks for student " + (i+1) + ":");
            marks[i][0] = sc.nextInt();
            marks[i][1] = sc.nextInt();
            marks[i][2] = sc.nextInt();
        }
        sc.close();
        System.out.println("\n");
    }
    void highestMarks()
    {
        int h1=0,h2=0,h3=0,r1 = 0,r2 = 0, r3 = 0;
        for(int i = 0; i<marks.length;i++)
        {
            if(marks[i][0] > h1)
            {
                h1 = marks[i][0];
                r1 = i+1;
            }
            if(marks[i][1] > h2)
            {
                h2 = marks[i][1];
                r2 = i+1;
            }
            if(marks[i][2] > h3)
            {
                h3 = marks[i][2];
                r3 = i+1;
            }
        }
        System.out.println("Highest in subject 1 is:\nRoll number:" + r1 + "\nMarks: " + h1);
        System.out.println("Highest in subject 2 is:\nRoll number:" + r2 + "\nMarks: " + h2);
        System.out.println("Highest in subject 3 is:\nRoll number:" + r3 + "\nMarks: " + h3);
        System.out.println("\n");
    }
    void highestTotal()
    {
        int h1 = 0,r1 = 0;
        for(int i = 0; i<total.length;i++)
        {
            if(h1 < total[i])
            {
                h1 = total[i];
                r1 = i+1;
            }
        }
        System.out.println("The maximum total is obtained is\nRoll number: " + r1 + "\nMarks: " + h1);
        System.out.println("\n");
    }
}

