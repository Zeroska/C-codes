#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>

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


		//------------------MAIN---------------------
int main()
{
	LIST list;
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
			gets_s(ten);
			while (getchar() != '\n');
			int timTen = timThongTinSVTheoTen(list, ten);
			if (timTen == 1)
			{
				printf("Found one.\n");
			}
			else
			{
				printf("Clueless.\n");
			}
			break;
		}
		}
	} while (option != 10);
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
	printf("\n10.Thoat khoi chuong trinh.                                   |");
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
	
	while (p->next != NULL)
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
	while (p != NULL)
	{
		if (strcmp(p->info.ten, ten) == 0)
		{
			return 1;
		}
		p = p->next;
	}
}