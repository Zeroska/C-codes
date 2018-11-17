#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define HO_MAX 30
#define TEN_MAX 10

typedef struct
{
	int mssv;
	float toan, ly, hoa, diemtb;
	char ho[HO_MAX];
	char ten[TEN_MAX];

}SINHVIEN;


typedef struct NODE
{
	SINHVIEN info;
	NODE* next;

}NODE;


typedef struct
{
	NODE* head;
}LIST;


		//---------------PROTOTYPEs------------------
void initialize(LIST &list);
bool isListEmpty(LIST list);
NODE* createNode(SINHVIEN sinhvien);
NODE* insertHead(LIST &list, SINHVIEN sinhvien);
NODE* insertLast(LIST &list, SINHVIEN sinhvien, NODE* q);
void nhapDSLK(LIST &list, int &n);
void timSVCoDiemToanBeHon8(LIST list);
void tinhDiemTBCuaSinhVien(LIST list);
int demSinhVienCodiemTBLonHon7(LIST list);
NODE* timSVCoDiemLyCaoNhat(LIST list);
NODE* timSVCoDiemHoaThapNhat(LIST list);
void interchangeSort_SapxepTheoTen(LIST &list);
void xuatFile(char* fileOutput, LIST list);
void interchangeSort_SapxeptheoMSSV(LIST &list);
void hoanvi(LIST list, SINHVIEN &a, SINHVIEN &b);
void printMainMenu();
void xuatDanhSachSVCoDiemTB(LIST list);
int timThongTinSVTheoTen(LIST list, char ten[]);
void xuatFile(char* fileOutput, LIST list);
void makeUserInputFreely(char string[]);
void outputWhenFoundTheName(int foundedOrNot);
void askForThePath();
void themSVTheoThuTuMSSV(LIST &list);


		//------------------MAIN---------------------
int main()
{
	LIST list;
	char fileoutput[50];
	int option, sinhvien = 0;
	char ten[TEN_MAX];
	nhapDSLK(list, sinhvien);
	tinhDiemTBCuaSinhVien(list);
	do {
		/*---------------MAIN MENU--------------*/
		printMainMenu();
		scanf("%d",&option);
		switch (option)
		{
		case 1:
		{
			timSVCoDiemToanBeHon8(list);
			break;
		}
		case 2:
		{
			xuatDanhSachSVCoDiemTB(list);
			break;
		}
		case 3:
		{
			int soSinhVienCoDiemTBLonHon7 = demSinhVienCodiemTBLonHon7(list);
			printf("Tong so sinh vien co diem lon hon 7: %d\n\n", soSinhVienCoDiemTBLonHon7);
			break;
		}
		case 4:
		{
			printf("Sinh vien co diem Ly cao nhat la:\n");
			NODE* sinhvien = timSVCoDiemLyCaoNhat(list);
			printf("MSSV: %d,   Toan: %.2f,   Ly: %.2f,   Hoa: %.2f,   Ho: %20s,   Ten: %10s.\n", sinhvien->info.mssv, sinhvien->info.toan, sinhvien->info.ly, sinhvien->info.hoa, sinhvien->info.ho, sinhvien->info.ten);
			break;
		}
		case 5:
		{
			printf("Sinh vien co diem Hoa thap nhat la:\n");
			NODE* sinhvien2 = timSVCoDiemHoaThapNhat(list);
			printf("MSSV: %d,   Toan: %.2f,   Ly: %.2f,   Hoa: %.2f,   Ho: %20s,   Ten: %10s.\n", sinhvien2->info.mssv, sinhvien2->info.toan, sinhvien2->info.ly, sinhvien2->info.hoa, sinhvien2->info.ho, sinhvien2->info.ten);
			break;
		}
		case 6:
		{
			interchangeSort_SapxeptheoMSSV(list);
			printf("---Da sap xep theo MSSV---\n\n");
			break;
		}
		case 7:
		{
			interchangeSort_SapxepTheoTen(list);
			printf("---Da sap xe theo ten---\n\n");
			break;
		}
		case 8:
		{
			printf("Nhap ten sinh vien can tim: ");
			while (getchar() != '\n');
			gets_s(ten);
			makeUserInputFreely(ten);
			int timTen = timThongTinSVTheoTen(list, ten);
			outputWhenFoundTheName(timTen);
			break;
		}
		case 9:
		{
			
			break;
		}
		case 10:
		{
			themSVTheoThuTuMSSV(list);
			break;
		}
		case 11:
		{
			askForThePath();
			while (getchar() != '\n');
			gets_s(fileoutput);
			xuatFile(fileoutput, list);
			break;
		}
		}
	} while (option != 12);
	{
		printf("GoodBye\n");
	}
	_getch();
}
		//---------------FUNCTIONs-------------------
