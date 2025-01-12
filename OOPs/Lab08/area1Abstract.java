import java.util.*;
public class area1Abstract {
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
abstract class Area{
    abstract double calcArea();
}
class Rectangle extends Area{
    double length;
    double breadth;
    Rectangle(double length, double breadth){
        this.length = length;
        this.breadth = breadth;
    }
    double calcArea(){
        return length*breadth;
    }
}
class Circle extends Area{
    double radius;
    Circle(double radius){
        this.radius = radius;
    }
    double calcArea(){
        return 3.141592*radius;
    }
}
