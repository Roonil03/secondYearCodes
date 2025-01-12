import java.util.*;
public class studentException {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try{
            String name = sc.nextLine();
            int rollNo = Integer.parseInt(sc.next());
            int[] marks = new int[3];
            for(int i = 0; i< marks.length;i++)
            {
                marks[i] = Integer.parseInt(sc.next());
            }
            System.out.println("Name: " + name);
            System.out.println("Roll No: " + rollNo);
            for(int i = 0;i<marks.length;i++)
            {
                System.out.println("Marks " + (i+1) + ": " + marks[i]);
            }
        }
        catch(NumberFormatException e)
        {
            System.out.println("The input was not a number, please try again later...");
        }
        sc.close();
    }
}
