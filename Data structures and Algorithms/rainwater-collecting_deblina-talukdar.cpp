#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define pb push_back
#define pf push_front
#define mp make_pair
#define fs first
#define sc second
const ll mod=1e9+7;
const ll siz=5*1e5+5;
int main(){
	//l[] and r[] store the maximum height from the left and right uptill now
	int n,i,mr=0,ml=0,l[siz],r[siz],a[siz],s=0;
	//the number of bars
	cin>>n;
	//getting the height of each bar
	for(i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>ml)
			ml=a[i];
		l[i]=ml;
	}
	for(i=n-1;i>=0;i--){
		if(a[i]>mr)
			mr=a[i];
		r[i]=mr;
	}
	//total water collected is the sum of
	//min of left and right minus the height of the bar
	for(i=0;i<n;i++)
		s+=min(l[i],r[i])-a[i];
	cout<<s;
	return 0;
}
