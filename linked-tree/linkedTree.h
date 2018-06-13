//
//  linkedTree.h
//  linked-tree
//
//  Created by POTADOS on 2018. 5. 9..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#ifndef linkedTree_h
#define linkedTree_h

#include <stdio.h>
#include <stdlib.h>
#include "linkedQueue.h"

typedef int treeElement;


#pragma mark TreeNode

typedef struct _TreeNode {
    treeElement data;
    struct _TreeNode *left;
    struct _TreeNode *right;
    
    void (*init)(struct _TreeNode *, treeElement, struct _TreeNode *, struct _TreeNode *);
    void (*setKey)(struct _TreeNode *, treeElement);
    treeElement (*getKey)(struct _TreeNode *);
    void (*setChild)(struct _TreeNode *, struct _TreeNode *, struct _TreeNode *);
    void (*preorder)(struct _TreeNode *);
    void (*inorder)(struct _TreeNode *);
    void (*postorder)(struct _TreeNode *);
    void (*levelorder)(struct _TreeNode *);
    struct _TreeNode* (*search)(struct _TreeNode *, treeElement);
    void (*insert)(struct _TreeNode *, treeElement);
    void (*remove)(struct _TreeNode *, treeElement);
    
} _TreeNode;
typedef _TreeNode* TreeNode;

TreeNode new_TreeNode(treeElement Key, TreeNode left, TreeNode right);
void TreeNode_init(TreeNode self, treeElement key, TreeNode left, TreeNode right);
void TreeNode_setKey(TreeNode self, treeElement key);
treeElement TreeNode_getKey(TreeNode self);
void TreeNode_setChild(TreeNode self, TreeNode left, TreeNode right);
void TreeNode_preorder(TreeNode self);
void TreeNode_inorder(TreeNode self);
void TreeNode_postorder(TreeNode self);
void TreeNode_levelorder(TreeNode self);
TreeNode TreeNode_search(TreeNode self, treeElement key);
void TreeNode_insert(TreeNode self, treeElement key);
void TreeNode_remove(TreeNode self, treeElement key);

#pragma mark Tree

typedef struct _Tree {
    TreeNode root;
    
    void (*init)(struct _Tree *);
    void (*setRoot)(struct _Tree *, struct _TreeNode *);
} _Tree;
typedef _Tree* Tree;

Tree new_Tree(void);
void Tree_init(Tree self);
void Tree_setRoot(Tree self, TreeNode root);


#endif /* linkedTree_h */
