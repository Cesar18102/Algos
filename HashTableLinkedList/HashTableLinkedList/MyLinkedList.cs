using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HashTableLinkedList
{
    class MyLinkedList
    {
        public Node First { get; set; }
        public Node Last
        {
            get
            {
                if (First == null)
                    return null;

                Node i = First;
                for (; i.Next != null; i = i.Next) ;
                return i;
            }
            private set {  }
        }
        public int Count { get; private set; }

        public MyLinkedList()
        {
            this.First = null;
            this.Count = 0;
        }

        public MyLinkedList(int firstItem)
        {
            this.First = new Node(firstItem, null);
            this.Last = this.First;
            this.Count = 1;
        }

        public MyLinkedList(MyLinkedList copyList)
        {
            for (Node i = First; i != null; i = i.Next)
                this.AddItem(i.Value);
        }

        public void AddItem(int item)
        {
            if (this.Last == null)
            {
                this.First = new Node(item, null);
                this.Last = this.First;
            }
            else
                this.Last.Next = new Node(item, null);

            this.Count++;
        }

        public override string ToString()
        {
            string data = "";
            for (Node i = First; i != null; i = i.Next)
                data += i.Value.ToString() + ", ";
            return data;
        }
    }
}
