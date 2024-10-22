import java.util.*;
public class arrayPrime
{
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int nums[] = new int[n];
        System.out.println("Enter the elements of the array:");
        Scanner s = new Scanner(System.in);        
        int i;
        for(i=0;i<n;i++)
        {
            nums[i] = s.nextInt();
        }
        for(i=0;i<n;i++)
        {
            if(isPrime(nums[i]))
            {
                System.out.print(nums[i] + " ");
            }
        }
        s.close();
    }
    static boolean isPrime(int x)
    {
        for(int i = 2; i<x/2;i++)
        {
            if(x % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}