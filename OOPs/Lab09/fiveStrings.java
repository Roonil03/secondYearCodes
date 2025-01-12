import java.util.Scanner;

public class fiveStrings {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1,s2,s3,s4,s5;
        System.out.println("Enter the five strings:");
        s1 = sc.nextLine();
        s2 = sc.nextLine();
        s3 = sc.nextLine();
        s4 = sc.nextLine();
        s5 = sc.nextLine();
        String newStr = s1+s2+s3+s4+s5;
        System.out.println("The new string is: " +newStr);
        sc.close();

    }
}
