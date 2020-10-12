using System;

namespace Lab7
{
    class Program
    {
        static void Main(string[] args)
        {
            Client clnt = new Client(90);
            Server_non_Static Serv = new Server_non_Static();
            System.Console.WriteLine($"Client.Value = {clnt.get_value()}");
            System.Console.WriteLine($"Server_Static.Value = {clnt.get_value_thro_serv_static()}");
            System.Console.WriteLine($"Server_non_Static.Value = {clnt.get_value_thro_serv(Serv)}");

        }
    }
    class Client
    {
        public Client(int a) => value = a;
        private int value = 0;
        public int get_value() => value;
        public int get_value_thro_serv_static() => Server_Static.get_value(this);
        public int get_value_thro_serv(Server_non_Static serv) => serv.get_value(this);
    }
    static class Server_Static // это что-то типа общности
    {
        static public int get_value(Client a) => a.get_value();
    }
    class Server_non_Static // это сервер из "клиент - сервер"
    {
        public int get_value(Client a) => a.get_value();
    }



}

