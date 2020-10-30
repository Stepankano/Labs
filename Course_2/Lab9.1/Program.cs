using System;

namespace Lab9._1
{
    
    class Program
    {
        delegate void Non_return();
    delegate int Int_return();
    delegate void Action<T>(T value);
    delegate T Func<T>(T value);
        static void Main(string[] args)
        {
            ///// 1
            Non_return NR = prent1;
            Int_return IR = one;
            NR();
            System.Console.WriteLine(IR());
            ///// 2
            NR+=prent2;
            NR+=prent3;
            NR();
            ///// 3
            NR = delegate(){
                System.Console.WriteLine("Anonimus - delegatus");
            };
            NR();
            ///// 4
            Func<string> oper = STR;
            System.Console.WriteLine(oper("Template delegate"));
            Action<string> act = Integer<string>;
            act("String, again");
        }
        public static int one()=>1;

        public static void prent1()=>System.Console.WriteLine("Prent1");
        public static void prent2()=>System.Console.WriteLine("Prent2");
        public static void prent3()=>System.Console.WriteLine("Prent3");
        public static string STR(string str)=>str;
        public static void Integer<T>(T val)=>System.Console.WriteLine(val.ToString());
    }
}
