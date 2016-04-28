all: search

search: client.o linked_list.o entry.o hash_table.o stop_word.o stop_table.o stop_linked_list.o memwatch.o
	gcc -O0 -pg -o search -g client.o linked_list.o entry.o hash_table.o stop_word.o stop_table.o stop_linked_list.o memwatch.o

client.o: client.c client.h
	gcc -c -g client.c -Wall -DMEMWATCH -DMW_STDIO

linked_list.o: linked_list.c linked_list.h
	gcc -c -g linked_list.c -Wall -DMEMWATCH -DMW_STDIO

entry.o: entry.c entry.h
	gcc -c -g entry.c -Wall -DMEMWATCH -DMW_STDIO

hash_table.o: hash_table.c hash_table.h
	gcc -c -g hash_table.c -Wall -DMEMWATCH -DMW_STDIO

stop_word.o: stop_word.c stop_word.h
	gcc -c -g stop_word.c -Wall -DMEMWATCH -DMW_STDIO

stop_table.o: stop_table.c stop_table.h
	gcc -c -g stop_table.c -Wall -DMEMWATCH -DMW_STDIO

stop_linked_list.o: stop_linked_list.c stop_linked_list.h
	gcc -c -g stop_linked_list.c -Wall -DMEMWATCH -DMW_STDIO

memwatch.o: memwatch.c memwatch.h
	gcc -c -g memwatch.c -DMEMWATCH -DMW_STDIO

clean: 
	rm *.o
	rm memwatch.log
