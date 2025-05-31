using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Oracle.DataAccess.Client;
using Oracle.DataAccess.Types;

namespace ConnectionDemo
{
    public partial class Form1 : Form
    {
        OracleConnection conn;
        OracleCommand comm;
        DataSet ds;
        OracleDataAdapter da;
        DataTable dt;
        DataRow dr;
        int i = 0;
        public Form1()
        {
            InitializeComponent();
            button1.Text = "Connect";
            button2.Text = "Command";
            button2.Enabled = false;
            label1.Text = "Driver ID:";
            label2.Text = "Name";
            label3.Text = "Address";
            button3.Text = "Next";
            button3.Enabled = false;
            button4.Text = "Prev";
            button4.Enabled = false;
            button5.Text = "Insert";
            button5.Enabled = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string connection = "DATA SOURCE=IPAddress/ictorcl;USER ID=Branch_RegNo;Password=ThePassCode";
            conn = new OracleConnection(connection);
            conn.Open();
            MessageBox.Show("Connected!");
            button2.Enabled = true;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            comm = new OracleCommand();
            //button1.Enabled = false;
            comm.CommandText = "select * from person";
            comm.CommandType = CommandType.Text;
            ds = new DataSet();
            da = new OracleDataAdapter(comm.CommandText, conn);
            da.Fill(ds, "person");
            dt = ds.Tables["person"];
            int t = dt.Rows.Count;
            MessageBox.Show(t.ToString());
            dr = dt.Rows[i];
            button3.Enabled = true;
            button4.Enabled = true;
            button5.Enabled = true;
            textBox1.Text = dr["driver_id"].ToString();
            textBox2.Text = dr["name"].ToString();
            textBox3.Text = dr["address"].ToString();
            conn.Close(); 
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            i++;
            if (i >= dt.Rows.Count)
                i = 0;
            dr = dt.Rows[i];
            textBox1.Text = dr["driver_id"].ToString();
            textBox2.Text = dr["name"].ToString();
            textBox3.Text = dr["address"].ToString();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            i--;
            if (i < 0)
                i = dt.Rows.Count-1;
            dr = dt.Rows[i];
            textBox1.Text = dr["driver_id"].ToString();
            textBox2.Text = dr["name"].ToString();
            textBox3.Text = dr["address"].ToString();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            //MessageBox.Show("Yet to implement");
            comm = new OracleCommand();
            comm.Connection = conn;
            comm.CommandText = "insert into person values ('" + textBox1.Text + "','" + textBox2.Text + "','" + textBox3.Text + "')";
            comm.CommandType = CommandType.Text;
            comm.ExecuteNonQuery();
            MessageBox.Show("Inserted values!");
            conn.Close();
        }
    }
}
