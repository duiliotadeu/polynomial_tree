#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

struct Node
{
    int num;
    graph graph;
    struct Node *left;
    struct Node *right;
};

typedef struct Node Node;

void createTree(Node **pRoot)
{
    *pRoot = NULL;
}

void insert(Node **pRoot, int num2)
{
	if (*pRoot == NULL)
	{
	      *pRoot=(Node *)malloc(sizeof (Node));
	      (*pRoot)->left=NULL;
	      (*pRoot)->right=NULL;
	      (*pRoot)->num=num2;
	}
	else 
        {
		if (num2 < ((*pRoot)->num))
		{
			insert(&((*pRoot)->left), num2);
		}
		else
		{
			insert(&((*pRoot)->right), num2);
		}
	}
}

// It's not necessary to make a function to remove sheets in our sofwate. 

void preOrder(Node *Root){
    if(Root){
        printf("\n%d", "\t", Root->graph);
        preOrder(Root->left);
        preOrder(Root->right);
    }
}

int countSheets(Node *pRoot){
   if(pRoot == NULL)
        return 0;
   if(pRoot->left == NULL && pRoot->right == NULL)
        return 1;
   return countSheets(pRoot->left) + countSheets(pRoot->right);
} // Return the amount of maximals.