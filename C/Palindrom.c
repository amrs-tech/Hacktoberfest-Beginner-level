/*=====================================================================
Nama program    : Palindrom_058.c
Deskripsi       : Program untuk menentukan kata palindrom atau bukan, 
                  mengandung satu fungsi palindrom.

Ditulis oleh:
NIM     : 11S14058
Nama    : Boy Suganda Sinaga
Kelas   : S1-TI-02
Tanggal(last update): 28 April 2015
=======================================================================*/
#include<stdio.h>

//*===== PROTOTIPE FUNGSI=====*/
// Boleh anda tambahkan fungsi lain sesuai kebutuhan.

int palindrom(char *str);
//Fungsi untuk menentukan sebuah kata palindrom atau bukan. 
//Input: string str, 
//return value: 1 jika palindrom, 0 jika bukan palindrom. 

/*=====PROGRAM UTAMA=====*/
int main(){
    /*KAMUS*/
    char kalimat[25];
    
    /*ALGORITMA*/
    printf("Masukan sebuah kata/kalimat: "); //Masukkan sebuah input, untuk diproses
    gets(kalimat);
    
    if(palindrom(kalimat)==1) //memanggil fungsi palindrom.
       printf("Kata/kalimat Anda Palindrom");
    else printf("Kata/kalimat Anda BUKAN Palindrom");
    getch();
    return 0;
    }//End of main().

/*=====BODY OF FUNCTION=====*/
// Kode program untuk setiap fungsi dan prosedur.

int palindrom(char *str){
     /*KAMUS LOKAL*/
     int i,j=0,bool=1;
     /*ALGORITMA*/
     // tuliskan kode fungsi anda di sini!
     
     for(i=0;str[i]!='\0';i++){
     }
     
     while(j<=(i-1)/2){
     	if(str[j]==str[i-j-1]){
     		j=j+1;
     	}
     	else{
     		j=j+i;
     		bool=bool-1;
     	}
     }
	
	return bool;
    }
