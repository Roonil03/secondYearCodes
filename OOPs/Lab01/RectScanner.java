import java.util.*;

public class RectScanner
{
public static void main(String args[])
{
Scanner sc = new Scanner(System.in);
int a = sc.nextInt();
int b = sc.nextInt();
long area = a*b;
System.out.println("The Area is: " + area);
sc.close();
}
}