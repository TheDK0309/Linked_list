#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
int add_to_list(linked_list *ll, char *s){
	struct linked_list *x = ll;
	struct linked_list *temp = (linked_list*)malloc(sizeof(linked_list));
	int i = 0;
	if(x==NULL) return -1;
	temp->data = s;
	temp->next = NULL;

	while(x) {
		if (x->index > i) i = x->index;
		if (x->next==NULL) break;

		x = x->next;
	}
	i++;
	temp->index = i;
	x->next = temp;
	temp->prev=x;
	return temp->index;
}


int delete_from_list(linked_list *ll, int index){
	struct linked_list* current=ll;
	struct linked_list* temp;
	int i=0;
	if(current==NULL || temp==NULL) reuturn -1;
	if(index<=0 || index>display_list(ll)) return -1;
	for(i=0;i<=index-2;i++){
		
		current=current->next;
	}
	temp->next = current->next;
	current->next->previous = temp;
	free(temp);
	
	return display_list(ll)-1;
}

