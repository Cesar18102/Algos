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

            Console.WriteLine("Count of connected components: " + G.getCountOfconnectedComponents());
            /*int[][] temp = G.getAttachedCouples();
            for (int i = 0; i < temp.Length; i++)
                Console.WriteLine("Vertices attached to " + i + " are: " + String.Join(",", temp[i]));*/

            /*Console.Write("Input count of tests: ");
            int countOfTests = Convert.ToInt32(Console.ReadLine());
            for (int j = 0; j < countOfTests; j++)
            {
                Console.WriteLine("Input number of initial vertex for DFS: ");
                int initVertex = Convert.ToInt32(Console.ReadLine());

                Console.WriteLine("Input number of finish vertex for DFS: ");
                int finishVertex = Convert.ToInt32(Console.ReadLine());

                Console.WriteLine(G.DFS(initVertex, finishVertex));
                //G.PrintDXTR(G.DXTR(initVertex), initVertex);
            }

            Console.WriteLine("Minimal spanning tree is: ");
            G.Crusckall().PrintGraph();*/
            Console.ReadLine();
        }
    }
}
