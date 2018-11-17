using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace NguyenDangKhuong_2175415
{
    class Program
    {
        static void Main(string[] args)
        {
            Library library = new Library();
            Magazine magazineMain = new Magazine();
            Menu menu = new Menu("Big Assignment");
            library.addFromFile();
            int TotalMagazine = library.countTheMagazineNumber();
            float AvgPrize = library.calculateTheMagazinePrize();
            while (true)
            {
                Console.Clear();
                menu.display();
                int option = menu.GetChoice();
                switch (option)
                {
                    case 0:
                        {
                            Menu.SayBye();
                            return;
                        }
                    case 1:
                        {
                            Console.WriteLine("HERE IS YOUR LIST.");
                            library.Output();
                            Magazine.PrintFooter(TotalMagazine, AvgPrize);
                            break;
                        }
                    case 2:
                        {
                            Console.WriteLine("HERE IS YOUR SORTED LIST.");
                            library.sortByName();
                            library.Output();
                            break;
                        }
                    case 3:
                        {
                            Console.WriteLine("HERE IS YOUR SORTED LIST");
                            library.sortByNameAndID();
                            library.Output();
                            break;
                        }
                    case 4:
                        {
                            Console.Write("What is your favorite book: ");
                            string userFavoriteBook = Console.ReadLine();
                            string found = library.FindUserFavoriteBook(userFavoriteBook);
                            Console.WriteLine("{0}", found);
                            break;
                        }
                    case 5:
                        {
                            Console.WriteLine("Look at the title, cool huh??.");
                            const int maxProgressBarLength = 60; //
                            const string progressBarElement = "█";

                            var title = "";// empty string for the title , var is implicitly (meaning: khong tuong minh)
                            int loop = 60; //Loop 60 times equal to the bar lenght
                            do
                            {
                                loop--;// subtract Loop value 
                                title += progressBarElement; //append bar element to the empty title

                                if (title.Length > maxProgressBarLength) //append until the lenght of the title > 60 then stop title = 60
                                {
                                    title = progressBarElement; // title = 60 words long
                                }

                                Console.Title = title; //every time adding a bar element into the console title

                                Thread.Sleep(50); // Control the speed 
                            } while (loop != 0);// end when loop = 0, loop 60 times and it will auto stop (speed milisecond) 
                            break;
                        }
                }
                //Delay
                Menu.Delay();
            }
        }

    }
}
