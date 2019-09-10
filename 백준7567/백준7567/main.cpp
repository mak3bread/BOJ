#include <iostream>
using namespace std;

int main(){
    string a;
    cin>>a;
    int sum=10;
    
    if(a.length()>=3&&a.length()<=50){
    
      
    for(int i=0;i<a.length()-1;i++){
        if(a[i]==a[i+1]){
            sum+=5;
        }
        else{
            sum+=10;
        }
    }
        cout<<sum<<endl;
    }
    else{
        cout<<"오류"<<endl;
    }
    

    return 0;
}
