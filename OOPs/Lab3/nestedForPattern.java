public class nestedForPattern {
    public static void main(String[] args) {
        int k=1;
        final int n = 10;
        for(int i=1;k<=n;i++)
        {
            for(int j = 0;j<i&&k<=n;j++,k++)
            {
                System.out.print(k + "\t");
            }
            System.out.println("");
        }
    }
}
