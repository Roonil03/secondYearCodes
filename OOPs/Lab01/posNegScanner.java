import java.util.*;

public class posNegScanner
{
public static void main(String args[])
{
	Scanner sc = new Scanner(System.in);
	int pos = 0, neg = 0, zero = 0;
	for(int i = 0; i<10;i++)
	{
int a = sc.nextInt();
if(a>0)
	pos++;
else if(a<0)
	neg++;
else
	zero++;
}
System.out.println("The number of positives is: " + pos);
System.out.println("The number of negatives is: " + neg);
System.out.println("The number of zeros is: " + zero);
sc.close();
}
}