using System;

namespace Lab7
{
    class Program
    {
        static void Main(string[] args)
        {
            Client clnt = new Client(90);
            Server srvr = new Server();
            System.Console.WriteLine($"Server.Value = {srvr.get_b()}");
            System.Console.WriteLine($"Client.Value = {srvr.get_get_value(clnt)}");
        }
    }
    class Client
    {
        public Client(int a) => value = a;

        private int value = 0;
        public int get_value() => value;

    }
    class Server
    {
        public int get_get_value(Client a) => a.get_value();
        private int b = 100;
        public int get_b() => b;
    }


}

