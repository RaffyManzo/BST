#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
struct node {
  Item value;
  struct node *left;
  struct node *right;
};

BST newBST() { return malloc(sizeof(struct node)); }

int isEmptyBST(BST bst) { return bst == NULL; }

BST getLeft(BST bst) { return bst->left; }

BST getRight(BST bst) { return bst->right; }

Item getItem(BST bst) { return bst->value; }

Item search(BST bst, Item a) {
  if (!isEmptyBST(bst)) {
    if (cmpItem(a, getItem(bst)) == 0)
      return getItem(bst);
    else if (cmpItem(a, getItem(bst)) < 0)
      return search(bst->left, a);
    else
      return search(bst->right, a);
  } else
    return NULL;
}

Item min(BST bst) {
  if (!isEmptyBST(bst)) {
    if (isEmptyBST(bst->left))
      return bst->value;
    else
      return min(bst->left);
  } else
    return NULL;
}

Item max(BST bst) {
  if (!isEmptyBST(bst)) {
    if (isEmptyBST(bst->right))
      return bst->value;
    else
      return max(bst->right);
  } else
    return NULL;
}

void insertBST(BST *bst, Item a) {
  if (isEmptyBST(*bst)) {
    *bst = newBST();
    (*bst)->left = NULL;
    (*bst)->right = NULL;
    (*bst)->value = a;
  } else {
    if (cmpItem(a, (*bst)->value) == 0)
      return;
    else if (cmpItem(a, (*bst)->value) < 0)
      insertBST(&(*bst)->left, a);
    else if (cmpItem(a, (*bst)->value) > 0)
      insertBST(&(*bst)->right, a);
  }
}
Item deleteBST(BST *bst, Item a) {
  if (isEmptyBST(*bst))
    return NULL;

  // confronta i valori con Item a
  if (cmpItem(a, (*bst)->value) > 0)
    return deleteBST(&(*bst)->right, a);
  else if (cmpItem(a, (*bst)->value) < 0)
    return deleteBST(&(*bst)->left, a);
  else {
    if (isEmptyBST((*bst)->left) && isEmptyBST((*bst)->right)) {
      // Il nodo da eliminare è una foglia
      free(*bst);
      return NULL;
    } else if (isEmptyBST((*bst)->left)) {
      // Il nodo ha solo il figlio destro
      BST tempBst = *bst;
      *bst = (*bst)->right;
      free(tempBst);
      return a;
    } else if (isEmptyBST((*bst)->right)) {
      // Il nodo ha solo il figlio sinistro
      BST tempBst = *bst;
      *bst = (*bst)->left;
      free(tempBst);
      return a;
    } else {
      // Il nodo ha sia il figlio sinistro che destro
      Item mx;
      mx = max((*bst)->left);
      Item a = (*bst)->value;
      (*bst)->value = mx;
      deleteBST(&((*bst)->left), mx);
      return a;
    }
  }
  return a;
}

int getBSTNodes(BST bst) {
  if (!isEmptyBST(bst)) {
    return 1 + getBSTNodes(bst->left) + getBSTNodes(bst->right);
  } else
    return 0;
}

void printPerLevel(BST bst) {
  if (!isEmptyBST(bst)) {
    BST *queue = malloc(getBSTNodes(bst) * sizeof(BST));
    BST current;

    queue[0] = bst;

    for (int currentRoot = 0, rearTree = 1; currentRoot < rearTree;) {
      current = queue[currentRoot++];
      if (!current)
        fprintf(stderr, "Assegnazione da queue non riuscita");
      outputItem(current->value);

      if (!isEmptyBST(getLeft(current)))
        queue[rearTree++] = getLeft(current);

      if (!isEmptyBST(getRight(current)))
        queue[rearTree++] = getRight(current);
    }
    queue = NULL;
    free(queue);
  }
}