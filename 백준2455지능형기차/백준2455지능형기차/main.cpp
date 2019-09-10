#include <iostream>
using namespace std;

struct station{
    int in;
    int out;
};

int main(){
    
    int sum[4]={0};
    int p_n=0;
    int max=0;
    
    station s[4];
    
    for(int i=0;i<4;i++){
        cin>>s[i].out>>s[i].in;
        
        p_n+=(s[i].in-s[i].out);
        if(p_n>=0){
        sum[i]=p_n;
        }
    }
    max=sum[0];
    
    for(int j=1;j<4;j++){
        if(max<sum[j]){
            max=sum[j];
        }
    }
    
    cout<<max<<endl;
  
    
    
    return 0;
}
