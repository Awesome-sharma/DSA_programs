/******PROGRAM FOR PAIRWISE SWAP OF ELEMENTS IN LINKED LIST********/
/********AUTHOR : ANANYA SHUKLA, ADMISSION NO. : 2019B101169*******/
/******************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int info;
	struct Node* next;
};
/****************************************************************/
Getnode()
{
    struct node *t;
    t=(struct node*)malloc(sizeof(struct Node));
    return t;
}
/****************************************************************/
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
/****************************************************************/
void pairWiseSwap(struct Node* start)
{
	struct Node* temp = start;
	while (temp != NULL && temp->next != NULL)
    {
		swap(&temp->info, &temp->next->info);
		temp = temp->next->next;
	}
}
/****************************************************************/
void InsBeg(struct Node** list, int x)
{
	struct Node* p;
	p = Getnode();
	p->info = x;
	p->next = (*list);
	(*list) = p;
}
/****************************************************************/
void traverse(struct Node* node)
{
	while (node!= NULL)
    {
		printf("%d ", node->info);
		node = node->next;
	}
}
/****************************************************************/
int main()
{
	struct Node* start = NULL;
	InsBeg(&start, 5);
	InsBeg(&start, 4);
	InsBeg(&start, 3);
	InsBeg(&start, 2);
	InsBeg(&start, 1);
	printf("Linked list before calling function\n");
	traverse(start);
	pairWiseSwap(start);
	printf("\nLinked list after calling swap function\n");
	traverse(start);
	return 0;
}

