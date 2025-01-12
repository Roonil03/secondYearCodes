import java.util.*;
public class occuranceArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int mat[][] = new int[n][m];
        System.out.println("Enter the matrix:");
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                mat[i][j] = sc.nextInt();
            }
        }
        System.out.println("Enter data to find: ");
        int data = sc.nextInt();
        int count = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(mat[i][j] == data)
                {
                    System.out.println("mat[" + i + "][" + j + "]  ");
                    count++;
                }
            }
        }
        if(count==0)
        {
            System.out.println("It didn't appear!");
        }
        else{
            System.out.println("It appeared " + count + " times");
        }
        sc.close();
    }
}
