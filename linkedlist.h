 
typedef struct linked_list{
	char *data;
	int index; 
	struct linked_list *next;
}linked_list;
int add_to_list(linked_list *ll, char *s);
int display_item(linked_list *ll);
int display_list(linked_list *ll);
linked_list * search_from_list(linked_list *ll, char *s);
int delete_from_list(linked_list *ll, int index);
int empty_list(linked_list *ll);
void sort_list(linked_list *ll);
void swap_list(linked_list *f, linked_list *s);
int linkedlist_status(linked_list *ll);