link :  btree item_str main
	gcc item_str.o main.o btree.o -o btree.exe

btree :
	gcc -c btree.c
	
item_str :
	gcc -c item_str.c

main : 
	gcc -c main.c

clean : 
	rm -f *.o *.exe

