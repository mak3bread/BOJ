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
class DQueue {

private:
    typedef Node<T> NODE;
    typedef Node<T>* pNODE;
    pNODE head;
    pNODE tail;
    int n;
public:
    DQueue(){
        head=new NODE;
        tail=new NODE;
        head->next=tail;
        tail->prev=head;
        n=0;
    }
    ~DQueue(){while(!empty())pop();}
    
    pNODE createNew(T data){
        pNODE newNode=new NODE;
        newNode->next=NULL;
        newNode->prev=NULL;
        newNode->data=data;
        
        return newNode;
    }
    
    bool empty(){return (head->next==tail);}
    
    int pop(){
        if(empty()){return -1;}
        else{
            n--;
            pNODE remove=tail->prev;
            
            remove->prev->next=tail;
            tail->prev=remove->prev;
            return remove->data;
            
        }
    }
    
    void push(T data){
        n++;
        pNODE aNode=createNew(data);
        aNode->next=head->next;
        aNode->prev=head;
        head->next->prev=aNode;
        head->next=aNode;
    }
    
    int size(){return n;}
    
    pNODE front(){
        return tail->prev;
    }
    
    pNODE back(){
        return head->next;
    }
    
    
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin>>N;
    DQueue<int> dq;
    
    for(int i=0;i<N;i++){
        string s;
        
        cin>>s;
        
        if(s=="push"){
            int a;
            cin>>a;
            dq.push(a);
        }
        
        else if(s=="pop"){
            cout<<dq.pop()<<'\n';
        }
        
        else if(s=="size"){
            cout<<dq.size()<<'\n';
        }
        
        else if(s=="empty"){
            cout<<dq.empty()<<'\n';
        }
        
        else if(s=="front"){
            if(dq.empty()){cout<<-1<<'\n';}
            else{
            cout<<dq.front()->data<<'\n';
            }
        }
        
        else if(s=="back"){
            if(dq.empty()){cout<<-1<<'\n';}
            else{
                cout<<dq.back()->data<<'\n';
            }
        }
        
        else{
            continue;
        }
    }
    return 0;
}
