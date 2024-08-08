import java.util.*;

public class FactScanner
{
public static void main(String args[])
{
Scanner sc = new Scanner(System.in);
int num = sc.nextInt();
long fact = 1;
	while(num!=0)
	{
		fact *= num;
		num--;
	}
	System.out.println("The factorial is: " + fact);
	sc.close();
}
}