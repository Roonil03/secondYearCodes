import java.util.Scanner;

public class telephone {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a phone number in the format (555) 555 5555: ");
        String phoneNumber = scanner.nextLine();
        String areaCode = phoneNumber.substring(1, 4); 
        String firstThreeDigits = phoneNumber.substring(6, 9);
        String lastFourDigits = phoneNumber.substring(10, 14);
        System.out.println("Area Code: " + areaCode);
        System.out.println("Phone Number: " + firstThreeDigits /*+ "-" */+ lastFourDigits);
        scanner.close();
    }
}

