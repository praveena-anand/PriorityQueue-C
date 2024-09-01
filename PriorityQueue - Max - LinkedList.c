// PRAVEENA ANAND [CH.SC.U4CSE23044]

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	int priority;
	struct node *next;
} node;

node * head = NULL;

void enqueue()
{
	node *temp = (node *)malloc(sizeof(node));
	
	int data, priority;
	
	printf("Enter the Data : ");
	scanf("%d", &data);
	
	printf("Enter the Priority : ");
	scanf("%d", &priority);
	
	temp -> data = data;
	temp -> priority = priority;
	temp -> next = NULL;
	
	if (!head || priority > head -> priority)
	{
		temp -> next = head;
		head = temp;
	}
	
	else
	{
		node *start = head;
		
		while (start -> next != NULL && start -> next -> priority >= priority)
		{
			start = start -> next;
		}
		
		temp -> next = start -> next;
		start -> next = temp;
	}
	
	printf("Successfully Inserted!\n");
}

void dequeue()
{
	if (isEmpty())
	{
		printf("Underflow!\n");
		return;
	}
	
	node * temp = head;
	head = head -> next;
	free(temp);
	
	printf("Successfully Deleted!\n");
}

void peek()
{
	if (isEmpty())
	{
		printf("Underflow!\n");
		return;
	}
	
	printf("%d\n", head -> data);
}

int isEmpty()
{
	return head == NULL;
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
