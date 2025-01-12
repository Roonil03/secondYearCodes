public class swapingvalues {
    static void swap(int a, int b) {
        int temp = a;
        a = b;
        b = temp;
        System.out.println("Inside swap method: a = " + a + ", b = " + b);
    }
    public static void main(String[] args) {
        int x = 10;
        int y = 20;
        System.out.println("Computing pass by value: ");
        System.out.println("Before swap: x = " + x + ", y = " + y);
        swap(x, y);
        System.out.println("After swap: x = " + x + ", y = " + y);
        System.out.println("\nComputing pass by reference: ");
        Pair p = new Pair(10, 20);
        System.out.println("Before swap: a = " + p.a + ", b = " + p.b);
        swap(p);
        System.out.println("After swap: a = " + p.a + ", b = " + p.b);
    }
    static void swap(Pair pair) {
        int temp = pair.a;
        pair.a = pair.b;
        pair.b = temp;
        System.out.println("Inside swap method: a = " + pair.a + ", b = " + pair.b);
    }
}
class Pair {
    int a;
    int b;

    Pair(int a, int b) {
        this.a = a;
        this.b = b;
    }
}
