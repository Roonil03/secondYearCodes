import java.util.Scanner;

public class threeLetters {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.nextLine();
        // /* 
        if(s1.length()!=5){
            System.exit(0);
        }
        // */
        //int count  = 0;
        three(s1);
        sc.close();
    }
    static void three(String str)
    {
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            for (int j = 0; j < str.length(); j++) {
                for (int k = 0; k < str.length(); k++) {
                    if (i != j && j != k && i != k) {
                        String combination = "" + str.charAt(i) + str.charAt(j) + str.charAt(k);
                        System.out.println(combination);
                        count++;
                    }
                }
            }
        }
        System.out.println("Number of unique combinations: " + count);
    }
    // static boolean check(char[] n, char ch, int num)
    // {
    //     for(int i = 0; i<num; i++){
    //         if(n[i] == ch){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
}
