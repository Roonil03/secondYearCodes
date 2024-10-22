import java.util.Arrays;
import java.util.Scanner;

public class stringSort {
    public static void main(String[] args) {
        System.out.println("Enter the number of strings:");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String[] st = new String[n];
        for(int i = 0; i<n;i++)
        {
            System.out.println("Enter string " + (i+1) + ":");
            st[i] = sc.nextLine();
        }
        Arrays.sort(st);
        System.out.println("The sorted string is: ");
        for(int i = 0; i<n;i++)
        {
            System.out.println(st[i]);
        }
        sc.close();
    }
}
