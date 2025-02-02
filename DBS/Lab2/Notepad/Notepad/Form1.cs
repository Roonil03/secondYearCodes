using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Notepad
{
    public partial class Form1 : Form
    {
        Boolean bar = false;
        public Form1()
        {
            InitializeComponent();
            toolStripStatusLabel1.Text = "";
            toolStripStatusLabel2.Text = "";
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {
            if (bar)
            {
                toolStripStatusLabel1.Text = "Character: " + richTextBox1.Text.Length;
            }
        }

        private void fILEToolStripMenuItem_Click(object sender, EventArgs e)
        {
        
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog odlg = new OpenFileDialog();
            //odlg.Filter = "txt files (*.txt)|(*.txt)|All Files";
            if (odlg.ShowDialog() == DialogResult.OK)
            {
                string filename = odlg.FileName;
                StreamReader sr = new StreamReader(filename);
                richTextBox1.Text = sr.ReadToEnd();
                sr.Close();
            }
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveFileDialog s = new SaveFileDialog();
            if (s.ShowDialog() == DialogResult.OK)
            {
                string filename = s.FileName;
                StreamWriter sw = new StreamWriter(filename);
                sw.Write(richTextBox1.Text);
                sw.Flush();
                sw.Close();
            }
            // richTextBox1.SaveFile(s.FileName, RichTextBoxStreamType.PlainText);
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = "";
        }

        private void cutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Cut();
        }

        private void fontColourToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FontDialog fd = new FontDialog();
            fd.Font = richTextBox1.SelectionFont;
            fd.Color = richTextBox1.SelectionColor;
            if (fd.ShowDialog() == DialogResult.OK)
            {
                richTextBox1.SelectionFont = fd.Font;
                richTextBox1.SelectionColor = fd.Color;
            }
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void copyToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Copy();
        }

        private void pasteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Paste();
        }

        private void statusBarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            bar = !bar;
            if (bar)
            {
                statusStrip1.Enabled = true;
                toolStripStatusLabel1.Text = "Character: " + richTextBox1.Text.Length;
                // int id = richTextBox1.SelectionStart;
                //toolStripStatusLabel2.Text = "\tL: " + richTextBox1.GetLineFromCharIndex(id) + 1 + "|R: " + (id - richTextBox1.GetFirstCharIndexOfCurrentLine() + 1);

            }
            else
            {
                statusStrip1.Enabled = false;
                toolStripStatusLabel1.Text = "";
                toolStripStatusLabel2.Text = "";
            }

        }

        private void statusStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void statusStrip1_ItemClicked_1(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void toolStripStatusLabel1_Click(object sender, EventArgs e)
        {

        }

        private void toolStripStatusLabel2_Click(object sender, EventArgs e)
        {

        }

        private void wordWrapToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.WordWrap = !richTextBox1.WordWrap;
        }

        private void zoomToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.SelectAll();
            richTextBox1.SelectionFont = new Font(richTextBox1.SelectionFont.FontFamily, richTextBox1.SelectionFont.Size + 5);
            richTextBox1.DeselectAll();
        }

        private void zoomOutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.SelectAll();
            richTextBox1.SelectionFont = new Font(richTextBox1.SelectionFont.FontFamily, richTextBox1.SelectionFont.Size - 5);
            richTextBox1.DeselectAll();
        }

    }
}
