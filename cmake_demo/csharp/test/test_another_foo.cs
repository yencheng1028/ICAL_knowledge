using System;
using System.IO;

using csdemo;

namespace cstest
{
    class Program
    {
        static void Main(string[] args)
        {
            SomeFoo someFoo = new SomeFoo();

            // Test another_foo()...
            someFoo.another_foo();

            Console.Write("Press any key to continue...");
            Console.ReadKey();
        }
    }
}
