/* Spesifikasi:
	 Judul/Nama file: ContohCall_058.c
     Input (/ IS): 
	 Proses: 
	 Output (/ FS): string
   Dibuat oleh: Boy Suganda Sinaga
   Tanggal: 05 Maret 2015
*/

#include <stdio.h>
void swap1 (int x, int y); /*prototype*/
void swap2 (int *x, int *y); /*prototype*/
int main(){
	int i, j;
	i = 3, j = 15;
	printf ("i dan j sebelum ditukar : i = %d, j = %d\n", i, j);
	swap1(i,j); //call by value
	printf (" i dan j setelah memanggil swap1: i = %d, j = %d\n", i, j);
	swap2(&i,&j); //call by reference
	printf (" i dan j setelah memanggil swap2: i = %d, j = %d\n", i, j);
	return 0;
}

void swap1(int x, int y){
	int temp;
	temp = x;
	x = y;
	y = temp;
	printf("nilai variabel pertama = %d\n", x);
	printf("nilai variabel kedua = %d\n", y);
}

void swap2(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
