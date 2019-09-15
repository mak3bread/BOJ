//링크드 리스트 없이 배열 2개로 푸는 법
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N,K;
    cin>>N>>K;
    
    int *arr =new int[N];
    int *jose=new int[N];
    
    for(int i=0;i<N;i++){
        arr[i]=i+1;
        jose[i]=0;
    }
    int index=0;
    int jump=0;
    int F_N=N;
    
    for(int i=0;i<F_N;i++){
        for(int j=0;j<K-1;j++){
            jump++;
            if(jump>N-1){
                jump=jump%N;
            }
            if(j==K-2){
                jose[index]=arr[jump];
                index++;
            }
        }
    
        for(int j=jump;j<N-1;j++){
            arr[j]=arr[j+1];
        }
        N--;
    }
    
    cout<<"<";
    if(K==1){
        for(int i=1;i<=F_N;i++){
            cout<<i;
            if(i==F_N){break;}
            cout<<", ";
        }
    }
    else{
    for(int i=0;i<F_N;i++){
        cout<<jose[i];
        if(i==F_N-1){break;}
        cout<<", ";
    }
    }
    cout<<">"<<'\n';
    
    delete []arr;
    delete []jose;
    return 0;
}
