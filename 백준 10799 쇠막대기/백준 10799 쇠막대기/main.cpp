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
class Dstack{
private:
    typedef Node<T> NODE;
    typedef Node<T>* pNODE;
    pNODE head;
    pNODE tail;
    int n;
    
public:
    Dstack(){
        head=new NODE;
        tail=new NODE;
        head->next =tail;
        tail->prev=head;
    }
    
    ~Dstack(){
        while(!empty()){pop();}
    }
    
    pNODE createNew(T data){
        pNODE newNode=new NODE;
        newNode->data=data;
        
        newNode->next=NULL;
        newNode->prev=NULL;
        
        return newNode;
    }
    
    pNODE front(){
        return head->next;
    }
    
    pNODE back(){
        return tail;
    }

    void pop(){
        if(head->next==tail){return;}
        else{
            n--;
            pNODE xNode=head->next;
            xNode->next->prev=head;
            head->next=xNode->next;
            delete xNode;
        }
    }
    
    void push(T data){
        n++;
        pNODE nNode=createNew(data);
        nNode->next=head->next;
        nNode->prev=head;
        head->next->prev=nNode;
        head->next=nNode;
    }
    
    int size(){
        return n;
    }
    
    bool empty(){
        return (head->next==tail);
    }
           
    void print(){
        if(head->next==tail){return;
        }
        else{
            for(pNODE aNode=front();aNode!=back();aNode=aNode->next){
                cout<<aNode->data<<endl;
            }
        }
           }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin>>s;
    int result=0;
    
    Dstack<char> stack;
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            stack.push(s[i]);
        }
        else{
            stack.pop();
            if(s[i-1]=='('){
                result+=stack.size();
            }
            else{
                result++;
            }
        }
        
    }
    
    cout<<result<<'\n';
    
    return 0;
}
