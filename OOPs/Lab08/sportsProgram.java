import java.util.*;

public class sportsProgram {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the sport:\n1. Hockey\n2. Football");
        int sportChoice = sc.nextInt();
        sc.nextLine(); 

        switch (sportChoice) {
            case 1:
                Hockey h1 = new Hockey();
                Hockey h2 = new Hockey();

                System.out.println("Enter player names for Team 1: ");
                for (int i = 0; i < 10; i++) {
                    h1.team[i] = sc.nextLine();
                }

                System.out.println("Enter player names for Team 2: ");
                for (int i = 0; i < 10; i++) {
                    h2.team[i] = sc.nextLine();
                }

                h1.getNumberOfGoals(sc);
                h2.getNumberOfGoals(sc);

                if (h1.goals > h2.goals) {
                    h1.dispTeam();
                } else {
                    h2.dispTeam();
                }
                break;

            case 2:
                Football f1 = new Football();
                Football f2 = new Football();

                System.out.println("Enter player names for Team 1: ");
                for (int i = 0; i < 11; i++) {
                    f1.team[i] = sc.nextLine();
                }

                System.out.println("Enter player names for Team 2: ");
                for (int i = 0; i < 11; i++) {
                    f2.team[i] = sc.nextLine();
                }

                f1.getNumberOfGoals(sc);
                f2.getNumberOfGoals(sc);

                if (f1.goals > f2.goals) {
                    f1.dispTeam();
                } else {
                    f2.dispTeam();
                }
                break;

            default:
                System.out.println("Invalid choice. Exiting.");
                System.exit(0);
        }

        sc.close();
    }
}

interface Sports {
    void getNumberOfGoals(Scanner sc);
    void dispTeam();
}

class Hockey implements Sports {
    int goals;
    String[] team = new String[10];

    public void getNumberOfGoals(Scanner sc) {
        System.out.println("Enter number of goals: ");
        goals = sc.nextInt();
        sc.nextLine(); 
    }

    public void dispTeam() {
        System.out.println("The team is: ");
        for (int i = 0; i < team.length; i++) {
            System.out.println((i + 1) + ". " + team[i]);
        }
    }
}

class Football implements Sports {
    int goals;
    String[] team = new String[11];

    public void getNumberOfGoals(Scanner sc) {
        System.out.println("Enter number of goals: ");
        goals = sc.nextInt();
        sc.nextLine(); 
    }

    public void dispTeam() {
        System.out.println("The team is: ");
        for (int i = 0; i < team.length; i++) {
            System.out.println((i + 1) + ". " + team[i]);
        }
    }
}
