#include <iostream>
using namespace std;

//print  the fabonacci series between 1 to N 

int main() {
    int N;
    cin >> N;
    int a = 0;
    int c;
    int b = 1;
    while(a<N){
        cout<<a<<" ";
        c=a+b;
        a=b;
        b=c;
    }
}
