#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    bool arr[20001];
    arr[0]=arr[1]=true;
    for(int i=2;i<=20000;i++){
        if(arr[i]==false){
            for(int j=i+i;j<=20000;j+=i){
                arr[j]=true;
            }
        }
    }
    
    for(int i=0;i<T;i++){
        int n;
        cin>>n;
        int *num=new int[n];
        for(int i=0;i<n;i++){
            if(arr[i]==false){
                num[i]=i;
            }
            else{
                num[i]=0;
            }
        }
        int min=0;
        int max=0;
        for(int i=n/2;i<n;i++){
            for(int j=0;j<=n/2;j++){
                if(num[i]+num[j]==n){
                    min=j;
                    max=i;
                    break;
                }
            }
            if(min>=1&&max>=1){
                cout<<min<<' '<<max<<'\n';
                break;
            }
        }
        delete [] num;
    }
    return 0;
}
