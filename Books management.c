#include<stdio.h> 
#include<stdlib.h> 

// Structure for a Book Information
struct Node 
{ 
	int    Year; 
	int    Version;
	float  Price;
	char*  BookName;
	char*  AuthorName;
	
	struct Node *next; 
}; 

// Function to insert a node at the beginning of a linked list.
void InsertAtTheBegin(struct Node **NodeStart_ref, int arr_Year, int arr_Version, float arr_Price, char* arr_BookName, char* arr_AuthorName); 

// Function to bubble sort the given linked list by price.
void BubbleSort_Price(struct Node *NodeStart); 

// Function to bubble sort the given linked list by year.
void BubbleSort_Year(struct Node *NodeStart); 

// Function to bubble sort the given linked list by authorname.
void BubbleSort_AuthorName(struct Node *NodeStart);

// Function to swap data of two nodes a and b.
void Swap(struct Node *a, struct Node *b); 

// Function to print nodes in a given linked list.
void PrintList(struct Node *NodeStart); 

// Function to print app details by given Author name.
void PrintAppByAuthorName(struct Node *NodeStart, char AppCount, char* AuthorName);

// Function to print app details by given Year.
void PrintAppByYear(struct Node *NodeStart, char AppCount, unsigned int Year);


// Program Start
int main() 
{ 
	// Pre-filled Books Details in Array.
	int arr_year[6]          = {1968, 			2015, 				2009, 			2009, 			1987, 				1990 }; 
	int arr_version[6]       = {1,    			2,    				3,    			4,    			5,    				6 };
	float arr_price[6]       = {340.00, 		560.00, 			238.00, 		141.00, 		451.00, 			390.00 }; 
	char* arr_BookName[6]    = { "You Can Win", "Wings of Fire", 	"India Today", 	"Orange Tree", 	"What to do NEXT", 	"Try Again" };
	char* arr_AuthorName[6]  = { "Vijay   ", 		"Kumar   ", 			"Zinthal ", 		"Triveni ", 		"Nesan   ", 			"Augutian" };
	int list_size, i; 

	// NodeStart with empty linked list.
	struct Node *NodeStart = NULL; 

	// Create linked list based application information.
	for (i = 0; i< 6; i++) 
	{
		InsertAtTheBegin(&NodeStart, arr_year[i], arr_version[i], arr_price[i], arr_BookName[i], arr_AuthorName[i]); 
	}

	// Print created linked list.
	printf("\n /********************** Array of Books Details at Program Start ************************/ ");
	PrintList(NodeStart); 
	
	/****************** A. List Application Details for a given AuthorName ******************/
	PrintAppByAuthorName(NodeStart, 6, "Triveni ");
	
	/****************** B. Sort By Price ******************/
	// Sort the linked list
	BubbleSort_Price(NodeStart); 

	// print list after sorting based on price list.
	printf("\n/******** B) Sort By Price ********/ ");
	PrintList(NodeStart); 		
	
	/****************** C. List Application Details for a given Year ******************/
    PrintAppByYear(NodeStart, 6, 2009);
	
	
	/****************** D. Sort By Year ******************/
	// Sort the linked list
	BubbleSort_Year(NodeStart); 

	// print list after sorting based on Year.
	printf("\n/******** D.1) Sort By Year ********/ ");
	PrintList(NodeStart); 	

	/****************** D. Sort By AuthorName ******************/
	// print list after sorting based on Year.
	printf("\n/******** D.2) Sort By AuthorName ********/ ");

	// Sort the linked list
	BubbleSort_AuthorName(NodeStart); 

	PrintList(NodeStart); 	

	return 0; 
} 


// Function to insert a node at the beginning of a linked list.
void InsertAtTheBegin(struct Node **NodeStart_ref, int arr_Year, int arr_Version, float arr_Price, char* arr_BookName, char* arr_AuthorName)
{ 
	struct Node *ptrNode = (struct Node*)malloc(sizeof(struct Node)); 
	
	ptrNode->Year          = arr_Year; 
	ptrNode->Version       = arr_Version;
	ptrNode->Price         = arr_Price;
	ptrNode->BookName      = arr_BookName;
	ptrNode->AuthorName    = arr_AuthorName;
	
	
	ptrNode->next = *NodeStart_ref; 
	*NodeStart_ref = ptrNode; 
} 

// Function to print nodes in a given linked list.
void PrintList(struct Node *NodeStart) 
{ 
	struct Node *temp = NodeStart; 
	printf("\n"); 
	printf("\n");
	printf("Price  Year Version   Author Name  Book Name\n");
	while (temp!=NULL) 
	{ 
		printf("%0.2f ", temp->Price); 
	    printf("%d ", temp->Year); 
		printf("   %d ", temp->Version); 
		printf("     %s ", temp->AuthorName); 
		printf("    %s ", temp->BookName); 
		printf("\n");
	
		temp = temp->next; 
	} 
} 

