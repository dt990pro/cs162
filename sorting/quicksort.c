#include <stdio.h>
#include <stdlib.h>

typedef struct timeval time;
void print_array(int *, int);
void merge(int *, int, int, int);
void merge_sort(int *, int, int);
void selection_sort(int *, int);
void insertion_sort(int *, int);
void bubble_sort(int *, int);
void fill_array(int **, int *);
void add_num(int **, int *, int);
void quicksort(int *, int, int);
int partition(int *, int, int);
void swap(int *, int, int);

int main(){
   int *nums=NULL;
   int size=0;
   //time stop, start;

   fill_array(&nums, &size);
   print_array(nums, size);
   nums = (int *)malloc(sizeof(int) * 10);

   int i, check, n = 10;

   printf("sorted-1 reversed-2: ");
   scanf("%d", &check);

   if (check == 1)
   {
	   for (i = 0; i < n; i++)
	   {
		   nums[i] = i;
	   }

	   printf("\n\n");
   }

   if (check == 2)
   {
	   for (i = 0; i < n; i++)
	   {
		   nums[i] = n - i;
	   }

	   printf("\n\n");
   }

   size = n;

   //Time the function here
   //gettimeofday(&start, NULL);
   
   quicksort(nums, 0, size-1);

   //gettimeofday(&stop, NULL);

   //printf("MicroSeconds: %d\n", stop.tv_usec-start.tv_usec);
   //printf("Seconds: %d\n", stop.tv_sec-start.tv_sec);

   print_array(nums, size);
   free(nums);

   return 0;
}

void quicksort(int a[], int low, int high)
{
	int pivot;
	// Termination condition! 
	if (high > low)
	{
		pivot = partition(a, low, high);
		quicksort(a, low, pivot - 1);
		quicksort(a, pivot + 1, high);
	}
} //end quicksort

int partition(int a[], int low, int high)
{
	int left, right;
	int pivot_item;
	int pivot = left = low;
	pivot_item = a[low];
	right = high;
	while (left < right)
	{
		// Move left while item < pivot 
		while (a[left] <= pivot_item)
			left++;
		// Move right while item > pivot 
		while (a[right] > pivot_item)
			right--;
		if (left < right)
			swap(a, left, right);
	}
	// right is final position for the pivot 
	a[low] = a[right];
	a[right] = pivot_item;
	return right;
}//end partition

void swap(int a[], int left, int right)
{
	int temp;
	temp = a[left];
	a[left] = a[right];
	a[right] = temp;
}//end swap

/*************************************************
 * Description: This prints the contents of an array
 * Params: array of integers and size of the array
 * Returns: none
 * Post-conditions: none
 * Pre-conditions: size is accurate number of 
 *                 elements in the array >=0
 * **********************************************/
void print_array(int *nums, int size){
   int i;

   printf("The array elements are:\n");
   for(i=0; i<size; i++)
      printf("%d-", nums[i]);
   printf("\n\n");
}

/*************************************************
 * Description: This adds an element to the array
 * and sets the contents to num
 * Params: address of array pointer to ints and 
 *         address of size of the array
 * Returns: none
 * Post-conditions: size is increased by one and
 * nums points to new array with one more element
 * where the contents are the same with num at the end
 * Pre-conditions: nums points to valid array or NULL
 * and size is accurate number of elements in array >=0
 * **********************************************/
void add_num(int **nums, int *size, int num){
   int *old_nums, i;

   *size+=1;
   old_nums=*nums;
   *nums=(int *) malloc(sizeof(int)*(*size));

   for(i=0; i<*size-1; i++)
      (*nums)[i]=old_nums[i];
   (*nums)[*size-1]=num;

   free(old_nums);
}

/*************************************************
 * Description: This fills an array with contents
 * from a file
 * Params: address of array pointer to ints and 
 *         address of size of the array
 * Returns: none
 * Post-conditions: array pointer is pointing to
 * valid array of integers or NULL and size has
 * a positive integer
 * Pre-conditions: nums points to valid array or NULL
 * and size is accurate number of elements in array >=0
 * **********************************************/
void fill_array(int **nums, int *size) {
   FILE *fptr;
   char filename[20], num[10];

   printf("Enter the filename: ");
   scanf("%s",filename);
   fptr=fopen(filename,"r");

   while(fscanf(fptr,"%s", num)!=EOF){
      add_num(nums, size, atoi(num));
   }

   fclose(fptr);
}
