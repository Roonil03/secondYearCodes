import java.util.*;

public class terenarySmallest
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int min = a<b?(a>c?c:a):(b>c?c:b);
        int max = a>b?(a>c?a:c):(b>c?b:c);
        System.out.println("Min = " + min);
        System.out.println("Max = " + max);
        sc.close();
    }  
}