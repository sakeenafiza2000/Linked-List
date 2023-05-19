#inlcude <stdio.h>
#include <stdlib.h> 

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next; 
} *first = NULL; 

void create(int A[], int n)
{
	struct Node *t, *last; 
	int i; 
	
	first = (struct Node*)malloc(sizeof(struct Node)); 
	first->data = A[0];
	first->prev = NULL;
	first->next = NULL; 
	first = last; 
	
	for(i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i]; 
		t->prev = last; 
		last->next = t; 
		last = t; 
	}
}

void Display(struct Node *p)
{
	while(p)
	{
		printf("%d ", p->data); 
		p = p->next;	
	}
	
}

void insert(struct Node *p, int index, int x)
{
	struct Node *t; 
	
	if(index < 0 || index > Length(p))
		return;
	
	if(index == 0)
	{
		t = (struct Node*)malloc(sizeof(struct Node)); 
		t->data = x; 
		t->prev = NULL;
		t->next = first; 
		first->prev = t; 
		first = t;
	}
	else
	{
		for(int i = 0; i < index - 1; i++)
		{
			p = p->next; 
		}
		t =   (struct Node*)malloc(sizeof(struct Node));
		t->data = x;
		
		t->prev = p;
		t->next = p->next; 
		if(p->next)p->next->prev = t;
		p->next = t;
	}
}

int delete(struct Node *p, int index)
{
	struct Node *q;
	int x = -1;
	
	if(index < 1 || index > Length(p))
		return -1; 
		
	if(index == 1)
	{
		first = first->next; 
		if(first)first->prev = NULL;
		
		x = p->data;
		free(p);
	}
	else
	{
		for(int i =0; i < index - 1; i++)
			p = p->next; 
		p->prev->next = p->next; 
		if(p->next)p->next->prev = p->prev;
		
		x = p->data;
		free(p); 
	}
	
	return x;
} 




void Length(struct Node *p)
{
	int len = 0;
	while(p)
	{
		len++;
		p = p->next;
	}
	
	return len; 
}


int main()
{
	
	int A[] = {10, 20, 30, 40, 50};
	create(A, 5); 
	
	return 0; 
	
}
