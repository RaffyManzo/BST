link :  bst item_int main
	gcc item_int.o main.o bst.o -o bst.exe

bst :
	gcc -c bst.c
	
item_int :
	gcc -c item_int.c

main : 
	gcc -c main.c

clean : 
	rm -f *.o *.exe

