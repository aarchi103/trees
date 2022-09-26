#include <iostream>
#include <queue>
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

void buildFromLevelOrder(Node* root){
    queue<Node*>q;
    int data;
    cout<<"Enter data for root of tree: "<<endl;
    cin>>data;
    root= new Node(data);
    q.push(root);
    while(!q.empty()){
        Node* temp= q.front();
        q.pop();
        cout<<" Enter data for the left of: "<<temp->data<<endl;
        int leftd;
        cin>>leftd;
        if(leftd!=-1){
            temp->left= new Node(leftd);
            q.push(temp->left);
        }

        cout<<" Enter data for the right of: "<<temp->data<<endl;
        int rightd;
        cin>>rightd;
        if(rightd!=-1){
            temp->right= new Node(rightd);
            q.push(temp->right);
        }
    }

}

int height (Node* root){
    if(root==NULL){
        return 0;
    }
    int lefth= height(root->left);
    int righth= height(root->right);
    int finalH= max(lefth,righth) +1;
    return finalH;
}



int main(){
    Node* root=NULL;
    root = buildFromLevelOrder(root);

    
    return 0;
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
}
