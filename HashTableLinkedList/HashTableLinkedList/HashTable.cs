using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HashTableLinkedList
{
    class HashTable
    {
        private MyLinkedList[] gaps;
        private HashFunc HashFunction;

        public MyLinkedList this[int i]
        {
            get { return ((i < 0 || i >= gaps.Length) ? null : new MyLinkedList(gaps[i])); }
        }

        public HashTable(int size, HashFunc hashFunction)
        {
            gaps = new MyLinkedList[size];
            for (int i = 0; i < size; i++)
                gaps[i] = new MyLinkedList();
            HashFunction = hashFunction;
        }

        public void AddItem(int item)
        {
            gaps[HashFunction(item)].AddItem(item);
        }

        public override string ToString()
        {
            string data = "";
            for (int i = 0; i < gaps.Length; i++)
                data += "gap number " + i + ": " + gaps[i].ToString() + ". Count of collisions: " + gaps[i].Count + "\n";
            return data;
        }

        public int CountOfCollisions
        {
            get
            {
                int count = 0;
                for (int i = 0; i < gaps.Length; i++)
                    if (gaps[i].Count == 0)
                        count++;
                return count;
            }
        }

        public delegate int HashFunc(int item);
    }
}
