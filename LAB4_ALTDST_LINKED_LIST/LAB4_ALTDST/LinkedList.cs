using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LAB4_ALTDST
{
    public class Node
    {
        public int Value { get; private set; }
        public Node Next { get; set; }

        public Node(int data, Node next)
        {
            Value = data;
            Next = next;
        }
    }


    public class MyLinkedList
    {
        private int count = 0;

        public Node First { get; private set; }
        public int Count { get { return count; } }
        public Node Last {
            get
            {
                if (First == null)
                    return null;


                Node i = First;
                for (; i.Next != null; i = i.Next) ;
                return i;

            }
        }

        public MyLinkedList()
        {

        }

        public MyLinkedList(int first)
        {
            First = new Node(first, null);
        }

        public MyLinkedList(MyLinkedList linkedList)
        {
            for (Node i = linkedList.First; i != null; i = i.Next)
                this.AddLast(i.Value);
        }

        public void AddLast(int data)
        {
            if (First == null)
                First = new Node(data, null);
            else
                Last.Next = new Node(data, null);
            count++;
        }
    }
}
