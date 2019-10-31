#include  <stdio.h>
  
  int print(int *a, int n) {
  int i;
  for (i = 0; i < n;  i++)
  printf("%d\t", a[i]);
  }
  
  void radix_sort(int *a, int n) {
  int i, b[10], m = 0,  exp = 1;
  for (i = 0; i < n;  i++) {
  if (a[i] > m)
  m = a[i];
  }
  
  while (m / exp >  0) {
  int box[10] = { 0 };
  for (i = 0; i <  n; i++)
  box[a[i] / exp %  10]++;
  for (i = 1; i <  10; i++)
  box[i] += box[i -  1];
  for (i = n - 1; i  >= 0; i--)
  b[--box[a[i] / exp  % 10]] = a[i];
  for (i = 0; i <  n; i++)
   a[i] = b[i];
  exp *= 10;
  }
  }
  
  int main() {
  int arr[10];
  int i, num;
  
  printf("Input  number of elements: ");
  scanf("%d",  &num);
  
  printf("\nInput  array elements one by one : ");
  for (i = 0; i <  num; i++)
  scanf("%d", &arr[i]);
  
  printf("\nArray  elements : ");
  print(&arr[0],  num);
  
  radix_sort(&arr[0], num);
  
  printf("\nSorted  elements : ");
  print(&arr[0],  num);
  return 0;
  }
