using DualInterfaceDllLib;
using System;

namespace DualInterfaceNetClient
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            CustomListClass cl = new CustomListClass();

            ICustomList list = cl as ICustomList;

            Console.WriteLine("Add 3 elements");

            list.Add(25);
            list.Add(26);
            list.Add(27);

            Console.WriteLine("The sum is " + list.Sum);

            Console.WriteLine("Set 0-th element");

            list.At[0] = 28;

            Console.WriteLine("The sum is " + list.Sum);

            Console.WriteLine("Iterate");

            Console.WriteLine("The size is " + list.Count);

            for (uint i = 0; i < list.Count; i++)
            {
                Console.WriteLine("\tItem at position " + i + " is " + list.At[i]);
            }

            Console.WriteLine("Remove 3 elements");

            list.Remove(28);
            list.Remove(26);
            list.Remove(27);

            Console.WriteLine("The size is " + list.Count);
            Console.WriteLine("The sum is " + list.Sum);
        }
    }
}
