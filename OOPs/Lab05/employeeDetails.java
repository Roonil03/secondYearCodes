import java.util.*;
public class employeeDetails {
    public static void main(String[] args) {
        Employee v1 = new Employee();
        getData(v1);
        calculate(v1);
        display(v1);
    }
    static void getData(Employee v1)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the employee name: ");
        v1.employeeName = sc.nextLine();
        System.out.println("Enter the city: ");
        v1.city = sc.nextLine();
        System.out.println("Enter the basic salary");
        v1.basicSalary = sc.nextInt();
        System.out.println("Enter the dearness allowance");
        v1.dearnessAllowance = sc.nextDouble();
        System.out.println("Enter the house rent:");
        v1.houseRent = sc.nextDouble();
        sc.close();
    }
    static void calculate(Employee temp)
    {
        temp.total = temp.basicSalary + temp.basicSalary*temp.dearnessAllowance/100 + temp.basicSalary*temp.houseRent/100;
    }
    static void display(Employee temp)
    {
        System.out.println("/nThe total is: " + temp.total);
    }
}
class Employee{
    String employeeName;
    String city;
    int basicSalary;
    double dearnessAllowance;
    double houseRent;
    double total;
}
