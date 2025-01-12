import java.util.*;
//import java.lang.*;
public class negRoot {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        try{
            test(num);
            System.out.println(-((Math.sqrt(num))));
        }
        catch(NegativeNumberException e)
        {
            System.out.println(e);
        }        
        sc.close();
    }
    static void test(int num) throws NegativeNumberException{
        if(num<0)
        {
            throw new NegativeNumberException();
        }
    }
}
class NegativeNumberException extends Exception{
    public NegativeNumberException(){
        super("The input number is negative...");
    }
}
