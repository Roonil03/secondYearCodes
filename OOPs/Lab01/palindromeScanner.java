public class palindromeScanner
{
public static void main(String args[])
{
int a = Integer.parseInt(args[0]);
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
}
}
