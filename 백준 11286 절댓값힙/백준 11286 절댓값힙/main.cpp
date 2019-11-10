//vector 만 이용한 힙 구현
#include <iostream>
#include <vector>
using namespace std;

class Heap{
private:
    int hcount;
public:
    vector<int> hp;
    Heap(){
        hp.push_back(0);
        hcount=0;
    }
    ~Heap(){hp.clear();}
    
    void swap(int* a,int* b){
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    
    bool empty(){return(hcount==0);}
    
    void insert(int data){
        hp.push_back(data);
        hcount++;
        if(hcount<=1){return;}
        else{
            int child=hcount;
            while(1){
                if(child<=1){break;}
                int parent=child/2;
                int chil;
                int par;
                if(hp[child]<0){chil=-hp[child];}
                else{chil=hp[child];}
                if(hp[parent]<0){par=-hp[parent];}
                else{par=hp[parent];}
                if(chil>par){break;}
                else if(chil==par){
                    if(hp[child]>=hp[parent]){break;}
                    else{swap(&hp[parent],&hp[child]);}
                }
                else{swap(&hp[parent],&hp[child]);}
                child=child/2;
            }
        }
    }
    
    int pop(){
        if(empty()){return 0;}
        else{
            int result=hp[1];
            if(hcount<=1){
                hp.pop_back();
                hcount--;
                return result;
            }
            else if(hcount==2){
                swap(&hp[1],&hp[2]);
                hcount--;
                hp.pop_back();
                return result;
            }
            else{
                swap(&hp[1],&hp[hcount]);
                hcount--;
                hp.pop_back();
                int parent=1;
                while(1){
                    int child;
                    int left=2*parent>hcount?-1:2*parent;
                    int right=2*parent+1>hcount?-1:2*parent+1;
                    if(left==-1&&right==-1){break;}
                    else if(left!=-1&&right==-1){child=left;}
                    else{
                        int lf;
                        int rt;
                        if(hp[left]<0){lf=-hp[left];}
                        else{lf=hp[left];}
                        if(hp[right]<0){rt=-hp[right];}
                        else{rt=hp[right];}
                        if(lf>rt){child=right;}
                        else if(lf==rt){
                            if(hp[right]>=hp[left]){child=left;}
                            else{child=right;}
                        }
                        else{child=left;}
                    }
                    int chil;
                    int par;
                    if(hp[child]<0){chil=-hp[child];}
                    else{chil=hp[child];}
                    if(hp[parent]<0){par=-hp[parent];}
                    else{par=hp[parent];}
                    if(chil>par){break;}
                    else if(chil==par){
                        if(hp[child]>=hp[parent]){break;}
                        else{swap(&hp[parent],&hp[child]);}
                    }
                    else{swap(&hp[parent],&hp[child]);}
                    parent=child;
                }
                return result;
            }
        }
    }
    
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    Heap hp;
    
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        if(x==0){
            cout<<hp.pop()<<'\n';
        }
        else{
            hp.insert(x);
        }
    }
    
    return 0;
}
