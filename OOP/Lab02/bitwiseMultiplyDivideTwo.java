public class bitwiseMultiplyDivideTwo
{
    public static void main(String[] args) {
        int num = Integer.parseInt(args[0]);
        System.out.println(num + " x 2 = " + (num<<1));
        System.out.println(num + " / 2 = " + (num>>1));
    }
}