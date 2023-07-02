/****************
* Avraham sikirov
* 318731478
* 01
* ex6
***************/

#include "ex6.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Utils.h"

Trin_Ari* CreateFamilyNode(char* nameOfMember, int idMember);
Trin_Ari* findMember(Trin_Ari* headlist, int idMember);
void printFamilyTree(Trin_Ari* headlist);
void deleteNode(Trin_Ari* headlist, int id);

/******************
* Function Name: printMenu
* Input: none
* Output: Print the manu
* Function Operation: Just prints the menu
******************/

void printMenu()
{
	printf("Please select an operation:\n");
	printf("\t0. Exit.\n");
	printf("\t1. Create family.\n");
	printf("\t2. Add family member.\n");
	printf("\t3. Print Family-Tree.\n");
	printf("\t4. Bidud.\n");
	printf("\t5. Superspreader.\n");
	printf("\t6. Vaccine.\n");
	printf("\t7. Print the menu.\n");
	return;


}

/******************
* Function Name: printSubMenu
* Input: none
* Output: Print the sub manu
* Function Operation: Just prints the sub menu
******************/

void printSubMenu()
{
	printf("Please select an operation:\n");
	printf("\t0. Return to the main menu.\n");
	printf("\t1. Print Trin-Ari family.\n");
	printf("\t2. Print Pre-order.\n");
	printf("\t3. Print Left-order.\n");
	printf("\t4. Print BFS.\n");
	return;
}

/******************
* Function Name: CreateFamily
* Input: adress of headlist, pointer to int.
* Output: 
* Function Operation: The functions checks if there already been created a family, 
* if so it prints that is has been already created, if there is no family, 
* the function calls an auxilary function which node, and the the function assign this 
* node to the head to of the list.
******************/

void CreateFamily(Trin_Ari** headlist, int *isFamily)
{
	if (*isFamily == FALSE)
	{
		int id;
		char name[NAME_LENGTH];
		*isFamily = TRUE;
		printf("enter name\n");
		scanf(" %[^\n]", name);
		printf("enter ID\n");
		scanf("%d", &id);
		// Assign the node to the head of the list.
		*headlist = CreateFamilyNode(name, id);
		return;
	}
	printf("The family has already been created\n");
	return;
}

/******************
* Function Name: CreateFamilyNode
* Input: pointer to string of name of the new memnber, and int which is the id of the new member.
* Output: null or pointer to the new node of the list.
* Function Operation: The function uses malloc to assign new place in memory (new struct).
* then assign the values ​​it received and then
* assign the values to the new struct and the return the pointer to it's location.
******************/

Trin_Ari* CreateFamilyNode(char* nameOfMember, int idMember)
{
	//Allocating place in the memory.
	Trin_Ari* newNode = (Trin_Ari*)malloc(sizeof(Trin_Ari));
	// Checks if the allocation failed.
	printf("%p", newNode);
	if (newNode == NULL)
	{
		printf("Malloc Failed!");
		free(newNode);
		exit(1);
	}
	
	newNode->name = (char*)malloc(sizeof(char)*NAME_LENGTH);
	if (newNode->name == NULL)
	{
		return NULL;
	}
	// Assigning the name and the id, and the next pointers of the tree to null.
	strcpy(newNode->name, nameOfMember);
	newNode->id = idMember;
	newNode->right = NULL;
	newNode->middle = NULL;
	newNode->left = NULL;
	printf("Hello %s, ID: %d\n", newNode->name, newNode->id);
	return newNode;
}

/******************
* Function Name: addFamilyMember
* Input: adress of the head of the tree, and int which represent in there is a family. 
* Output: 
* Function Operation: The function uses an auxiliary function that
* checks if an existing user then checks the number of children.
* If everything is related the function will create a meeting
* from the left side on the right side
******************/

