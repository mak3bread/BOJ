#include <iostream>
using namespace std;

int calc(int k, int n) {
    if(k == 0) {
        return n;
    }else {
        int sum =0;
        for(int i=1; i<=n; i++) {
            sum += calc(k-1, i);
        }
        return sum;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int k,n;
        cin>>k>>n;
      
        cout<<calc(k,n)<<'\n';
    }
    return 0;
}
