using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace NguyenDangKhuong_2175415
{
    class Library
    {
        //Fields
        public List<Magazine> magazineList = new List<Magazine>();

        //Methods
        public void addMagazine(Magazine magazine) //Using object magazine and add magazine into list
        {
            magazineList.Add(magazine);
        }

        //Function had 5 parameter (add magazine into list manually)
        public void addMagazine(string magazineName, string publishedDate, int ID, int prize, string author)
        {
            magazineList.Add(new Magazine(magazineName, publishedDate, ID, prize, author));
        }

        public void addFromFile()
        {
            try
            {
                using (StreamReader file = new StreamReader("Magazine.txt")) //ReadFile
                {
                    while (!file.EndOfStream) //While not end of the file = keep reading until end of file
                    {
                        string line = file.ReadLine();
                        string[] arr = line.Split(',');//Split the string which has separtate by ','(each line) into an array has 5 elements  
                        string magazineName = arr[0]; //the first elements and so on
                        string publishedDate = arr[1];
                        int id = Int32.Parse(arr[2]);
                        int prize = Int32.Parse(arr[3]);
                        string author = arr[4];
                        addMagazine(magazineName, publishedDate, id, prize, author); //ADD magazine into the list
                    }
                }
            }
            catch (Exception e) //If something goes wrong, reported the problem but keep the program running without crashing
            {
                Console.WriteLine("Can't read the file \"Magazine.txt\" ");
                Console.WriteLine(e.Message);
            }
        }

        //OutPut
        public void Output()
        {
            foreach (Magazine magazine in magazineList)//for each item in the list
            {
                Console.WriteLine(magazine); //output to the screen
            }
        }


        public int countTheMagazineNumber()
        {
            int numberOfMagazine = 0;
            for (int i = 0; i < magazineList.Count; i++)
            {
                numberOfMagazine += 1;
            }
            return numberOfMagazine;
        }


        public float calculateTheMagazinePrize()
        {
            float totalMoney = 0;
            int totalOfMagazine = countTheMagazineNumber();
            for (int i = 0; i < magazineList.Count; i++)
            {
                totalMoney = totalMoney + magazineList[i].Prize;
            }
            return totalMoney / totalOfMagazine;
        }


        //Sort by Name and ID
        public void sortByName() //Using interchange sort
        {
            for (int i = 0; i < magazineList.Count; i++)
            {
                for (int j = i + 1; j < magazineList.Count; j++)
                {

                    if (magazineList[i].MagazineName.CompareTo(magazineList[j].MagazineName) > 0)
                    {
                        Magazine temp = magazineList[i];
                        magazineList[i] = magazineList[j];
                        magazineList[j] = temp;
                    }
                }
            }
        }
        public void sortByNameAndID() //also using interchange sort
        {
            for (int i = 0; i < magazineList.Count; i++)
            {
                for (int j = i + 1; j < magazineList.Count; j++)
                {

                    if (magazineList[i].MagazineName.CompareTo(magazineList[j].MagazineName) > 0) //compare 2 object 
                    {
                        Magazine temp = magazineList[i]; //Swap 
                        magazineList[i] = magazineList[j];
                        magazineList[j] = temp;
                    }                                                      //if the object are the same
                    else if (magazineList[i].MagazineName.CompareTo(magazineList[j].MagazineName) == 0)
                    {
                        if (magazineList[i].ID.CompareTo(magazineList[j].ID) < 0) //then compare its ID
                        {
                            Magazine temp2 = magazineList[i]; //swap their position
                            magazineList[i] = magazineList[j];
                            magazineList[j] = temp2;
                        }
                    }
                }
            }
        }

        public string FindUserFavoriteBook(string targetBook)
        {
            for (int i = 0; i < magazineList.Count; i++)
            {
                if (targetBook.CompareTo(magazineList[i].MagazineName) == 0) //Looping thought the hold list, if targetBook founded return its info
                {
                    return magazineList[i].ToString();// return only one book
                }
            }
            return string.Format("I can't find your book, maybe it doesn't belong to the Library\nOr you just enter the wrong name\n");
        }
    }
}
