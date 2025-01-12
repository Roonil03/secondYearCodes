import java.util.*;
import java.lang.*;

public class taylorSeries {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        double sin = sin(x,n);
        double sum = sum(x);
        System.out.println( "Sin: "+ sin + "\nSum: " + sum);
        sc.close();
    }
    static double sin(int x, int n)
    {
        double sin = 0;
        int i = 1;
        for(int j = 1; j<=n;j++,i += 2)
        {
            int p = ((i+1)/2)-1;
            sin += Math.pow(-1,p) * Math.pow(x,i) / fact(i);
        }
        return sin;
    }
    static double fact(int x)
    {
        double n = 1;
        while(x != 0)
        {
            n *= x;
            x--;
        }
        return n;
    }
    static double sum(int x)
    {
        double sum=0;
        while(x!=0)
        {
            sum += x * 1 / x;
            x--;
        }
        return sum;
    }
}
