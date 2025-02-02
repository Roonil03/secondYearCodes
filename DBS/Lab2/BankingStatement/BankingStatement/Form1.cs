using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BankingStatement
{
    public partial class Form1 : Form
    {
        List<Users> data = new List<Users>();

        public Form1()
        {
            InitializeComponent();
            button1.Text = "Submit!";
            button2.Text = "Forgot Password!";
            button3.Hide();
            button3.Enabled = false;
            label1.Text = "Username: ";
            label2.Text = "Password: ";
            data.Add(new Users("admin", "admin", 1000000.0, DateTime.Now, new string[] {
            "Deposited $500",
            "Transferred $1000 to User123",
            "Received $200 from User456",
            "Paid $300 for utilities",
            "Withdrawn $400"
            }));
            data.Add(new Users("User1", "12345", 21000, DateTime.Now, new string[]
            {
                "Deposited $800",
                "Transferred $100 to R03",
                "Received $900 from Wess",
                "Paid $30 for household",
                "Withdrawn $40"
            }));
            // StextBox2
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Boolean done = false;
            foreach (Users temp in data)
            {
                if (textBox1.Text.Equals(temp.getUsername()) && textBox2.Text.Equals(temp.getPassword()))
                {
                    done = !done;
                    Form2 f = new Form2(temp);
                    f.Show();
                    this.Hide();
                    break;
                }
            }
            if (!done)
            {
                MessageBox.Show("Username or password incorrect!");
            }
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            label1.Text = "Account: ";
            label2.Text = "New Password: ";
            button3.Show();
            button1.Enabled = false;
            button2.Enabled = false;
            button1.Hide();
            button2.Hide();
            button3.Enabled = true;
            button3.Text = "Change Password!";

        }

        private void button3_Click(object sender, EventArgs e)
        {
            Boolean done = false;
            foreach (Users temp in data)
            {
                if (textBox1.Text.Equals(temp.getUsername()))
                {
                    done = !done;
                    temp.changePassword(textBox2.Text);
                    break;
                }
            }
            if (!done)
            {
                MessageBox.Show("Username does not exist!");
            }
            button1.Enabled = true;
            button2.Enabled = true;
            button3.Enabled = false;
            button1.Show();
            button2.Show();
            button3.Hide(); 
            label1.Text = "Username: ";
            label2.Text = "Password: ";
        }
    }
}

public class Users
{
    private string username, password;
    private double balance;
    private DateTime lastAccess;
    private string[] lastTransaction;
    public Users(string u, string p, double b, DateTime last, string[] las)
    {
        username = u;
        password = p;
        balance = b;
        lastAccess = last;
        lastTransaction = las;
    }
    public string getUsername()
    {
        return username;
    }
    public string getPassword()
    {
        return password;
    }
    public void changePassword(string s)
    {
        password = s;
    }
    public double getBalance()
    {
        return balance;
    }
    public void changeBalance(double b)
    {
        balance -= b;
    }
    public DateTime getLastAccess()
    {
        return lastAccess;
    }

    public string getLastTransaction()
    {
        string s = "\n";
        foreach (string temp in lastTransaction)
        {
            s += temp + "\n";
        }
        return s;
    }
    public string[] getLastTransactionArray()
    {
        return lastTransaction;
    }

    public void modifyTransaction(string[] s)
    {
        lastTransaction = s;
    }
    public void setLastAccess(DateTime c)
    {
        lastAccess = c;
    }
}