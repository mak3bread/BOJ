#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin>>N;
    
    int i=1;
    N--;
    while((N-6*(i-1))>0){
        N=(N-6*(i-1));
        i++;
    }
    cout<<i<<'\n';
    return 0;
}
