using System;
using System.Collections.Generic;
using System.IO;

namespace Lab2
{
    class Programm
    {
        static void Main(string[] args)
        {
            ///// begin of monster
            Graph A = new Graph(
                0, //a
               new Graph[2]{
                new Graph(
                    1, //k
                   new Graph[1]{
                       new Graph(
                           3, //j
                           new Graph[0]{})}
                ),
                new Graph(
                    2, //b
                    new Graph[3]{
                        new Graph(
                            4, //d
                            new Graph[0]{}),
                        new Graph(
                            5, //e
                            new Graph[0]{}),
                        new Graph(
                            6, //f
                            new Graph[0]{})
                    }
                )
               }
            );
            ///// end of monster
            System.Console.WriteLine($"1 A");
            for (int i = 1; i < 7; i++)
            {
                A.MoveTo(i, new char[7] { 'A', 'K', 'B', 'J', 'D', 'E', 'F' });
            }
        }

    }

    class Graph
    {
        private int Value;
        private List<Graph> Childs;
        public void Add(Graph new_child)
        {
            Childs.Add(new_child);
        }
        public void Add(Graph[] new_child)
        {
            foreach (var item in new_child)
            {
                Childs.Add(item);
            }
        }
        public Graph(int value)
        {
            Childs = new List<Graph>();
            Value = value;
        }
        public Graph(int value, Graph[] new_childs)
        {
            Childs = new List<Graph>();
            Value = value;
            this.Add(new_childs);
        }
        public void MoveTo(int i, char[] ch)
        {

            System.Console.Write($"{this.Value + 1} => ");
            foreach (Graph k in Childs)
            {
                if (k.Value == i)
                {
                    System.Console.WriteLine($"{k.Value + 1} {ch[i]}");
                    return;
                }
                foreach (Graph h in k.Childs)
                {
                    if (h.Value == i)
                    {
                        System.Console.WriteLine($"{k.Value + 1} => {h.Value + 1} {ch[i]}");
                        return;
                    }
                }
            }

        }
    }

}
