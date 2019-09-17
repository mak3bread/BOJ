//with stack
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
class DList{
private:
    typedef Node<T> NODE;
    typedef Node<T>* pNODE;
    pNODE head;
    pNODE tail;
    char b=NULL;
public:
    DList(){
        head=new NODE;
        tail=new NODE;
        head->next=tail;
        tail->prev=head;
    }
    ~DList(){
        while(!empty()){pop();}
    }

    pNODE createNode(T data){
        pNODE newNode=new NODE;
        newNode->data=data;
        newNode->next=NULL;
        newNode->prev=NULL;

        return newNode;
    }

    void push(T data){
        pNODE aNode=createNode(data);
        aNode->prev=head;
        aNode->next=head->next;
        head->next->prev=aNode;
        head->next=aNode;
    }

    char pop(){
        if(head->next==tail){
            return NULL;
        }
        else{
            pNODE rNode=head->next;
            b=rNode->data;
            rNode->next->prev=head;
            head->next=rNode->next;
            delete rNode;
            return b;
        }
    }

    bool empty(){
        if(head->next==tail){
            return true;
        }
        else{
            return false;
        }
    }

    pNODE top(){
        return head->next;
    }


};

int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
    DList<char> dl;
    int T;
    cin >> T;

    for (int i = 0; i < T; i++){
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++){
            if (s[j] == '(' || dl.empty()) dl.push(s[j]);
            else if(dl.top()->data == '(')dl.pop();
        }

        if (dl.empty()) {cout << "YES" << '\n';}
        else {cout << "NO" << '\n';}
        while (!dl.empty()) dl.pop();
    }

    return 0;
}



//without stack

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    int T;
//    cin >>T ;
//
//    for (int i = 0; i < T; i++){
//        string s;
//        cin >> s;
//        int count = 0;
//        for (int j = 0; j < s.length() && count >= 0; j++){
//            if (s[j] == '(') count++;
//            else count--;
//        }
//
//        if (count ==0) cout << "YES" << '\n';
//        else cout << "NO" << '\n';
//    }
//}

