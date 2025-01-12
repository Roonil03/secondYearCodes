import java.util.*;

public class nonPrincipleDiag {
    public static void main(String[] args) {
        System.out.println("Enter the dimension of square matrix: ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int mat[][] = new int[n][n];
        System.out.println("Enter the elements of the matrix");
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                mat[i][j] = sc.nextInt();
            }
        }
        int sum=0;
        System.out.println("\nThe non principal diagonal elements are: ");
        for(i=0;i<n;i++)
        {
            System.out.print(mat[i][n-i-1] + " ");
            sum += mat[i][n-i-1];
        }
        System.out.println("\nThe sum is: "+ sum);
        sc.close();
    }
}
