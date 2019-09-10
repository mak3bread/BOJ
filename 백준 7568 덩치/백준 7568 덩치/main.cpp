#include <iostream>
using namespace std;

struct human{
    int x;
    int y;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin>>N;
    int *arr=new int[N+1];
    
    for(int i=0;i<N;i++){
        arr[i]=1;
    }
    
    human a[N];
    
    for(int i=0;i<N;i++){
        cin>>a[i].x>>a[i].y;
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(a[i].x<a[j].x&&a[i].y<a[j].y){
                arr[i]++;
            }
        }
    }
    
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
        if(i==N-1){
            cout<<'\n';
        }
    }

    return 0;
}
