import java.util.*;
public class minMaxArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int min, max,i;
        int num[] = new int[Integer.parseInt(args[0])];
        System.out.println("Enter the elements:");
        min = max = num[0] = sc.nextInt();
        for(i=1;i<Integer.parseInt(args[0]);i++)
        {
            num[i] = sc.nextInt();
            if(min>num[i]){
                min = num[i];
            }
            if(max<num[i]){
                max = num[i];
            }
        }
        System.out.println("The min is: "+min +"\nThe max is: "+max);
        sc.close();
    }
}
