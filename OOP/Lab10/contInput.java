import java.util.*;

public class contInput {
    public static void main(String[] args) {
        int sum = 0;
        Scanner sc = new Scanner(System.in);
        String a = "0";
        try {
            while (!a.equals("-1")) {
                if (Double.parseDouble(a) % 1 != 0) {
                    throw new InputException();
                }                
                sum += Integer.parseInt(a);
                a = sc.nextLine();
            }
        } catch (InputException e) {
            System.out.println(e.getMessage());
        } catch (NumberFormatException e) {
            System.out.println("Invalid input: Please enter a valid integer.");
        } finally {
            System.out.println("Total sum: " + sum);
            sc.close();
        }
    }
}

class InputException extends RuntimeException {
    public InputException() {
        super("Floating point detected.");
    }
}
