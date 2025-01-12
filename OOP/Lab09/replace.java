import java.util.*;
public class replace {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the string:");
        String str = sc.nextLine();
        System.out.println("Enter the word:");
        String word = sc.nextLine();
        System.out.println("Enter the character to replace: ");
        char ch = sc.next().charAt(0);
        String newStr = "";
        for(int i = 0; i<str.length();i++){
            if(ch == str.charAt(i)){
                newStr += word;
            }
            else{
                newStr += Character.toString(str.charAt(i));
            }
        }
        System.out.println("The new word is: " + newStr);
        sc.close();
    }
}
