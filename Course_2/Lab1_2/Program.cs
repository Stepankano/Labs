using System;
using System.Collections.Generic;

namespace Lab1_2
{
    class Program
    {
        static void Main(string[] args)
        {
            Graph A = new Graph<>();
            Graph B = new Graph<>();
            Graph K = new Graph<>();

            A.Add(B);
            A.Add(K);

            Graph J = new Graph<>();
            Graph D = new Graph<>();
            Graph E = new Graph<>();
            Graph F = new Graph<>();

            K.Add(J);
            B.Add(D);
            B.Add(E);
            B.Add(F);
        }
    }

    class Graph
    {
        private List<Graph> Childs;
        public void Add(Graph new_child)
        {
            Childs.Add(new_child);
        }
        public Graph()
        {
            Childs.Clear();
        }
    }
}
