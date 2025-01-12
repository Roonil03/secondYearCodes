import java.util.*;
public class arraySize {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int [] s = new int[sc.nextInt()];
        try{
            System.out.println(s[s.length]);
        }
        catch(ArrayIndexOutOfBoundsException e)
        {
            System.out.println("The index " + s.length + " does not exist");
        }
        sc.close();
    }
}
