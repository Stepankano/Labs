using System;

namespace Lab4
{
    class Program
    {
        static void Main(string[] args)
        {
            System.Console.WriteLine($"Lab4.A : \nЭто абстрактный класс");
            B b = new B();
            K k = new K();
            D d = new D();
            F f = new F();
        }
    }

    abstract class A
    {

        public void A_func()
        {
            System.Console.WriteLine("Afunc");
        }
        protected int A_int_func()
        {
            return 1;
        }
    }
    class B : A
    {
        public B()
        {
            System.Console.WriteLine($"{this.ToString()} : ");
            B_func();

        }
        protected virtual void B_func()
        {
            System.Console.WriteLine("Это расширение по функции");
        }
    }
    class K : A
    {
        public K()
        {
            System.Console.WriteLine($"{this.ToString()} : ");
            str = "Это расширение по полю";
            System.Console.WriteLine(str);
        }
        private string str = null;
    }
    class D : B
    {
        public D() : base() { }
        protected override void B_func()
        {
            System.Console.WriteLine("Это специализация");
        }
    }
    public interface J
    {
        void begin();
    }
    public interface E
    {
        void of_phrase();
    }
    class F : D, J, E   // ко всему классу применено всё и сразу (конструирование)
    {
        public F()
        {
            System.Console.WriteLine($"{this.ToString()} : ");
            begin();
            of_phrase();
            System.Console.WriteLine($"Это комбинирование и спецификация J и E интерфейсов");
            void_func();
            B_func();
        }
        protected override void B_func()
        {
            System.Console.WriteLine("И специализация тоже");
        }
        public void begin()
        {
            System.Console.Write("\"Начало "); //это спецификация
        }
        public void of_phrase()
        {
            System.Console.WriteLine("фразы\""); //тоже спецификация
        }
        private int new_value = 12; // это расширение по полю
        private void void_func()
        {
            System.Console.WriteLine($"И расширение (value = {new_value})");
        } // это расширение по функции
    }
}
