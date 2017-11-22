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
	return temp->index;
	i++;
	temp->index = i;
	x->next = temp;
	return temp->index;
}
int display_item(linked_list *ll){
	if(ll->data==NULL){
		return -1;
	}
	else{
		printf("%s\n",ll->data);
		return 0;
	}
	
}
int display_list(linked_list *ll){
	//struct linked_list* =ll;
	int count=0;
	if(ll->data==NULL){
		count=0;
		ll=ll->next;
	}
	while(ll!=NULL){
		printf("%s\n",ll->data);
		ll=ll->next;
		count++;
	}
	return count;
}
linked_list * search_from_list(linked_list *ll, char *s){
	struct linked_list* x=ll;
	while(x!=NULL){
		if(x->data== s){
			return x;
		}
		x=x->next;
	}
	return NULL;
}
int delete_from_list(linked_list *ll, int index){
	struct linked_list* current=ll;
	struct linked_list* temp;
	int i=0;
	if(index<=0 || index>display_list(ll)) return -1;
	for(i=0;i<=index-2;i++){
		
		current=current->next;
	}
	temp=current->next;
	current->next=temp->next;
	free(temp);
	
	return display_list(ll)-1;
}
int empty_list(linked_list *ll)
{
    linked_list *cursor,*tmp;
 
    if(ll != NULL)
    {
        cursor = ll->next;
        ll->next = NULL;
        while(cursor != NULL)
        {
            tmp = cursor->next;
            free(cursor);
            cursor = tmp;
        }
    }
	return display_item(ll);
}
void sort_list(linked_list *ll){
	linked_list *temp1;                         
	temp1 = (linked_list*)malloc(sizeof(linked_list)); 
 
	linked_list *temp2;                         
	temp2 = (linked_list*)malloc(sizeof(linked_list)); 
 
	char *temp;                        
 
	for( temp1 = ll ; temp1!=NULL ; temp1 = temp1->next )
	{
		for( temp2 = temp1->next ; temp2!=NULL ; temp2 = temp2->next )
		{
            if( (char *)temp1->data > (char *)temp2->data )
            {
                  temp = temp1->data;
                  temp1->data = temp2->data;
                  temp2->data = temp;
            }
		}
	}
}
void swap_list(linked_list *f, linked_list *s){
	char *temp= f->data;
	f->data=s->data;
	s->data=temp;
}
int linkedlist_status(linked_list *ll){
	linked_list *x=ll;
	int c=0;
	while(x->next!=NULL){
		c++;
		x=x->next;
	}
	return c;
}


/*
http://www.learn-c.org/en/Linked_lists
https://www.codeproject.com/Articles/24684/How-to-create-Linked-list-using-C-C
http://www.geeksforgeeks.org/delete-a-given-linked_list-in-linked-list-under-given-constraints/
http://www.zentut.com/c-tutorial/c-linked-list/
*/