#include <iostream>
#include <cmath>
using namespace std;

struct TAMGIAC
{
    float a;
    float b;
    float c;
};

TAMGIAC tg;

void nhap(TAMGIAC &tg){
    cin>>tg.a;
    cin>>tg.b;
    cin>>tg.c;
}

void xuat(TAMGIAC tg){
    cout<<tg.a<<" "<<tg.b<<" "<<tg.c<<endl;
}

void chuVi(TAMGIAC tg){
    cout<<tg.a+tg.b+tg.c<<endl;
}

void dienTich(TAMGIAC tg){
    float p = (tg.a+tg.b+tg.c)/2;
    float dt = sqrt(p*(p-tg.a)*(p-tg.b)*(p-tg.c));
    cout<<dt<<endl;
}

int main(){
    nhap(tg);
    xuat(tg);
    chuVi(tg);
    dienTich(tg);
}    