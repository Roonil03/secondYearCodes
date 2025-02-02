using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BankingStatement
{
    public partial class Form3 : Form
    {
        Users temp;
        public Form3(Users temp)
        {
            this.temp = temp;
            InitializeComponent();
            label1.Text = "Account Number to: ";
            label2.Text = "Amount: ";
            button1.Text = "Transfer!";
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form3_Load(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (temp.getBalance() > int.Parse(textBox1.Text) && int.Parse(textBox1.Text) > 0)
            {
                temp.changeBalance(int.Parse(textBox1.Text));
                temp.setLastAccess(DateTime.Now);
                string[] strings = new string[5];
                for (int i = 0; i <= 3; i++)
                {
                    strings[i] = temp.getLastTransactionArray()[i + 1];
                }
                strings[4] = "Transferred $" + textBox1.Text + " to " + textBox2.Text;
                temp.modifyTransaction(strings);
                MessageBox.Show("Transfer Successful!");
                Form2 f = new Form2(temp);
                f.Show();
                this.Hide();
            }
            else
            {
                MessageBox.Show("Insufficient Funds!");
            }
        }
    }
}
