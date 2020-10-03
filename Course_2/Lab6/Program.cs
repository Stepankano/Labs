using System;

namespace Lab6
{
    class Program
    {
        static void Main(string[] args)
        {
            A k = new A(3);
            B h = new B(8);
            k.set_B(h);
            System.Console.WriteLine("888");
        }
    }
    class S
    {
        protected int value { get; set; }
        protected S(int val)
        {
            value = val;
        }
    }
    class A : S
    {
        public A(int a) : base(a) { }
        private B b { get; set; } = null;
        public void set_B(B new_b)
        {
            if (b == null || (b != null && b.GetHashCode() != new_b.GetHashCode()))
            {
                b = new_b;
                b.set_A(this);
            }
            return;
        }
        private B get_B()
        {
            return b;
        }
    }  // 1 A : 1 B
    class B : S
    {
        public B(int b) : base(b) { }
        private A a { get; set; } = null;
        private C[] c_array { get; set; } = null;

        public void set_A(A new_a)
        {
            if (a == null || (a != null && a.GetHashCode() != new_a.GetHashCode()))
            {
                a = new_a;
                a.set_B(this);
            }
            return;
        }
        public void set_C(C[] new_c){
            //TODO 
        }
        private A get_A()
        {
            return a;
        }
    } // 1 B : N C ; 1 B : 1 A
    class C : S
    {
        public C(int c) : base(c) { }
        private B b { get; set; } = null;

        private void set_B(B new_b){
            b = new_b;
        }
        private B get_B()
        {
            return b;
        }
    }  // N C : 1 B

}
