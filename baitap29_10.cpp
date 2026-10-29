#include <iostream>
#include <string>
using namespace std;

struct hanghoa{
    int mahang;
    string tenhang;
    string ngayxuat;
    float gia;
};

void nhap(hanghoa *a, int n){
    for(int i=0;i<n;i++){
        cout<<"\nNhap thong tin hang hoa thu "<<i+1<<":"<<endl;

        cout<<"Nhap ma hang hoa: ";
        cin>>a[i].mahang;
        cin.ignore();

        cout<<"Nhap ten hang hoa: ";
        getline(cin,a[i].tenhang);

        cout<<"Nhap ngay xuat hang: ";
        getline(cin,a[i].ngayxuat);

        cout<<"Nhap gia xuat hang (trieu dong): ";
        cin>>a[i].gia;
        cin.ignore();
    }
}

void xuat(hanghoa *a, int n){
    for(int i=0;i<n;i++){
        cout<<"\nHang hoa thu "<<i+1<<":"<<endl;
        cout<<"Ma hang hoa: "<<a[i].mahang<<endl;
        cout<<"Ten hang hoa: "<<a[i].tenhang<<endl;
        cout<<"Ngay xuat hang: "<<a[i].ngayxuat<<endl;
        cout<<"Gia xuat hang: "<<a[i].gia<<" trieu dong"<<endl;
    }
}

void quicksort(hanghoa *a, int left, int right){
    int i=left;
    int j=right;

    float pivot=a[(left+right)/2].gia;

    while(i<=j){
        while(a[i].gia<pivot){
            i++;
        }

        while(a[j].gia>pivot){
            j--;
        }

        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }

    if(left<j){
        quicksort(a,left,j);
    }

    if(i<right){
        quicksort(a,i,right);
    }
}

int timkiemnhiphan(hanghoa *a, int n, float x){
    int left=0;
    int right=n-1;

    while(left<=right){
        int mid=(left+right)/2;

        if(a[mid].gia==x){
            return mid;
        }

        if(a[mid].gia<x){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }

    return -1;
}

void timtatca(hanghoa *a, int n, float x){
    int vt=timkiemnhiphan(a,n,x);

    if(vt==-1){
        cout<<"\nKhong tim thay hang hoa co gia "<<x<<" trieu dong."<<endl;
        return;
    }

    int left=vt;
    int right=vt;

    while(left>0 && a[left-1].gia==x){
        left--;
    }

    while(right<n-1 && a[right+1].gia==x){
        right++;
    }

    cout<<"\nCac hang hoa co gia "<<x<<" trieu dong:"<<endl;

    for(int i=left;i<=right;i++){
        cout<<"\nMa hang hoa: "<<a[i].mahang<<endl;
        cout<<"Ten hang hoa: "<<a[i].tenhang<<endl;
        cout<<"Ngay xuat hang: "<<a[i].ngayxuat<<endl;
        cout<<"Gia xuat hang: "<<a[i].gia<<" trieu dong"<<endl;
    }
}

int main(){
    int n;

    cout<<"Nhap so luong hang hoa: ";
    cin>>n;

    hanghoa *a=new hanghoa[n];

    cout<<"\n===== NHAP DANH SACH HANG HOA ====="<<endl;
    nhap(a,n);

    cout<<"\n===== DANH SACH HANG HOA VUA NHAP ====="<<endl;
    xuat(a,n);

    quicksort(a,0,n-1);

    cout<<"\n===== DANH SACH SAU KHI SAP XEP TANG DAN THEO GIA ====="<<endl;
    xuat(a,n);

    float x;
    cout<<"\nNhap gia can tim X: ";
    cin>>x;

    timtatca(a,n,x);

    delete[] a;

    return 0;
}
