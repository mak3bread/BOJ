#include <iostream>
using namespace std;

int main(){
    
    int N;
    cin>>N;
    int first=N;
    
    
    if(N>=0&&N<10){
        N=N*10+N;
    }
    else{
        N=((N%10)*10)+((N%10)+(N/10))%10;
    }


    int count=1;

    while(first!=N){
        if(N>=0&&N<10){
            N=N*10+N;
        }
        else{
            N=((N%10)*10)+((N%10)+(N/10))%10;
        }
        count++;
    }

    cout<<count<<endl;
    
    
    return 0;
}
