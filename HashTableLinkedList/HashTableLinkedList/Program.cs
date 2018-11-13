using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HashTableLinkedList
{
    class Program
    {
        static void Main(string[] args)
        {
            HashTable ht = new HashTable(100, item => item % 100);

            Random rand = new Random();
            int[] randoms = new int[60];

            for (int i = 0; i < 60; i++)
                randoms[i] = rand.Next(0, 451);

            for (int i = 0; i < 60; i++)
                ht.AddItem(randoms[i]);

            Console.Write(ht.ToString() + "\nTotal count of collisions: " + ht.CountOfCollisions);
            Console.ReadLine();
        }
    }
}
