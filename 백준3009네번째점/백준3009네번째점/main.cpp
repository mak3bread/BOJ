#include <iostream>
using namespace std;

struct point{
    int x;
    int y;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    point pt[3];
    
    for(int i=0;i<3;i++){
        cin>>pt[i].x>>pt[i].y;
    }
    point last_pt;
    
    if(pt[0].x==pt[1].x&&pt[0].x!=pt[2].x){
        last_pt.x=pt[2].x;
    }
    if(pt[0].x!=pt[1].x&&pt[0].x==pt[2].x){
         last_pt.x=pt[1].x;
    }
    if(pt[1].x==pt[2].x&&pt[0].x!=pt[2].x){
        last_pt.x=pt[0].x;
    }
    if(pt[0].y==pt[1].y&&pt[0].y!=pt[2].y){
        last_pt.y=pt[2].y;
    }
    if(pt[0].y!=pt[1].y&&pt[0].y==pt[2].y){
        last_pt.y=pt[1].y;
    }
    if(pt[1].y==pt[2].y&&pt[0].y!=pt[2].y){
        last_pt.y=pt[0].y;
    }
    
    cout<<last_pt.x<<' '<<last_pt.y<<'\n';
    return 0;
}
