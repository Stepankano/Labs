using System;

namespace Lab9._1
{
    
    class Program
    {
        delegate void Non_return();
    delegate int Int_return();
    delegate Generic Operate<Generic>(Generic value);
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
            Operate<string> oper = STR;
            System.Console.WriteLine(oper("Template delegate"));


            

        }
        public static int one()=>1;

        public static void prent1()=>System.Console.WriteLine("Prent1");
        public static void prent2()=>System.Console.WriteLine("Prent2");
        public static void prent3()=>System.Console.WriteLine("Prent3");
        public static string STR(string str)=>str;
        

    }
}
