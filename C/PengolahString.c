/*=====================================================================
Nama program    : PengolahString_058.c
Deskripsi       : Program untuk mengolah string, 
                  mengandung beberapa fungsi untuk mengolah string.

NIM     : 11S14058
Nama    : Boy Suganda Sinaga
Kelas   : S1-TI-02
Tanggal(last update): 28 April 2015
=======================================================================*/
#include<stdio.h>
/*=====KAMUS GLOBAL=====*/
  // Tuliskan kamus global di sini   

/*=====PROTOTIPE FUNGSI=====*/
//Bagian ini jangan anda ubah.
void displayStr(char *str); 
//Prosedur displayStr(char *str), menampilkan string str ke layar. 
//Argumen prosedur (parameter input): string str, 
//output tampilan str di layar.
int cntKar(char *str);
//Fungsi int cntKar(char *str), untuk menghitung banyaknya karakter dari string str. 
//Argumen fungsi (parameter input): string str, 
//return value: banyaknya karakter dari string str.
int cntVokal(char *str);
//Fungsi int cntVokal(char *str), untuk menghitung banyaknya huruf vokal dari string str. 
//Argumen fungsi (parameter input): string str, 
//return value: banyaknya huruf vokal dari string str.
int cntHrf(char *str, char hrf);
//Fungsi int cntHrf(char *str, char hrf), untuk menghitung banyaknya huruf yang sama dengan huruf hrf (sesuai input) pada string str. 
//Argumen fungsi (parameter input): string str dan sebuah karakter hrf, 
//return value: banyaknya huruf yang dicari, sesuai input ke fungsi.
int cntKata(char *str);
//Fungsi int cntKata(char *str), untuk menghitung banyaknya kata dari string str. 
//Argumen fungsi (parameter input): string str, 
//return value:banyaknya kata dari string str, 
//delimiter setiap kata pada kalimat (string str) adalah spasi (' ').

/*=====PROGRAM UTAMA=====*/
int main(){
    /*KAMUS*/
    char kalimat[30]; //asumsi panjang maksimum kalimat = 30 karakter. Boleh anda ubah.
    char cari; // Variabel untuk menampung huruf yang dicari.
    int n;  // Variabel untuk menampung banyak kata.
    
    /*ALGORITMA*/
    // Contoh penggunaan (Call) fungsi untuk mengolah string input.
    printf("Masukan sebuah kalimat: "); 
    gets(kalimat); //bandingkan jika diganti dengan gets(kalimat);
    printf("Kalimat anda:"),displayStr(kalimat);
    printf("\nbanyaknya karakter: %d\n", cntKar(kalimat));
    printf("banyaknya huruf vokal: %d\n", cntVokal(kalimat));
    printf("Huruf yang anda cari: \n");
    scanf("%c", &cari);
    printf("banyaknya huruf %c: %d\n", cari, cntHrf(kalimat,cari));
    n = cntKata(kalimat);
    printf("banyaknya kata: %d\n",n);
    if(n>2) 
       printf("Kalimat panjang");
    else if (n>1)
         printf("Kalimat pendek");
    else printf("Hanya satu kata\nBukan kalimat atau kalimat tidak lengkap");
    getch();
    return 0;
}

/*=====BODY OF FUNCTION=====*/
// Kode program untuk setiap fungsi dan prosedur.
void displayStr(char *str){
     /*KAMUS LOKAL*/
     char kalimat[30];
     /*ALGORITMA*/
     // tuliskan kode prosedur anda di sini!
     printf ("%s", str);
	 }
                
int cntKar(char *str){
    /*KAMUS LOKAL*/
    char kalimat[30];
     int i=0, cntKar=0;
    /*ALGORITMA*/
    // tuliskan kode fungsi anda di sini!
	while (str[i]!='\0')
	{
		cntKar=cntKar+1;
		i=i+1;
	}
	return cntKar;

}
    
int cntVokal(char *str){
    /*KAMUS LOKAL*/
     char kalimat[30];
     char a[]={'a','A','i','I','u','U','e','E','o','U'};
     int cntVokal=0, i, j;
     
    /*ALGORITMA*/
    // tuliskan kode fungsi anda di sini!
    for(i=0;str[i]!='\0';i++)
    {
    	for (j=0;a[j]!='\0';j++)
    	{
    		if (str[i]==a[j])
    		{
    			cntVokal=cntVokal+1;
    		}
    	}
    }
    return cntVokal;
}
    
int cntHrf(char *str, char cari){
    /*KAMUS LOKAL*/
     char kalimat[30];
	 int i,count=0; 
    /*ALGORITMA*/
    // tuliskan kode fungsi anda di sini!
   for(i=0;str[i]!='0';i++){
    	if(str[i]==hrf){
    		count=count+1;
    	}
    }
    
int cntKata(char *str){
    /*KAMUS LOKAL*/
    char kalimat[30];
    int i, cntKata=1;
     
    /*ALGORITMA*/
    // tuliskan kode fungsi anda di sini!
    for (i=0;str[i]!='\0';i++)
    {
    	if (str[i]== ' ')
    	{
    		cntKata+=1;
    	}
    }
    return cntKata;
}
