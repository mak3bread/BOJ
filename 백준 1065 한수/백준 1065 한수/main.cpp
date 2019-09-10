
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;

    if(N<100){
        cout<<N<<'\n';
    }
    if(N>=100){
        int count=0;
        for(int i=100;i<=N;i++){
            int c=i%10;
            int b=(i%100-c)/10;
            int a=(i-b*10-c)/100;
           
            if(a-b==b-c){
                count++;
            }
        }
        cout<<count+99<<'\n';
    }
    return 0;
}
