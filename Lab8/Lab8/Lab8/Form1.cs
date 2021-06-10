using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace WindowsFormsApp8
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            checkBox1.Checked = WindowsFormsApp9.Properties.Settings.Default.checkbox1;
            textBox1.Text = WindowsFormsApp9.Properties.Settings.Default.textbox;
            checkBox2.Checked = WindowsFormsApp9.Properties.Settings.Default.checkbox2;

            if ((ModifierKeys & Keys.Shift) == 0)
            {
                string initLocation = WindowsFormsApp9.Properties.Settings.Default.InitialLocation;
                Point il = new Point(0, 0);
                Size sz = Size;
                if (!string.IsNullOrWhiteSpace(initLocation))
                {
                    string[] parts = initLocation.Split(',');
                    if (parts.Length >= 2)
                    {
                        il = new Point(int.Parse(parts[0]), int.Parse(parts[1]));
                    }
                    if (parts.Length >= 4)
                    {
                        sz = new Size(int.Parse(parts[2]), int.Parse(parts[3]));
                    }
                }
                Size = sz;
                Location = il;
            }
        }
       private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            WindowsFormsApp9.Properties.Settings.Default.checkbox1 = checkBox1.Checked;
            WindowsFormsApp9.Properties.Settings.Default.checkbox2 = checkBox2.Checked;
            WindowsFormsApp9.Properties.Settings.Default.textbox = textBox1.Text;
            WindowsFormsApp9.Properties.Settings.Default.Save();

            if ((ModifierKeys & Keys.Shift) == 0)
            {
                Point location = Location;
                Size size = Size;
                if (WindowState != FormWindowState.Normal)
                {
                    location = RestoreBounds.Location;
                    size = RestoreBounds.Size;
                }
                string initLocation = string.Join(",", location.X, location.Y, size.Width, size.Height);
                WindowsFormsApp9.Properties.Settings.Default.InitialLocation = initLocation;
                WindowsFormsApp9.Properties.Settings.Default.Save();
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
           
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {

        }
    }

}