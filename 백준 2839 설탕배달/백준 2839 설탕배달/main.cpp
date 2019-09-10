#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin>>N;
    if(N%5==0){
        cout<<N/5<<'\n';
    }
    else{
        if(N%5==1){
            int a=(N/5)-1;
            int b=(N-(a*5))/3;
            if(a>=1){
            cout<<a+b<<'\n';
            }
            else if(a==0){
                cout<<2<<'\n';
            }
            else{cout<<-1<<'\n';}
        }
        if(N%5==2){
            int a=(N/5)-2;
            if(a>=1){
                cout<<a+4<<'\n';
            }
            else if(a==0){
                cout<<4<<'\n';
            }
            else{
                cout<<-1<<'\n';
            }
        }
        if(N%5==3){
            int a=(N/5);
            if(a>=1){
            cout<<a+1<<'\n';
            }
            else if(a==0){
                cout<<1<<'\n';
            }
            else{
                cout<<-1<<'\n';
            }
        }
        if(N%5==4){
            int a=(N/5)-1;
            if(a>=1){
                cout<<a+3<<'\n';
            }
            else if(a==0){
                cout<<3<<'\n';
            }
            else{
                cout<<-1<<'\n';
            }
        }
        
    }
    return 0;
}
