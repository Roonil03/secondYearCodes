import java.util.*;
class Stack{
    public static final int MAX = 50;
    int data[] = new int[MAX];
    int top;
    Stack()
    {
        top = -1;
    }
    boolean isEmpty()
    {
        return top == -1;
    }
    boolean isFull()
    {
        return top == MAX-1;
    }
    void push(int n)
    {
        if(isFull())
        {
            System.out.println("The stack is full.");
            return;
        }
        data[++top] = n;
    }
    int pop()
    {
        if(isEmpty())
        {
            System.out.println("The stack is empty: Error = -1");
            return -1;
        }
        return data[top--];
    }
    void display()
    {
        if(isEmpty())
        {
            System.out.println("Stack is empty, nothing to display!");
            return;
        }
        System.out.println("The values are:");
        for(int i = 0; i<=top;i++)
        {
            System.out.print(data[i] + " ");
        }
        System.out.println("");
    }
    void peek()
    {
        if(isEmpty())
        {
            System.out.println("The stack is empty");
            return;
        }
        System.out.println("The peeked value is: " + data[top]);
    }
}
public class stackUsage {
    public static void main(String[] args) {
        
    Stack s = new Stack();
    int choice = 0;
    do{
        System.out.println("1. Push");
        System.out.println("2. Pop");
        System.out.println("3. Display");;
        System.out.println("4. Peek");
        System.out.println("5. Exit Program");
        Scanner sc = new Scanner(System.in);
        choice = sc.nextInt();
        switch(choice)
        {
            case 1:
            System.out.println("Enter the data to push:");
            s.push(sc.nextInt());
            break;
            case 2:
            System.out.println("The popped element is: " + s.pop());
            break;
            case 3:
            s.display();
            break;
            case 4:
            s.peek();
            break;
            case 5:
            System.out.println("Exiting program...");
            sc.close();
            break;
            default:
            System.out.println("Invalid choice... Try again");
            break;
        }
    }while(choice!=5);
}
}
