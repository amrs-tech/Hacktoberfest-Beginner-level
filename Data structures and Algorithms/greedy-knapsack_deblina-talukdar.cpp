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
bool sortinrev(const pair<float,int> &a, const pair<float,int> &b){ 
       return (a.first > b.first); 
}
int main(){
	int n,i,W,w[siz],v1[siz];
	float s=0.0;
	vector<pair<float,int>>v;
	//getting the number of items in knapsack
	cin>>n;
	for(i=0;i<n;i++){
		cin>>w[i]>>v1[i];
		v.pb({(float)((float)v1[i]/(float)w[i]),i});
	}
	//getting the total weight
	cin>>W;
	//sorting in decreasing order of value/weight
	sort(v.begin(),v.end(),sortinrev);
	for(i=0;i<n;i++){
		if(w[v[i].second]<=W){
			s+=v1[v[i].second];
			W-=w[v[i].second];
		}
		else{
			s+=(v[i].first*W);
			W=0;
			break;
		}
	}
	//sum of values of all items in the knapsack
	cout<<s;
	return 0;
}
