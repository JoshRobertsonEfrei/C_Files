//Josh Robertson
// 10/4/2023
//Stellantis Sept. 2023 Cohort
//Assignment: Exam for C Programming - Problem 2

//Library Inclusion
#include <stdio.h>
#include <stdlib.h>


// Implementation of a Doubly Linked list
struct node {
	struct node* prev;
	int data;
	struct node* next;
};


//Declarations
// Inserting a node in an empty list
void addToEmpty(struct node** head, int data);

// Inserting a node at the end of a doubly linked list
void addAtEnd(struct node** head, int data);

// Printing a Doubly linked List
void print_DLL(struct node** head);

// Deleting the first node of a DLL
void delFirst(struct node** head);
// Deleting the last node of a DLL
void delLast(struct node** head);

// Deleting the intermediate node of a DLL
void delInter(struct node** head, int position);

//Transform DLL to CDLL
void transform(struct node** head);

//search for value in list and returns its position
int search(struct node** head, int value);

//Sort Ascending of DLL
void sort_a(struct node** head);

//Main
int main(){

printf("\nProblem 2.\n\n");

//Create DLL of 5 elements
struct node* head = NULL;
//Adding a node to the DLL
addToEmpty(&head, 45);
//Adding to an existing DLL
addAtEnd(&head,78);
//Adding to an existing DLL
addAtEnd(&head,94);
//Adding to an existing DLL
addAtEnd(&head,35);
//Adding to an existing DLL
addAtEnd(&head,23);

printf("Here are the 5 elements of the DLL\n");
print_DLL(&head);
printf("\n");

//Deleting a particular element with position given by the user
//Delete last Test
//delLast(&head);
//print_DLL(&head);

//Delete First Test
//delFirst(&head);
//print_DLL(&head);

//Delete the intermediate node of a DLL
printf("Deleting a particular element with position given by the user\n");
delInter(&head,2);
print_DLL(&head);

printf("\n");


//Search for a particular element given by user and return its position in the list
printf("Search for element and return its position\n");

//Search for index
int location = search(&head,94);

//Print statement 
printf("The loc is: %d\n",location);
if (location == -1){
printf("The DLL is empty\n");
}else if(location == -2){
printf("The element cannot be found\n");
} else{
printf("The element can be found at node %d.\n",location);
}


//Sort Ascending
printf("\nHere is the DLL sorted in Ascending Order\n");
sort_a(&head);
print_DLL(&head);
printf("\n");

/*Transform would be as follows
sent the pre of first node to last node. send next of last node to first node
*/
printf("Transform of the DLL to a CDLL\n");
transform(&head); //Transforms the DLL to CDLL

//Free the data
free(head);

//Notes: Could add the while loop user interface later for easier usage.

}//End of main


//Definitions

// Inserting a node in an empty list
void addToEmpty(struct node** head, int data){

    //printf("Inserting a node in an empty list\n");
	struct node* temp = malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;

	*head = temp;
}

// Inserting a node at the end of a doubly linked list
void addAtEnd(struct node** head, int data){

    //printf("Inserting a node at the end of a Doubly Linked List\n");
	struct node *temp, *tp;
    temp = malloc(sizeof(struct node));


	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;
    
    
    tp = *head; //dereference head
    while(tp->next != NULL)
        tp = tp->next;
    tp->next = temp;
    temp->prev = tp;

}

//Printing a Doubly linked List
void print_DLL(struct node** head)
{
    //printf("Printing the Doubly Linked List\n");
    struct node* ptr;
    ptr = *head;
    if(ptr == NULL)
        printf("List is empty!");
        else
        {
            while(ptr != NULL)
            {
                printf("%d ", ptr->data);
                ptr = ptr->next;
            }
        }
        printf("\n"); // new line
    
}

// Deleting the first node of a DLL
void delFirst(struct node** head)
{
    printf("Deleting the first node\n");
    struct node* temp;
    temp = *head;
    *head = temp->next;
    free(temp->prev);
    temp->prev = NULL;
    //return head;
}

