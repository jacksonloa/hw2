all:arr.c arr.h bs.c bs.h bst.c bst.h ll.c ll.h main.c
	gcc arr.c arr.h bs.c bs.h bst.c bst.h ll.c ll.h main.c -o main
	./main -d 10000 -q 1000 -bst -bs -ll -arr