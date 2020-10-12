using System;

namespace Lab8
{
    class Program
    {
        static void Main(string[] args)
        {
            Template<int> intr = new Template<int>(100);
            Template<string> str = new Template<string>("string");
            Template<Template<int>> TT = new Template<Template<int>>(intr);
            intr.print_value();
            str.print_value();
            TT.print_value();
            int int1 = 1, int2 = 2;
            System.Console.WriteLine($"int1 = {int1}, int 2 = {int2}");
            Template<int>.swap(ref int1,ref int2);
            System.Console.WriteLine($"int1 = {int1}, int 2 = {int2}");
        }
    }
    class Template<T>
    {
        private T value;
        public Template(T arg)
        {
            value = arg;
            if (arg is int)
            {
                System.Console.WriteLine("New int object!");
                return;
            }
            if (arg is string)
            {
                System.Console.WriteLine("New string object!");
                return;
            }
            if (arg is Template<int>)
            {
                System.Console.WriteLine("New Template<int> object!");
                return;
            }
            else
            {
                System.Console.WriteLine("I dont know what is it");
            }
        }
        public void print_value() =>
            System.Console.WriteLine($"{this.ToString()} = {this.value}");
        public static void swap(ref T frst, ref T scnd)
        {
            T third = frst;
            frst = scnd;
            scnd = third;
            System.Console.WriteLine("Swap!");
        }

    }
}
