//Josh Robertson
//10/4/2023
//Stellantis Sept. 2023 Cohort
//Assignment: Exam for C Programming - Problem 1

//Library Inclusion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Implementation of a Singly Linked List
struct record {
    int data; //Employee data number
   // char name[30]; // string of 30 characters
    int grade; //Grade
    struct record *link;
};


//Declarations
//void add_end_sll(struct record *head, int data, char name[], int grade); // with name
void add_end_sll(struct record *head, int data, int grade); //Add element at end of SLL

//Print
void print_sll(struct record *head); // Print

//Displays the employee of a specific location
void display_employee(struct record *head, int employee_loc); //Displays the employee of a specific location

int find_pos(struct record *head, int value); //Find value and provide its index

//Delete specific node
struct record* delete_loc_sll(struct record *head, int number); //Deletes a specific element in the SLL

//Sort Descending
struct record* sort_d(struct record *head);

//Append 2 SLL's together
struct record* append_sll_decending(struct record *head, struct record *head2);

//Main
int main(void){

printf("Problem 1.\n\n");


//Starting the linked list
struct record *head = malloc(sizeof(struct record));

head->data = 123;
//char head_str[] = "Josh Robertson";
//strncpy(head->name,head_str,(sizeof(head_str)/sizeof(char))); // This is long and not sure if best method
head->grade = 5;
head->link = NULL;

struct record *current = malloc(sizeof(struct record));
current->data = 444;
//char current_str[] = "Mohamad M";
//strncpy(current->name,current_str,(sizeof(current_str)/sizeof(char))); // This is long and not sure if best method
current->grade = 2;
current->link = NULL;
head->link = current;

//Adds a 3rd element testing the function here 
add_end_sll(head,888,3); // add name later
//Adds a 4th element testing the function here 
add_end_sll(head,328,5); // add name later

//Testing my position finding based on data value
//int TTT = find_pos(head,445);
//printf("The loc is %d\n",TTT);

//Part B.
//Sort would just continue to loop through the SLL as it checks each value...
//and its next value to see if the first is less than the second.
//flips them if needed and repeats this process until you get through whole
//list wtihout needing to flip anything
//Not concerned with this part, just didnt have time...

//Part B demonstration
printf("Part B. Demonstration\nHere is the original Employee\n");
print_sll(head);
head = sort_d(head);
printf("Here is the decending sorted Employee Record\n");
print_sll(head);
printf("\n");

//Part C.
//I would create a new empty SLL. I'd extract the values from a previous employee record SLL onto it
// and then add the next one to the new SLL as well.
//Then to sort it would be easy to just use func from part B.

//Starting a second linked list
struct record *head2 = malloc(sizeof(struct record));

head2->data = 1322;
//char head_str[] = "K Robertson";
//strncpy(head->name,head_str,(sizeof(head_str)/sizeof(char))); // This is long and not sure if best method
head2->grade = 5;
head2->link = NULL;
//Adds 3 more elements
add_end_sll(head2,222,2); // add name later
add_end_sll(head2,91,4); // add name later
add_end_sll(head2,85,3); // add name later

//Part C. Demonstration
printf("Part C. Demonstration\nHere are the new employee records to integrate\n");
print_sll(head2);

//Appends and sorts them
head = append_sll_decending(head, head2); // Head is now the newly appended and sorted record
printf("Here is the newly merged employee record sorted in decending order\n");
print_sll(head);

//End of Part C demonstration

//Part A
printf("\nPart A. Demonstration\nCan test of all the features below\n");

//User input
int choice, data, grade, employee_loc;
//char name[30];

while(1){
    printf("\nHere are the following actions you can do to the employee records\n");
    printf("1. Insert Employee\n");   // Works
    printf("2. Delete Employee\n");   // Works
    printf("3. Display Employees\n"); // Works
    printf("4. Display Specific Employee by Searching ID\n");
    printf("5. Sort Descending (Part B)\n");
    printf("6. Quit\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);
    printf("\n");

switch(choice){

    case 1:
        printf("Enter the employee info to add at end of node:\n");
        printf("Please provide the Employee Number: ");
        scanf("%d", &data);//Scans the employee number

        //printf("\nPlease provide the Employee Name: ");
        //fgets(name, sizeof(name), stdin);//Scans the employee name
        
        printf("\nPlease provide the Employee Grade: ");
        scanf("%d", &grade);//Scans the employee number
        
        //add_end_sll(head,data,name,grade); // add name later
        add_end_sll(head,data,grade); // add name later

        break;

    case 2:
        printf("Which employee would you like to delete?\nPlease provide their Employee #: ");
        scanf("%d", &data);//Scans the employee number
        employee_loc = find_pos(head,data);//Data in this case is the employee number
        
        if(employee_loc==-1){
            printf("The records are empty!\n");
        } else if(employee_loc==-2){
            printf("The number was not found in the record.\n");
        } else{
            head = delete_loc_sll(head,employee_loc);
        }

        break;

    case 3:
        print_sll(head);
        printf("\n");
        break;

    case 4:

        printf("Which employee would you like to display?\nPlease provide their Employee #: ");
        scanf("%d", &data);//Scans the employee number
        int employee_loc = find_pos(head,data);//Data in this case is the employee number

        if(employee_loc==-1){
            printf("The records are empty!\n");
        } else if(employee_loc==-2){
            printf("The number was not found in the record.\n");
        } else{
            display_employee(head,employee_loc);
        }

        break;

    case 5:

        head = sort_d(head);
        printf("The employee records have been sorted in decending grade order.\n\n");

        break;

    case 6:
        printf("Loop is now ending. Thank you and have a nice day!");
        exit(1);

    default:
        printf("This is not a valid choide, try again!\n");

    }


} //End of while loop

//Free
free(head);
free(head2);

//Notes
//All working except trouble reading in string with fgets, so removed strings for now, but most of the code is there and works
//funcs to uncomment my code for once I fix my name reading issues
//print_sll
//display_employee
//add_end_sll


}//End of main


//Definitions

//Print
void print_sll(struct record *head){

    if (head == NULL)
        printf("Linked list is empty");
    else
    {
        printf("The data stored in the list:\n");
        struct record *ptr = NULL;
        ptr = head;

        while(ptr != NULL){
            //With Name version
            //printf("(%d & %s & %d) ", ptr->data, ptr->name ,ptr->grade); //This works if i include the name
            printf("(ID# %d, Grade: %d) ", ptr->data,ptr->grade);
            ptr = ptr->link;
        }
        printf("\n");
    }

}

//Displays the employee of a specific location
void display_employee(struct record *head, int employee_loc){ //Displays the employee of a specific location

    struct record *ptr = NULL;
    ptr = head;

while(employee_loc!=1){
ptr = ptr->link;
employee_loc--;
}
printf("\nEmployee Details\n");
printf("ID Number: %d\n",ptr->data);
//printf("Name: %s",ptri->name); // add name later if I fix name issues
printf("Grade: %d\n\n",ptr->grade);

}

// add end
//void add_end_sll(struct record *head, int data, char name[], int grade){ //name version i get that working
void add_end_sll(struct record *head, int data, int grade){ //Add element at end of SLL

    struct record *ptr, *temp; // Declares two node structure variables.
    ptr = head; // Starts ptr at head.
    
    temp = (struct record*) malloc(sizeof(struct record)); // Creates the new node to insert.
    temp->data = data; //Adds the new values
    //temp->name = name; // add later if I get name working
    temp->grade = grade;
    temp->link = NULL; //Null because it will be at the end of the list

    while(ptr->link != NULL){ // loops through list till you get to the current last node 
        ptr = ptr->link; // moves pointer to the subsequent node in the sll
    }

    ptr->link = temp; //Assigns the link of the last element of the current SLL to the new node
}

//Find at position
int find_pos(struct record *head, int value){

int index = -2; // Not found

if(head==NULL){
index = -1; // Empty
}else{
        
    int counter = 1;
    struct record *ptr = NULL;
    ptr = head;

            while(ptr!=NULL){

            if(ptr->data==value){
            index = counter;
            //printf("The index: %d\n",index); // printing here to help check the value
            }           

            counter++;
            ptr = ptr->link;
            }

    }

return index;

}

//Delete at a given position
struct record* delete_loc_sll(struct record *head, int number){
    //....

    struct record *ptr1, *ptr2;
    ptr1 = head;

    if(head == NULL){
        printf("The Employee record is empty!");
        return head;
    }
    if(number==1){

                struct record* temp = head;
                head = head->link;
                free(temp);
                temp = NULL;
                return head;

    } else{

    while(number!=1){
    ptr2 = ptr1; // Holds initial value of ptr for that iteration
    ptr1 = ptr1->link; //Gets the link of the next node for ptr. would be NULL if its the last node in sll
    number--;
    }

    ptr2->link = ptr1->link; //Linking one node to the node after the one you want to delete or to null
    free(ptr1); // Freeing the data for the node you deleted
    return head;
    }

}

//Sort Descending
struct record* sort_d(struct record *head){

//variable declaration
int temp_data, temp_grade;
//char temp_name; // add later for the name


if(head->link==NULL){
    //Do nothing, the SLL is sorted
}else{

//Variable declaration
    struct record *ptr1, *ptr2; // Declares two node structure variables.
    int trigger;

//Keeps sorting till it gets through without having moved anything around
do{
    //Variable Reset
    trigger = 0; //resets it to 0 each time, only sets of trigger if it has to rearrage
    ptr1 = head; // Starts ptr1 at head
    ptr2 = ptr1->link; // moves ptr2 to the next node    
    
    //Iterates through the SLL
    while(ptr2 != NULL){
    
        if(ptr1->grade < ptr2->grade ){ //If case to swap the data of the two nodes

        trigger = 1; //

        //Swapping the data
        //Note: The data is just rearranged, not the nodes, so no need to move head.

        //Temp hold of ptr1
        temp_data = ptr1->data;
        //temp_name = ptr1->name; // Add names later
        temp_grade = ptr1->grade;

        //Assign ptr2 to ptr1
        ptr1->data = ptr2->data;
        //ptr1->name = ptr2->name; // Add names later
        ptr1->grade = ptr2->grade;

        //Assign temp (ptr1) to ptr2
        ptr2->data = temp_data;
        //ptr2->name = temp_name; // Add names later
        ptr2->grade = temp_grade;


        }  //end of if case

    //iterates to the next nodes
        ptr1 = ptr1->link;
        ptr2 = ptr2->link;

    } // end of while that moves it through the SLL one time

} while(trigger==1);

}

return head;
}

//Append SLL
struct record* append_sll_decending(struct record *head, struct record *head2){

struct record *ptr;
ptr = head;

while(ptr->link != NULL){
ptr = ptr->link;
}

ptr->link = head2; //assigns the end of head to the start of head2

//sorts the newly appended list in decending order

head = sort_d(head);

return head;

}

