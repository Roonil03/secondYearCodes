using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator
{
    
    public partial class Form1 : Form
    {
        string var1 = "", var2 = "";
        char op = '\0';
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if(op == '\0')
            {
                var1 += 1;
                label1.Text = var1;
            }
            else{
                var2 += 1;
                label1.Text = var2;
            } 
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(op == '\0')
            {
                var1 += 0;
                label1.Text = var1;
            }
            else{
                var2 += 0;
                label1.Text = var2;
            } 
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if(op == '\0')
            {
                var1 += 2;
                label1.Text = var1;
            }
            else{
                var2 += 2;
                label1.Text = var2;
            } 
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if(op == '\0')
            {
                var1 += 3;
                label1.Text = var1;
            }
            else{
                var2 += 3;
                label1.Text = var2;
            } 
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (!var2.Equals(""))
            {
                int n1 = int.Parse(var1);
                int n2 = int.Parse(var2);
                int res = 0;
                switch (op)
                {
                    case '+':
                        res = n1 + n2;
                        break;
                    case '-':
                        res = n1 - n2;
                        break;
                    case '*':
                        res = n1 * n2;
                        break;
                    case '/':
                        if (n2 == 0)
                        {
                            MessageBox.Show("Cannot divide by zero, setting res to 0");
                            res = 0;
                            break;
                        }
                        res = n1 / n2;
                        break;

                    default:
                        res = 0;
                        break;
                }
                var1 = "" + res;
                var2 = "";
            }
                op = '+';
        }

        private void button6_Click(object sender, EventArgs e)
        {
            if (!var2.Equals(""))
            {
                int n1 = int.Parse(var1);
                int n2 = int.Parse(var2);
                int res = 0;
                switch (op)
                {
                    case '+':
                        res = n1 + n2;
                        break;
                    case '-':
                        res = n1 - n2;
                        break;
                    case '*':
                        res = n1 * n2;
                        break;
                    case '/':
                        if (n2 == 0)
                        {
                            MessageBox.Show("Cannot divide by zero, setting res to 0");
                            res = 0;
                            break;
                        }
                        res = n1 / n2;
                        break;

                    default:
                        res = 0;
                        break;
                }
                var1 = "" + res;
                var2 = "";
            }
            op = '-';
        }

        private void button7_Click(object sender, EventArgs e)
        {
            if(var1.Equals("") || var2.Equals("") || op == '\0')
            {
                MessageBox.Show("All details not entered");
            }
            else{
                int n1 = int.Parse(var1);
                int n2 = int.Parse(var2);
                int res = 0;
                switch(op)
                {
                    case '+':
                        res = n1 + n2;
                        break;
                    case '-':
                        res = n1 - n2;
                        break;
                    case '*':
                        res = n1 * n2;
                        break;
                    case '/':
                        if (n2 == 0)
                        {
                            MessageBox.Show("Cannot divide by zero, setting res to 0");
                            res = 0;
                            break;
                        }
                        res = n1 / n2;
                        break;
                    default:
                        res = 0;
                        break;
                }
                label1.Text = "Answer = " + res;
            }
        }

        private void button8_Click(object sender, EventArgs e)
        {
            var1 = "";
            var2 = "";
            op = '\0';
        }

        private void button9_Click(object sender, EventArgs e)
        {
            if (op == '\0')
            {
                var1 += 4;
                label1.Text = var1;
            }
            else
            {
                var2 += 4;
                label1.Text = var2;
            } 
        }

        private void button10_Click(object sender, EventArgs e)
        {
            if (op == '\0')
            {
                var1 += 5;
                label1.Text = var1;
            }
            else
            {
                var2 += 5;
                label1.Text = var2;
            } 
        }

        private void button11_Click(object sender, EventArgs e)
        {
            if (op == '\0')
            {
                var1 += 6;
                label1.Text = var1;
            }
            else
            {
                var2 += 6;
                label1.Text = var2;
            } 
        }

        private void button12_Click(object sender, EventArgs e)
        {
            if (op == '\0')
            {
                var1 += 7;
                label1.Text = var1;
            }
            else
            {
                var2 += 7;
                label1.Text = var2;
            } 
        }

        private void button13_Click(object sender, EventArgs e)
        {
            if (op == '\0')
            {
                var1 += 8;
                label1.Text = var1;
            }
            else
            {
                var2 += 8;
                label1.Text = var2;
            } 
        }

        private void button14_Click(object sender, EventArgs e)
        {
            if (op == '\0')
            {
                var1 += 9;
                label1.Text = var1;
            }
            else
            {
                var2 += 9;
                label1.Text = var2;
            } 
        }

        private void button15_Click(object sender, EventArgs e)
        {
            if (!var2.Equals(""))
            {
                int n1 = int.Parse(var1);
                int n2 = int.Parse(var2);
                int res = 0;
                switch (op)
                {
                    case '+':
                        res = n1 + n2;
                        break;
                    case '-':
                        res = n1 - n2;
                        break;
                    case '*':
                        res = n1 * n2;
                        break;
                    case '/':
                        if (n2 == 0)
                        {
                            MessageBox.Show("Cannot divide by zero, setting res to 0");
                            res = 0;
                            break;
                        }
                        res = n1 / n2;
                        break;
                        
                    default:
                        res = 0;
                        break;
                }
                var1 = "" + res;
                var2 = "";
            }
            op = '*';
        }

        private void button16_Click(object sender, EventArgs e)
        {
            if (!var2.Equals(""))
            {
                int n1 = int.Parse(var1);
                int n2 = int.Parse(var2);
                int res = 0;
                switch (op)
                {
                    case '+':
                        res = n1 + n2;
                        break;
                    case '-':
                        res = n1 - n2;
                        break;
                    case '*':
                        res = n1 * n2;
                        break;
                    case '/':
                        if (n2 == 0)
                        {
                            MessageBox.Show("Cannot divide by zero, setting res to 0");
                            res = 0;
                            break;
                        }
                        res = n1 / n2;
                        break;

                    default:
                        res = 0;
                        break;
                }
                var1 = "" + res;
                var2 = "";
            }
            op = '/';
        }

    }
}
