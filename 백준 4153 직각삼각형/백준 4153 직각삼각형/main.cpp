#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(1){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0&&b==0&&c==0){break;}
        
        int max=a;
        if(max<b){
            max=b;
        }
        if(max<c){
            max=c;
        }
        int num1=0,num2=0;
        if(max==a){
            num1=b;
            num2=c;
        }
        if(max==b){
            num1=a;
            num2=c;
        }
        if(max==c){
            num1=a;
            num2=b;
        }
        
        if(num1*num1+num2*num2==max*max){
            cout<<"right\n";
        }
        else{
            cout<<"wrong\n";
        }
    }
    return 0;
}
