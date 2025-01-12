public class areaPerimetreArgument
{
public static void main(String args[])
{
int a = Integer.parseInt(args[0]);
int b = Integer.parseInt(args[1]);
int area = a*b;
int peri = 2*(a+b);
System.out.println("Area: " + area + "\nPerimetre: " + peri);
}
}