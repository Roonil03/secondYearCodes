public class TablesArguments
{
public static void main(String args[])
{
int num = Integer.parseInt(args[0]);
for(int i = 1;i<11;i++)
		{
			System.out.println(num + "\tx\t" + i + "\t=\t" + (num*i));
		}
}
}