void addFamilyMember(Trin_Ari** headlist, int isFamily)
{
	// check if family has already been created.
	if (isFamily == FALSE)
	{
		printf("Please create the family first\n");
		return;
	}
	int firstId, secondId, flag = FALSE;;
	char name[NAME_LENGTH];
	printf("Enter the ID of the person who wants to make an appointment?\n");
	scanf("%d", &firstId);
	Trin_Ari* tempFirstId = findMember(*headlist, firstId);
	// check if the member exists.
	if (tempFirstId == NULL)
	{
		printf("There is no ID %d\n", firstId);
		return;
	}
	// check if the member has already 3 childrens. 
	if (tempFirstId->left != NULL && tempFirstId->middle != NULL && tempFirstId->right != NULL)
	{
		printf("%s ID: %d can't meet more than 3 members!\n", tempFirstId->name, tempFirstId->id);
		return;
	}
	// the loop will run until it hit a "break"
	while (flag == FALSE)
	{
		printf("enter name\n");
		scanf(" %[^\n]", name);
		printf("enter ID\n");
		scanf("%d", &secondId);
		Trin_Ari* tempSecondId = findMember(*headlist, secondId);

		if (tempSecondId != NULL)
		{
			printf("ID %d belongs to %s\n", tempSecondId->id, tempSecondId->name);
			continue;
		}

		if (tempFirstId->left == NULL)
		{
			tempFirstId->left = CreateFamilyNode(name, secondId);
			break;
		}
		if (tempFirstId->middle == NULL)
		{
			tempFirstId->middle = CreateFamilyNode(name, secondId);
			break;
		}
		if (tempFirstId->right == NULL)
		{
			tempFirstId->right = CreateFamilyNode(name, secondId);
			break;
		}
	}
	return;
}

/******************
* Function Name: findMember
* Input: adress of the head of the tree, and int which represent the id of the member.
* Output: NUll if there is no such member, is there is, the function returns pointer to it.
* Function Operation: With the help of recursion
* the function goes through the whole
* tree and finds the user by comparing his ID.
******************/

Trin_Ari* findMember(Trin_Ari* headlist, int idMember)
{
	if (headlist == NULL)
	{
		return NULL;
	}
	if (headlist->id == idMember)
	{
		return headlist;
	}
	// Saves the returned values in a temporary variable. 
	Trin_Ari* found = findMember(headlist->left, idMember);
	if (found != NULL)
	{
		return found;
	}
	//// Saves the returned values in a temporary variable. 
	found = findMember(headlist->middle, idMember);
	if (found != NULL)
	{
		return found;
	}
	return findMember(headlist->right, idMember);
}

/******************
* Function Name: findFather
* Input: adress of the head of the tree, and int which represent the id of the member.
* Output: NUll if there is no such member, is there is, the function returns pointer to it.
* Function Operation: With the help of recursion
* the function goes through the whole
* tree and finds the father by comparing his childrens ID.
******************/

Trin_Ari* findFather(Trin_Ari* headlist, int idMember)
{
	if (headlist == NULL)
	{
		return NULL;
	}
	if (headlist->left != NULL && headlist->left->id == idMember || headlist->middle != NULL &&
		headlist->middle->id == idMember || headlist->right != NULL && headlist->right->id == idMember)
	{
		return headlist;
	}	
	// Saves the returned values in a temporary variable. 
	Trin_Ari* found = findFather(headlist->left, idMember);
	if (found != NULL)
	{
		return found;
	}
	// Saves the returned values in a temporary variable. 
	found = findFather(headlist->middle, idMember);
	if (found != NULL)
	{
		return found;
	}
	return findFather(headlist->right, idMember);
}

/******************
* Function Name: printFamilyTree
* Input: pointer to the head of the tree.
* Output: prints the family tree.
* Function Operation: The function requests input from the
* user for the print form of the family, and then
* calls the function corresponding to the print
******************/

void printFamilyTree(Trin_Ari* headlist)
{
	
	char choise;
	int avrage;
	int countdevide;
	//Initial string to print before BFS
	char string[EMPTY_STRING] = "";
	while (TRUE)
	{
		printSubMenu();
		scanf(" %c", &choise);

		if (choise == '0')
		{
			return;
		}
		else if (choise == '1')
		{
			print2DUtil(headlist, TREE_SPACES);
			return;
		}
		// Calls the appropriate function the pointer to function. 
		else if (choise >= '2' && choise <= '3')
		{
			void(*function[])(Trin_Ari*) = { printPreOrder, printLeftOrder };
			(*function[CONVERT_TO_DEC - 2])(headlist);
			return;
		}
		else if (choise == '4')
		{
			BFS(headlist, string);
			return;
		}
		else
		{
			printf("Error: unrecognized operation.\n");
			continue;
		}

	}
}

/******************
* Function Name: quarantine
* Input: pointer to the head of the tree.
* Output: prints the member which should be in quarantine
* Function Operation: The function first checks that there is indeed a family,
* then checks the correctness of the ID and then prints
* everyone who comes in contact with the inserted user
******************/

