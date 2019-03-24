#include <iostream>
using namespace std;

void swap_value(int, int);
void swap_reference(int* ,int*);

int main() {
    int a,b;
    cout<<"enter two integers: ";
    cin>>a>>b;
   swap_reference(&a,&b);
    swap_value(a,b);
    return 0;
}

void swap_value(int c, int d){
    int r=c;
    c=d;
    d=r;
    cout<<"swapped values (passby-value) are: "<<c<<" "<<d<<endl;
}

void swap_reference(int*a,int*b){
   int r=*a;
   *a=*b;
   *b=r;
   cout<<"swapped values (passby-reference) are: "<<*a<<" "<<*b<<endl;
}
