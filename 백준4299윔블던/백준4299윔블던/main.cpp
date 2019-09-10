#include <iostream>
using namespace std;

int main(){
    
    int plus;
    int minus;
    int team1=0;
    int team2=0;
    cin>>plus>>minus;
    
    if(plus>=0&&minus>=0&&plus>=minus){
        if((plus+minus)%2==0&&(plus-minus)%2==0){
            team1=(plus+minus)/2;
            team2=(plus-minus)/2;
            
            cout<<team1<<" "<<team2<<endl;
        }
       
        else{
            cout<<"-1"<<endl;
        }
    }
    else{
        cout<<"-1"<<endl;
    }
    
    return 0;
}
