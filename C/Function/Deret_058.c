/* Spesifikasi:
	 Judul/Nama file: Deret_058.c
     Input (/ IS): a,r,n(integer)
	 Proses: menghitung deret
	 Output (/ FS): Un, Sn
  Dibuat oleh: Boy Suganda Sinaga
   Tanggal: 05 Maret 2015
*/

#include <stdio.h>
int pangkat(int r, int n); /* prototype */
int sukuke(int a, int r, int n); /* prototype */
int jumlahsuku(int a, int r, int n); /* prototype */

int main(){
	
 /* KAMUS */
 	int a, r, n, sukuke, jumlahsuku;
 
 /*ALGORITMA*/
 	printf("Masukkan nilai a: ");
 	scanf("%d",&a);
 	printf("Masukkan nilai r: ");
 	scanf("%d",&r);
 	printf("Masukkan nilai n: ");
 	scanf("%d",&n);
 	sukuke = Un(a,r,n);
 	printf("Un = %d\n", sukuke);
 	jumlahsuku = Sn(a,r,n);
	printf("Sn = %d", jumlahsuku);
 
 return 0;
 }

int pangkat(int r, int n){
	if(n==0){
		return 1;
	}
	else{
		return (r * pangkat(r,(n-1)));
	}
}

int Un(int a, int r, int n){
	return (a * pangkat(r,(n-1)));
}

int Sn(int a, int r, int n){
	if(n == 1){
		return (a * (pangkat(r,n) -1)) / (r -1);
	}
		else{
			return ((a - (a * pangkat(r,n))) / (1 - r));
		}
}

