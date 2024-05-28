/*Viết hàm standard(char s[]) loại bỏ toàn bộ khoảng trắng đầu xâu, 
cuối xâu và giữa 2 từ trong s chỉ còn 1 khoảng trắng.*/


#include <iostream>
#include <cstring>
#define MAX 100

using namespace std;

void input(char s[]) {
    cin.getline(s, MAX);
}

void print(char s[]){
	for (int i = 0; i < strlen(s); ++i)
	{
		cout<<s[i];
	}
}


void Delete(char s[],int pos){
	int len = strlen(s);
	for (int i = pos; i < len; ++i)
	{
		s[i]=s[i+1];
	}
}

void standard(char s[]){
	while(s[0]==' ') Delete(s,0);

	int len = strlen(s);
	while(s[len-1]==' '){
		Delete(s,len-1);
		len--;
	} 


	int countSpace = 0;
	for (int i = 0; i < strlen(s); ++i)
	{
		if(s[i]==' '){
			++countSpace;
			if(countSpace>=2){
				Delete(s,i);
				--countSpace;
				--i;
			}

		}
		else{
			countSpace = 0;
		}

	}
}


int main(){
	char s[MAX];
	input(s);
	standard(s);
	print(s);
}