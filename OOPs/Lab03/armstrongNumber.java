import java.lang.*;

public class armstrongNumber
{
    public static void main(String[] args) {
        int count = (args[0]).length();
        int a = Integer.parseInt(args[0]);
        int temp=a,b=0;
        while(temp!=0)
        {
            b += Math.pow((temp%10),count);
            temp /= 10;
        }
        if(b==a)
        {
            System.out.println("The number is an Armstrong Number!");
        }
        else{
            System.out.println("The number is not an Armstrong Number...");
        }
    }
}