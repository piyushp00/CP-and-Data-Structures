/* 
Given a BST and an integer k. Find and return the path from the node 
with data k and root (if a node with data k is present in given BST)
in a list. Return empty list otherwise.
Note: Assume that BST contains all unique elements.
*/
 

#include <iostream>
#include "BinaryTreeNode.h"
#include "Node.h"
#include <vector>
#include <climits>
#include <queue>
using namespace std;

//Root to Node Path in BST
vector<int>* rootToNodePathBST(BinaryTreeNode<int>* root, int data){
    
    
    if(root == NULL){
        return NULL;
    }

    if(root->data == data){
        vector<int>* v = new vector<int>();
        v->push_back(root->data);
        return v;
    }

    if(data < root->data){
        vector<int>* leftTree = rootToNodePathBST(root->left, data);
        if(leftTree != NULL){
            leftTree->push_back(root->data);
            return leftTree;
        } else {
            return NULL;
        }
    } 

    if(data >= root->data){
        vector<int>* rightTree = rootToNodePathBST(root->right, data);
        if(rightTree != NULL){
            rightTree->push_back(root->data);
            return rightTree;
        } else {
            return NULL;
        }
    }
}

//Print Level at New Line
void printLevelWise(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    
    while(pendingNodes.size() != 0) {
        BinaryTreeNode<int>* frontNode = pendingNodes.front();
        pendingNodes.pop();

        if(frontNode == NULL) {
            cout << endl;
            if(!pendingNodes.empty()) {
                pendingNodes.push(NULL);
            }
        } else {
            cout << frontNode->data << " ";

            if(frontNode->left != NULL) {
                pendingNodes.push(frontNode->left);
            }

            if(frontNode->right != NULL) {
                pendingNodes.push(frontNode->right);
            }
        }
    }
}

//Print Level Wise
void printTreeLevelWise(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return;
    }
    
    queue<BinaryTreeNode<int>*> pendingNode;
    pendingNode.push(root);

    while(pendingNode.size() != 0) {
        BinaryTreeNode<int>* front = pendingNode.front();
        pendingNode.pop();

        cout << front->data << ":";
        if(front->left == NULL) {
            cout<<"L:-1,";
        } else {
            cout << "L:" << front->left->data << ",";
            pendingNode.push(front->left);
        }

        if(front->right == NULL) {
            cout << "R:-1";
        } else {
            cout << "R:" << front->right->data;
            pendingNode.push(front->right);
        }
        cout << endl;
    }
}

//Take Input Level wise
BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter Root Data" << endl;
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter Left Child of " << front->data << endl; 
        int leftChildData;
        cin >> leftChildData;
        if(leftChildData != -1) {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout << "Enter Right Child of " << front->data << endl; 
        int rightChildData;
        cin >> rightChildData;
        if(rightChildData != -1) {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}



// 1 2 3 4 5 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 8 9 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    int n;
    cin >> n;
    
    vector<int>* v = rootToNodePathBST(root, n);
    cout << endl;
    for(int i = 0; i < v->size(); i++){
        cout << v->at(i) << " ";
    }
    delete root;
    delete v;
}
