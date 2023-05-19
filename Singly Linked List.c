#include <stdio.h> 
#include <stdlib.h> 

struct Node
{
	int data;
	struct Node *next; 
} *first = NULL; //global pointer, directly accessed, can be passed as a parameter 

//create a linked list
void create(int A[], int n)
{
	int i;
	struct Node *t, *last;
	first = (struct Node *)malloc(sizeof(struct Node)); 
	first->data = A[0];
	first->next = NULL; 
	last = first; 
	
	for(i=1;i<n;i++)
	{
		t = (struct Node *)malloc(sizeof(struct Node)); 
		t->data = A[i];
		t->next = NULL; 
		last->next = t; 
		last = t; 	
	}
}

int count(struct Node *p)
{
	int l = 0;
	while(p)
	{
		l++;
		p=p->next;
	}
	return l;
}

void display(struct Node *p)
{
	while(p!=NULL)
	{
		printf("%d ", p->data);
		p = p->next; 
	}
}

void insert(struct Node *p, int index, int x)
{
	struct Node *t;
	
	if(index < 0 || index > count(p))
		return; 
		
	t = (struct Node*)malloc(sizeof(struct Node));
	t->data = x;
	
	if(index == 0)
	{
		t->next = first;
		first = t;
	}
	else
	{
		for(i=0;i<index-1;i++)
		{
			p = p->next;
		}
		t->next = p->next;
		p->next = t;  
	}	
}

int delete(struct Node *p, int pos)
{	
	struct Node *q=NULL; 
	int x = -1; 
	
	if(pos < 1 || pos > count(p))
		return -1; 
		
	if(pos == 1)
	{
		q = first;
		x = first->data;
		first = first->next;
		free(q); 
		return x;
	}
	else
	{
		for(int i = 0; i < pos - 1; i++)
		{
			q = p;
			p = p->next; 
		}
		q->next = p->next;
		x = p->data;
		free(p);
		return x; 
	}
}

int main()
{
	int A[] = {3, 5, 7, 10, 15};
	
	create(A, 5);
	
	return 0;
}
