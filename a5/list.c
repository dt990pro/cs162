#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/*********************************************************************
** Function:	length
** Description:	display the length of the nodes
** Parameters:	number of the nodes
** Pre-Conditions:	stack list passed in
** Post-Conditions:	number of nodes displayed
*********************************************************************/
int length(struct list dt)
{
	int num = 0;
	struct node *temp = NULL;

	temp = dt.head;

	while (temp != NULL)
	{
		num += 1;
		temp = temp->next;
	}
	
	return num;
}

/*********************************************************************
** Function:	print
** Description:	display the val of the nodes
** Parameters:	none
** Pre-Conditions:	stack list passed in
** Post-Conditions:	val of nodes displayed
*********************************************************************/
void print(struct list dt)
{
	struct node *temp = NULL;

	temp = dt.head;

	printf("ele:\n");
	while (temp != NULL)
	{
		printf("%d\n", temp->val);
		temp = temp->next;
	}
}

/*********************************************************************
** Function:	push_front
** Description:	push forward val
** Parameters:	temp to hold the val
** Pre-Conditions:	stack list passed in, the data is going to stored
** Post-Conditions:	val of temp stored in the node
*********************************************************************/
void push_front(struct list *dt, int n)
{
	struct node *temp = NULL;
	temp = (struct node *) malloc(sizeof(struct node));
	temp->val = n;
	//printf("pre %d\n", temp->val);

	if (dt->head == NULL)
	{
		//initia
		temp->next = NULL;
		temp->prev = NULL;

		dt->head = temp;
		dt->tail = temp;
	}
	else
	{
		//set head
		temp->next = dt->head;
		dt->head->prev = temp;
		dt->head = temp;
		dt->head->prev = NULL;
	}
}

/*********************************************************************
** Function:	push_back
** Description:	push back val
** Parameters:	temp to hold the val
** Pre-Conditions:	stack list passed in, the data is going to stored
** Post-Conditions:	val of temp stored in the node
*********************************************************************/
void push_back(struct list *dt, int n)
{
	struct node *temp = NULL;
	temp = (struct node *) malloc(sizeof(struct node));
	temp->val = n;
	//printf("nx %d\n", temp->val);

	temp->prev = dt->tail;
	dt->tail->next = temp;
	dt->tail = dt->tail->next;
	dt->tail->next = NULL;
}

/*********************************************************************
** Function:	sort_ascending
** Description:	sort the val by ascending order
** Parameters:	temp to hold the val, check to start exchange, swp to
**				hold temp val
** Pre-Conditions:	stack list passed in
** Post-Conditions:	val sorted in ascending order
*********************************************************************/
void sort_ascending(struct list *dt)
{
	int check = 0, swp;
	struct node *temp = NULL;
	
	while (check == 0)
	{
		check = 1;
		temp = dt->head;
		
		while (temp != NULL)
		{
			if (temp->next != NULL && temp->val > temp->next->val)
			{
				check = 0;
				swp = temp->next->val;
				temp->next->val = temp->val;
				temp->val = swp;
			}
			temp = temp->next;
		}
	}
}

/*********************************************************************
** Function:	sort_descending
** Description:	sort the val by descending order
** Parameters:	temp to hold the val, check to start exchange, swp to
**				hold temp val
** Pre-Conditions:	stack list passed in
** Post-Conditions:	val sorted in descending order
*********************************************************************/
void sort_descending(struct list *dt)
{
	int check = 0, swp;
	struct node *temp = NULL;

	while (check == 0)
	{
		check = 1;
		temp = dt->head;

		while (temp != NULL)
		{
			if (temp->next != NULL && temp->val < temp->next->val)
			{
				check = 0;
				swp = temp->next->val;
				temp->next->val = temp->val;
				temp->val = swp;
			}
			temp = temp->next;
		}
	}
}

/*********************************************************************
** Function:	clear
** Description:	delete the nodes
** Parameters:	temp to hold the val
** Pre-Conditions:	stack list passed in
** Post-Conditions:	list deleted
*********************************************************************/
void clear(struct list *dt)
{
	struct node *temp = NULL;

	temp = dt->head;

	while (temp != NULL)
	{
		dt->head = temp->next;
		free(temp);
		temp = dt->head;
	}
}

/*********************************************************************
** Function:	remove_val
** Description:	remove the nodes
** Parameters:	temp to hold the val
** Pre-Conditions:	stack list passed in, int the val wanted to be rm
** Post-Conditions:	node removed
*********************************************************************/
void remove_val(struct list *dt, int n)
{
	struct node *temp = NULL;
	temp = dt->head;
	//go through the node
	while (temp != NULL)
	{
		if (temp->val == n)
		{
			if (temp == dt->head)
			{
				dt->head = dt->head->next;
				dt->head->prev = NULL;
				printf("removed\n");
				free(temp);
				return;
			}

			if (temp == dt->tail)
			{
				dt->tail = dt->tail->prev;
				dt->tail->next = NULL;
				printf("removed\n");
				free(temp);
				return;
			}

			if (!(temp->val == dt->head->val && temp->val == dt->tail->val))
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				printf("removed\n");
				free(temp);
				return;
			}
		}

		temp = temp->next;
	}
	
	printf("nothing matched\n");
}

/*********************************************************************
** Function:	insert
** Description:	insert the nodes
** Parameters:	nxtemp to hold the val, temp to locate
** Pre-Conditions:	stack list passed in, int the val wanted to be
**					added, int i to locate
** Post-Conditions:	node added
*********************************************************************/
void insert(struct list *dt, int n, int i)
{
	struct node *temp = NULL, *nxtemp = NULL;
	nxtemp = (struct node*) malloc(sizeof(struct node));
	temp = dt->head;
	nxtemp->val = n;

	int loop;
	for (loop = 0; loop < i; loop++)
	{
		temp = temp->next;

		if (temp == NULL)
		{
			printf("out of range, nothing stored.\a\n");
			free(nxtemp);
			return;
		}
	}

	if (temp->next != NULL)
	{
		nxtemp->prev = temp;
		nxtemp->next = temp->next;
		temp->next = nxtemp;
		nxtemp = nxtemp->next->prev;
	}
	else
	{
		temp = dt->tail;
		temp->next = nxtemp;
		temp = nxtemp->prev;
		dt->tail = dt->tail->next;
		dt->tail->next = NULL;
	}
}