void printMainMenu()
{
	printf("-----------------------------MAIN MENU------------------------|");
	printf("\n1.Tim sinh vien co diem toan be hon 8.                        |");
	printf("\n2.Xuat danh sach co diem TB.                                  |");
	printf("\n3.Dem sinh vien co diem TB lon hon 7.                         |");
	printf("\n4.Tim sinh vien co diem Ly cao nhat.                          |");
	printf("\n5.Tim sinh vien co diem hoa thap nhat.                        |");
	printf("\n6.Sap xep theo MSSV (ma so sinh vien).                        |");
	printf("\n7.Sap xep theo Ten.                                           |");
	printf("\n8.Tim thong tinh sinh vien theo Ten.                          |");
	printf("\n9.Xoa sinh vien theo MSSV.                                    |");
	printf("\n10.Them sinh vien theo MSSV.                                  |");
	printf("\n11.Xuat file.                                                 |");
	printf("\n12.Thoat khoi chuong trinh.                                   |");
	printf("\n--------------------------------------------------------------|");
	printf("\n\nLua chon cua ban : ");
}


void initialize(LIST &list)
{
	list.head = NULL;
}


bool isListEmpty(LIST list)
{
	if (list.head == NULL)
	{
		return true;
	}
	return false;
}


NODE* createNode (SINHVIEN sinhvien)
{
	NODE* p = new NODE;
	if (p != NULL)
	{
		p->info = sinhvien;
		p->next = NULL;
	}
	return p;
}


NODE* insertHead(LIST &list, SINHVIEN sinhvien)
{
	NODE* p = createNode(sinhvien);
	if (p != NULL)
	{
		p->next = list.head;
		list.head = p;
	}
	return p;
}


NODE* insertLast(LIST &list, SINHVIEN sinhvien, NODE* q)
{
	NODE* p = createNode(sinhvien);
	if (list.head == NULL)
	{
		insertHead(list, sinhvien);
	}
	else
	{
		q = list.head; 
		while (q->next != NULL)
		{
			q = q->next;
		}
		q->next = p; //linked
	}
	return p;
}


void nhapDSLK(LIST &list, int &n)
{
	FILE* file = fopen("inputDSLK.txt", "rt");
	if (file == NULL)
	{
		printf("Khong the mo duoc file inputDLSK.txt");
	}
	else
	{
		initialize(list);
		fscanf(file, "%d", &n);
		SINHVIEN sinhvien;
		fscanf(file, "%d", &sinhvien.mssv);
		fscanf(file, "%f", &sinhvien.toan);
		fscanf(file, "%f", &sinhvien.ly);
		fscanf(file, "%f", &sinhvien.hoa);
		fscanf(file, "%s", &sinhvien.ho);
		fscanf(file, "%s", &sinhvien.ten);
		insertHead(list, sinhvien);
		NODE* p = list.head;
		for (int i = 0; i < n - 1; i++)
		{
			fscanf(file, "%d", &sinhvien.mssv);
			fscanf(file, "%f", &sinhvien.toan);
			fscanf(file, "%f", &sinhvien.ly);
			fscanf(file, "%f", &sinhvien.hoa);
			fscanf(file, "%s", &sinhvien.ho);
			fscanf(file, "%s", &sinhvien.ten);
			insertLast(list, sinhvien, p);
			p = p->next;
		}
		fclose(file);
	}
}


void timSVCoDiemToanBeHon8(LIST list)
{
	NODE* p = list.head;
	if (p == NULL)
	{
		printf("Khong tim thay du lieu");
	}
	else
	{
		while (p != NULL)
		{
			if (p->info.toan < 8)
			{ 
				printf("MSSV: %d,   Toan: %.2f,   Ly: %.2f,   Hoa: %.2f,   Ho: %20s,   Ten: %10s.\n",p->info.mssv,p->info.toan,p->info.ly,p->info.hoa,p->info.ho,p->info.ten);
			}
			p = p->next;
		}
	}
}


void tinhDiemTBCuaSinhVien(LIST list)
{
	NODE* p = list.head;
	while (p != NULL)
	{
		p->info.diemtb = (p->info.hoa + p->info.ly + p->info.toan) / 3;
		p = p->next;
	}
}


void xuatDanhSachSVCoDiemTB(LIST list)
{
	NODE* p = list.head;
	while (p != NULL)
	{
		printf("MSSV:%d  Toan:%.2f  Ly:%.2f  Hoa:%.2f  Ho:%20s   Ten:%10s  TB:%.2f\n", p->info.mssv, p->info.toan, p->info.ly, p->info.hoa, p->info.ho, p->info.ten,p->info.diemtb);
		p = p->next;
	}
}


int demSinhVienCodiemTBLonHon7(LIST list)
{
	NODE* p = list.head;
	int count = 0;
	while (p != NULL)
	{	
		if (p->info.diemtb > 7)
		{
			count += 1;
		}
		p = p->next;
	}
	return count;
}


NODE* timSVCoDiemLyCaoNhat(LIST list)
{
	NODE* p = list.head;
	while(p->next!= NULL)
	{
		NODE* q = p->next;
		while (q != NULL)
		{
			if (q->info.ly < p->info.ly)
			{
				hoanvi(list, q->info, p->info);
			}
			q = q->next;
		}
		p = p->next;
	}
	return p;
}


