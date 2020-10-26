using System;

namespace lab4
{
    class Program
    {
        static void Main(string[] args)
        {
            System.Console.WriteLine($"Lab4.A : \nАбстрактный класс А");
            B b = new B();
            System.Console.WriteLine("---------");
            C c = new C();
            System.Console.WriteLine("---------");
            D d = new D();
            System.Console.WriteLine("---------");
            E e = new E();
        }
    }

    abstract class A
    {
        public void A_function()
        {
            System.Console.WriteLine("Class A");
        }
        protected int A_proof_function()
        {
            return 1;
        }
    }
    class B : A
    {
        public B()
        {
            System.Console.WriteLine($"{this.ToString()} : ");
            Call();
        }
        public virtual void Call()
        {
            B_func();
        }
        protected virtual void B_func()
        {
            System.Console.WriteLine("Расширение класса А по функции");
        }
    }
    class C : A
    {
        public C()
        {
            System.Console.WriteLine($"{this.ToString()} : ");
            string Message = "Расширение класса А по полю";
            System.Console.WriteLine(Message);
        }
    }
    class D : B
    {
        public D() : base() { }
        protected override void B_func()
        {
            System.Console.WriteLine("Специализация класса А");
        }
    }
    public interface F
    {
        void value();
    }
    public interface J
    {
        void degree();
    }
    class E : D, F, J
    {
        public E() : base(){}
        public override void Call()
        {
            value();
            degree();
            System.Console.WriteLine($"Комбинирование и спецификация F и J интерфейсов,");
            void_func();
            B_func();
        }
        public void value()
        {
            System.Console.WriteLine("Значение: x");
        }
        public void degree()
        {
            System.Console.WriteLine("Степень: y");
        }
        private void void_func()
        {
            System.Console.WriteLine($"расширение (новый множитель = {multiplier})");
        }
        private int multiplier = 100;
        protected override void B_func()
        {
            System.Console.WriteLine("и специализация");
        }
    }
}