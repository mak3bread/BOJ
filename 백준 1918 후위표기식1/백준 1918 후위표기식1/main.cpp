#include <iostream>
using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
};

template <typename T>
class Dstack{
private:
    typedef Node<T> NODE;
    typedef Node<T>* pNODE;
    pNODE head;
    pNODE tail;
    T result;
    
public:
    Dstack(){
        head=new NODE;
        tail=new NODE;
        head->next=tail;
        tail->prev=head;
    }
    
    ~Dstack(){
        while(!empty())pop();
    }
    
    pNODE createNew(T data){
        pNODE newNode=new NODE;
        newNode->data =data;
        newNode->next=NULL;
        newNode->prev=NULL;
        
        return newNode;
    }

    bool empty(){return (head->next==tail);}
    
    void pop(){
           if(head->next==tail){return;}
           else{
               pNODE remove =head->next;
               remove->next->prev=head;
               head->next=remove->next;
           }
       }
    
    void push(T data){
        pNODE aNode=createNew(data);
        aNode->next=head->next;
        aNode->prev=head;
        head->next->prev=aNode;
        head->next=aNode;
    }
    
    T Top(){return head->next->data;}
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    
  
    Dstack<char> print;
    
    //65 - 90
    for(int i=0;i<s.size();i++){
        if(s[i]>=65&&s[i]<=90){
            cout<<s[i];
        }
        else if(s[i]=='('){
            print.push(s[i]);
        }
        
        else if(s[i]==')'){
            while(print.Top()!='('){
                if(!print.empty()){
                cout<<print.Top();
                print.pop();
                }
            }
            if(!print.empty()){
            print.pop();
            }
        }
        
        else if(s[i]=='+'||s[i]=='-'){
            while(print.Top()!='('&&!print.empty()){
                cout<<print.Top();
                print.pop();
            }
            print.push(s[i]);
        }
        
        else if(s[i]=='*'||s[i]=='/'){
            if(print.Top()=='+'||print.Top()=='-'){
               print.push(s[i]);
            }
            else{
                while(print.Top()!='+'&&print.Top()!='-'&&print.Top()!='('&&!print.empty()){
                    cout<<print.Top();
                    print.pop();
                }
                print.push(s[i]);
            }
        }
        else{continue;}
    }
    while(!print.empty()){
        cout<<print.Top();
        print.pop();
    }
    cout<<'\n';
    return 0;
}
