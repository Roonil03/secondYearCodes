import java.util.*;

public class fourFunctionCalcualtor
{
    public static void main(String[] args) {
        double a, b, ans=0;
        char ch = 'y';
        Scanner sc = new Scanner(System.in);
        do{
            System.out.println("Enter first number, operator and second number: ");
            a = sc.nextDouble();
            ch = sc.next().charAt(0);
            // if(ch != '/' || ch != '*' || ch != '+'||ch != '-'){
            //      break;
            // }
            b = sc.nextDouble();
            switch(ch)
            {
                case '+':
                ans = a + b;
                break;
                case '-':
                ans = a-b;
                break;
                case '*':
                ans = a*b;
                break;
                case '/':
                ans = a/b;
                break;
            }
            System.out.println("Answer = " + ans);
            System.out.println("Do another (y/n)? ");
            ch = sc.next().charAt(0);
        }while(ch == 'y');
        sc.close();
    }
}