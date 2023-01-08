#include <stdlib.h>
#include <string.h>
typedef struct hash_table_entry_s {
	  char *key;
	    void *value;
	      struct hash_table_entry_s *next;
} hash_table_entry_t;
typedef struct {
	  hash_table_entry_t **entries;
	    unsigned long int size;
} hash_table_t;
hash_table_t *hash_table_create(unsigned long int size) {
	  hash_table_t *hash_table = malloc(sizeof(hash_table_t));
	    if (hash_table == NULL) {
		        return NULL;
			  }
	      hash_table->entries = calloc(size, sizeof(hash_table_entry_t*));
	        if (hash_table->entries == NULL) {
			    free(hash_table);
			        return NULL;
				  }
		  hash_table->size = size;
		    return hash_table;
}
