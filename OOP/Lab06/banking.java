import java.util.*;

class Account {
    String name;
    int accNo;
    double balance;

    Account(String name, int accNo, double balance) {
        this.name = name;
        this.accNo = accNo;
        this.balance = balance;
    }

    Account() {
    }

    void deposit(double input) {
        if (input > 0) {
            balance += input;
            displayBalance();
        } else {
            System.out.println("The amount must be positive");
        }
    }

    void displayBalance() {
        System.out.println("The balance amount is: " + balance);
    }

    boolean withdraw(double amount) {
        if (amount < 0) {
            System.out.println("Cannot withdraw negative funds!");
            return false;
        }
        if (amount > balance) {
            System.out.println("Account does not have enough balance!");
            return false;
        }
        balance -= amount;
        displayBalance();
        return true;
    }
}

class CurrentAccount extends Account {
    final double minBalance = 1000;
    final int serviceCharge = 100;

    CurrentAccount(String name, int no, double bal) {
        super(name, no, bal);
    }

    boolean withdraw(double amount) {
        if (amount < 0) {
            System.out.println("Cannot withdraw negative funds!");
            return false;
        }
        else if(amount > balance)
        {
            System.out.println("Insufficient funds");
            return false;
        }
        else if (amount > balance - minBalance) {
            System.out.println("Taking service fee...");
            balance -= amount + serviceCharge;
            displayBalance();
            return true;
        } else {
            return super.withdraw(amount);
        }
    }

    boolean checkMinBalance() {
        if (balance < minBalance) {
            System.out.println("Account balance is below minimum balance.");
            return true;
        }
        System.out.println("Account balance is above minimum balance.");
        return false;
    }
}

class SavingsAccount extends Account {
    double interest;

    SavingsAccount(String name, int accNo, double balance, double interest) {
        super(name, accNo, balance);
        this.interest = interest;
    }

    void accountInterest() {
        double in = this.interest * balance;
        balance += in;
        System.out.println("Interest amount deposited: " + in);
        displayBalance();
    }
}

public class banking{
    public static void main(String[] args) {
        CurrentAccount a1 = new CurrentAccount("John Doe", 1231112, 30000);
        SavingsAccount a2 = new SavingsAccount("Jane Doe", 2313441, 40000, 0.11);
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.println("Access which account:");
            System.out.println("1. Account a1");
            System.out.println("2. Account a2");
            System.out.println("3. Exit Program");
            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    accountA1(a1, sc);
                    break;
                case 2:
                    accountA2(a2, sc);
                    break;
                case 3:
                    System.out.println("Thank you!");
                    sc.close();
                    System.exit(0);
                default:
                    System.out.println("Incorrect Option!");
                    break;
            }
        }
    }

    static void accountA1(CurrentAccount a1, Scanner sc) {
        System.out.println("Current Account: ");
        System.out.println("1. Deposit Amount");
        System.out.println("2. Display Balance");
        System.out.println("3. Withdraw Amount");
        System.out.println("4. Check minimum balance");
        //int choice = sc.nextInt();
        switch (sc.nextInt()) {
            case 1:
                System.out.println("Enter amount to deposit");
                a1.deposit(sc.nextDouble());
                break;
            case 2:
                a1.displayBalance();
                break;
            case 3:
                System.out.println("Enter amount to withdraw");
                a1.withdraw(sc.nextDouble());
                break;
            case 4:
                a1.checkMinBalance();
                break;
            default:
                System.out.println("Incorrect option, returning back...\n");
                break;
        }
    }

    static void accountA2(SavingsAccount a2, Scanner sc) {
        System.out.println("Savings Account:");
        System.out.println("1. Deposit Amount");
        System.out.println("2. Display Balance");
        System.out.println("3. Compute Interest");
        System.out.println("4. Withdraw");
        int choice = sc.nextInt();
        switch (choice) {
            case 1:
                System.out.println("Enter the amount to deposit");
                a2.deposit(sc.nextDouble());
                break;
            case 2:
                a2.displayBalance();
                break;
            case 3:
                a2.accountInterest();
                break;
            case 4:
                System.out.println("Enter the amount to withdraw:");
                a2.withdraw(sc.nextDouble());
                break;
            default:
                System.out.println("Invalid choice... returning back.");
                break;
        }
    }
}
