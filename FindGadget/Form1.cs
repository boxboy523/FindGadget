using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FindGadget
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string path = "C:/Users/junyeong/Documents/Programs/2dVision/temp/parts.png";
            byte[] pathBytes = Encoding.ASCII.GetBytes(path);
            unsafe
            {
                fixed (byte* p = pathBytes)
                {
                    sbyte* sp = (sbyte*)p;
                    CLR.CLRImageProcess obj = new CLR.CLRImageProcess(0, sp);
                }
            }
        }
    }
}
