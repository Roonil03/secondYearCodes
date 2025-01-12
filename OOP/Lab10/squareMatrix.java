import java.util.*;
public class squareMatrix {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int rows = sc.nextInt();
        int col = sc.nextInt();
        try{
            test(rows,col);
        }
        catch(MatrixException e)
        {
            System.out.println(e);
        }
        sc.close();
    }
    static void test(int rows, int col) throws MatrixException{
        if(rows != col)
        {
            throw new MatrixException();
        }
    }
}
class MatrixException extends Exception{
    MatrixException()
    {
        super("The rows and columns don't match");
    }
}