public class posNegArgument
{
public static void main(String args[])
{
int pos = 0, neg = 0, zero = 0;
for(int i = 0; i<10;i++)
{
int a = Integer.parseInt(args[i]);
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
}
}