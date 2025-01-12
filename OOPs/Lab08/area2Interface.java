import java.util.*;
public class area2Interface {
    public static void main(String[] args) {
        System.out.println("Enter the side, base and height of the shapes");
        Scanner sc = new Scanner(System.in);
        Area a1 = new Square(sc.nextDouble());
        Area a2 = new Triangle(sc.nextDouble(), sc.nextDouble());
        System.out.println("Area of square is: " + a1.calc());
        System.out.println("Area of Triangle is: " + a2.calc());
        sc.close();
    }
}
interface Area{
    abstract double calc();
}
class Square implements Area{
    double s;
    Square(double s){
        this.s = s;
    }
    public double calc(){
        return s*s;
    }
}
class Triangle implements Area{
    double base;
    double height;
    Triangle(double base, double height){
        this.base = base;
        this.height = height;
    }
    public double calc(){
        return 0.5*base*height;
    }
}
