#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    string s;
    stack<char> st;
    cin>>s;
    n=s.length();
    for(i=0;i<n;i++)
    {
        st.push(s[i]);
    }

    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }

    return 0;
}
