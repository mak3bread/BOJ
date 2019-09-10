#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin>>T;
    
    for(int i=0;i<T;i++){
        int H,W,N;
        cin>>H>>W>>N;
     
        if(N/H+1<=10){
            if(N/H+1<=9){
                if(N%H==0){
                    cout<<H<<0<<N/H<<'\n';
                }
                else{
                    cout<<N%H<<0<<N/H+1<<'\n';
                }
            }
            else{
                if(N%H==0){
                    cout<<H<<0<<N/H<<'\n';
                }
                else{
                    cout<<N%H<<N/H+1<<'\n';
                }
            }
        }
        else{
            if(N%H==0){
               cout<<H<<N/H<<'\n';
            }
            else{
            cout<<N%H<<N/H+1<<'\n';
            }
        }
    }
    return 0;
}
