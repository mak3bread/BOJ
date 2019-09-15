
#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
class Node{
public:
    typedef Node<T>* pNODE;
    pNODE next;
    pNODE prev;
    T data;
};

template <typename T>
class DList{
private:
    typedef Node<T>* pNODE;
    typedef Node<T> NODE;
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

    pNODE begin(){
        return head->next;
    }
    
    pNODE end(){
        return tail;
    }
    
    void add(pNODE a,T data){
        pNODE newNode=createNode(data);
        newNode->data=data;
        newNode->next=a;
        newNode->prev=a->prev;
        a->prev->next=newNode;
        a->prev=newNode;
    }
    
    void remove(pNODE rNode){
        if(rNode==head||rNode==tail){return;}
        else{
            rNode->prev->next=rNode->next;
            rNode->next->prev=rNode->prev;
            delete rNode;
        }
    }
    
    void print(){
        for(pNODE a=begin();a!=end();a=a->next){
            cout<<a->data;
        }
        cout<<'\n';
    }
    
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin>>T;
    
    for(int i=0;i<T;i++){
        string s;
        cin>>s;
        DList<char> dl;
        Node<char>* cursor=dl.end();
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='<'){
               
                    if (cursor == dl.begin()) {
                        continue;
                    }
                    else {
                        cursor = cursor->prev;
                    }
            }
            else if(s[i]=='>'){
                if (cursor == dl.end()) {continue;}
                else {
                    cursor = cursor->next;
                }
            }
            else if(s[i]=='-'){
                if(dl.begin()==dl.end()||cursor==dl.begin()){continue;}
                else{
                    dl.remove(cursor->prev);
                }
            }
            
            else{
                dl.add(cursor,(char)s[i]);
                }
            }
        dl.print();
    }
    return 0;
}
