import java.util.*;
public class traceAndNorm {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = 3;
        int mat[][] = new int[n][n];
        int i,j;
        double trace = 0, norm = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                mat[i][j] = sc.nextInt();
                norm += Math.pow(mat[i][j],2);
            }
            trace += mat[i][i];
        }
        norm = Math.sqrt(norm);
        System.out.println("The Trace is=  "+trace + " and norm is = "+norm);
        sc.close();
    }
    
}
