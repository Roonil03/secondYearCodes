public class numberMethods {
    public static void main(String[] args) {
        Number n1 = new Number();
        n1.display();
        Number n2 = new Number(3.4);
        n2.display();
        Number n3 = new Number(50);
        n3.display();
    }
}
class Number{
    double num;
    Number()
    {
        num=0;
    }
    Number(double num)
    {
        this.num = num;
    }
    boolean isZero(){
        if(num == 0)
        {
            return true;
        }
        return false;
    }
    boolean isPositive(){
        if(num > 0)
        {
            return true;
        }
        return false;
    }
    boolean isNegative(){
        if(num <0)
        {
            return true;
        }
        return false;
    }
    boolean isOdd(){
        return num%2==0?true:false;
    }
    boolean isEven(){
        return num%2!=0?true:false;
    }
    boolean isPrime(){
        int i;
        if(num == 0 || num == 1)
        {
            return false;
        }
        for(i=2;i<=num/2;i++)
        {
            if(num%i==0)
            {
                return false;
            }
        }
        return true;
    }
    boolean isArmstrong(){
        int i,temp = (int)num,b=0;
        int count=0;
        while(temp!=0)
        {
            temp /= 10;
            count++;
        }
        temp = (int)num;
        for(i=0;i<temp;i++)
        {
            b += Math.pow(temp%10,count);
            temp /= 10;
        }
        return b==(int)num?true:false;
    }
    void display()
    {
        System.out.println("The number is: "+ num);
        System.out.println("isZero: " + isZero());
        System.out.println("isPrime: " + (isPrime()));
        System.out.println("isArmstrong: " + isArmstrong());
        System.out.println("isEven: " + isEven());
        System.out.println("isNegative: " + isNegative());
        System.out.println("isOdd: " + isOdd());
        System.out.println("isPositive: " + isPositive());
        System.out.println("\n");
    }
}