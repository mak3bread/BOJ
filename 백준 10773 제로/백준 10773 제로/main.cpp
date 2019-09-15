#include <iostream>
using namespace std;

template<typename T>
class Node{
public:
    Node<T>* next;
    Node<T>* prev;
    T data;
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
    }
    
    pNODE createNode(T data){
        pNODE newNode=new NODE;
        newNode->next=NULL;
        newNode->prev=NULL;
        newNode->data=data;
        return newNode;
    }
    
    void push(T data){
        pNODE aNode=new NODE;
        aNode->next=head->next;
        aNode->prev=head;
        head->next->prev=aNode;
        head->next=aNode;
        aNode->data=data;
    }
    
    void pop(){
        if(head->next==tail){return;}
        else{
            pNODE rNode=head->next;
            rNode->next->prev=head;
            head->next=rNode->next;
            delete rNode;
        }
    }
    
    pNODE begin(){
        return head->next;
    }
    
    pNODE end(){
        return tail;
    }
    
    int sum(){
        int result=0;
        for(pNODE a=begin();a!=end();a=a->next){
            result+=a->data;
        }
        return result;
    }
};

int main(){
    int K;
    cin>>K;
    
    DList<int> dl;
    
    for(int i=0;i<K;i++){
        int a;
        cin>>a;
        
        if(a==0){
            dl.pop();
        }
        else{
            dl.push(a);
        }
    }
    cout<<dl.sum()<<'\n';
    return 0;
}
