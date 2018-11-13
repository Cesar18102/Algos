using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LAB4_ALTDST
{
    public class Edge : IComparable
    {
        public int Vertex1 { get; private set; }
        public int Vertex2 { get; private set; }
        public float Weight { get; private set; }

        public Edge(int V1, int V2, float Weight)
        {
            Vertex1 = V1;
            Vertex2 = V2;
            this.Weight = Weight;
        }

        int System.IComparable.CompareTo(object obj)
        {
            Edge E = obj as Edge;

            if (E.Weight < Weight)
                return 1;

            if (E.Weight > Weight)
                return -1;

            return 0;
        }
    }
}
