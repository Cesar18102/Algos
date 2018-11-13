using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LAB4_ALTDST
{
    class Program
    {
        static void Main(string[] args)
        {
            Graph G = Graph.ReadGraph();
            G.PrintGraph();

            Console.Write("Input count of tests: ");
            int countOfTests = Convert.ToInt32(Console.ReadLine());
            for (int j = 0; j < countOfTests; j++)
            {
                Console.WriteLine("Input number of initial vertex for DXTR: ");
                int initVertex = Convert.ToInt32(Console.ReadLine());

                G.PrintDXTR(G.DXTR(initVertex), initVertex);
            }
        }
    }
}
