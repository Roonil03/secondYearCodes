import java.util.*;

public class palindromeArgument
{
public static void main(String args[])
{
	Scanner sc = new Scanner(System.in);
	int a = sc.nextInt();
	int temp = a, b = 0;
	while(temp>0)
	{		
		b *= 10;
		b = b + temp%10;
		temp /= 10;
	}
	if(a == b)
	{
		System.out.println("The number is palindrome");
	}
	else{
		System.out.println("Nope");
	}
	sc.close();
}
}