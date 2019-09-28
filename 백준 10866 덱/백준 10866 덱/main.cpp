#include <iostream>
using namespace std;

template <typename T>
class Node{
public:
    Node<T>* next;
    Node<T>* prev;
    T data;
};

template <typename T>
class DeQueue{
private:
    typedef Node<T>* pNODE;
    typedef Node<T> NODE;
    pNODE head;
    pNODE tail;
    int n;
public:
    DeQueue(){
        head=new NODE;
        tail=new NODE;
        head->next=tail;
        tail->prev=head;
        n=0;
    }
    
    ~DeQueue(){
        while(!empty()) pop();
    }
    
    pNODE createNew(T data){
        pNODE aNode=new NODE;
        aNode->next=NULL;
        aNode->prev=NULL;
        aNode->data=data;
        return aNode;
    }
    
    bool empty(){return (head->next==tail);}
    
    void push_front(T data){
        pNODE fNode=createNew(data);
        fNode->next=head->next;
        fNode->prev=head;
        head->next->prev=fNode;
        head->next=fNode;
        n++;
    }
    
    void push_back(T data){
        pNODE bNode=createNew(data);
        bNode->next=tail;
        bNode->prev=tail->prev;
        tail->prev->next=bNode;
        tail->prev=bNode;
        n++;
    }
    
    void pop(){
        if(empty()){return;}
        else{
            pNODE fNode=head->next;
            fNode->next->prev=head;
            head->next=fNode->next;
            delete fNode;
        }
    }
    
    void pop_front(){
        if(empty()){cout<<-1<<'\n';}
        else{n--;
            pNODE fNode=head->next;
            fNode->next->prev=head;
            head->next=fNode->next;
            cout<<fNode->data<<'\n';
            delete fNode;
        }
    }
    
    void pop_back(){
        if(empty()){cout<<-1<<'\n';}
        else{
            n--;
            pNODE bNode=tail->prev;
            bNode->prev->next=tail;
            tail->prev=bNode->prev;
            cout<<bNode->data<<'\n';
            delete bNode;
        }
    }
    
    int size(){return n;}
    
    void front(){
        if(empty()){cout<<-1<<'\n';}
        else{
            cout<<head->next->data<<'\n';
        }
    }
    
    void back(){
        if(empty()){cout<<-1<<'\n';}
        else{
            cout<<tail->prev->data<<'\n';
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin>>N;
    DeQueue<int> dq;
    
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        
        if(s=="push_back"){
            int a;
            cin>>a;
            dq.push_back(a);
        }
        else if(s=="push_front"){
            int a;
            cin>>a;
            dq.push_front(a);
        }
        else if(s=="pop_front"){
            dq.pop_front();
        }
        else if(s=="pop_back"){
            dq.pop_back();
        }
        else if(s=="size"){
            cout<<dq.size()<<'\n';;
        }
        else if(s=="empty"){
            cout<<dq.empty()<<'\n';
        }
        else if(s=="front"){
            dq.front();
        }
        else if(s=="back"){
            dq.back();
        }
        else{continue;}
    }
    
    return 0;
}
