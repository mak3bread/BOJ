#include <iostream>

using namespace std;

int main(){
    int X;
    cin>>X;
    
    if(X>=1&&X<=10000000){
         int i=1;
        int sum=0;
        while(1){
           
            sum+=i;
            if(X-sum<=0)
                break;
            i++;
        }
        int cnt=0;
        for(int j=1;j<i;j++){
            cnt+=j;
        }

        cnt=X-cnt;
      
        if(i%2==0){
            if(i==cnt){
            cout<<i<<"/1"<<'\n';
          
        }
            for(int j=1;j<i;j++){
                if(j==cnt){
                    cout<<j<<"/"<<i-j+1<<'\n';
                }
            }
        }
        if(i%2==1){
            if(i==cnt){
                cout<<"1/"<<i<<'\n';
            }
            for(int j=1;j<i;j++){
                if(j==cnt){
                    cout<<i-j+1<<"/"<<j<<'\n';
                }
            }
            
        }
    }
    return 0;
}
