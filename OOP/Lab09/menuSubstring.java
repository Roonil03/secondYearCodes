import java.util.Scanner;

public class menuSubstring {
    public static String compareStrings(String str1, String str2) {
        return str1.equals(str2) ? "Strings are equal." : "Strings are not equal.";
    }
    public static String convertCase(String str) {
        StringBuilder converted = new StringBuilder();
        for (char ch : str.toCharArray()) {
            if (Character.isUpperCase(ch)) {
                converted.append(Character.toLowerCase(ch));
            } else {
                converted.append(Character.toUpperCase(ch));
            }
        }
        return converted.toString();
    }
    public static boolean isSubstring(String str1, String str2) {
        return str2.contains(str1);
    }
    public static String replaceSubstring(String str1, String str2) {
        if (isSubstring(str1, str2)) {
            return str2.replace(str1, "Hello");
        } else {
            return str2;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Compare two strings");
            System.out.println("2. Convert case of a string");
            System.out.println("3. Check if one string is a substring of another");
            System.out.println("4. Replace substring with 'Hello'");
            System.out.println("5. Exit");
            //System.out.print("Enter your choice (1-5): ");
            int choice = scanner.nextInt();
            scanner.nextLine();
            switch (choice) {
                case 1:
                    System.out.print("Enter the first string: ");
                    String str1 = scanner.nextLine();
                    System.out.print("Enter the second string: ");
                    String str2 = scanner.nextLine();
                    System.out.println(compareStrings(str1, str2));
                    break;
                case 2:
                    System.out.print("Enter a string: ");
                    String strToConvert = scanner.nextLine();
                    System.out.println("Converted string: " + convertCase(strToConvert));
                    break;
                case 3:
                    System.out.print("Enter the first string: ");
                    String substring = scanner.nextLine();
                    System.out.print("Enter the second string: ");
                    String mainString = scanner.nextLine();
                    if (isSubstring(substring, mainString)) {
                        System.out.println("\"" + substring + "\" is a substring of \"" + mainString + "\".");
                    } else {
                        System.out.println("\"" + substring + "\" is not a substring of \"" + mainString + "\".");
                    }
                    break;
                case 4:
                    System.out.print("Enter the substring: ");
                    String subStr = scanner.nextLine();
                    System.out.print("Enter the main string: ");
                    String mainStr = scanner.nextLine();
                    String result = replaceSubstring(subStr, mainStr);
                    System.out.println("Modified string: " + result);
                    break;
                case 5:
                    System.out.println("Exiting the program.");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}

