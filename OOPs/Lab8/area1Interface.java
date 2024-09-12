import java.util.*;
public class area1Interface {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the length, breadth and radius");
        Area a1 = new Rectangle(sc.nextDouble(), sc.nextDouble());
        Area a2 = new Circle(sc.nextDouble());
        System.out.println("Area of Rectangle is: " + a1.calcArea());
        System.out.println("Area of Circle is: " + a2.calcArea());
        sc.close();
       } 
}
interface Area{
    double calcArea();
}
class Rectangle implements Area{
    double length;
    double breadth;
    Rectangle(double length, double breadth){
        this.length = length;
        this.breadth = breadth;
    }
    public double calcArea(){
        return length*breadth;
    }
}
class Circle implements Area{
    double radius;
    Circle(double radius){
        this.radius = radius;
    }
    public double calcArea(){
        return 3.141592*radius;
    }
}
