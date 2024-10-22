import java.util.*;
public class bankingInterest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the ROI for SBI bank");
        Bank b1 = new SBI();
        b1.getRateOfInterest(sc.nextDouble());
        System.out.println("Enter the ROI for ICICI Bank");
        Bank b2 = new ICICI();
        b2.getRateOfInterest(sc.nextDouble());
        System.out.println("Enter the ROI for AXIS Bank");
        Bank b3 = new AXIS();
        b3.getRateOfInterest(sc.nextDouble());
        Bank b4 = new Bank();
        System.out.println("Enter the ROI for default bank");
        b4.getRateOfInterest(sc.nextDouble());
        b1.display();
        b2.display();
        b3.display();
        b4.display();
        sc.close();
    }
}
class Bank{
    double ROI;
    Bank(){}
    void getRateOfInterest(double ROI){
        this.ROI = ROI;
    }
    void display()
    {
        System.out.println("ROI: " + ROI);
    }
}
class SBI extends Bank{
    void getRateOfInterest(double ROI){
        super.getRateOfInterest(ROI);
    }
}

class ICICI extends Bank{
    void getRateOfInterest(double ROI){
        super.getRateOfInterest(ROI);
    }
}
class AXIS extends Bank{
    void getRateOfInterest(double ROI){
        super.getRateOfInterest(ROI);
    }
}