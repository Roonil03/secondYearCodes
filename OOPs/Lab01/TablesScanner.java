import java.util.*;

public class TablesScanner
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		for(int i = 1;i<11;i++)
		{
			System.out.println(num + " x " + i + " = " + (num*i));
		}
		sc.close();
	}
}