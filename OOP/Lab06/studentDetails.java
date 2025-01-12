import java.util.*;
public class studentDetails {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ugCount = 0, pgCount = 0;
        System.out.println("Enter the total number of students");
        Student s[] = new Student[sc.nextInt()];        
        int ugIndex[] = new int[s.length];
        int pgIndex[] = new int[s.length];
        for(int i = 0; i<s.length;i++){
            System.out.println("\n1. UG Student");
            System.out.println("2. PG Student");
            String name;
            int regNo, age, fees;
            byte semester;
            byte choice = sc.nextByte();
            sc.nextLine();
            System.out.println("Enter the name of the student");
            name = sc.nextLine();
            System.out.println("Enter the age of the student");
            age = sc.nextInt();
            System.out.println("Enter the registration number of student");
            regNo = sc.nextInt();
            System.out.println("Enter the fees");
            fees = sc.nextInt();
            System.out.println("Enter the semester number");
            semester = sc.nextByte();
            switch(choice){
                case 1:
                    ugIndex[ugCount++] = i;
                    // System.out.println("Enter the name of the student");
                    // name = sc.nextLine();
                    // System.out.println("Enter the age of the student");
                    // age = sc.nextInt();
                    // System.out.println("Enter the registration number of student");
                    // regNo = sc.nextInt();
                    // System.out.println("Enter the fees");
                    // fees = sc.nextInt();
                    // System.out.println("Enter the semester number");
                    // semester = sc.nextByte();
                    s[i] = new UG(regNo, age, fees, semester, name);
                    break;
                case 2:
                    pgIndex[pgCount++] = i;
                    s[i] = new PG(fees, semester, regNo, age, name);
                    break;
                default:
                    System.out.println("Incorrect choice retry...");
                    i--;
                    break;
            }
        }
        System.out.println("\nUG Students:");
        if(ugCount == 0){
            System.out.println("There are no UG students");
        }
        else{
            for(int i = 0; i<ugCount;i++){
                s[ugIndex[i]].display();
            }
        }
        System.out.println("\nPG Students:");
        if(pgCount==0){
            System.out.println("There are no PG students");
        }
        else{
            for(int i = 0;i<pgCount;i++){
                s[pgIndex[i]].display();
            }
        }
        sc.close();
    }
}
class Student{
    int regNo;
    String name;
    int age;
    Student(){
    }
    Student(int regNo, String name, int age){
        this.regNo = regNo;
        this.name = name;
        this.age  = age;
    }
    void display(){
        System.out.println("Name: " + name);
        System.out.println("Registration Number: " + regNo);
        System.out.println("Age: " + age);
    }
}
class UG extends Student{
    int fees;
    byte semester;
    UG(){
    }
    UG(int regNo, int age, int fees, byte semester,String name){
        super(regNo, name, age);
        this.fees = fees;
        this.semester = semester;
    }
    void display(){
        super.display();
        System.out.println("Semester: " + semester);
        System.out.println("Fees: " + fees);
        System.out.println("Program: UG\n");
    }
}
class PG extends Student{
    int fees;
    byte semester;
    PG(){
    }
    PG(int fees, byte semester, int regNo, int age, String name){
        super(regNo, name, age);
        this.fees = fees;
        this.semester = semester;
    }
    void display(){
        super.display();
        System.out.println("Fees: " + fees);
        System.out.println("Semester: " + semester);
        System.out.println("Program: PG\n");
    }
}
