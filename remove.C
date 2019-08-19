void remove(string first,string last) {
    if (isEmpty()) {
        cout<<"No survivor is there"<<endl;
        return;
    }

    treeNode *curr = root;
    treeNode *parent;

    // find searched node
    while (curr) {
        if (curr->last == last && curr->first==first) {
            break;
        } else {
            parent = curr;
            curr = last.compare(curr->last)>0 ? curr->right : curr->left;
        }
    }

    if (curr == nullptr) {
        cout << "Survivor is not found! " << endl;
        return;
    }

    //if node is leaf node
    if (curr->left == nullptr and curr->right == nullptr) {
        if (parent->left == curr)
            parent->left = nullptr;
        else
            parent->right = nullptr;

        delete curr;
        nodes--;
        return;
    }

    //if  node is with single child
    if ((curr->left == nullptr and curr->right != nullptr) or (curr->left != nullptr and curr->right == nullptr)) {
        if (curr->left == nullptr and curr->right != nullptr) {
            if (parent->left == curr) {
                parent->left = curr->right;
            } else {
                parent->right = curr->right;
            }
        } else {
            if (parent->left == curr) {
                parent->left = curr->left;
            } else {
                parent->right = curr->left;
            }
        }
        delete curr;
        nodes--;
        return;
    }
    //if  node have 2 children then replace node with smallest value in right subtree
    if (curr->left != nullptr and curr->right != nullptr) {
        treeNode *curr_right = curr->right;
        if(curr_right->left == nullptr and curr_right->right == nullptr) {
            curr->first=curr_right->first;
            curr->last = curr_right->last;
            delete curr_right;
            curr->right = nullptr;
        } else {

            if((curr->right)->left != nullptr) {
                treeNode* lcurr;
                treeNode* lcurr_parent;
                lcurr_parent = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != nullptr) {
                    lcurr_parent = lcurr;
                    lcurr = lcurr->left;
                }
                curr->first=lcurr->first;
                curr->last = lcurr->last;
                delete lcurr;
                lcurr_parent->left = nullptr;
            } else {
                treeNode *tmp = curr->right;
                curr->first = tmp->first;
                curr->last = tmp->last;
                curr->right = tmp->right;
                delete tmp;
            }
        }
        nodes--;
    }
}
