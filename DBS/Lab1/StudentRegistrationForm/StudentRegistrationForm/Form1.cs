using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace StudentRegistrationForm
{
    public partial class Form1 : Form
    {
        string branch = null;
        int noOfClubs = 0;
        string clubs = null;
        public Form1()
        {
            InitializeComponent();
            textBox2.Enabled = false;
            groupBox1.Enabled = false;
            comboBox1.Enabled = false;
            button1.Enabled = false;
            dateTimePicker1.Enabled = false;
            listBox1.Enabled = false;
            //checkedListBox1.Enabled = false;
            groupBox2.Enabled = false;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            groupBox1.Enabled = true;
            //label3.ForeColor++;
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            textBox2.Enabled = true;
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {
            comboBox1.Enabled = true;
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (radioButton1.Checked == true)
            {
                branch = radioButton1.Text;
            }
            else if (radioButton2.Checked == true)
            {
                branch = radioButton2.Text;
            }
            else if (radioButton3.Checked == true)
            {
                branch = radioButton3.Text;
            }
            else if (radioButton4.Checked == true)
            {
                branch = "Not in CSE Branches";
            }
            if (branch.Equals("IT"))
            {
                listBox1.Items.Add("DBS");
                listBox1.Items.Add("ES");
            }
            else if (branch.Equals("CCE"))
            {
                listBox1.Items.Add("OS");
                listBox1.Items.Add("WCC");
            }
            else if (branch.Equals("CSE"))
            {
                listBox1.Items.Add("AI");
                listBox1.Items.Add("EDS");
            }
            else
            {
                listBox1.Items.Add("Synthesis");
                listBox1.Items.Add("VLSI Design");
            }
            dateTimePicker1.Enabled = true;
            //button1.Enabled = true;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            
            MessageBox.Show("Name: " + textBox1.Text + "\nReg No: " + textBox2.Text + "\nBranch: " + branch + "\nSemester: " + comboBox1.Text + "\nDOB: " + dateTimePicker1.Text + "\nElected Course: " + listBox1.Text + "\nClubs: " + clubs);
        }

        private void progressBar1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click_1(object sender, EventArgs e)
        {

        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {
            listBox1.Enabled = true;
            
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            groupBox2.Enabled = true;
        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void groupBox2_Enter(object sender, EventArgs e)
        {
            button1.Enabled = true;
            if (noOfClubs == 0)
            {
                if (checkBox1.Checked == true)
                {
                    clubs = checkBox1.Text;
                }
                else if (checkBox2.Checked == true)
                {
                    clubs = checkBox2.Text;
                }
                else if (checkBox3.Checked == true)
                {
                    clubs = checkBox3.Text;
                }
                else
                {
                    clubs = checkBox4.Text;
                }
                noOfClubs++;
            }
            else
            {
                if (checkBox1.Checked == true)
                {
                    clubs = clubs + ", " + checkBox1.Text;
                }
                else if (checkBox2.Checked == true)
                {
                    clubs = clubs + ", " + checkBox2.Text;
                }
                else if (checkBox3.Checked == true)
                {
                    clubs = clubs + ", " + checkBox3.Text;
                }
                else
                {
                    clubs = clubs + ", " + checkBox4.Text;
                }
                noOfClubs++;
            }
        }
    }
}
