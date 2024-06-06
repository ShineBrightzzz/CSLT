#include <iostream>
#include <cmath>
using namespace std;

struct DIEM
{
    int x;
    int y;
};

DIEM a;
DIEM b;

void nhap(DIEM &diem){
    cin>>diem.x;
    cin>>diem.y;
}

void xuat(DIEM diem){
    cout<<diem.x<<" "<<diem.y<<endl;
}

void khoangCach(DIEM a,DIEM b){
    float kc = sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
    cout<<kc<<endl;
}

void doiXungQuaGoc(DIEM diem){
    cout<<-diem.x<<" "<<-diem.y<<endl;
}

void doiXungOx(DIEM diem){
    cout<<diem.x<<" "<<-diem.y<<endl;
}

void doiXungOy(DIEM diem){
    cout<<-diem.x<<" "<<diem.y<<endl;
}

int main(){
    nhap(a);
    nhap(b);
    xuat(a);
    xuat(b);
    khoangCach(a,b);
    doiXungQuaGoc(a);
    doiXungOx(a);
    doiXungOy(a);
}