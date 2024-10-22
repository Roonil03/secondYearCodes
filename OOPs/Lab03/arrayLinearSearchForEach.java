import java.util.*;
public class arrayLinearSearchForEach
{
    public static void main(String[] args) {
        Scanner sct = new Scanner(System.in);
        int i, n=1;
        System.out.println("Enter number of elements in the array: ");
        n = sct.nextInt();
        System.out.println("Enter array elements: ");
        int nums[] = new int[n];
        for(i=0;i<n;i++)
        {
            nums[i] = sct.nextInt();
        }
        System.out.println("Enter the element to search: ");
        int s = sct.nextInt();
        System.out.println("Value found at position: ");
        int count=0;
        boolean none = true;
        for(int k : nums)
        {
            if(k==s)
            {
                none = false;
                System.out.print("a[" + count + "], ");
            }
            count++;
        }
        sct.close();
        if(none)
        {
            System.out.println("none exist in this array");
        }
      
    }
}