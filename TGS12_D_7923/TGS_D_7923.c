#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#define max 10

typedef char string[20];

typedef struct
{
	int id_tiket;
	string nama_film;
	string genre_film;
	string nama_pengunjung;
	int id_pengunjung;
}bioskop;

void init(bioskop lord_dije[]);
int isEmpty(bioskop lord_dije[]);
int isFull(bioskop lord_dije[]);
void input(int pesan,bioskop lord_dije[]);
void tampil(int temp,bioskop lord_dije[]);
void cari(int temp, bioskop lord_dije[]);
void hapus(int tmp, bioskop lord_dije[]);
void edit(int temp, bioskop lord_dije[]);
void Tugas(int tmp, bioskop lord_dije[]);
int temp,jenis =0;
int tmp;
int _idtiket=0;

int main()
{

	int pesan=0;
	char pilih;
	bioskop lord_dije[max];
	init(lord_dije);

	do
	{
		system("cls");
		printf("----------MENU----------\n");
		printf("1.Input data\n");
		printf("2.Tampil data\n");
		printf("3.Cari data\n");
		printf("4.Hapus data\n");
		printf("5.Edit data\n");
		printf("6.Tugas Hapus Data\n");
		printf("0.Keluar data\n");
		printf("Masukkan pilihan: ");scanf("%d",&pilih);

		switch(pilih)
		{
		case 1:
			
			if(isFull(lord_dije)==0)
			{
				system("cls");
				printf("----------Input Data----------\n");
				do
				{
					printf("\nMasukkan jumlah tiket yang ingin dipesan: ");scanf("%d",&pesan);
					if(pesan>max)
					{
						printf("\nJumlah yang ingin anda pesan melebihi tiket yang tersedia(%d)",pesan);
					}
				}while(pesan>=max);
				temp=temp+pesan;

				do
				{
					printf("\nMasukkan jenis pemesanan(1. online/2. offline): ");scanf("%d",&jenis);
				}while(jenis !=1 && jenis !=2);

				
				input(pesan,lord_dije);
			}
			else
			{
				printf("Maaf, tiket habis");				
			}			
			break;
		case 2:
			if(isEmpty(lord_dije)==0)
			{
				tampil(temp,lord_dije);
			}
			
			break;
		case 3:			
			cari(temp,lord_dije);
			break;
		case 4:		
			hapus(temp,lord_dije);
			break;
		case 5:			
			edit(temp,lord_dije);
			break;	
		case 6: 
			Tugas(tmp,lord_dije);
			break;
		}
		getch();
	}while(pilih!='0');

	return 0;
}

void input(int pesan,bioskop lord_dije[])
{
	int i,a=1;
	
	
		for(i=0;i<pesan;i++)
		{
			printf("Input data ke-%d\n",a++);
			printf("Masukkan id tiket: ");scanf("%d",&lord_dije[i].id_tiket);
			printf("Masukkan nama film: ");fflush(stdin);gets(lord_dije[i].nama_film);

			do
			{
				printf("Masukkan genre film: ");fflush(stdin);gets(lord_dije[i].genre_film);

				if(strcmpi(lord_dije[i].genre_film,"action")!=0 && strcmpi(lord_dije[i].genre_film,"komedi")!=0 && strcmpi(lord_dije[i].genre_film,"horror")!=0)
				{
					printf("Jenis kategori hanya ada action, komedi, horror saja\n");
				}

			}while(strcmpi(lord_dije[i].genre_film,"action")!=0 && strcmpi(lord_dije[i].genre_film,"komedi")!=0 && strcmpi(lord_dije[i].genre_film,"horror")!=0);
			
			printf("Masukkan nama pengunjung: ");fflush(stdin);gets(lord_dije[i].nama_pengunjung);
			if(jenis=1)
			{
				printf("Masukkan id pengunjung: ");scanf("%d",&lord_dije[i].id_pengunjung);
			}
		}	
}

void edit(int temp, bioskop lord_dije[])
{
	int _idtiket;
	int i=0;

	printf("\nMasukkan ID Tiket di cari : ");scanf("%d",&_idtiket);
	
	while(i<temp && (_idtiket != lord_dije[i].id_tiket))
	{
		i++;
	}

	if(i<temp)
	{
		printf("\nsebelum di edit :\n");
		printf("id_tiket: %d\n",lord_dije[i].id_tiket);
		printf("id_pengunjung: %d\n",lord_dije[i].id_pengunjung);
		printf("nama_film: %s\n",lord_dije[i].nama_film);
		printf("nama_pengunjung: %s\n",lord_dije[i].nama_pengunjung);
		printf("genre_film: %s\n",lord_dije[i].genre_film);
	}

	printf("Masukkan nama film: ");fflush(stdin);gets(lord_dije[i].nama_film);
	printf("Masukkan nama pengunjung: ");fflush(stdin);gets(lord_dije[i].nama_pengunjung);
}

