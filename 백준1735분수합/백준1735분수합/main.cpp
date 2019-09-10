#include <iostream>
using namespace std;

int GCD(int a,int b){
    return b?GCD(b,a%b):a;
}

int main(){
    
    int A,B,C,D;
    cin>>A>>B>>C>>D;
    //A,C - 분자 B,D는 분모
    // A/B C/D
    
    if(A>=1&&A<=30000&&B>=1&&B<=30000&&C>=1&&C<=30000&&D>=1&&D<=30000){
        int son=0;
        int mom=0;
        
        mom=B*D;
        son=(A*D)+(C*B);
        int gcd=GCD(son,mom);
        
        cout<<son/gcd<<" "<<mom/gcd<<endl;
    }
    
    return 0;
}
