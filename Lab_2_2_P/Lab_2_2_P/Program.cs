using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_2_2_P
{
    class Program
    {
        static void Main(string[] args)
        {
            Rect R = new Rect(new PNT(0, 0), new PNT(2, 2));
            R.Draw('#');
            Console.ReadLine();
        }
    }
}
