#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a[10];
    for(int i=0;i<10;i++){
        cin>>a[i];
        a[i]%=42;
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(i==j){continue;}
            if(a[i]==a[j]){
                a[j]=-1;
            }
        }
    }
    int count=0;
    for(int i=0;i<10;i++){
        if(a[i]>=0){
            count++;
        }
    }
    cout<<count<<'\n';
    return 0;
}
