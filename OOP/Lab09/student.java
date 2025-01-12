public class student {
    
}

/*
import java.util.Scanner;

class Student {
    private String registrationNumber;
    private String firstName;
    private String lastName;
    private String degree;

    public Student(String registrationNumber, String firstName, String lastName, String degree) {
        this.registrationNumber = registrationNumber;
        this.firstName = firstName;
        this.lastName = lastName;
        this.degree = degree;
    }

    public String getRegistrationNumber() {
        return registrationNumber;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public String getDegree() {
        return degree;
    }

    @Override
    public String toString() {
        return "Registration Number: " + registrationNumber +
               ", Name: " + firstName + " " + lastName +
               ", Degree: " + degree;
    }
}

public class StudentSearch {
    private static Student[] students = new Student[10];

    public static void main(String[] args) {
        initializeStudents();

        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the first name or last name of the student to search:");
        String searchQuery = scanner.nextLine();

        searchStudent(searchQuery);
    }

    private static void initializeStudents() {
        students[0] = new Student("REG001", "John", "Doe", "Computer Science");
        students[1] = new Student("REG002", "Jane", "Smith", "Mathematics");
        students[2] = new Student("REG003", "Emily", "Jones", "Physics");
        students[3] = new Student("REG004", "Michael", "Brown", "Chemistry");
        students[4] = new Student("REG005", "Sarah", "Davis", "Biology");
        students[5] = new Student("REG006", "David", "Wilson", "History");
        students[6] = new Student("REG007", "Linda", "Taylor", "Literature");
        students[7] = new Student("REG008", "James", "Anderson", "Engineering");
        students[8] = new Student("REG009", "Jessica", "Thomas", "Economics");
        students[9] = new Student("REG010", "Daniel", "Jackson", "Art");
    }

    private static void searchStudent(String query) {
        boolean found = false;
        for (Student student : students) {
            if (student.getFirstName().equalsIgnoreCase(query) ||
                student.getLastName().equalsIgnoreCase(query)) {
                System.out.println("Student found: " + student);
                found = true;
            }
        }
        if (!found) {
            System.out.println("No student found with the name: " + query);
        }
    }
}

 */