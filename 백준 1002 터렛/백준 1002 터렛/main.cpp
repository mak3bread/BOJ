#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    
    for(int i=0;i<T;i++){
        int x1,y1,r1;
        int x2,y2,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        int R=0;
        if(r1-r2>=0){
            R=r1-r2;
        }
        else{
            R=-(r1-r2);
        }
        
        double d=0.0;
        d=pow(x1-x2,2)+pow(y1-y2,2);
        double sumR=(r1+r2)*(r1+r2);
        double minR=(r1-r2)*(r1-r2);
        
        if(x1==x2&&y1==y2&&r1==r2){
            cout<<-1<<'\n';
        }
        else if(d>sumR){
            cout<<0<<'\n';
        }
        else if(d==sumR){
            cout<<1<<'\n';
        }
        else if(minR<d&&d<sumR){
            cout<<2<<'\n';
        }
        else if(minR==d){
            cout<<1<<'\n';
        }
        else{
            cout<<0<<'\n';
        }
    }
    return 0;
}
