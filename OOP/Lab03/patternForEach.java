import java.lang.*;

public class patternForEach
{
    public static void main(String[] args) {
        //String nums = {"1","2","3","4","5"};
        int nums[] = {1,2,3,4,5};
        for(int i : nums)
        {
            
            for(int j = 0; j<i;j++)
            {
                System.out.print(i + " ");
            }
            System.out.println("");
        }
    }
}