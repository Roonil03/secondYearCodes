import java.util.*;

public class areaPerimetreScanner
{
public static void main (String args[])
{
Scanner s = new Scanner(System.in);
int a = s.nextInt();
int b = s.nextInt();
int area = a*b;
int peri = 2*(a+b);
System.out.println("Area: " + area + "\nPerimetre: " + peri);
s.close();
}
}