#include <iostream>
using namespace std;

template <typename T>
class Node{
public:
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
    T n;
};

template <typename T>
class Tree{
private:
    typedef Node<T>* pNODE;
    typedef Node<T> NODE;
    
    int t_size;
public:
    pNODE root;
    Tree(){t_size=0;}
    ~Tree(){}
    
    pNODE createNew(T data){
        pNODE newN=new NODE;
        newN->left=NULL;
        newN->right=NULL;
        newN->n=data;
        newN->parent=NULL;
        return newN;
    }
    
    int size(){return t_size;}
    
    bool empty(){return (t_size==0);}
    
    void insert(T data){
        pNODE newN=createNew(data);
        if(empty()){
            root=newN;
            t_size++;
            return;
        }
        else{
            t_size++;
            pNODE cur=root;
            while(1){
                if(cur->n<data){
                    if(cur->right==NULL){
                        cur->right=newN;
                        newN->parent=cur;
                        break;
                    }
                    else{cur=cur->right;}
                }
                else{
                    if(cur->left==NULL){
                        cur->left=newN;
                        newN->parent=cur;
                        break;
                    }
                    else{cur=cur->left;}
                }
            }
        }
    }
    
    void postorder(pNODE r){
        if(r==NULL){return;}
        postorder(r->left);
        postorder(r->right);
        cout<<r->n<<'\n';
    }
};

int main(){
 
    int temp;
    Tree<int> btr;
    while(scanf("%d", &temp) != EOF) {
        btr.insert(temp);
    }
    btr.postorder(btr.root);
    return 0;
}
