using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NguyenDangKhuong_2175415
{
    class Menu
    {
        //Fields
        string name;

        //Constructor
        public Menu(string name)
        {
            this.name = name;
        }

        public void display()
        {
            Console.WriteLine("\t\t-------HOA SEN UNIVERSITY-------");
            Console.WriteLine("\tBig Assignment -- Student: Nguyen Dang Khuong, ID: 2175415.");
            Console.WriteLine("|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
            Console.WriteLine("|1.Look at the list of Magazine.                                     |");
            Console.WriteLine("|2.Sort by magazine's name.                                          |");
            Console.WriteLine("|3.Sort by magazine's ID and name.(ID decreasing)                    |");
            Console.WriteLine("|4.Find your favorite magazine.                                      |");
            Console.WriteLine("|5.Something I found on the Internet.                                |");
            Console.WriteLine("|0.Exit the program.                                                 |");
            Console.WriteLine("|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
            Console.Write("\tYour choice: ");
        }

        public int GetChoice()
        {
            int choice;
            choice = Int32.Parse(Console.ReadLine());
            return choice;
        }

        public static void SayBye()
        {
            Console.WriteLine("Bye!! I hope seeing you again...");
            Console.WriteLine("Press any key to exit");
            Console.ReadKey();
        }
        public static void Delay()
        {
            Console.WriteLine("Press any key to continue ...");
            Console.ReadKey();
        }
    }
}
