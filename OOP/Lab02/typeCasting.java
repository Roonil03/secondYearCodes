import java.util.*;

public class typeCasting
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        double d = sc.nextDouble();
        char ch = sc.next().charAt(0);
        System.out.println("\n");
        System.out.println((byte)num);
        System.out.println((int)ch);
        System.out.println((byte)d);
        System.out.println((int)d);
        sc.close();
    }
}