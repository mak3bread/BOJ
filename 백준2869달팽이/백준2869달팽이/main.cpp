#include <cstdio>
using namespace std;

int main(){
    
    int A,B,V;
    scanf("%d%d%d",&A,&B,&V);
    int C=A-B;
    int D=V-A;
    if(D%C==0){
         int E=(D/C)+1;
        printf("%d\n",E);
    }
    else{
        int E=(D/C)+2;
        printf("%d\n",E);
    }
    return 0;
}
