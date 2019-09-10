#include <iostream>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int T;
    cin>>T;

    
    for(int i=0;i<T;i++){
      string X;
      cin>>X;
      int count[10]={0};
        int result =0;
      
        for(int j=0;j<X.length();j++){
            switch(X[j]){
                case '0': count[0]++; break;
                case '1': count[1]++; break;
                case '2': count[2]++; break;
                case '3': count[3]++; break;
                case '4': count[4]++; break;
                case '5': count[5]++; break;
                case '6': count[6]++; break;
                case '7': count[7]++; break;
                case '8': count[8]++; break;
                case '9': count[9]++; break;
            }
        }
        for(int i=0;i<10;i++){
            if(count[i]!=0){result++;}
        }
        cout<<result<<"\n";
    }
    return 0;
}
