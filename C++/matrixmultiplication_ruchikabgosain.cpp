//This program multiplies two matrices in C++.

 #include <iostream>  
 using namespace std;  
 int main()  
 {  
 int a[10][10],b[10][10],mul[10][10],r,c,i,j,k;  

 cout<<"\n Enter number of rows: ";    //input row and columns
 cin>>r;    
 cout<<"\n Enter number of columns: ";    
 cin>>c;    

 cout<<"\n Enter the first matrix: \n"; //input matrix
 for(i=0;i<r;i++)    
    for(j=0;j<c;j++)    
        cin>>a[i][j];     

 cout<<"\n Enter the second matrix: \n";    //input matrix
 for(i=0;i<r;i++)       
    for(j=0;j<c;j++)        
        cin>>b[i][j];    

 for(i=0;i<r;i++)                //product calculation
    for(j=0;j<c;j++)    
       {    
         mul[i][j]=0;    
         for(k=0;k<c;k++)    
             mul[i][j]+=a[i][k]*b[k][j];       
        }    

 cout<<"\n Resultant multiplication matrix: \n";   

 for(i=0;i<r;i++)           //printing the result
 {     for(j=0;j<c;j++)      
        cout<<mul[i][j]<<" ";    

   cout<<"\n";    
 }    

 return 0;  
 }    