// Deleting the last node of a DLL
void delLast(struct node** head)
{
    printf("Deleting the last node\n");
    struct node* ptr;
    ptr = *head;
    if(ptr->next == NULL)
    {
        free(ptr);
        ptr = NULL;
        //return ptr;
    }
    else
    {
        while(ptr->next->next != NULL)
            {
                ptr = ptr->next;
            }
        free(ptr->next);
        ptr->next = NULL;
        //return head;
    }    
}

// Deleting the intermediate node of a DLL
void delInter(struct node** head, int position)
{
    printf("Deleting the node at position %d.\n",position);
    struct node* temp = *head;
    struct node* temp2 = NULL;
    if (position == 1)
        {
            delFirst(head);
            //return head;
        }
    while(position > 1)
    {
        temp = temp->next;
        position--;
    }
    if(temp->next == NULL)
        delLast(head);
    else 
    {
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
        temp = NULL;
    }
    //return head;
}

//search for value in list and returns its position
int search(struct node** head, int value){

int loc;
loc = -2; //Not found unless it otherwise changes

//Create ptr
struct node* ptr1;
ptr1 = *head;


if(ptr1==NULL){
loc = -1; //Empty
} else{

       int counter = 1;

            while(ptr1!=NULL){
            //printf("Counter %d is %d, while value is %d\n",counter,ptr1->data,value); //Code just to check

            if(ptr1->data == value){
            loc = counter;
            //return loc;
            //break;
            //printf("The index: %d\n",index); // printing here to help check the value
            }           

            counter++;
            ptr1 = ptr1->next;
            }

    }

//Old notes
/*
int loc = -2; // not found
int counter = 1;

struct node* temp;
temp = *head;

if(temp == NULL){
    loc = -1;
} else{

while(temp->next!=NULL){

if(temp->data == value){
loc = counter;
return loc;
break;
}
temp = temp->next;
counter++;
}

}
*/

return loc;

}

//Transform DLL to CDLL
void transform(struct node** head){

//Create temp ptr
struct node* temp;
struct node* temp2;
temp = *head;
temp2 = *head;

//Summary of what happens below
//if : Empty DLL
//if else : Only 1 Node
//else: > 1 Node

if(temp==NULL){
printf("The DLL is empty\n");

} else if(temp->next == NULL){
printf("The DLL is only 1 element\n");

temp->next = temp;
temp->prev = temp;
//No need to move head, there is only 1 element.
printf("The DLL is now a CDLL");
} else{

while(temp->next!=NULL){ // While loop to move the temp pointer to 
temp = temp->next; // Moves to next node, if it hits null here, won't run again and then be at end of DLL
}

temp->next = temp2; // Points to the start of the DLL
temp2->prev = temp; // Point the start of the list to the ed of the DLL
*head = temp; // head is now pointed at the previous end of the DLL, which makes it the tail.
// The variable name isn't changed, but it is effectively the tail at this point.

printf("The DLL is now a CDLL");
}//End of the else statement
}// End of transform func

//Sort Ascending of DLL
void sort_a(struct node** head){

//Variable declaration
struct node* ptr1;
struct node* ptr2;
int temp_data, trigger;
ptr1 = *head;


if(ptr1==NULL || ptr1->next == NULL){
//Nothing, the DLL is empty or only 1 node and therefore "sorted"
} else{

//variable declaration
//ptr2 = ptr1->next;

//Keeps sorting till it gets through without having moved anything around
do{
    //Variable Reset
    trigger = 0; //resets it to 0 each time, only sets of trigger if it has to rearrage
    ptr1 = *head; // Starts ptr1 at head
    ptr2 = ptr1->next; // moves ptr2 to the next node    
    
    //Iterates through the SLL
    while(ptr2 != NULL){
    
        if(ptr1->data > ptr2->data ){ //If case to swap the data of the two nodes

        trigger = 1; //

        //Swapping the data
        //Note: The data is just rearranged, not the nodes, so no need to move head.

        //Temp hold of ptr1
        temp_data = ptr1->data;

        //Assign ptr2 to ptr1
        ptr1->data = ptr2->data;

        //Assign temp (ptr1) to ptr2
        ptr2->data = temp_data;

        }  //end of if case

    //iterates to the next nodes
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

    } // end of while that moves it through the DLL one time

} while(trigger==1);

} //End of else statement

//No need to reassign head, values are only swapped, not relocated

} //End of sort a

