#include <iostream>
using namespace std;

template <typename T>
class Node{
private:
public:
    Node<T>* next;
    Node<T>* prev;
    int data;
};

template <typename T>
class DList{
private:
    typedef Node<T>* pNODE;
    typedef Node<T> NODE;
    pNODE head;
    pNODE tail;
    int n;
public:
    DList(){
        head=new NODE;
        tail=new NODE;
        head->next=tail;
        tail->prev=head;
        n=0;
    }
    
    pNODE createNode(T data){
        pNODE newNode=new NODE;
        newNode->next=NULL;
        newNode->prev=NULL;
        newNode->data=data;
        return newNode;
    }
    
    
    //push, pop size empty top
    
    void push(T data){
        pNODE newNode=createNode(data);
        newNode->next=head->next;
        newNode->prev=head;
        head->next->prev=newNode;
        head->next=newNode;
        n++;
    }
    
    bool empty(){
        if(head->next==tail){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    void size(){cout<<n<<'\n';}
    
    void top(){
        if(!empty()){
            cout<<head->next->data<<'\n';
        }
        else{
            cout<<-1<<'\n';
        }
    }
    
    void pop(){
        if(empty()){
           cout<<-1<<'\n';
        }
        else{
            int a=head->next->data;
            pNODE rNode=head->next;
            head->next=rNode->next;
            rNode->next->prev=head;
            delete rNode;
            cout<<a<<'\n';
            n--;
        }
    }
    
    
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin>>N;
    DList<int> dl;
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        if(s=="push"){
            int a;
            cin>>a;
            dl.push(a);
        }
        if(s=="pop"){
            dl.pop();
        }
        if(s=="size"){
            dl.size();
        }
        if(s=="empty"){
            cout<<dl.empty()<<'\n';
        }
        if(s=="top"){
            dl.top();
        }
    }
    return 0;
}
