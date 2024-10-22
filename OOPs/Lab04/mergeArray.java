import java.util.*;

public class mergeArray {
    public static void main(String[] args) {
        // Define the two arrays
        int[] array1 = {3, 1, 4, 1, 5};
        int[] array2 = {9, 2, 6, 5, 3};

        int[] mergedArray = new int[array1.length + array2.length];

        for (int i = 0; i < array1.length; i++) {
            mergedArray[i] = array1[i];
        }

        for (int i = 0; i < array2.length; i++) {
            mergedArray[array1.length + i] = array2[i];
        }

        Arrays.sort(mergedArray);

        System.out.println("Merged and Sorted Array:");
        for (int element : mergedArray) {
            System.out.print(element + " ");
        }
    }
}
