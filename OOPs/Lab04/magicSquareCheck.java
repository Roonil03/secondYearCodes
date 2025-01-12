import java.util.*;

public class magicSquareCheck {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=3;
        int mat[][] = new int[n][n];
        System.out.println("Enter the elements of the matrix: ");
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                mat[i][j] = sc.nextInt();
            }
        }
        int sum = 0;
        for(i=0;i<n;i++)
        {
            sum += mat[0][i];
        }
        int r,c;
        for(i=0;i<n;i++)
        {
            r = 0;
            c = 0;
            for(j=0;j<n;j++)
            {
                r += mat[i][j];
                c += mat[j][i];
            }
            if(c != sum || r != sum)
            {
                System.out.println("It is not a magic square");
                System.exit(0);
            }
        }
        r=0;c=0;
        for(i=0;i<n;i++)
        {
            r += mat[i][i];
            c += mat[i][n-i-1];
        }
        if(c != sum || r != sum)
            {
                System.out.println("It is not a magic square");
                System.exit(0);
            }
            System.out.println("It is a magic square!");
        sc.close();
    }
}
