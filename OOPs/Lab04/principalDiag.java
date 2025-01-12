import java.util.*;
public class principalDiag {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the dimensions of square matrix: ");
        int n = sc.nextInt();
        int mat[][] = new int[n][n];
        int i, j;
        System.out.println("Enter the elements of the array: ");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                mat[i][j] = sc.nextInt();
            }
        }
        int sum = 0;
        System.out.println("\n\nThe principal diagonal elements are: ");
        for(i=0;i<n;i++)
        {
            System.out.print(mat[i][i] + " ");
            sum += mat[i][i];
        }
        System.out.println("\nThe sum is: " + sum);
        sc.close();
    }
}
