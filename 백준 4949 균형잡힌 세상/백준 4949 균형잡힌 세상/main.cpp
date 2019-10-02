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
class Dequeue{
private:
    typedef Node<T> NODE;
    typedef Node<T>* pNODE;
    pNODE head;
    pNODE tail;
    
public:
    Dequeue(){
        head=new NODE;
        tail=new NODE;
        head->next=tail;
        tail->prev=head;
    }
    
    ~Dequeue(){
        while(!empty()){pop();}
    }
    
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
            pNODE removal=head->next;
            removal->next->prev=head;
            head->next=removal->next;
            
        }
    }
    
    void push(T data){
        pNODE aNode=createNew(data);
        aNode->next=head->next;
        aNode->prev=tail;
        head->next->prev=aNode;
        head->next=aNode;
    }
    
    T top(){return head->next->data;}

};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    Dequeue<char> dq;
    while(true)
    {
       string s;
       getline(cin,s);
        
       if(s[0]=='.'){break;}
        
        int a=s.size();
        
        bool result=true;
        
        
        for(int i=0;i<a;i++){
            if(s[i]=='.'){break;}
            else{
                if(s[i]=='('||s[i]=='['){
                    dq.push(s[i]);
                }
                else{
                    if(s[i]==')'){
                        if(dq.top()=='('&&!dq.empty()){
                            dq.pop();
                        }
                        else{
                            if(dq.empty()){
                                result=false;
                                break;
                            }
                            else{
                            break;
                            }
                        }
                    }
                    else if(s[i]==']'){
                        if(dq.top()=='['&&!dq.empty()){
                            dq.pop();
                        }
                        else{
                            if(dq.empty()){
                                result=false;
                                break;
                            }
                            else{
                            break;
                            }
                        }
                    }
                    else{continue;}
                }
            }
        }
        
        if(dq.empty()&&result){cout<<"yes"<<'\n';}
        else{cout<<"no"<<'\n';}
        dq.~Dequeue();
        }
    
    
    
    return 0;
}
