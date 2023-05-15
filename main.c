#include "btree.h"
#include "item.h"
#include <stdio.h>

int main(){
	BTree h,a,c,d,l,p,s,o,q;
	q=buildTree(NULL,NULL,"q");
	o=buildTree(NULL,NULL,"o");
	s=buildTree(NULL,NULL,"s");
	p=buildTree(NULL,NULL,"p");
	d=buildTree(NULL,NULL,"d");
	l=buildTree(o,q,"l");
	a=buildTree(d,l,"a");
	c=buildTree(p,s,"c");
	h=buildTree(a,c,"h");
	printf("preorder:\t");
	preOrder(h);
	printf("\npostorder:\t");
	postOrder(h);
	printf("\ninorder:\t");
	inOrder(h);
	return 0;
}