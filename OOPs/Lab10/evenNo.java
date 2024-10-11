public class evenNo {
    public static void main(String[] args) {
        int a = 3;
        int b = 2;
        try{
            if(a % 2 == 0)
            {
                throw new EvenNumberException();
            }
            else{
                System.out.println(a);
            }
            if(b % 2 == 0)
            {
                throw new EvenNumberException();
            }
            else{
                System.out.println(b);
            }
        }
        catch(EvenNumberException e)
        {
            System.out.println(e);
        }
    }
}
class EvenNumberException extends RuntimeException{
    public EvenNumberException(){
        super("The number is even.");
    }
}
