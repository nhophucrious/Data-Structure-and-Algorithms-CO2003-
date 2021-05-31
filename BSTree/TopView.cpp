#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
    map<Node*,int>dist;
    void traverse(Node* root, int n)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->left!=NULL)
        {
            dist[root->left] = n-1;
            traverse(root->left, n-1);
        }
        
        if(root->right !=NULL)
        {
            dist[root->right] = n+1;
            traverse(root->right, n+1);
        }
    }
    void topView(Node * root) {
        if(root == NULL)
        {
            return;
        }
        dist[root] = 0;
        traverse(root,0);
        map<int, int>view;
        queue<Node*>q;
        view[0]=root->data;
        q.push(root);
        while(q.empty() == false)
        {
            Node*curr=q.front();
            q.pop();
            if(curr->left!=NULL)
            {
                int k = dist[curr->left];
                if(view.count(k) == 0)
                view[k]=curr->left->data;
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                int k = dist[curr->right];
                if(view.count(k)==0)
                view[k]=curr->right->data;
                q.push(curr->right);
            }
        }
        for(auto x: view)
        {
            cout <<x.second<<" ";
        }
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.topView(root);
    return 0;
}
