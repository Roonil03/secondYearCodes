import java.util.*;

public class symmetricMatrixChecker
{
    public static void main(String[] args) {
        System.out.println("Enter rows of matrix: ");
        Scanner sc = new Scanner(System.in);
        int rows = sc.nextInt();
        System.out.println("Enter columns of matrix: ");
        int col = sc.nextInt();
        int mat[][] = new int[rows][col];
        int i,j;
        System.out.println("Enter the elements of the matrix: ");
        for(i=0;i<rows;i++)
        {
            for(j=0;j<col;j++)
            {
                mat[i][j] = sc.nextInt();
            }
        }
        for(i=0;i<rows;i++)
        {
            for(j=0;j<col;j++)
            {
                if(mat[i][j] != mat[j][i])
                {
                    System.out.println("The matrix is not symmetric!");
                    return;
                }
            }
        }
        System.out.println("The matrix is symmetric!");
        sc.close();
    }
}