import java.util.Scanner;
import java.lang.*;

public class sqrtCubeRootPrimeScanner
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        float b = sc.nextFloat();
        double sqrt = Math.sqrt(b);
        double cbrt = Math.cbrt(b);
        System.out.println("The Square root is: " + sqrt + "\nThe Cube root is: " + cbrt);
        int temp = (int)b;
        for(int i = 2; i<temp/2; i++)
        {
            if(temp%i == 0)
            {
                System.out.println("Number is not a prime");
                System.exit(0);
            }
        }
        System.out.println("Number is a prime");
        sc.close();
    }
}