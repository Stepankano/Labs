using System;
using System.Collections.Generic;
using System.IO;

namespace Lab2
{
    class Programm
    {
        static void Main(string[] args)
        {
            Graph_A A = new Graph_A(
                new Graph_B(
                    new Graph_D(5),
                    new Graph_E(6),
                    new Graph_F(7),
                    3
                ),
                new Graph_K(
                    new Graph_J(4),
                    2
                ),
                1
            );

            System.Console.WriteLine($"1 A");
            A.MoveTo('K');
            A.MoveTo('B');
            A.MoveTo('J');
            A.MoveTo('D');
            A.MoveTo('E');
            A.MoveTo('F');

        }

    }
    class Graph_A
    {
        private int Value;
        private Graph_B B = null;
        private Graph_K K = null;

        public Graph_A(Graph_B _B, Graph_K _K, int value)
        {
            Value = value;
            K = _K;
            B = _B;
        }
        ~Graph_A()
        {
        }
        public void MoveTo(char name)
        {
            System.Console.Write($"{Value} => ");
            if (name == 'K' || name == 'J')
            {
                this.K.MoveTo(name);
            }
            else
            {
                this.B.MoveTo(name);
            }

        }
    }
    class Graph_B
    {
        private int Value;
        private Graph_D D = null;
        private Graph_E E = null;

        private Graph_F F = null;

        public Graph_B(Graph_D _D, Graph_E _E, Graph_F _F, int value)
        {
            Value = value;
            E = _E;
            F = _F;
            D = _D;
        }
        ~Graph_B()
        {
        }
        public void MoveTo(char name)
        {
            if (name == 'D')
            {
                System.Console.Write($"{Value} => ");
                this.D.MoveTo(name);
            }
            else if (name == 'E')
            {
                System.Console.Write($"{Value} => ");
                this.E.MoveTo(name);
            }
            else if (name == 'F')
            {
                System.Console.Write($"{Value} => ");
                this.F.MoveTo(name);
            }
            else
            {
                System.Console.WriteLine($"{Value} B");
            }
        }
    }
    class Graph_K
    {
        private int Value;
        private Graph_J J = null;

        public Graph_K(Graph_J _J, int value)
        {
            Value = value;
            J = _J;
        }
        ~Graph_K()
        {
        }
        public void MoveTo(char name)
        {
            if (name == 'K')
            {
                System.Console.WriteLine($"{Value} K");
            }
            else
            {
                System.Console.Write($"{Value} => ");
                this.J.MoveTo(name);
            }
        }
    }
    class Graph_J
    {
        private int Value;

        public Graph_J(int value)
        {
            Value = value;
        }
        ~Graph_J()
        {
        }
        public void MoveTo(char name)
        {
            System.Console.WriteLine($"{Value} J");
        }
    }
    class Graph_D
    {
        private int Value;

        public Graph_D(int value)
        {
            Value = value;
        }
        ~Graph_D()
        {
        }
        public void MoveTo(char name)
        {
            System.Console.WriteLine($"{Value} D");
        }
    }
    class Graph_E
    {
        private int Value;

        public Graph_E(int value)
        {
            Value = value;
        }
        ~Graph_E()
        {
        }
        public void MoveTo(char name)
        {
            System.Console.WriteLine($"{Value} E");
        }
    }
    class Graph_F
    {
        private int Value;

        public Graph_F(int value)
        {
            Value = value;
        }
        ~Graph_F()
        {
        }
        public void MoveTo(char name)
        {
            System.Console.WriteLine($"{Value} F");
        }
    }
}
