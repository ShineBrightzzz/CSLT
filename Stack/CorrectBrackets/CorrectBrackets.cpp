#include <iostream>
#include <bits/stdc++.h>
using namespace std;

stack<int> brackets;

bool process_brackets(string s){

	for (int i = 0; i < (int)s.size(); ++i)
	{
		if(s[i]=='('){
			brackets.push(i);
		}else{
			if(brackets.empty()) return false;
			brackets.pop();
		}
	}
	if(!brackets.empty()) return false;
	return true;	
}




int main(){
	string s;
	cin>>s;
	cout<<process_brackets(s);
}