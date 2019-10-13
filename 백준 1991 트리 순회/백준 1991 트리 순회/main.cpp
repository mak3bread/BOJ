#include <iostream>
#include <vector>
using namespace std;

struct Node{
    Node* parent;
    Node* left;
    Node* right;
    char n=NULL;
};

void preorder(Node* r,vector<Node*> T,int N){
    if(r==NULL)return;

    
    cout<<r->n;
    preorder(r->left,T,N);
    preorder(r->right,T,N);
}

void inorder(Node* r,vector<Node*> T,int N){
    if(r==NULL)return;
    
    inorder(r->left,T,N);
   
    cout<<r->n;
    
    inorder(r->right,T,N);
    
}

void postorder(Node* r,vector<Node*> T,int N){
    if(r==NULL)return;
    
    postorder(r->left,T,N);
    postorder(r->right,T,N);
    cout<<r->n;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    
    vector<Node*>tree;
    Node* root=NULL;
    
    for(int i=0;i<n;i++){
        Node* newN=new Node;
        newN->parent=NULL;
        newN->left=NULL;
        newN->right=NULL;
        newN->n=65+i;
        if(i==0){root=newN;}
        tree.push_back(newN);
    }
    
    for(int i=0;i<n;i++){
        char a;
        cin>>a;
        char b;
        cin>>b;
        char c;
        cin>>c;
        //a-65-i 번째 트리에 있음
        
        if(b=='.'||c=='.'){
            if(b=='.'&&c!='.'){
                tree[a-65]->left=NULL;
                tree[a-65]->right=tree[c-65];
                tree[c-65]->parent=tree[a-65];
            }
            else if(c=='.'&&b!='.'){
                tree[a-65]->right=NULL;
                tree[a-65]->left=tree[b-65];
                tree[b-65]->parent=tree[a-65];
            }
            else if(b=='.'&&c=='.'){
                tree[a-65]->left=NULL;
                tree[a-65]->right=NULL;
            }
            else{continue;}
        }
        
        else{
            tree[a-65]->left=tree[b-65];
            tree[a-65]->right=tree[c-65];
            tree[b-65]->parent=tree[a-65];
            tree[c-65]->parent=tree[a-65];
        }
    }

    //전위순회
    preorder(root,tree,n);
    cout<<'\n';
    inorder(root,tree,n);
    cout<<'\n';
    postorder(root,tree,n);
    cout<<'\n';
    
    return 0;
}
