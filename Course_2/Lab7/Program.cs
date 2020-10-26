using System;

namespace Lab7
{
    class Program
    {
        static void Main(string[] args)
        {
            Client clnt = new Client(94);
            Server_non_Static Serv = new Server_non_Static();
            System.Console.WriteLine($"Client.Value = {clnt.get_value()}");
            System.Console.WriteLine($"Server_Static.Value = {clnt.get_value_thro_serv_static()}");
            System.Console.WriteLine($"Server_non_Static.Value = {clnt.get_value_thro_serv(Serv)}");
            System.Console.WriteLine($"Server = {clnt.get_value_server()}");

        }
    }
    class Client
    {
        private Server srv = new Server();
        public Client(int a) => value = a;
        private int value = 0;
        public int get_value() => value;
        public int get_value_thro_serv_static() => Server_Static.get_value(this);
        public int get_value_thro_serv(Server_non_Static serv) => serv.get_value(this);
        public int get_value_server()=>srv.get_val(value);
    }
    static class Server_Static // это что-то типа общности
    {
        static public int get_value(Client a) => a.get_value();
    }
    class Server_non_Static // это сервер из "клиент - серверис"
    {
        public int get_value(Client a) => a.get_value();
    }
    class Server{
        private int[] value = new int[]{0,1,2,3,4,5,6,7,8,9};
        public int get_val(int i)=>value[i%10];
    }



}

