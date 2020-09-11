using System;

namespace Lab1
{
    class Program
    {
        static void Main(string[] args)
        {
            new TestClass();
            new TestClass(1,2);
            new TestClass(new TestClass(3,4));

            TestClass a = new TestClass();
            a.F();
            a.F(1,2);
            a.F(a);
            Program b = new Program();
            b.F();
            b.F(1,2);
            b.F(b);
        }
        public void F()
        {
            System.Console.WriteLine($"Function 1\nThis object from {this.ToString()} class\n");
        }
        public void F(int c, int d)
        {
            System.Console.WriteLine($"Function 2\nThis object from {this.ToString()} class\nnew numbers = [{c},{d}]\n");
        }
        public void F(Program copy){
            System.Console.WriteLine($"Function 3\nThis object from {this.ToString()} class");
            System.Console.WriteLine($"New object from {copy.ToString()} class\n");
        }
    }
}