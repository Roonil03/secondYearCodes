import java.util.*;

public class addMultiMatrix {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.println("1. Add matrix");
        System.out.println("2. Multiple matrix");
        int choice = sc.nextInt();
        switch(choice)
        {
            case 1:
            add();
            break;
            case 2:
            multiply();
            break;
            default:
            System.exit(0);

        }
    }
    static void add(){
        System.out.println("Enter the dimensions of first matrix: ");
        int r1 = sc.nextInt();
        int c1 = sc.nextInt();
        System.out.println("Enter the dimensions of second matrix: ");
        int r2 = sc.nextInt();
        int c2 = sc.nextInt();
        if(!(r1==r2 && c1 == c2))
        {
            System.out.println("The matrix dimensions incorrect for computation!");
            return;    
        }
        int A[][] = new int[r1][c1];
        int B[][] = new int[r2][c2];
        int sum[][] = new int[r2][c1];
        System.out.println("Enter the elements of Matrix A:");
        int i,j;
        for(i=0;i<r1;i++)
        {
            for(j = 0;j<c1;j++)
            {
                A[i][j] = sc.nextInt();
            }
        }
        System.out.println("Enter the elements of Matrix B:");
        for(i=0;i<r2;i++)
        {
            for(j=0;j<c2;j++)
            {
                B[i][j] = sc.nextInt();
                sum[i][j] = A[i][j] + B[i][j];
            }
        }
        System.out.println("\n\nThe sum is:");
        for(i=0;i<r2;i++)
        {
            for(j=0;j<c2;j++)
            {
                System.out.print(sum[i][j]);
            }
            System.out.println("");
        }
    }
    static void multiply()
    {
        System.out.println("Enter the dimensions of first matrix: ");
        int r1 = sc.nextInt();
        int c1 = sc.nextInt();
        System.out.println("Enter the dimensions of second matrix: ");
        int r2 = sc.nextInt();
        int c2 = sc.nextInt();
        if(!(c1==r2))
        {
            System.out.println("The matrix dimensions incorrect for computation!");
            return;    
        }
        int A[][] = new int[r1][c1];
        int B[][] = new int[r2][c2];
        int pro[][] = new int[r1][c2];
        System.out.println("Enter the elements of Matrix A:");
        int i,j;
        for(i=0;i<r1;i++)
        {
            for(j = 0;j<c1;j++)
            {
                A[i][j] = sc.nextInt();
            }
        }
        System.out.println("Enter the elements of Matrix B:");
        for(i=0;i<r2;i++)
        {
            for(j=0;j<c2;j++)
            {
                B[i][j] = sc.nextInt();
            }
        }
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                for(int k = 0;k<c1;k++)
                {
                    pro[i][j] += A[i][k]*B[k][j];
                }
            }
        }
        for(i=0;i<r2;i++)
        {
            for(j=0;j<c2;j++)
            {
                System.out.print(pro[i][j]);
            }
            System.out.println("");
        }
    }
    //sc.close();
}
