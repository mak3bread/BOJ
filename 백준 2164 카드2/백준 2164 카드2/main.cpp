#include <iostream>
using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node<T>* prev;
    Node<T>* next;
};

template <typename T>
class Dequeue{
private:
    typedef Node<T> NODE;
    typedef Node<T>* pNODE;
    pNODE head;
    pNODE tail;
    int n;
    int result;
public:
    Dequeue(){
        head=new NODE;
        tail=new NODE;
        head->next=tail;
        tail->prev=head;
        n=0;
        result=0;
    }
    
    ~Dequeue(){while(!empty())pop();}
    
    pNODE createNew(T data){
        pNODE aNode=new NODE;
        aNode->next=NULL;
        aNode->prev=NULL;
        aNode->data=data;
        return aNode;
    }
    
    bool empty(){return (head->next==tail);}
    
    void pop(){
        if(empty()){return;}
        else{
            n--;
            pNODE removal=head->next;
            removal->next->prev=head;
            head->next=removal->next;
            delete removal;
        }
    }
    
    int size(){return n;}
    
    void push_front(T data){
        n++;
        pNODE aNode=createNew(data);
        aNode->data=data;
        aNode->next=head->next;
        aNode->prev=head;
        head->next->prev=aNode;
        head->next=aNode;
    }
    
    void push_back(T data){
        n++;
        pNODE aNode=createNew(data);
        aNode->data=data;
        aNode->next=tail;
        aNode->prev=tail->prev;
        tail->prev->next=aNode;
        tail->prev=aNode;
    }
    
    T pop_front(){
        if(empty()){return -1;}
        else{
            n--;
            pNODE removal=head->next;
            removal->next->prev=head;
            head->next=removal->next;
            result=removal->data;
            delete removal;
            return result;
        }
    }
    
    T pop_back(){
        if(empty()){return;}
        else{n--;
            pNODE removal=tail->prev;
            removal->prev->next=tail;
            tail->prev=removal->prev;
            result= removal->data;
            delete removal;
            return result;
        }
    }
    
    int top(){
        return head->next->data;
    }
    
    int rear(){
        return tail->prev->data;
    }
    
    pNODE front(){return head->next;}
    
    pNODE back(){return tail;}
    
    void print(){
        if(empty()){return;}
        else{
            for(pNODE aNode=back()->prev;aNode!=front()->prev;aNode=aNode->tail){
                cout<<aNode->data;
                if(aNode!=front()){
                    cout<<" ";
                }
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin>>N;
    Dequeue<int> dq;
    
    for(int i=1;i<=N;i++){
        dq.push_back(i);
    }
    
    int a=0;
    int i=1;
    
    while(!dq.empty()){
        
        a=dq.pop_front();
        
        if(i%2==1){
            i++;
            if(dq.empty()){break;}
            else{continue;}
        }
        
        else if(i%2==0){
            i++;
            dq.push_back(a);
        }
        
        else{
            i++;
            continue;
        }
    }
    
    cout<<a<<'\n';
    
    return 0;
}
