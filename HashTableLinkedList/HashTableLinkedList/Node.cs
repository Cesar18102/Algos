using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HashTableLinkedList
{
    class Node
    {
        public int Value { get; private set; }
        public Node Next { get; set; }

        public Node(int value, Node next)
        {
            this.Value = value;
            this.Next = next;
        }
    }
}
