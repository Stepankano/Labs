using System;

namespace Lab5
{
    class Program
    {
        static void Main(string[] args)
        {
            B b = new B();
            D d = new D();
            
            b.func_1();
            d.func_1();
            d.func_2();
        }
    }
    interface A
    {
        void func_1();
    }
    class B : A
    {
        public virtual void func_1()
        {
            System.Console.WriteLine("Func_1");
        }
    }
    interface C : A
    {
        void func_2();
    }
    class D : B, C
    {
        public override void func_1()
        {
            System.Console.Write("That`s override ");
            base.func_1();
        }
        public void func_2(){
            System.Console.WriteLine("Func_2");
        } 
    }
}
