import java.util.*;
interface Sales{
    double getSales3Months();
}
public class hardwareSoftware{
    public static void main(String[] args) {
        System.out.println("Enter the details for hardware:");
        Scanner sc = new Scanner(System.in);
        Hardware h1 = new Hardware(sc.nextLine(),sc.nextLine());
        System.out.println("The sales for three months is: " + h1.getSales3Months());
        System.out.println("Enter the details for software:");
        Software s1 = new Software(sc.nextLine(), sc.nextLine());
        System.out.println("The sales for the three months is: " + s1.getSales3Months());
        sc.close();
    }
}
class Hardware implements Sales{
    String category;
    String Manufacturer;
    public double getSales3Months(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the sales for past three months:");
        double raw = sc.nextDouble();
        sc.close();
        return raw;
    }
    Hardware(String category, String Manufacturer){
        this.Manufacturer = Manufacturer;
        this.category = category;
    }
}
class Software implements Sales{
    String OS;
    String typeOfSoftware;
    Software(String OS, String typeOfSoftware){
        this.OS = OS;
        this.typeOfSoftware = typeOfSoftware;
    }
    public double getSales3Months(){
        Scanner sc = new Scanner(System.in);
        System.out.println("How much did software sell?");
        double raw = sc.nextDouble() * 3;
        sc.close();
        return raw;
    }
}