void hapus(int tmp, bioskop lord_dije[])
{
	int _idtiket;
	int i=0;

	printf("\nMasukkan ID Tiket yang ingin dihapus : ");scanf("%d",&_idtiket);
	
	for ( i = _idtiket - 1 ; i < tmp - 1 ; i++ )
	{
         lord_dije[i] = lord_dije[i+1];
		 temp=tmp-1;
	}

	printf("\nsisa tiket : ");

	if(temp>0)
	{
		for(i=0;i<temp;i++)
		{
			printf("\nData ke-i=%d\n\n",i+1);
			printf("id_tiket: %d\n",lord_dije[i].id_tiket);
			printf("id_pengunjung: %d\n",lord_dije[i].id_pengunjung);
			printf("nama_film: %s\n",lord_dije[i].nama_film);
			printf("nama_pengunjung: %s\n",lord_dije[i].nama_pengunjung);
			printf("genre_film: %s\n",lord_dije[i].genre_film);
		}
	}
	else
	{
		printf("\ntiket telah terhapus semua!!!");
	}
}

void cari(int temp, bioskop lord_dije[])
{
	int _idtiket;
	int i=0;

	printf("\nMasukkan ID Tiket di cari : ");scanf("%d",&_idtiket);
	
	while(i<temp && (_idtiket != lord_dije[i].id_tiket))
	{
		i++;
	}

	if(i<temp)
	{
		printf("id_tiket: %d\n",lord_dije[i].id_tiket);
		printf("id_pengunjung: %d\n",lord_dije[i].id_pengunjung);
		printf("nama_film: %s\n",lord_dije[i].nama_film);
		printf("nama_pengunjung: %s\n",lord_dije[i].nama_pengunjung);
		printf("genre_film: %s\n",lord_dije[i].genre_film);
	}
}

void tampil(int temp, bioskop lord_dije[])
{
	int i;
	for(i=0;i<temp;i++)
	{
		printf("\nData ke-i=%d\n\n",i+1);
		printf("id_tiket: %d\n",lord_dije[i].id_tiket);
		printf("id_pengunjung: %d\n",lord_dije[i].id_pengunjung);
		printf("nama_film: %s\n",lord_dije[i].nama_film);
		printf("nama_pengunjung: %s\n",lord_dije[i].nama_pengunjung);
		printf("genre_film: %s\n",lord_dije[i].genre_film);
	}
}

void init(bioskop lord_dije[])
{
	int i;
	for(i=0;i<max;i++)
	{
		lord_dije[i].id_tiket=0;
	}
}

int isEmpty(bioskop lord_dije[])
{
	int i;
	for(i=0;i<max;i++)
	{
		if(lord_dije[i].id_tiket!=0)
			return 0;
	}
	return 1;
}

int isFull(bioskop lord_dije[])
{
	int i;
	for(i=0;i<max;i++)
	{
		if(lord_dije[i].id_tiket==0)
			return 0;
	}
	return 1;
}

void Tugas(int tmp, bioskop lord_dije[])
{
	int pesan;

	int i=0;

	printf("\nMasukkan ID Tiket yang ingin dihapus : ");scanf("%d",&pesan);
	
	for ( i = pesan - 1 ; i < tmp - 1 ; i++ )
	{
         lord_dije[i] = lord_dije[i+1];
		 temp=tmp-1;
	}

	if(temp>0)
	{
		for(i=0;i<temp;i++)
		{
			printf("\nData ke-i=%d\n\n",i+1);
			printf("id_tiket: %d\n",lord_dije[i].id_tiket);
			printf("id_pengunjung: %d\n",lord_dije[i].id_pengunjung);
			printf("nama_film: %s\n",lord_dije[i].nama_film);
			printf("nama_pengunjung: %s\n",lord_dije[i].nama_pengunjung);
			printf("genre_film: %s\n",lord_dije[i].genre_film);
		}
	}
	else
	{
		printf("\nSemua Data telah terhapus semua!!!");
	}
}