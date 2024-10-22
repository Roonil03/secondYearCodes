public class leapYear
{
    public static void main(String[] args) {
        boolean leap=false;
        int year = Integer.parseInt(args[0]);
        if(year % 400 == 0)
        {
            leap = true;
        }
        else if(year % 100 != 0 && year % 4 == 0)
        {
            leap = true;
        }
        if(leap)
            System.out.println("It is leap year.");
        else
        System.out.println("It is common year.");
    }
}