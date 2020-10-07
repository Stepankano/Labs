using System;

namespace Lab6
{
    class Program
    {
        static void Main(string[] args)
        {
            A a0 = new A(3);
            B b0 = new B(8);
            C c1 = new C(1);
            C c2 = new C(2);
            C c3 = new C(3);

            a0.ouput();
            b0.ouput();
            c1.ouput();
            c2.ouput();
            c3.ouput();
            System.Console.WriteLine();

            a0.set_B(b0);
            a0.get_B().ouput();
            b0.get_A().ouput();

            b0.set_C(new[] { c1, c2, c3 });
            b0.get_C(0).ouput();
            b0.get_C(1).ouput();
            b0.get_C(2).ouput();
            System.Console.WriteLine();

            c1.ouput();
            c1.next().ouput();

            c2.prev().ouput();
            c2.ouput();
            c2.next().ouput();

            c3.prev().ouput();
            c3.ouput();

            c1.prev().ouput(); //exeption
            c3.next().ouput(); //exeption

        }
    }
    class S
    {
        public void ouput()
        {
            System.Console.WriteLine($"{this.ToString()} = {value}");
        }
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
        public B get_B() => b;
    }  // 1 A : 1 B
    class B : S
    {
        public B(int b) : base(b) { }
        private A a { get; set; } = null;
        private C[] c_array { get; set; } = null;
        public C get_C(int posit)
        {
            if (posit >= c_array.Length || posit < 0)
            {
                throw new Exception(" Out of array :(");
            }
            return c_array[posit];
        }


        public void set_A(A new_a)
        {
            if (a == null || (a != null && a.GetHashCode() != new_a.GetHashCode()))
            {
                a = new_a;
                a.set_B(this);
            }
            return;
        }
        public void set_C(C[] new_c)
        {
            int size = new_c.Length;
            this.c_array = new C[size];
            for (int i = 0; i < size; i++)
            {
                c_array[i] = new_c[i];
                c_array[i].set_B(this);
                c_array[i].set_pos(i);
            }

        }
        public A get_A() => a;

    } // 1 B : N C ; 1 B : 1 A
    class C : S
    {
        public C(int c) : base(c) { }
        private B b { get; set; } = null;
        private int position = 0;
        public void set_pos(int pos) => position = pos;
        public C next() => b.get_C(position + 1);
        public C prev() => b.get_C(position - 1);

        public void set_B(B new_b) => b = new_b;

        private B get_B() => b;
    }  // N C : 1 B

}
