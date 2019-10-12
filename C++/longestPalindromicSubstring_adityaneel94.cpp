#include<bits/stdc++.h>
using namespace std;

int find_max_len(string s,int start,int end){
    while(start>=0 && end<s.length() && s[start]==s[end]){
        start--;
        end++;
    }
    return end-start-1;
}

string longestPalindrome(string s) {
    int l=s.length();
    if(l==0)
        return "";
    if(l==1)
        return s;
    int max_len=INT_MIN;
    int start=0,end=0;
    for(int i=0;i<l;i++){
        int l1=find_max_len(s,i,i);
        int l2=find_max_len(s,i,i+1);
        int len=max(l1,l2);
        if(len> end-start){
            start=i-(len-1)/2;
            end=i+len/2;
        }
    }
    return s.substr(start,end-start+1);
}

int main(){
	string s;
	cin>>s;
	string res = longestPalindrome(s);
	cout<<"Longest palindromic subsequence : "<<res;
}