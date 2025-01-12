public class negArrays {
    public static void main(String[] args) {
        try{
            int [] m = new int[-1];
        }
        catch(NegativeArraySizeException e)
        {
            System.out.println("The array size is negative...");
        }
        //finally
    }
}
