using System;

namespace Lab1
{
    class TestClass
    {
        private int a;
        public int b;

        public TestClass()
        {
            System.Console.WriteLine("Default construct");
            this.a = 0;
            this.b = 0;
        }
        public TestClass(int c, int d)
        {
            this.a = c;
            this.b = d;
            System.Console.WriteLine("Usually construct");
        }
        public TestClass(TestClass origin)
        {
            this.a = origin.a;
            this.b = origin.b;
            System.Console.WriteLine("Copy construct");
        }
        public void F()
        {
            System.Console.WriteLine($"Function 1\nThis object from {this.ToString()} class\na = {this.a}\nb = {this.b}\n");
        }
        public void F(int c, int d)
        {
            System.Console.WriteLine($"Function 2\nThis object from {this.ToString()} class\na = {this.a}\nb = {this.b}\nnew numbers = [{c},{d}]\n");
        }
        public void F(TestClass copy){
            System.Console.WriteLine($"Function 3\nThis object from {this.ToString()} class\na = {this.a}\nb = {this.b}\n");
            System.Console.WriteLine($"New object from {copy.ToString()} class\na = {copy.a}\nb = {copy.b}\n");
        }
    }

}