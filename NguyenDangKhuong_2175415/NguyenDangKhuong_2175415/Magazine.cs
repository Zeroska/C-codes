using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NguyenDangKhuong_2175415
{
    class Magazine
    {
        //Fields
        string magazineName;
        string publishedDate;
        int id;
        float prize;
        string author;

        //Getter and Setter
        public string MagazineName
        {
            get { return magazineName; }
            set { magazineName = value; }
        }

        public string PublishedDate
        {
            get { return publishedDate; }
            set { publishedDate = value; }
        }

        public int ID
        {
            get { return id; }
            set { id = value; }
        }
        public float Prize
        {
            get { return prize; }
            set { prize = value; }
        }

        public string Author
        {
            get { return author; }
            set { author = value; }
        }

        //Constructor
        public Magazine(string magazineName, string publishedDate, int id, float prize, string author)
        {
            this.magazineName = magazineName;
            this.publishedDate = publishedDate;
            this.id = id;
            this.prize = prize;
            this.author = author;
        }


        public Magazine()
        {
            magazineName = "PlayBoy";
            publishedDate = "2/12/1999";
            id = 217415;
            prize = 690000;
            author = "Hugh Helfer";
        }


        public void Input()
        {
            Console.WriteLine("Enter magazine name: ");
            magazineName = Console.ReadLine();
            Console.WriteLine("Enter the published date (DD/MM/YYYY): ");
            publishedDate = Console.ReadLine();
            Console.WriteLine("Enter your magazine ID (7 digits): ");
            id = Int32.Parse(Console.ReadLine());
            Console.WriteLine("Enter magazine's prize: ");
            prize = float.Parse(Console.ReadLine());
            Console.WriteLine("Enter your author name: ");
            author = Console.ReadLine();
        }


        public static void PrintHeader()
        {
            Console.WriteLine("|{0, -20} |{1,-15} |{2,8} |{3,10} |{4,-20}", "Magazine Name", "Publised Date", "ID", "Prize", "Author");
            Console.WriteLine("----------------------------------------------------------------------------");
        }

        public static void PrintFooter(int numberOfMagazine, float AvgPrize)
        {
            Console.WriteLine("\nThe total number of Magazine: {0}", numberOfMagazine);
            Console.WriteLine("The average prize of magazine: {0}\n", AvgPrize);
        }


        public override string ToString()
        {
            return string.Format($"|{magazineName,-20} |{publishedDate,-15} |{id,8} |{prize,10} |{author,-20}");
        }

        public void Output()
        {
            PrintHeader();
            Console.WriteLine(ToString());
        }
    }
}
