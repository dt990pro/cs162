/******************************************************
** Program: list.c
** Author: Jiawei Mo
** Date: 06/03/2016
** Description:	a list that reads numbers from a file
**				and stores them and sorts them
** Input:	the file name
** Output:	the sorted order
******************************************************/
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	char filename[20];
	struct list l;
	l.head = NULL;
	l.tail = NULL;

	FILE *fileptr;
	char num[3]; //read positive integers 0-99
	printf("Enter filename: ");
	scanf("%s", filename);
	fileptr = fopen(filename, "r");
	//continue reading until we are at the end of the file
	while (fscanf(fileptr, "%s", num) != EOF)
	{
		printf("number is: %d\n", atoi(num));
		//push to front of list
		push_front(&l, atoi(num));
		//push to back of list
		push_back(&l, atoi(num));
	}
	//print length of list
	printf("data num: %d\n", length(l));
	//print the contents of the list
	print(l);
	//sort in ascending order
	sort_ascending(&l);
	//print the contents of the list
	printf("ascending sorted\n");
	print(l);
	//sort in descending order
	sort_descending(&l);
	//print the contents of the list
	printf("descending sorted\n");
	print(l);
	//prompt user for the value/integer to remove from list
	int val_rm;
	printf("input the val you want to remove: ");
	scanf("%d", &val_rm);
	//remove specific value/integer from list
	remove_val(&l, val_rm);
	//print the contents of the list
	print(l);
	//prompt user for item/int to add and location in list
	int val_add, loc;
	printf("the val you want to add: ");
	scanf("%d", &val_add);
	printf("the location you want to store it, by default, it pushes to the nx (right hand): ");
	scanf("%d", &loc);
	//insert int into specific location
	insert(&l, val_add, loc);
	//print the contents of the list
	print(l);
	//clear list ¨C no memory leaks
	printf("clear\n");
	clear(&l);

	fclose(fileptr);
	return 0;
}