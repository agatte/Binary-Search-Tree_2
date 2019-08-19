#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

/*
 * treeNode class for storing the data in nodes of
 * BST. Data is First Name, Last Name of survivor, left and
 * right nodes to current node.
 */
class treeNode {
public:
    treeNode *left;
    treeNode *right;
    string last;
    string first;
    treeNode(string first,string last)
            : first(first)
            , last(last)
            , left(nullptr)
            , right(nullptr) {
    }
};

/*
 * Binary Search Tree Class that contains insertion, deletion, sorting and searching
 */
class BST{
public:
    treeNode *root;
    int nodes;
    BST() {
        root = nullptr;
        nodes = 0;
    }
    bool isEmpty() {
        return root == nullptr;
    }

    void insert(string first,string last) {
        treeNode *newNode = new treeNode(first,last);
        treeNode *parent = nullptr;

        // if it is first node
        if(isEmpty()) {
            root = newNode;
            nodes++;
            return;
        }
        //if BST was already there
        treeNode *curr = root;
        // Find the new node's parent
        while(curr) {
            parent = curr;
            //if last name of new node is alphabetically bigger than current node's, go to right, else go left
            curr = newNode->last.compare(curr->last)>0 ? curr->right : curr->left;
        }
        //if last name of new node is alphabetically bigger than it's parent, go to right, else go left
        if(newNode->last.compare(parent->last)<0)
            parent->left = newNode;
        else
            parent->right = newNode;
        nodes++;
    }

    void remove(string first,string last) {
        if (isEmpty()) {
            cout<<"No survivor is there"<<endl;
            return;
        }

        treeNode *curr = root;
        treeNode *parent;

        /*
         Find searched node
        */


    treeNode* search(string value) {
        treeNode *curr = root;
        while (curr) {
            if(curr->last == value) {
                 cout<<curr->first<<" "<<curr->last<<endl;
                if(curr->right && curr->right->last==value){
                    curr=curr->right;
                }
                else return curr;

            } else if(value.compare(curr->last)<0) {
                curr = curr->left;
            } else curr = curr->right;
        }
        return nullptr;
    }

    /*
     * Sort the tree using inorder to print it.
     */
    void sort(treeNode* node) {
        if(node != nullptr) {
            if(node->left) sort(node->left);
            cout << " " << node->first << " "<<node->last<<endl;
            if(node->right)
                sort(node->right);
        }
    }
};

int main() {
    char option;
    string firstName;
    string lastName;
    ifstream file("names.txt");
    string   line;
    BST *B=new BST();
    while(getline(file, line))
    {
        stringstream   linestream(line);
        linestream>>firstName>>lastName;

        B->insert(firstName,lastName);
    }
    while(1){
        cout<<"Select an option"<<endl;
        cout<<"1. Search a survivor with last name"<<endl;
        cout<<"2. Register a new survivor "<<endl;
        cout<<"3. Remove an already registered survivor "<<endl;
        cout<<"4. Count of survivors registered"<<endl;
        cout<<"5. print out of all the registered survivors in alphabetical order by family name"<<endl;
        cout<<"0. exit"<<endl;
        cin>>option;
        switch(option)
        {
            case '1' :
                cout<<"Enter survivor's last name"<<endl;
                cin>>lastName;
                if(B->search(lastName)==NULL){
                    cout<<"Sorry no survivor with this name"<<endl;
                }
                break;
            case '2' :
                cout<<"Enter survivor's first name"<<endl;
                cin>>firstName;
                cout<<"Enter survivor's last name"<<endl;
                cin>>lastName;
                B->insert(firstName,lastName);
                cout<<"Survivor added successfully"<<endl;
                break;
            case '3' :
                cout<<"Enter survivor's first name"<<endl;
                cin>>firstName;
                cout<<"Enter survivor's last name"<<endl;
                cin>>lastName;
                B->remove(firstName,lastName);
                break;
            case '4' :
                cout<<"Total "<<B->nodes<<" survivors are here."<<endl;
                break;
            case '5':
                B->sort(B->root);
                break;
            case '0':
                exit(1);

            default : cout<<"Invalid selection"<<endl;
        }
    }
    return 0;
}
