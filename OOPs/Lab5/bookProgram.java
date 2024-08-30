import java.util.*;
public class bookProgram {
    public static void main(String[] args) {
        Book list[] = new Book[6];
        int i;
        Scanner sc = new Scanner(System.in);
        // Scanner sc2 = new Scanner(System.in);
        // Scanner sc3 = new Scanner(System.in);
        for(i=0;i<6;i++)
        {
            String s1,s2; int i1;
            System.out.println("Enter the title: ");
            s1 = sc.nextLine();
            System.out.println("Enter the author: ");
            s2 = sc.nextLine();
            System.out.println("Enter the edition number: ");
            i1 = sc.nextInt();
            sc.nextLine();
            list[i] = new Book(s1,s2,i1);
            System.out.println("\n");
        }

        // sc2.close();
        // sc3.close();
        for(i = 0; i<6;i++)
        {
            for(int j=i;j<6-1;j++)
            {
                if(list[j].edition>list[j+1].edition)
                {
                    String temp;

                    temp = list[j].title;
                    list[j].title = list[j+1].title;
                    list[j+1].title = temp;

                    temp = list[j].author;
                    list[j].author = list[j+1].author;
                    list[j+1].author = temp;

                    list[j].edition = list[j].edition ^ list[j+1].edition;
                    list[j+1].edition = list[j].edition ^ list[j+1].edition;
                    list[j].edition = list[j].edition ^ list[j+1].edition;

                }
            }
        }

        System.out.println("Enter the name of the author to find: ");
        String au = sc.nextLine();
        for(i=0;i<6;i++)
        {
            if(au.equalsIgnoreCase(list[i].author))
            {
            System.out.println("Title: " + list[i].title);
            System.out.println("Author: " + list[i].author);
            System.out.println("Edition: " + list[i].edition);
            System.out.println("\n");
            }
        }
        sc.close();
    }
}
class Book{
    String title;
    String author;
    int edition;
    Book(){
        edition = -1;
        title = "";
        author = "";
    }
    Book(String title, String author, int edition){
        this.title = title;
        this.author = author;
        this.edition = edition;
    }
}