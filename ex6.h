/****************
* Avraham sikirov
* 318731478
* 01
* ex6
***************/


#ifndef _EX6_H_
#define _EX6_H_
#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0
#define NAME_LENGTH 50
#define TREE_SPACES 3
#define CONVERT_TO_DEC choise - '0'
#define STRING_LENGTH 12
#define EMPTY_STRING 1
#define LEFT 0
#define MIDDLE 1
#define RIGHT 2

struct Trin_Ari {
	int id;
	char* name;
	struct Trin_Ari* left;
	struct Trin_Ari* middle;
	struct Trin_Ari* right;
};

typedef struct Trin_Ari Trin_Ari;

void printMenu();
void CreateFamily(Trin_Ari** headlist,int* isFamily);
void addFamilyMember(Trin_Ari** headlist, int isFamily);
void printFamilyTree(Trin_Ari* headlist);
void quarantine(Trin_Ari* headlist, int isFamily);
void superSpreader(Trin_Ari** headlist, int isFamily);
void vaccine(Trin_Ari** headlist, int* isFamily);
void deleteRoot(Trin_Ari* headlist, Trin_Ari* tempHead);

#endif