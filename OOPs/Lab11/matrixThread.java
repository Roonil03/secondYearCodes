import java.util.*;

public class matrixThread {
    public static void main(String[] args) {
        Matrix matrix = new Matrix(4, 4);

        DisplayMatrixThread t1 = new DisplayMatrixThread(matrix);
        TransposeMatrixThread t2 = new TransposeMatrixThread(matrix);
        MaxValueThread t3 = new MaxValueThread(matrix);
        PrincipalDiagonalThread t4 = new PrincipalDiagonalThread(matrix);
        NonDiagonalElementsThread t5 = new NonDiagonalElementsThread(matrix);
        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();
        try {
            t1.join();
            t2.join();
            t3.join();
            t4.join();
            t5.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
class Matrix {
    private int[][] matrix;
    private int rows;
    private int cols;

    public Matrix(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        matrix = new int[rows][cols];
        populateMatrix();
    }

    // private void populateMatrix() {
    //     Random rand = new Random();
    //     for (int i = 0; i < rows; i++) {
    //         for (int j = 0; j < cols; j++) {
    //             matrix[i][j] = rand.nextInt(100); // Random values from 0 to 99
    //         }
    //     }
    // }

    private void populateMatrix()
    {
        Scanner h = new Scanner(System.in);
        for(int i = 0; i< rows;i++)
        {
            for(int j = 0; j< cols; j++)
            {
                matrix[i][j] = h.nextInt();
            }
        }
        h.close();
    }

    public int[][] getMatrix() {
        return matrix;
    }

    public int[][] getTranspose() {
        int[][] transpose = new int[cols][rows];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                transpose[j][i] = matrix[i][j];
            }
        }
        return transpose;
    }

    public int getMaxValue() {
        int max = matrix[0][0];
        for (int[] row : matrix) {
            for (int value : row) {
                if (value > max) {
                    max = value;
                }
            }
        }
        return max;
    }

    public int[] getPrincipalDiagonal() {
        int size = Math.min(rows, cols);
        int[] diagonal = new int[size];
        for (int i = 0; i < size; i++) {
            diagonal[i] = matrix[i][i];
        }
        return diagonal;
    }

    public int[] getNonDiagonalElements() {
        int size = rows * cols;
        int[] nonDiagonal = new int[size - Math.min(rows, cols)];
        int index = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i != j) {
                    nonDiagonal[index++] = matrix[i][j];
                }
            }
        }
        return nonDiagonal;
    }
}

class DisplayMatrixThread extends Thread {
    private Matrix matrix;

    public DisplayMatrixThread(Matrix matrix) {
        this.matrix = matrix;
    }

    public void run() {
        System.out.println("Matrix:");
        for (int[] row : matrix.getMatrix()) {
            for (int value : row) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}

class TransposeMatrixThread extends Thread {
    private Matrix matrix;

    public TransposeMatrixThread(Matrix matrix) {
        this.matrix = matrix;
    }

    public void run() {
        System.out.println("Transpose:");
        int[][] transpose = matrix.getTranspose();
        for (int[] row : transpose) {
            for (int value : row) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}

class MaxValueThread extends Thread {
    private Matrix matrix;

    public MaxValueThread(Matrix matrix) {
        this.matrix = matrix;
    }

    public void run() {
        int max = matrix.getMaxValue();
        System.out.println("Maximum value in the matrix: " + max);
    }
}

class PrincipalDiagonalThread extends Thread {
    private Matrix matrix;

    public PrincipalDiagonalThread(Matrix matrix) {
        this.matrix = matrix;
    }

    public void run() {
        System.out.println("Principal Diagonal:");
        int[] diagonal = matrix.getPrincipalDiagonal();
        for (int value : diagonal) {
            System.out.print(value + " ");
        }
        System.out.println();
    }
}

class NonDiagonalElementsThread extends Thread {
    private Matrix matrix;

    public NonDiagonalElementsThread(Matrix matrix) {
        this.matrix = matrix;
    }

    public void run() {
        System.out.println("Non-Diagonal Elements:");
        int[] nonDiagonal = matrix.getNonDiagonalElements();
        for (int value : nonDiagonal) {
            System.out.print(value + " ");
        }
        System.out.println();
    }
}

