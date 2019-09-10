#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
   unsigned long long x,y;
    cin>>x>>y;
        
      unsigned long long length=y-x;
 
         unsigned long long j =sqrt(length);
        if(j*j<length){j++;}
        if(j*j==length){cout<<2*j-1<<'\n';}
        if(j*j>length&&(j-1)*(j-1)+(j-1)<length){
            cout<<2*j-1<<'\n';
        }
        if(j*j>length&&(j-1)*(j-1)+(j-1)>=length){
            cout<<2*j-2<<'\n';
        }
    }
    return 0;
}
