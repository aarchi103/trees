#include <iostream>
#include <queue>
using namespace std;
#include<math.h>


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

void levelOrderTraversal(Node* root) {

    //pehle ek queue bnaate hain, wo empty hota hai toh fir hum usmein pehle root node push krte hain aur null push krte hain for the enter line
    //fir loop chlate hain jab tak wo empty naa ho
    //har baari first element of queue ko temp mein assign krte hain aur usko pop kr dete hain
    //check if temp=null then press enter further check if there are child nodes left, if yes then push null into the queue
    //else cout the data of temp node nd push its right nd left

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

void preorder(Node* root){
    //root left right
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* root){
    // left right root
    if(root==NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

void inorder(Node* root){
    // left root right
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

int main(){
    Node* root=NULL;
    root = buildTree(root);
    cout<< "The Level order traversal: "<<endl;
    levelOrderTraversal(root);
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);
    
    return 0;
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
}
