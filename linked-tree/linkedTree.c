//
//  linkedTree.c
//  linked-tree
//
//  Created by POTADOS on 2018. 5. 9..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "linkedTree.h"


#pragma mark treeNode methods

TreeNode new_TreeNode(treeElement key, TreeNode left, TreeNode right) {
    TreeNode newNode = (TreeNode)malloc(sizeof(_TreeNode));
    newNode->init = TreeNode_init;
    newNode->init(newNode, key, left, right);
    
    return newNode;
}

void TreeNode_init(TreeNode self, treeElement Key, TreeNode left, TreeNode right) {
    self->data = Key;
    self->left = left;
    self->right = right;
    
    self->setKey = TreeNode_setKey;
    self->getKey = TreeNode_getKey;
    self->setChild = TreeNode_setChild;
    self->preorder = TreeNode_preorder;
    self->inorder = TreeNode_inorder;
    self->postorder = TreeNode_postorder;
    self->levelorder = TreeNode_levelorder;
    self->search = TreeNode_search;
    self->insert = TreeNode_insert;
    self->remove = TreeNode_remove;
}

void TreeNode_setKey(TreeNode self, treeElement key) {
    self->data = key;
}

treeElement TreeNode_getKey(TreeNode self) {
    return self->data;
}

void TreeNode_setChild(TreeNode self, TreeNode left, TreeNode right) {
    self->left = left;
    self->right = right;
}

void TreeNode_preorder(TreeNode self) {
    if (self) {
        printf("%d ", self->getKey(self));
        TreeNode_preorder(self->left);
        TreeNode_preorder(self->right);
    }
}

void TreeNode_inorder(TreeNode self) {
    if (self) {
        TreeNode_inorder(self->left);
        printf("%d ", self->getKey(self));
        TreeNode_inorder(self->right);
    }
}

void TreeNode_postorder(TreeNode self) {
    if (self) {
        TreeNode_postorder(self->left);
        TreeNode_postorder(self->right);
        printf("%d ", self->getKey(self));
    }
}

void TreeNode_levelorder(TreeNode self) {
    if (self == NULL)
        return;
    
    Queue myQueue = new_Queue();
    myQueue->enqueue(myQueue, self);
    
    while (! myQueue->isEmpty(myQueue)) {
        TreeNode node = (TreeNode)myQueue->dequeue(myQueue);
        printf("%d ", node->getKey(node));
        
        if (node->left)
            myQueue->enqueue(myQueue, node->left);
        if (node->right)
            myQueue->enqueue(myQueue, node->right);
        if (node->left && node->right)
            puts("");
    }
}

TreeNode TreeNode_search(TreeNode self, treeElement key) {
    if (self == NULL)
        return NULL;
    
    if (key == self->getKey(self))
        return self;
    else if (key < self->getKey(self))
        return TreeNode_search(self->left, key);
    else
        return TreeNode_search(self->right, key);
}

void TreeNode_insert(TreeNode self, treeElement key) {
    TreeNode newNode;
    TreeNode currentNode = self;
    TreeNode parentNode = NULL;
    
    int isChildOfLeft = 0;
    
    while (currentNode != NULL) {
        if (key == currentNode->getKey(currentNode)) return;
        
        parentNode = currentNode;
        
        if (key < currentNode->getKey(currentNode)) {
            currentNode = currentNode->left;
            isChildOfLeft = 1;
        } else {
            currentNode = currentNode->right;
            isChildOfLeft = 0;
        }
    }
    
    if ((newNode = new_TreeNode(key, NULL, NULL)) == NULL)
        error("memmory allocation failed");
    
    if (parentNode){
        if (isChildOfLeft)
            parentNode->left = newNode;
        else
            parentNode->right = newNode;
    }
    else
        self = newNode;
}

void TreeNode_remove(TreeNode self, treeElement key) {
    TreeNode currentNode = self;
    TreeNode parentNode = NULL;
    int isChildOfLeft = 0;

    while (key != currentNode->getKey(currentNode)) {
        if (currentNode == NULL) return; /* not found */
        
        parentNode = currentNode;
        if (key < currentNode->getKey(currentNode)) {
            currentNode = currentNode->left;
            isChildOfLeft = 1;
        } else {
            currentNode = currentNode->right;
            isChildOfLeft = 0;
        }
    }
    
    /* Case 1: current node has no child node */
    if ((! currentNode->left) && (! currentNode->right)) {
        
        if (parentNode) {
            if (isChildOfLeft)
                parentNode->left = NULL;
            else
                parentNode->right = NULL;
        }
        else
            self = NULL; /* if key is self->data, the parent node should be NULL */
    }
    
    /* Case 2: current node has one child node */
    else if ((! currentNode->left) || (! currentNode->right)) {
        TreeNode childNode = (currentNode->left) ? currentNode->left:currentNode->right;
        
        if (parentNode) {
            if (isChildOfLeft)
                parentNode->left = childNode;
            else
                parentNode->right = childNode;
        }
        else
            self = childNode;
    }
    
    /* Case 3: current node has two child nodes */
    else if ((currentNode->left) && (currentNode->right)) {
        TreeNode successionParent = currentNode;
        TreeNode succession = currentNode->right;
        
        while (succession->left != NULL) { /* find succession and its parent */
            successionParent = succession;
            succession = succession->left;
        }

        if (successionParent == currentNode)
            successionParent->right = NULL;
        else
            successionParent->left = NULL;
        
        currentNode->setKey(currentNode, succession->getKey(succession));
        currentNode = succession;
    }
    else
        exit(-1);
    
    free(currentNode);
    
}

#pragma mark Tree methods

Tree new_Tree(void) {
    Tree newTree = (Tree)malloc(sizeof(_Tree));
    if (newTree == NULL)
        error("memmory allocation failed");
    
    newTree->init = Tree_init;
    newTree->init(newTree);
    
    return newTree;
}

void Tree_init(Tree self) {
    self->root = NULL;
    
    self->setRoot = Tree_setRoot;
}

void Tree_setRoot(Tree self, TreeNode root) {
    self->root = root;
}

/*
 7 1 9 5 8 2 3 4 6
 
 
 
            7
    1               9
        5       8
      2
       3
 
 
                            7
                    1               9
                        5        8
                      2   6
                       3
                        4
 
 
 
 
 */
