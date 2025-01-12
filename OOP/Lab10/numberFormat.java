import java.util.*;
public class numberFormat{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.nextLine();
        int b = 0;
        try{
            b = Integer.parseInt(a);
        }
        catch(NumberFormatException e)
        {
            System.out.println("Value of b hasn't changed due to string containing non-numeric characters");
        }
        System.out.println(b);
        sc.close();
    }
}
