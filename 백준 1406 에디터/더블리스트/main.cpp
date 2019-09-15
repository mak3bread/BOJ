#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class Node{
private:
    
public:
    T data;
    Node* next;
    Node* prev;
};

template <typename T>
class DLinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
    
public:
    DLinkedList(){
        head=new Node<T>;
        tail=new Node<T>;
        head->next=tail;
        tail->prev=head;
    }
    
    Node<T>* createNode(T data){
        Node<T>* newNode=new Node<T>;
        newNode->data=data;
        newNode->next=NULL;
        newNode->prev=NULL;
        return newNode;
    }
    
    Node<T>* Front(){
        return head->next;
    }
    
    Node<T>* Back(){
        return tail;
    }
    
    Node<T>* at(T data){
        for(Node<T>* pNode=Front();pNode!=Back();pNode=pNode->next){
            if(pNode->data==data){
                return pNode;
            }
        }
        return NULL;
    }
    
    void add(Node<T>* pNode,T data){
        Node<T>* newNode=createNode(data);
        newNode->next=pNode;
        newNode->prev=pNode->prev;
        pNode->prev->next=newNode;
        pNode->prev=newNode;
    }
    
    void addFront(T data){
        add(head->next,data);
    }
    
    void addBack(T data){
        add(tail,data);
    }
    
    void remove(Node<T>* rNode){
        if(rNode==head||rNode==tail){return;}
        else{
            rNode->prev->next=rNode->next;
            rNode->next->prev=rNode->prev;
            delete rNode;
        }
    }
    
    void removeFront(){
        remove(head->next);
    }
    
    void removeBack(){
        remove(tail->prev);
    }
    
    void printNode(){
        for(Node<T>* pNode=Front();pNode!=tail;pNode=pNode->next){
            cout<<pNode->data;
        }
        cout<<'\n';
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    int length;
    cin >> length;
    
    DLinkedList<char> dl;
    
    for (int i = 0; i < s.length(); i++) {
        dl.addBack((char)s[i]);
    }
    
    Node<char>* cursor = dl.Back();
    
    
    for (int i = 0; i < length; i++) {
        string a;
        cin >> a;
        if (a == "L") {
            if (cursor == dl.Front()) {
                continue;
            }
            else {
                cursor = cursor->prev;
            }
        }
        
        else if (a == "D") {
            if (cursor == dl.Back()) {continue;}
            else {
                cursor = cursor->next;
            }
        }
        
        else if (a == "B") {
            if (cursor == dl.Front()) {
                continue;
            }
            else {
                dl.remove(cursor->prev);
            }
        }
        
        else if (a == "P") {
            char b;
            cin >> b;
            dl.add(cursor, b);
        }
        
        else {
            continue;
        }
    }
    dl.printNode();
    
    
    return 0;
}
