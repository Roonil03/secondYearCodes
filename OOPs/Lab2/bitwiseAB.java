public class bitwiseAB
{
    public static void main(String[] args) {
        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);
        System.out.println((a<<2) + (b>>2));
        System.out.println((b>0));
        System.out.println((a + b * 100)/10);
        System.out.println((a&b));
    }
}