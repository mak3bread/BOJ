#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int gcd(int a, int b) {
    int temp;
    if (a < b)
        swap(a, b);
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    
    if(T>=1&&T<=1000){
        for(int i=0;i<T;i++){
            int A,B;
            cin>>A>>B;
            if(A>=1&&A<=45000&&B>=1&&B<=45000){
            cout<<lcm(A,B)<<'\n';
            }
        }
    }
    return 0;
}
