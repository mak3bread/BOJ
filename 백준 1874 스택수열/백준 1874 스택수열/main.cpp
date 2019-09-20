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
    int top;
    
public:
    Dstack(){
        head=new NODE;
        tail=new NODE;
        head->next=tail;
        tail->prev=head;
        top=-1;
    }
    
    ~Dstack(){
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
    
     T Top(){return front()->data;}
    
     pNODE front(){return head->next;}
    
    pNODE back(){return tail;}
    
    void print(){
        if(head->next==tail){return;}
        else{
            for(pNODE aNode=front();aNode!=back();aNode=aNode->next){
                cout<<aNode->data<<'\n';
            }
        }
    }
    
    void push(T data){
        top++;
        pNODE aNode=createNew(data);
        aNode->prev=head;
        aNode->next=head->next;
        head->next->prev=aNode;
        head->next=aNode;
    }
    
    void pop(){
        if(head->next==tail){top--;return;}
        else{top--;
            pNODE bNode=head->next;
            bNode->next->prev=head;
            head->next=bNode->next;
            delete bNode;
        }
    }
    
    void push_back(T data){
         top++;
        pNODE aNode=createNew(data);
        aNode->next=tail;
        aNode->prev=tail->prev;
        tail->prev->next=aNode;
        tail->prev=aNode;
    }
    
    int size(){return top+1;}
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    
    int num=1;
    
    int *arr=new int[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Dstack<int> stack;
    Dstack<char> List;
    
    for (int i = 0; i < n; ++i) {
        if (stack.empty() || stack.Top() != arr[i]) {
            while (1) {
                if (num > n) {
                    cout<<"NO"<<'\n';
                    return 0;
                }
                
                stack.push(num++);
                List.push_back('+');
                
                if (stack.Top() == arr[i]) {
                    stack.pop();
                    List.push_back('-');
                    break;
                }
            }
        }
        else if (stack.Top() == arr[i]) {
            stack.pop();
            List.push_back('-');
        }
    }
    
    List.print();
    
    
    delete []arr;
    return 0;
}
