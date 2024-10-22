public class autoboxingUnboxing {
    public static void main(String[] args) {
        // Autoboxing
        Integer i = 10;
        Double d = 20.5;
        Character c = 'A';
        Boolean b = true;
        Byte by = 127;
        Short s = 32767;
        Long l = 1000000000L;
        Float f = 3.14f;

        // Unboxing
        int x = i;
        double y = d;
        char z = c;
        boolean flag = b;
        byte b1 = by;
        short s1 = s;
        long l1 = l;
        float f1 = f;

        System.out.println("Autoboxing and Unboxing examples:");
        System.out.println("Integer: " + i + " -> " + x);
        System.out.println("Double: " + d + " -> " + y);
        System.out.println("Character: " + c + " -> " + z);
        System.out.println("Boolean: " + b + " -> " + flag);
        System.out.println("Byte: " + by + " -> " + b1);
        System.out.println("Short: " + s + " -> " + s1);
        System.out.println("Long: " + l + " -> " + l1);
        System.out.println("Float: " + f + " -> " + f1);
    }
}