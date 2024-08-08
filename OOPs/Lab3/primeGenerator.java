public class primeGenerator
{
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int m = Integer.parseInt(args[1]);
        for(;n<=m;n++)
        {
            if(isPrime(n))
            {
                System.out.println(n);
            }
        }
    }
    static boolean isPrime(int n)
    {
        boolean prime = true;
        int i;
        for(i=2;i<=n/2;i++)
        {
            if(n%i==0)
            {
                prime = false;
                return prime;
            }
        }
        return prime;
    }
}