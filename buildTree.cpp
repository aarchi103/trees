#include <iostream>
using namespace std;



class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this-> data=d;
        this->left=NULL;
        this->right=NULL;

    }
};

Node* buildTree(Node* root){
    cout<<"Enter the data: "<<endl;

    //pehle root node ka data in krte hain. fir root node bnate hain new se  fir left, fir right

    int data;                                               
    cin>> data;
    root= new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

int main(){
    Node* root=NULL;
    root = buildTree(root);
    
    return 0;
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
}
