#include <iostream>
#define MAX 100
using namespace std;

struct HOTEN
{
    string ho;
    string ten;
};

struct HOCSINH
{
    HOTEN hoten;
    int namsinh;
    int diemtoan;
    int diemly;
    int diemhoa;
    int tongdiem;
};

HOCSINH hs[MAX];
int n;

void nhapMang(HOCSINH hs[],int &n){
    cin>>n;
    while(n<=0){
        cin>>n;
    }

    for (int i = 0; i < n; ++i)
    {
        cin>>hs[i].hoten.ho;
        cin>>hs[i].hoten.ten;
        cin>>hs[i].namsinh;
        cin>>hs[i].diemtoan;
        while(hs[i].diemtoan<0||hs[i].diemtoan>10){
            cin>>hs[i].diemtoan;
        }
        cin>>hs[i].diemly;
        while(hs[i].diemly<0||hs[i].diemly>10){
            cin>>hs[i].diemly;
        }
        cin>>hs[i].diemhoa;
        while(hs[i].diemhoa<0||hs[i].diemhoa>10){
            cin>>hs[i].diemhoa;
        }
        hs[i].tongdiem = hs[i].diemtoan + hs[i].diemly + hs[i].diemhoa;

    }
}

void xuat(HOCSINH hs){
    cout<<hs.hoten.ho<<" ";
    cout<<hs.hoten.ten<<" ";
    cout<< hs.namsinh<<" ";
    cout<< hs.diemtoan<<" ";
    cout<< hs.diemly<<" ";
    cout<< hs.diemhoa<<" ";
    cout<< hs.tongdiem<<" "<<endl;
}



void timKiem(HOCSINH hs[],string ho, string ten,int n){
    for(int i=0;i<n;++i){
        if(hs[i].hoten.ho== ho && hs[i].hoten.ten==ten){
            xuat(hs[i]);
        }

    }
}

void ketQua(HOCSINH hs[],int n){
    for(int i=0;i<n;++i){
        if(hs[i].tongdiem>15){
            xuat(hs[i]);
        }
    }
}

int main(){
    nhapMang(hs,n);
    timKiem(hs,"Ninh","Nam",n);
    // ketQua(hs,n);
}