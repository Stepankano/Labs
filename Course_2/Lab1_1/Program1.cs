using System;

namespace Lab1_1
{
    class Program
    {
        static void Main(string[] args)
        {
            NewClass a = new NewClass("aaaa");
            NewClass b = new NewClass("bbbb");
            NewClass c = new NewClass("cccc");

            System.Console.WriteLine(NewClass.Static_return(a));
            NewClass.Static_non_return(a);
            b.Non_static_non_return();
            System.Console.WriteLine(c.Non_static_return());

        }

    }

     class NewClass
    {
        private string Str;
        static public string Static_return(NewClass Str)
        {
            return Str.Str;
        }
        static public void Static_non_return(NewClass Str)
        {
            System.Console.WriteLine(Str.Str);
        }
        public string Non_static_return()
        {
            return Str;
        }
        public void Non_static_non_return()
        {
            System.Console.WriteLine(Str);
        }
        public NewClass(String new_str)
        {
            Str = new string(new_str);
        }
    }
}

