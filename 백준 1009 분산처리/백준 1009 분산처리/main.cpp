#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int a,b;
        cin>>a>>b;
        
        if(a>=1&&a<100&&b>=1&&b<1000000){
            int c=a%10;
            int d=0;
            if(c==0){
                cout<<"10"<<endl;
            }
            if(c==1||c==5||c==6){
                cout<<c<<endl;
            }
            if(c==4||c==9){
                d=b%2;
                if(d==0){
                    cout<<(c*c)%10<<endl;
                }
                if(d==1){
                    cout<<c<<endl;
                }
            }
            if(c==2||c==3||c==7||c==8){
                d=b%4;
                if(d==0){
                    cout<<(int)pow(c,4)%10<<endl;
                }
                if(d==1){
                     cout<<(int)pow(c,1)%10<<endl;
                }
                if(d==2){
                     cout<<(int)pow(c,2)%10<<endl;
                }
                if(d==3){
                     cout<<(int)pow(c,3)%10<<endl;
                }
            }
        }
    }
    return 0;
}
