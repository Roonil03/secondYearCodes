import java.util.*;
public class volumeManipulation {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the width, height and depth of the box: ");
        Box v1 = new Box(sc.nextDouble(),sc.nextDouble(), sc.nextDouble());
        System.out.println("The volume is: " + v1.volume());
        sc.close();
    }
}

class Box{
    double width;
    double height;
    double depth;
    double volume()
    {
        return (width * height * depth);
    }
    Box()
    {
    }
    Box(double width, double height, double depth)
    {
        this.width = width;
        this.height = height;
        this.depth = depth;
    }
}