#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <stack>

using namespace std;
stack<int> st;
vector<pair<int,int>> num;

void solve(int a[]){
	int i=0,j=0;
	st.push(a[0]);
	for (int i = 1; i < a.size(); ++i)
	{			
		if(a[i]>st.top()){
			num.push_back(st.top(),a[i]);
			st.pop();
		}
		st.push(a[i]);
	}
}

int main(){
	 int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    }
    solve(a);
    return 0;
}