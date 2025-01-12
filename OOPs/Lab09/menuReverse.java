import java.util.*;
public class menuReverse {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the string:");
        String str = sc.nextLine();
        System.out.println("1. Check for palindrome");
        System.out.println("2. Rewrite in alphabetical order");
        System.out.println("3. Reverse the string");
        System.out.println("4. Concatanate the original string and the reversed string");
        switch(sc.nextInt()){
            case 1:
            if(str.equals(reverse(str))){
                System.out.println("It is palindrome!");
            }
            else{
                System.out.println("It is not palindrome!");
            }
            break;
            case 2:
            char []n = str.toCharArray();
            Arrays.sort(n);
            str = "";
            for(int i = 0; i<n.length;i++)
            {
                str += Character.toString(n[i]);
            }
            System.out.println("The word sorted is: " + str);
            break;
            case 3:
            System.out.println("The reversed string is: " + reverse(str));
            break;
            case 4:
            str += reverse(str);
            System.out.println("The concananated string is: " + str);
            break;
            default:
            System.out.println("Error");
            break;
        }
        sc.close();
    }
    static String reverse(String str)
    {
        String rev = "";
        for(int i = str.length()-1;i>-1;i--)
        {
            rev += Character.toString(str.charAt(i));
        }
        return rev;
    }
}
