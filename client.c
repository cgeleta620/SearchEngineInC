//
// Created by Christopher Geleta on 4/15/16
//

#include "client.h"

int main(int argc, char *argv[]) {
    process(argc, argv);
    return 0;
}

void process(int argc, char *argv[]) {

   printf("Begin\n\n");

    char *file_name = NULL;
    char *stop_file = NULL;
    char *file_arr[argc];
    Stop_table *stop_table = create_table_stop(900);
    Table *t = create_table(70000);

    if (argc < 1) {
        fprintf(stderr, "Not enough arguments\n");
    }
    else {

      stop_file = argv[1];

        int q = 2;
        int s = 0;
        for (; q < argc; q++, s++) {
            file_arr[s] = argv[q];
        }

        char **arr = (char**)calloc(11000, sizeof(char *));
	//        int g = 0;
	/* for (; g < 9000; g++) {
            arr[g] = NULL;
	    }*/
	//	printf("%s\n", stop_file);
	stop_table = create_stop_table(stop_file, stop_table);
	//	printf("here\n");
	//	table_dump_stop(stop_table);

        int file_count = 0;
        int num_file = argc - 2;
        int found_stop = 0;
        int found_word = 0;

        while (file_count < num_file) {
	  //	printf("test 9\n");

            file_name = strdup(file_arr[file_count]);
            char *buffer = (char *) calloc(256 + 1, sizeof(char));
            FILE *in;
            in = fopen(file_name, "r");

            if (in == NULL) {
                fprintf(stderr, "NULL\n");
            }

            while (fscanf(in, "%s", buffer) != EOF) {
	      // printf("%s\n", buffer);
                int p = 0;
                while (buffer[p] != '\0') {
                    if (isalpha(buffer[p]) == 0) {
                        buffer[p] = ' ';
                    }
                    p++;
                }
                struct entry *entry = NULL;
                char *token;
                char *token_arr[9000];
                token = strtok(buffer, " ");

                int k = 0;
                while (token != NULL) {
                    token_arr[k] = token;
                    token = strtok(NULL, " ");
		    k++;
                }
		//	printf("K: %d\n", k);
                int v = 0;
		//	printf("Test 1\n");
                while (v < k) {
		  //	printf("Test 2\n");
		  // printf("%s\n", token_arr[v]);

                    found_stop = search_stop(stop_table, token_arr[v]);
		    //		printf("Test 3\n");

                    found_word = search_table(t, token_arr[v]);
		    //	printf("Test 4\n");

                    if (found_stop == 0) {
		      //	printf("Test 5\n");

                        if (found_word == 0) {
			  //	printf("Test 6\n");

                            arr[0] = file_name;
			    // printf("Test 6.1\n, FileName: %s\n", file_name);

                            entry = create_entry(token_arr[v], arr);
			    //	printf("Test 6.2\n");

                            t = insert(t, entry);
			    //	printf("Test 6.5\n");


                        }
                        else {
			  //		printf("Test 7\n");

                            struct entry *tmp = NULL;
                            tmp = get_entry_from_table(t, token_arr[v]);
                            if(tmp != NULL){
			      // printf("Null!\n");
			    
			    char **the_docs;

                            the_docs = get_docs(tmp);
                            qsort(the_docs, sizeof(the_docs) / sizeof(the_docs[0]), sizeof(char *), str_cmp);

                            int *item;
                            item = (int *) bsearch(&file_name, the_docs, sizeof(the_docs) / sizeof(the_docs[0]),
                                                   sizeof(char *), str_cmp);

                            if (item == NULL) {
                                int z = 0;
                                for (; z < 11000; z++) {

                                    if ((the_docs[z] == NULL)) {
                                        the_docs[z] = file_name;
                                        break;
                                    }
                                }

                                t = delete_item(t, tmp);
                                struct entry *new = NULL;
                                new = create_entry(token_arr[v], the_docs);
                                t = insert(t, new);
                            }
			    }
                        }
                    }
		    //  printf("V: %d\n", v);
                    v++;
                }
            }

            fclose(in);
            file_count++;
        }
        //table_dump(t);

        char str1[256];
        printf("\nEnter query (Ctrl - D to quit) \n");
        scanf("%s", str1);

        int found_word2 = 0;
	char ch = ' ';
	//  printf("t 80\n");

        while (ch != EOF ) {
	  //  printf("t 89\n");
	  if(ch == EOF) {
	    break;
	  }
            struct entry *tmp2 = NULL;
            found_word2 = search_table(t, str1);
            if (found_word2 != 0) {
                tmp2 = get_entry_from_table(t, str1);
                char **the_doc_list = get_docs(tmp2);
		//	printf("%s\n", the_doc_list[0]);
                int y = 0;
                for (; y < sizeof(the_doc_list)/sizeof(the_doc_list[0]); y++) {
		  // printf("%s\n", the_doc_list[0]);
                    if (the_doc_list[y] != NULL && ch != EOF) {
                        printf("%s ", the_doc_list[y]);
                    }
		     
                }
            }
	    //printf("test 67\n");

	    ch=getchar();
	    if(ch == EOF) {
	      printf("\n");
	      break;
	    }
	    // printf("\n");
            printf("\nEnter query (Ctrl - D to quit) \n");
	    
            scanf("%s", str1);

        }


    }
    printf("\n\nEnd\n");
}

Stop_table *create_stop_table(char *stop_file, Stop_table *stop_table) {

    char buffer_stop[256];
    // printf("%s\n", stop_file);
    FILE *stop;
    stop = fopen(stop_file, "r");

    while (fscanf(stop, "%s", buffer_stop) != EOF) {
      //      printf("In loop: %s\n", stop_file);
        struct stop_word *stop_entry = NULL;
        stop_entry = create_stop_word(buffer_stop);
	//	printf("test 4\n");
        stop_table = insert_stop(stop_table, stop_entry);
	//printf("test 5\n");

    }
    fclose(stop);
    return stop_table;
}

int str_cmp(const void *a, const void *b) {
    char **char_a = a;
    char **char_b = b;

    return strcmp(*char_a, *char_b);
}

