using System;
using System.Collections.Generic;

namespace Lab9._2_3
{
    class Program
    {
        delegate void non_return(int f);
        delegate int int_return();
        static void Main(string[] args)
        {
            /// 9.2
            non_return lambdaNR = (int f) => System.Console.WriteLine(f);
            int_return lambdaIR = () => 2;
            lambdaNR(2);
            System.Console.WriteLine(lambdaIR());

            /// 9.3
            System.Console.WriteLine("-----------------");
            Publisher BBC = new Publisher("BBC");
            Subscriber tv1 = new Subscriber("CNN"); 
            Subscriber tv2 = new Subscriber("Chanel");
            Subscriber tv3 = new Subscriber("UYU-tv");
            BBC.Notify+=tv1.Like;
            BBC.Notify+=tv2.Like;
            BBC.Notify+=tv3.Like;
            BBC.NewContent("Serial about animals");

        }
        class Publisher{
            public delegate void Publ(string message);
            public event Publ Notify;
            public Publisher(string nname)=>name = nname;
            private string name = "";
            public void NewContent(string Content){
                System.Console.WriteLine(name + " release: "+ Content);
                Notify?.Invoke(Content);
            }
        }
        class Subscriber{
            private string name = "";
            public Subscriber(string nname)=>name = nname;
            public void Like(string content){
                System.Console.WriteLine(name+ " like: "+ content);
            }
        }
        
    }
}