// Bubble sort the given linked list.
void BubbleSort_Price(struct Node *NodeStart) 
{ 
	int swapped, i; 
	struct Node *ptrNode; 
	struct Node *lptr = NULL; 

	// Checking for empty list.
	if (NodeStart == NULL) 
		return; 

	do
	{ 
		swapped = 0; 
		ptrNode = NodeStart; 

		while (ptrNode->next != lptr) 
		{ 
			if (ptrNode->Price > ptrNode->next->Price) 
			{ 
				Swap(ptrNode, ptrNode->next); 
				swapped = 1; 
			} 
			ptrNode = ptrNode->next; 
		} 
		lptr = ptrNode; 
	} 
	while (swapped); 
} 

// Function to swap data of two nodes a and b.
void Swap(struct Node *a, struct Node *b) 
{ 
	int temp    = a->Year; 
	int tempV   = a->Version; 
	float tempP = a->Price;
	char* tempB = a->BookName; 
	char* tempA = a->AuthorName; 
	
	a->Year         = b->Year; 
	a->Version      = b->Version; 
	a->Price        = b->Price; 
	a->BookName     = b->BookName; 
	a->AuthorName   = b->AuthorName; 
	
	b->Year         = temp; 
	b->Version      = tempV; 
	b->Price        = tempP; 
	b->BookName     = tempB;
	b->AuthorName   = tempA;
} 

// Print the app details by given AuthorName.
void PrintAppByAuthorName(struct Node *NodeStart, char AppCount, char* AuthorName)
{
	struct Node *ptrNode; 
	struct Node *lptr = NULL; 
	int i = 0;

	// Checking for empty list.
	if (NodeStart == NULL) 
		return; 

	ptrNode = NodeStart; 

    printf("\n/******** A) List Application Details by a given AuthorName ********/ \n\n");

	for(i=0; i < AppCount; i++)
	{
	    if(!strcmp(ptrNode->AuthorName, AuthorName))
	    { 
		    printf("%0.2f ", ptrNode->Price); 
	        printf("%d ", ptrNode->Year); 
		    printf("%d ", ptrNode->Version); 
		    printf(" %s ", ptrNode->AuthorName); 
		    printf(" %s ", ptrNode->BookName); 
		    printf("\n");
	    } 
	    else 
	    {
	        //printf("NotFound\n");
	    }
	    
	    ptrNode = ptrNode->next; 
	}
}

// Print the app details by given year.
void PrintAppByYear(struct Node *NodeStart, char AppCount, unsigned int Year)
{
	struct Node *ptrNode; 
	struct Node *lptr = NULL; 
	int i = 0;

	/* Checking for empty list */
	if (NodeStart == NULL) 
		return; 

	ptrNode = NodeStart; 

    printf("\n/******** C) List Application Details for a given Year ********/ \n\n");

	for(i=0; i < AppCount; i++)
	{
	    if(ptrNode->Year == Year)
	    { 
		    printf("%0.2f ", ptrNode->Price); 
	        printf("%d ", ptrNode->Year); 
		    printf("%d ", ptrNode->Version); 
		    printf(" %s ", ptrNode->AuthorName); 
		    printf(" %s ", ptrNode->BookName); 
		    printf("\n");
	    } 
	    else 
	    {
	        //printf("NotFound\n");
	    }
	    
	    ptrNode = ptrNode->next; 
	}
}

// Bubble sort the given linked list 
void BubbleSort_Year(struct Node *NodeStart) 
{ 
	int Swapped, i; 
	struct Node *ptrNode; 
	struct Node *ptrLastNode = NULL; 

	// Checking for empty list.
	if (NodeStart == NULL) 
		return; 

	do
	{ 
		Swapped = 0; 
		ptrNode = NodeStart; 

		// Do swap till it finds last node.
		while (ptrNode->next != ptrLastNode) 
		{ 
			if (ptrNode->Year > ptrNode->next->Year) 
			{ 
				Swap(ptrNode, ptrNode->next); 
				Swapped = 1; 
			} 
			ptrNode = ptrNode->next; 
		} 
		ptrLastNode = ptrNode; 
	} 
	while (Swapped); 
} 

void BubbleSort_AuthorName(struct Node *NodeStart) 
{
	int Swapped, i; 
	struct Node *ptrNode; 
	struct Node *ptrLastNode = NULL; 

	// Checking for empty list.
	if (NodeStart == NULL) 
		return; 

	do
	{ 
		Swapped = 0; 
		ptrNode = NodeStart; 

		// Do swap till it finds last node.
		while (ptrNode->next != ptrLastNode) 
		{ 
			if (strcmp(ptrNode->AuthorName, ptrNode->next->AuthorName) > 0) 
			{ 
				Swap(ptrNode, ptrNode->next); 
				Swapped = 1; 
			} 
			ptrNode = ptrNode->next; 
		} 
		ptrLastNode = ptrNode; 
	} 
	while (Swapped); 
}
