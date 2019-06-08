/*
Hamed Mirlohi
Create Linear Link List with 10 nodes and put first 10 prime numbers and display them at the end 
*/

#include "LinkListPrimes.h"

int main()
{
	int length;
	cout << "Please indicate the size of your Link List: " << endl;
	cin >> length;

	// create the first node here
	node* head = new node;
	node* temp = head;
	head->next = nullptr;

	// fill the array with prime numbers
	int* myArray = generatePrimes(length);

	// build the link list base on the demanded length
	int i = 0;
	while (i < length)
	{
		temp->data = myArray[i];
		temp->next = new node;
		temp = temp->next;
		++i;
	}
	// end of the road, set next to nullptr
	temp->next = nullptr;

	// display results
	display_nodes(head);


}


void display_nodes(node* head)
{
	int i = 0;
	cout << "Result: " << endl;
	while (head->next != nullptr)
	{
		cout << "Node: " << i << "------>" << head->data << endl;
		head = head->next;
		++i;
	}
}

int* generatePrimes(int length)
{
	int* myArray = new int[length];

	// starting with j=2 since we know 0 and 1 are not prime numbers
	for (int index = 0, j = 2; index < length; ++j)
	{
		if ((!(j % 2) && j != 2) || (!(j % 3) && j != 3) ||
			(!(j % 5) && j != 5) || (!(j % 7) && j != 7))
			continue;

		myArray[index] = j;
		++index;
	}
	return myArray;
}