void quarantine(Trin_Ari* headlist, int isFamily)
{
	if (isFamily == FALSE)
	{
		printf("Please create the family first\n");
		return;
	}
	int id;
	printf("Enter the ID of the suspected member\n");
	scanf("%d", &id);
	Trin_Ari* infected = findMember(headlist,id);
	if (infected == NULL)
	{
		printf("ID %d does not exist\n", id);
		return;
	}
	// finds the father. 
	Trin_Ari* father = findFather(headlist, id);
	// if father is null that means that the user is the father of the tree. 
	if (father != NULL)
	{
		printf("#StayHome! %s %d\n", father->name, father->id);
	}
	printf("#StayHome! %s %d\n", infected->name, infected->id);
	if (infected->left != NULL)
	printf("#StayHome! %s %d\n", infected->left->name, infected->left->id);
	if (infected->middle != NULL)
	printf("#StayHome! %s %d\n", infected->middle->name, infected->middle->id);
	if (infected->right != NULL)
	printf("#StayHome! %s %d\n", infected->right->name, infected->right->id);
}

/******************
* Function Name: superSpreader
* Input: adress  of head of the tree.
* Output: prints the member which should be in quarantine
* Function Operation: The function first checks that there is indeed a family,
* then checks the correctness of the ID and then prints
* Using the BFS print function to print anyone who needs to go into quarantine
******************/

void superSpreader(Trin_Ari** headlist, int isFamily)
{
	// Initial string before each print in the BFS function
	char string[STRING_LENGTH] = "#StayHome! ";
	if (isFamily == FALSE)
	{
		printf("Please create the family first\n");
		return;
	}
	printf("Enter the ID of the suspected Superspreader\n");
	int id;
	scanf("%d", &id);
	// find the super spreader.
	Trin_Ari* superSpreader = findMember(*headlist, id);
	if (superSpreader == NULL)
	{
		printf("ID %d does not exist\n", id);
		return;
	}
	// find the father.
	Trin_Ari* father = findFather(*headlist, id);
	if (father != NULL)
	{
		printf("#StayHome! %s %d\n", father->name, father->id);
	}
	// call BFS with the super spreader and the initial string. 
	BFS(superSpreader, string);
	return;
}

/******************
* Function Name: superSpreader
* Input: adress  of head of the tree.
* Output: prints the member which should be in quarantine
* Function Operation: The function first checks that there is indeed a family,
* then checks the correctness of the ID and then prints
* Using the BFS print function to print anyone who needs to go into quarantine
******************/

void vaccine(Trin_Ari** headlist, int* isFamily)
{
	if (*isFamily == FALSE)
	{
		printf("Please create the family first\n");
		return;
	}
	printf("Who got vaccinated (ID)?\n");
	int id;
	scanf("%d", &id);
	// find the pointer to the member who has got vaccinated. 
	Trin_Ari* vaccinated = findMember(*headlist, id);
	if (vaccinated == NULL)
	{
		printf("There is no ID %d\n", id);
		return;
	}
	// find the pointer to the father member who has got vaccinated. 
	Trin_Ari* check = findFather(*headlist, id);
	// if the father has got vaccine, It will again be possible to create a family
	if (check == NULL)
	{
		deleteRoot(*headlist, *headlist);
		*isFamily = FALSE;
	}
	deleteRoot(vaccinated, *headlist);
	if (vaccinated == *headlist)
	{
		printf("%s ID: %d Survived!\n", (*headlist)->name, (*headlist)->id);
		(*headlist) = NULL;
	}
}


void deleteRoot(Trin_Ari* headlist, Trin_Ari* tempHead)
{
	if (headlist == NULL)
		return;
	deleteRoot(headlist->left, tempHead);
	deleteRoot(headlist->middle, tempHead);
	deleteRoot(headlist->right, tempHead);
	if (tempHead == headlist)
	{
		return;
	}
	printf("%s ID: %d Survived!\n", headlist->name, headlist->id);
	deleteNode(tempHead, headlist->id);

	free(headlist->name);
	free(headlist);
}

/******************
* Function Name: deleteNode
* Input: head of the tree and integer which represent the ID member
* Output:
* Function Operation: The functions finds the father of the member, and find the location
* of the child (left middle or right) and deleting it by assigning it to null.
******************/

void deleteNode(Trin_Ari* headlist, int id)
{
	Trin_Ari* temp = findFather(headlist, id);
	if (temp == NULL)
	{
		return;
	}
	if (temp->left != NULL && temp->left->id == id)
	{
		temp->left = NULL;
	}
	if (temp->middle != NULL && temp->middle->id == id)
	{
		temp->middle = NULL;
	}
	if (temp->right != NULL && temp->right->id == id)
	{
		temp->right = NULL;
	}
}
