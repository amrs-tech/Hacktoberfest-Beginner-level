/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int a;
    cin>>a;
    for(int i=1;i<=a;i++)
    {
    int x,y;
    cin>>x;
    cin>>y;
    char *ch=new char[50];
    cin>>ch;
    int len=strlen(ch);
    for(int i=0;i<len;i++)
    
    {
        if(ch[i]=='L'||ch[i]=='l')
        {
            x=x-1;
        }
        else if(ch[i]=='R'||ch[i]=='r')
        {
            x=x+1;
        }
        else if(ch[i]=='U'||ch[i]=='u')
        {
            y=y+1;
        }
        else if(ch[i]=='D'||ch[i]=='d')
        {
            y=y-1;
        }
        else if(ch[i]==' '){;}
        else {
            exit(0);
             }
    }
    cout<<"\n"<<x<<" "<<y;

}
}