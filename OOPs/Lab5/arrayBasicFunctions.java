import java.util.*;
public class arrayBasicFunctions {
    public static void main(String[] args) {
        Arrays ar1 = new Arrays();
        ar1.input();
        ar1.displayVals();
        ar1.displayMax();
        ar1.displayAvg();
        ar1.sortAscending();
    }
}
class Arrays{
    int arr[] = new int[10];
    Scanner sc = new Scanner(System.in);
    void input()
    {
        System.out.println("Enter the elements: ");
        for(int i = 0; i<10;i++)
        {
            arr[i] = sc.nextInt();
        }
    }
    void displayVals()
    {
        System.out.println("Values are: ");
        for(int i=0;i<10;i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println("");
    }
    void displayMax()
    {
        int M = arr[0];
        for(int i = 1; i<10;i++)
        {
            if(M<arr[i])
            {
                M = arr[i];
            }
        }
        System.out.println("Tha maximum value is: " +M);
    }
    void displayAvg()
    {
        int sum = 0; double avg;
        for(int i = 0; i<10;i++)
        {
            sum += arr[i];
        }
        avg = (double)(sum/10);
        System.out.println("The average value is: " + avg);
    }
    void sortAscending()
    {
        int min, i,j;
        for(i=0;i<10;i++)
        {
            min = i;
            for(j=i+1;j<10;j++)
            {
                if(arr[min] > arr[j])
                {
                    min = j;
                }
            }
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
            // arr[min] = arr[i] ^ arr[min];
            // arr[i] = arr[i] ^ arr[min];
            // arr[min] = arr[i] ^ arr[min];
        }
        System.out.println("Array Sorted!");
        displayVals();
    }
}
