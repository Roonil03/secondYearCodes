import java.util.*;
public class counter{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your string:");
        String str = sc.nextLine();
        int chars = 0, words = 1, lines = 1, vowels = 0;
        for(int i = 0; i<str.length();i++){
            chars++;
            switch(str.charAt(i)){
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                vowels++;
                break;
                case '\n':
                lines++;
                break;
                case ' ':
                words++;
                break;
            }
        }
        System.out.println("The number of:");;
        System.out.println("Characters: " + chars);
        System.out.println("Words: " + words);
        System.out.println("Lines: " + lines);
        System.out.println("Vowels: " + vowels);
        sc.close();
    }
}