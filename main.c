/****************
* Avraham sikirov
* 318731478
* 01
* ex6
***************/
#include "ex6.h"
#include <stdio.h>
#include <string.h>
#include "Utils.h"
#include <stdlib.h>

int main()
{	
	Trin_Ari* headlist = NULL;
	// integer which represent if there is a family exists.
	int isFamily = FALSE;
	char choise = TRUE;
	printMenu();
	while (choise != FALSE)
	{
		scanf(" %c", &choise);
		if (choise == '0')
		{
			deleteRoot(headlist, headlist);
			if (headlist != NULL)
			{
				printf("%s ID: %d Survived!", headlist->name, headlist->id);
				free(headlist->name);
				free(headlist);
			}
			return 0;
		}
		else if (choise == '1')
		{
			CreateFamily(&headlist, &isFamily);
			printf("Select the next operation (insert 7 for the entire menu):\n");
		}
		else if (choise == '2')
		{
			addFamilyMember(&headlist, isFamily);
			printf("Select the next operation (insert 7 for the entire menu):\n");
		}
		else if (choise == '3')
		{
			printFamilyTree(headlist);
			printMenu();
		}
		else if (choise == '4')
		{
			quarantine(headlist, isFamily);
			printf("Select the next operation (insert 7 for the entire menu):\n");
		}
		else if (choise == '5')
		{
			superSpreader(&headlist, isFamily);
			printf("Select the next operation (insert 7 for the entire menu):\n");
		}
		else if (choise == '6')
		{
			vaccine(&headlist, &isFamily);
				
			printf("Select the next operation (insert 7 for the entire menu):\n");
		}
		else if (choise == '7')
		{
			printMenu();
		}
		else
		{
			printf("Error: unrecognized operation.\n");
			printf("Select the next operation (insert 7 for the entire menu):\n");
		}
	}
	return 0;
}

