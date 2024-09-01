// PRAVEENA ANAND [CH.SC.U4CSE23044]

#include <stdio.h>
#define MAX 10

int heap[MAX];
int size = 0;

void swap(int *a, int *b)
{ 
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapifyUp(int i)
{
	int parent = (i - 1) / 2;
	
	if (i > 0 && heap[i] > heap[parent])
	{
		swap(&heap[i], &heap[parent]);
		heapifyUp(parent);
	}
}

void heapifyDown(int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	
	if (l < size && heap[l] > heap[largest])
		largest = l;
		
	if (r < size && heap[r] > heap[largest])
		largest = r;
		
	if (largest != i)
	{
		swap(&heap[i], &heap[largest]);
		heapifyDown(largest);
	}
}

void enqueue()
{
	if (isFull())
	{
		printf("Overflow!\n");
		return;
	}
	
	printf("Enter the Data : ");
	scanf("%d", &heap[size]);
	heapifyUp(size);
	size++;
}

void dequeue()
{
	if (isEmpty())
	{
		printf("Underflow!\n");
		return;
	}
	
	int maxPriority = heap[0];
	heap[0] = heap[size - 1];
	size--;
	heapifyDown(0);
	
	printf("%d\n", maxPriority);
}

void peek()
{
	if (isEmpty())
	{
		printf("Underflow!\n");
		return;
	}
	
	printf("%d\n", heap[0]);
}

int isFull()
{
	return size == MAX;
}

int isEmpty()
{
	return size == 0;
}

int main()
{
	do
	{
		int ch;
		printf("\nMAIN MENU - \n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);
		
		switch (ch)
		{
			case 1:
				enqueue();
				break;
				
			case 2:
				dequeue();
				break;
				
			case 3:
				peek();
				break;
				
			case 4:
				printf("Thank you!\n");
				return 0;
				
			default:
				printf("Invalid Input!\n");
		}
	}
	while (1);
}
