/* Spesifikasi:
	 Judul/Nama file: Permutasi_058.c
     Input (/ IS): n(integer); k(integer)
	 Proses: menghitung n permutasi k
	 Output (/ FS): hasil(integer); hasilpermutasi(integer)
   Dibuat oleh: Boy Suganda Sinaga
   Tanggal: 05 Maret 2015
*/

#include <stdio.h>
/*KAMUS GLOBAL*/
int factorial(int); /* prototype */
int permutasi(int, int); /* prototype */

int main (){
  /* KAMUS LOKAL*/
  int n,k,p,K;
 
  /*ALGORITMA*/
	printf("n:");
	scanf("%dn", &n);
	printf("k:");
	scanf("%d", &k);
	p=permutasi(n, k);
	printf("nilai dari permutasi %d disusun %d adalah %d\n ",n,k,p);
	return 0;
 return 0;
 }
 
 int factorial(int n){
  /* KAMUS LOKAL*/
 
 
  /*ALGORITMA*/
 if(n==1)
    return(1);
    else
    return(n*factorial(n-1));
 } 

int permutasi(int n, int k){
 /* KAMUS LOKAL*/
 
 
 /*ALGORITMA*/
 return factorial(n)/factorial(n - k);

 } 
 
 
 
