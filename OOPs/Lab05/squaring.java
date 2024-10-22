//import java.util.*;
public class squaring {
    public static void main(String[] args) {
        System.out.println("Square of long 34: " +square(34L));
        System.out.println("Square of int 3 is: " + square(3));
        System.out.println("Square of double 0.5 is: " + square(.5));
        System.out.println("Square of float 0.02 is: " + square(0.02f));
    }
    static long square(long n)
    {
        return n*n;
    }
    static double square(double n)
    {
        return (double)(n*n);
    }
    static int square(int n)
    {
        return n*n;
    }
    static float square(float n)
    {
        return (float)(n*n);
    }
}
