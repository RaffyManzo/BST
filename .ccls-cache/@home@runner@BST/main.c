#include "bst.h"
#include "item.h"
#include <stdio.h>

void preOrder(BST b) {
  if (!isEmptyBST(b)) {
    outputItem(getItem(b));
    preOrder(getLeft(b));
    preOrder(getRight(b));
  }
}

int main() {
  BST tree = NULL;

  int aI = 11, bI = 12, cI = 10, dI = 8, eI = 7;

  insertBST(&tree, &aI);
  insertBST(&tree, &bI);
  insertBST(&tree, &cI);
  insertBST(&tree, &dI);
  insertBST(&tree, &eI);
  // insertBST(&tree, inputItem());
  printPerLevel(tree);

  printf("\n\n\nCancellazione di: ");
  outputItem(deleteBST(&tree, &dI));
  printf("\n\n");
  printPerLevel(tree);
}