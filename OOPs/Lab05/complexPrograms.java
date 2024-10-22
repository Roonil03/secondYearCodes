public class complexPrograms {
    public static void main(String[] args) {
        int n1 = 5;
        int n2[] = {3,4};int n3[] = {4,3};
        int case1[] = Complex.add(n1,n2);
        int case2[] = Complex.add(n2,n3);
        System.out.println(case1[0] + " + (" + case1[1] + "i)");
        System.out.println(case2[0] + " + (" + case2[1] + "i)");
    }
}
class Complex{
    static int[] add(int integer, int[] comp)
    {
        int num[] = new int[2];
        num[0] = integer + comp[0];
        num[1] = comp[1];
        return num;
    }
    static int[] add(int[] comp1, int[] comp2)
    {
        int num[] =  new int[2];
        num[0] = comp1[0] + comp2[0];
        num[1] = comp1[1] + comp2[1];
        return num;
    }
}