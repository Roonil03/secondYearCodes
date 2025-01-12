using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Demo
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            NationalityList.Items.Add("Indian");
        }
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            Enabler.Enabled = true;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Name: " + textBox1.Text + " " + " Reg No: " + textBox2.Text);
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            MessageBox.Show("YO!");
            Enabler.Enabled = false;
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void Enabler_Click(object sender, EventArgs e)
        {
            string branch = "";
            if (radioButton1.Checked == true)
            {
                branch = radioButton1.Text;
            }
            else if (radioButton2.Checked == true)
            {
                branch = radioButton2.Text;
            }
            else
            {
                branch = "Not in ICT";
            }
            MessageBox.Show("Branch Selected is: " + branch + " sejnfsenfjsef: " + NationalityList.Text);
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            //NationalityList.Items.Add("Indian");
        }
    }
}
