#include <iostream>
using namespace std;

template <typename T>
class Node{
public:
    Node<T>* next;
    Node<T>* prev;
    int data;
};

template <typename T>
class DList{
private:
    typedef Node<T> NODE;
    typedef Node<T>* pNODE;
    pNODE head;
    pNODE tail;
    
public:
    DList(){
        head=new NODE;
        tail=new NODE;
        head->next=tail;
        tail->prev=head;
        tail->next=head;
        head->prev=tail;
    }
    
    pNODE createNode(T data){
        pNODE newNode=new NODE;
        newNode->next=NULL;
        newNode->prev=NULL;
        newNode->data=data;
        
        return newNode;
    }
    
    pNODE begin(){
        return head;
    }
    
    pNODE end(){
        return tail;
    }
    
    void push(T data){
        pNODE nNode=createNode(data);
        nNode->next=tail;
        nNode->prev=tail->prev;
        tail->prev->next=nNode;
        tail->prev=nNode;
    }
    
    int remove(pNODE a){
        a->prev->next=a->next;
        a->next->prev=a->prev;
            return a->data;
    }
};

int main(){
    int N,K;
    cin>>N>>K;
    
    DList<int> OG;
    
    for(int i=1;i<=N;i++){
        OG.push(i);
    }
    Node<int>* pNode=OG.begin();
    cout<<"<";
    for(int i=1;i<=N;i++){
        for(int j=0;j<K;j++){
            if(pNode->next==OG.end()){
                pNode=OG.begin()->next;
                continue;
            }
            else{
                pNode=pNode->next;
            }
           
        }
        cout<<OG.remove(pNode);
        if(i==N){break;}
        cout<<", ";
    }
    cout<<">";
    cout<<'\n';
    return 0;
}
