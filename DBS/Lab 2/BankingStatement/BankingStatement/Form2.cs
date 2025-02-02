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
    public partial class Form2 : Form
    {
        Users temp;
        public Form2()
        {
            //InitializeComponent();
        }

        public Form2(Users temp)
        {
            this.temp = temp;
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            label1.Text = "Name:\t" + temp.getUsername();
            label2.Text = "Balance:\t" + temp.getBalance();
            label3.Text = "Last Access: \t" + temp.getLastAccess();
            label4.Text = "Last Transaction: \t" + temp.getLastTransaction();
            button1.Text = "Transfer Funds!";
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form3 f = new Form3(temp);
            f.Show();
            this.Hide();
        }
    }
}
