#include <iostream>
#include <vector>
using namespace std;
vector<int>hp;
int hcount=0;

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void push(int data){
    hp.push_back(data);
    hcount++;
    if(hcount==1){return;}
    else{
        int child=hcount;
        while(1){
            int parent=child/2;
            if(child<=1||hp[parent]>=hp[child]){break;}
            else{
                swap(&hp[parent],&hp[child]);
            }
            child=child/2;
        }
    }
}

int pop(){
    if(hcount==0){return 0;}
    else{
    int result=hp[1];
        if(hcount==1){
            hcount--;
            hp.pop_back();
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
            int child;
            int parent=1;
            while(1){
                int left=(parent*2>hcount)?-1:parent*2;
                int right=(parent*2+1>hcount)?-1:parent*2+1;
                if(left==-1&&right==-1){break;}
                else if(left!=-1&&right==-1){child=left;}
                else{
                    child=(hp[left]>=hp[right])?left:right;
                }
                if(hp[parent]>=hp[child]){break;}
                else{swap(&hp[parent],&hp[child]);}
                parent=child;
            }
            return result;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    hp.push_back(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        if(x==0){
            cout<<pop()<<'\n';
        }
        else if(x>=1){
            push(x);
        }
        else{continue;}
    }
    return 0;
}