NODE* timSVCoDiemHoaThapNhat(LIST list)
{
	NODE* p = list.head;
	while (p->next != NULL)
	{
		NODE* q = p->next;
		while (q != NULL)
		{
			if (q->info.hoa > p->info.hoa)
			{
				hoanvi(list, q->info, p->info);
			}
			q = q->next;
		}
		p = p->next;
	}
	return p;
}


void hoanvi(LIST list, SINHVIEN &a, SINHVIEN &b)
{
	SINHVIEN temp = a;
	a = b;
	b = temp;
}


void interchangeSort_SapxeptheoMSSV(LIST &list)
{
	NODE* p = list.head;	
	
	while (p->next != NULL)
	{
		NODE* q = p->next;
		while (q != NULL)
		{
			if (p->info.mssv > q->info.mssv)
			{
				hoanvi(list, p->info, q->info);
			}
			q = q->next;
		}
		p = p->next;
	}
}


void xuatFile(char* fileOutput, LIST list)
{
	FILE* file = fopen(fileOutput, "wt");
	if (file == NULL)
	{
		printf("Khong the mo file.");
	}
	else
	{
		NODE* p = list.head;
		while (p != NULL)
		{
			fprintf(file, "MSSV : %d,  Toan : %.2f,  Ly : %.2f,   Hoa : %.2f,   TB : %.2f\n"
					,p->info.mssv,p->info.toan,p->info.ly,p->info.hoa,p->info.diemtb);
			p = p->next;
		}
		fclose(file);
	}
}


void interchangeSort_SapxepTheoTen(LIST &list)
{
	NODE* p = list.head;
	
	while (p->next != NULL) // Next isn't NULL
	{
		NODE* q = p->next; 
		while (q != NULL)
		{
			if (strcmp(p->info.ten, q->info.ten) > 0)
			{
				hoanvi(list, q->info, p->info);
			}
			q = q->next;
		}
		p = p->next;
	}
}


int timThongTinSVTheoTen(LIST list, char ten[])
{
	NODE* p = list.head;
	int ans = -1;  //Set the base ans = -1;
	while (p != NULL)
	{
		if (strcmp(p->info.ten, ten) == 0) //if name == name => ans = 1.
		{
			ans = 1;
		}
		p = p->next;
	}
	return ans;
}


bool deleteHead(LIST &list)
{
	if (!isListEmpty(list))//check whether the list is empty or not. 
	{
		NODE* p = list.head;//If list == FULL.
		p = p->next;
		delete p; //delete the first Node.
		return true;	
	}
	return false;
}


NODE* search2(LIST list, SINHVIEN sinhvien,NODE* &q)
{
	NODE* p = list.head;
	while (p != NULL)
	{
		if (p->info.mssv == sinhvien.mssv )
		{
			break;
		}
		p = q;
		p = p->next;
	}
	return p;
}


bool deleteAfter(LIST &list, NODE* q )
{
	if (q != NULL)
	{
		NODE* p = q->next;
		if (p != NULL)
		{
			q->next = p->next;
			delete p;
			return true;
		}
	}
	return false;
}


bool deleteNode(LIST &list, SINHVIEN sinhvien)
{
	NODE* q = NULL;
	NODE* p = search2(list, sinhvien, q);
	if (p == NULL)
	{
		return false;
	}
	if (q == NULL)
	{
		return deleteHead(list);
	}
	else
	{
		return deleteAfter(list, q);
	}
}


void makeUserInputFreely(char string[])
{
	int L = strlen(string);//The lenght of the string
	string[0] = toupper(string[0]); //Upper case the first letter 
	for (int i = 1; i < L; i++)
	{
		string[i] = tolower(string[i]);//Lower case the rest of the string.
	}
}


void outputWhenFoundTheName(int foundedOrNot)
{
	if (foundedOrNot == 1)
	{
		printf("Found one bois.");
	}
	printf("I don't know this person");
}


void askForThePath()
{
	printf("Ban muon xuat file o dau: ");
}


SINHVIEN themSinhVien()
{
	SINHVIEN sv;
	sv.mssv = 215;
	strcpy(sv.ho, "NguyenHuy");
	strcpy(sv.ten, "Hoang");
	sv.toan = 7.6;
	sv.hoa = 8.2;
	sv.ly = 7.7;
	sv.diemtb = 0;
	return sv;
}


void themSVTheoThuTuMSSV(LIST &list)
{
	int dem = 0;
	NODE* p = list.head;
	SINHVIEN sv = themSinhVien();

	if (p != NULL && p->info.mssv > sv.mssv)
		insertHead(list, sv);
	else
	{
		while (p->next != NULL && p->info.mssv < sv.mssv)
			p = p->next;
		insertLast(list, sv, p);
	}
	xuatDanhSachSVCoDiemTB(list);
}


void bubbleSort(LIST &list)
{
	NODE* p = list.head;
	
}
