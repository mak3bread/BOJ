#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int a,b;
    cin>>a>>b;
    int a1,a2,a3;
    int b1,b2,b3;
    
    a3=a%10;
    a2=(a%100-a3)/10;
    a1=(a-a3-a2*10)/100;
    a=a3*100+a2*10+a1;
    
    b3=b%10;
    b2=(b%100-b3)/10;
    b1=(b-b3-b2*10)/100;
    b=b3*100+b2*10+b1;
    
    if(a>b){
        cout<<a<<'\n';
    }
    if(b>a){
        cout<<b<<'\n';
    }
   
    return 0;
}
