public class FactArgument
{
	public static void main(String args[])
{
	int num = Integer.parseInt(args[0]);
	long fact = 1;
	while(num!=0)
	{
		fact *= num;
		num--;
	}
	System.out.println("The factorial is: " + fact);
}
}