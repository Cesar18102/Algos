using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace LAB4_ALTDST
{
    class Graph
    {
        private float[][] attachmentMatrix;
        private int countOfVertexes;
        private int countOfEdges = 0;

        public Graph(int countOfVertexes)
        {
            this.countOfVertexes = countOfVertexes;
            attachmentMatrix = new float[countOfVertexes][];
            for (int i = 0; i < countOfVertexes; i++)
            {
                attachmentMatrix[i] = new float[countOfVertexes];
                for (int j = 0; j < countOfVertexes; j++)
                    attachmentMatrix[i][j] = float.NaN;
            }
        }

        public void addAttachment(int v1, int v2, float weight)
        {
            if (v1 < 0 || v2 < 0 || v1 >= attachmentMatrix.Length || v2 >= attachmentMatrix.Length)
                return;

            countOfEdges++;
            attachmentMatrix[v1][v2] = weight;
            attachmentMatrix[v2][v1] = weight;
        }

        public void removeAttachment(int v1, int v2)
        {
            if (v1 < 0 || v2 < 0 || v1 >= attachmentMatrix.Length || v2 >= attachmentMatrix.Length)
                return;

            attachmentMatrix[v1][v2] = float.NaN;
            attachmentMatrix[v2][v1] = float.NaN;
        }

        public static Graph ReadGraph()
        {
            Console.WriteLine("Input count of graph vertexes: ");
            int countOfVertexes = Convert.ToInt32(Console.ReadLine());
            Graph G = new Graph(countOfVertexes);

            Console.WriteLine("Input count of connections you want to add to the graph: ");
            int countOfConnections = Convert.ToInt32(Console.ReadLine());

            for (int i = 0; i < countOfConnections; i++)
            {
                Console.WriteLine("Input numbers of vertextes you want to connect: ");
                int v1 = Convert.ToInt32(Console.ReadLine());
                int v2 = Convert.ToInt32(Console.ReadLine());

                Console.WriteLine("Input weight of the edge: ");
                float w = (float)Convert.ToDouble(Console.ReadLine());

                G.addAttachment(v1, v2, w);
            }
            return G;
        }

        public void PrintGraph()
        {
            Console.WriteLine("Graph's matrix of attachment is: ");
            for (int i = 0; i < attachmentMatrix.Length; i++)
            {
                for (int j = 0; j < attachmentMatrix.Length; j++)
                    Console.Write((float.IsNaN(attachmentMatrix[i][j]) ? 0 : attachmentMatrix[i][j]) + " ");
                Console.WriteLine();
            }
        }

        public void PrintDXTR(MyLinkedList[] way, int initVertex)
        {
            for (int i = 0; i < way.Length; i++)
            {
                if (way[i].First == null)
                    continue;
                string sWay = way[i].First.Value.ToString();
                float length = way[i].First.Next == null ? 0 : attachmentMatrix[way[i].First.Value][way[i].First.Next.Value];
                for (Node j = way[i].First.Next; j != null && j.Value != -1; j = j.Next)
                {
                    sWay += ", " + j.Value.ToString();
                    length += j.Next == null ? 0 : attachmentMatrix[j.Value][j.Next.Value];
                }
                Console.WriteLine("The shortest way from " + initVertex + " to " + i + " is " + sWay + "; way length is " + length);
            }
        }

        public MyLinkedList[] DXTR(int vStart)
        {
            MyLinkedList[] way = new MyLinkedList[attachmentMatrix.Length];
            for (int i = 0; i < attachmentMatrix.Length; i++)
                way[i] = new MyLinkedList();

            way[vStart].AddLast(vStart);

            float[] bestLengthes = new float[attachmentMatrix.Length];
            for (int i = 0; i < attachmentMatrix.Length; i++)
                bestLengthes[i] = float.MaxValue;
            bestLengthes[vStart] = 0;

            int[] countOfVisited = new int[attachmentMatrix.Length];
            countOfVisited[vStart] = 1;
 
            bool[] visited = new bool[attachmentMatrix.Length];

            return DXTR(vStart, way, bestLengthes, countOfVisited, visited);
        }

        private MyLinkedList[] DXTR(int vStart, MyLinkedList[] way, float[] bestLengthes, int[] countOfVisited, bool[] visited)
        {
            visited[vStart] = true;

            for (int i = 0; i < this.attachmentMatrix[vStart].Length; i++)
            {
                if (float.IsNaN(this.attachmentMatrix[vStart][i]) && float.IsNaN(this.attachmentMatrix[i][vStart]))
                    continue;

                int v1 = vStart, v2 = i;

                if (float.IsNaN(attachmentMatrix[v1][v2]))
                {
                    v1 = i;
                    v2 = vStart;
                }

                if (bestLengthes[i] > bestLengthes[vStart] + attachmentMatrix[v1][v2])
                {
                    bestLengthes[i] = bestLengthes[vStart] + attachmentMatrix[v1][v2];
                    way[i] = new MyLinkedList(way[vStart]);
                    countOfVisited[i] = countOfVisited[vStart] + 1;
                    way[i].AddLast(i);
                }
            }

            int nextToGo = -1;
            for (int i = 0; i < visited.Length; i++)
                if (!visited[i] && bestLengthes[i] != float.MaxValue && (nextToGo == -1 ? true : bestLengthes[i] < bestLengthes[nextToGo]))
                    nextToGo = i;
            if (nextToGo == -1)
                return way;

            return DXTR(nextToGo, way, bestLengthes, countOfVisited, visited);
        }

        public bool DFS(Graph G, int start, int end, bool[] visited, Queue<int> toVisit)
        {
            visited[start] = true;

            if (start == end)
                return true;

            for (int i = 0; i < G.attachmentMatrix.Length; i++)
                if (!float.IsNaN(G.attachmentMatrix[start][i]) && !visited[i])
                    toVisit.Enqueue(i);

            if (toVisit.Count == 0)
                return false;

            return DFS(G, toVisit.Dequeue(), end, visited, toVisit);           
        }
    }
}
