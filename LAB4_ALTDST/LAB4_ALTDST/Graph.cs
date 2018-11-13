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

            countOfEdges--;
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

        public void PrintDXTR(int[][] way, int initVertex)
        {
            for (int i = 0; i < way.Length; i++)
            {
                string sWay = way[i][0].ToString();
                float length = 0;   

                for (int j = 1; j < way[i].Length && way[i][j] != -1; j++)
                {
                    sWay += ", " + way[i][j];
                    length += attachmentMatrix[way[i][j - 1]][way[i][j]];
                }
                Console.WriteLine("The shortest way from " + initVertex + " to " + i + " is " + sWay + "; way length is " + length);
            }
        }

        public int[][] DXTR(int vStart)
        {
            int[][] way = new int[attachmentMatrix.Length][];
            for (int i = 0; i < attachmentMatrix.Length; i++)
            {
                way[i] = new int[attachmentMatrix.Length];
                for (int j = 0; j < attachmentMatrix.Length; j++)
                    way[i][j] = -1;
            }
            way[vStart][0] = vStart;

            float[] bestLengthes = new float[attachmentMatrix.Length];
            for (int i = 0; i < attachmentMatrix.Length; i++)
                bestLengthes[i] = float.MaxValue;
            bestLengthes[vStart] = 0;

            int[] countOfVisited = new int[attachmentMatrix.Length];
            countOfVisited[vStart] = 1;
 
            bool[] visited = new bool[attachmentMatrix.Length];

            return DXTR(vStart, way, bestLengthes, countOfVisited, visited);
        }

        private int[][] DXTR(int vStart, int[][] way, float[] bestLengthes, int[] countOfVisited, bool[] visited)
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
                    Array.Copy(way[vStart], way[i], way[vStart].Length);
                    countOfVisited[i] = countOfVisited[vStart] + 1;
                    way[i][countOfVisited[i] - 1] = i;
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

        public Graph Crusckall()
        {
            Graph MinSpanningTree = new Graph(countOfVertexes);
            Edge[] G_Edges = new Edge[countOfEdges];

            int G_countOfEdges = 0;
            for (int i = 0; i < attachmentMatrix.Length; i++)
                for (int j = i; j < attachmentMatrix.Length; j++)
                    if (!float.IsNaN(attachmentMatrix[i][j]))
                        G_Edges[G_countOfEdges++] = new Edge(i, j, attachmentMatrix[i][j]);

            Array.Sort(G_Edges);

            foreach(Edge i in G_Edges)
                if(!MinSpanningTree.DFS(i.Vertex1, i.Vertex2))
                    MinSpanningTree.addAttachment(i.Vertex1, i.Vertex2, i.Weight);

            return MinSpanningTree;
        }

        public bool BFS(int start, int end)
        {
            return BFS(start, end, new bool[attachmentMatrix.Length], new Queue<int>());
        }

        private bool BFS(int start, int end, bool[] visited, Queue<int> toVisit)
        {
            visited[start] = true;

            if (start == end)
                return true;

            for (int i = 0; i < attachmentMatrix.Length; i++)
                if (!float.IsNaN(attachmentMatrix[start][i]) && !visited[i])
                    toVisit.Enqueue(i);

            if (toVisit.Count == 0)
                return false;

            return BFS(toVisit.Dequeue(), end, visited, toVisit);           
        }

        public bool DFS(int start, int end)
        {
            return DFS(start, end, new bool[attachmentMatrix.Length]);
        }

        private bool DFS(int start, int end, bool[] visited)
        {
            visited[start] = true;

            if (start == end)
                return true;

            for (int i = 0; i < attachmentMatrix.Length; i++)
                if (!float.IsNaN(attachmentMatrix[start][i]) && !visited[i])
                    if (DFS(i, end, visited))
                        return true;

            return false;
        }

        public int[][] getAttachedCouples()
        {
            int[][] result = new int[attachmentMatrix.Length][];
            int[] counts = new int[attachmentMatrix.Length];

            for (int i = 0; i < attachmentMatrix.Length; i++)
            {
                result[i] = new int[attachmentMatrix.Length];
                int[] temp = getAttachedCouples(i, new bool[attachmentMatrix.Length], new int[attachmentMatrix.Length], 0);
                Array.Copy(temp, 0, result[i], counts[i], temp.Length);
                counts[i] += temp.Length;
            }

            return result;
        }

        private int[] getAttachedCouples(int start, bool[] visited, int[] result, int last)
        {
            visited[start] = true;

            for(int i = 0; i < attachmentMatrix.Length; i++)
                if (!float.IsNaN(attachmentMatrix[start][i]) && !visited[i])
                {
                    result[last++] = i;
                    getAttachedCouples(i, visited, result, last);
                }

            return result;
        }

        public int getCountOfconnectedComponents()
        {
            int result = 0;
            bool[] visited = new bool[attachmentMatrix.Length];

            for(int i = 0; i < attachmentMatrix.Length; i++)
                if (!visited[i])
                {
                    result++;
                    DFSEach(i, visited);
                }

            return result;
        }

        private void DFSEach(int start, bool[] visited)
        {
            visited[start] = true;

            for (int i = 0; i < attachmentMatrix.Length; i++)
                if (!float.IsNaN(attachmentMatrix[start][i]) && !visited[i])
                    DFSEach(i, visited);
        }
    }
}
