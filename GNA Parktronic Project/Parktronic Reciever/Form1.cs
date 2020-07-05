using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Parktronic_Reciever
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
            SerialPort sp = new SerialPort("COM5", 9600);

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                sp.Open();
                label1.Visible = true;
                if (label2.ForeColor != System.Drawing.Color.Green)
                {
                    label2.ForeColor = System.Drawing.Color.Green;
                }
                label2.Text = "Connected";

            }
            catch (UnauthorizedAccessException)
            {

                label2.Text = "Already Connected";
            }
            catch (InvalidOperationException)
            {

                label2.Text = "Already Connected";
            }

            sp.DataReceived += new SerialDataReceivedEventHandler(DataReceived);

        }
        private void DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            SerialPort sp = (SerialPort)sender;
            label1.Invoke(new Action(() =>
            {
                label1.Text = sp.ReadLine();
                
            }));
        }

        private void button2_Click(object sender, EventArgs e)
        {

            sp.Close();
            if (label2.ForeColor != System.Drawing.Color.Red)
            {
                label2.ForeColor = System.Drawing.Color.Red;
            }
            label2.Text = "Disconnected";
            label1.Visible = false;
        }
        private void button3_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
