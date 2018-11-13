using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LAB5_P
{
    class Program
    {
        static void Main(string[] args)
        {
            MyArray arr = new MyArray(new int[] { 1, 9, 4, 2, -1, 3, 5, 11 }, 1, 3, 6);
            Console.WriteLine(arr.ToString());
            arr.SortMerge();
            Console.WriteLine(arr.ToString());
            Console.ReadLine();
        }
    }
}
