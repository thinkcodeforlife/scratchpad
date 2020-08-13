#include <stdlib.h>
#include <stdio.h>
// #include <mysql.h>
#include <math.h>
#include <ctype.h>
#include <errno.h>
#include <signal.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
// ******************************
// #include <threads.h>
// #include <regex.h>
// #include <sys/socket.h>
// #include <sys/types.h>
// ******************************

// ******************************
#define MAX_COLUMN_NAME 128
#define MAX_COLUMN_COUNT 64
#define MAX_ROW_CONTENT 256
#define MAX_ROW_COUNT 100
// ******************************
// typedef struct _table
// {
// 	char* name;
// 	char columns[MAX_COLUMN_COUNT][MAX_COLUMN_NAME];
// 	char rows[MAX_ROW_COUNT][MAX_COLUMN_COUNT][MAX_ROW_CONTENT];
// 	int columnCount;
// 	int rowCount;
// } table;
// ******************************
// typedef struct _table
// {
// 	char* name;
// 	char** columns;
// 	char*** rows;
// 	int columnCount;
// 	int rowCount;
// } table;
// ******************************
typedef struct _table
{
	char* name;
	char* columns[MAX_COLUMN_COUNT];
	char* rows[MAX_ROW_COUNT][MAX_COLUMN_COUNT];
	int columnCount;
	int rowCount;
} table;
// ******************************


typedef struct _dictionary
{
	char* key;
	char* value;
} dictionary;

typedef struct _container
{
	char* name;
	int size;
	dictionary collection[];
} container;

struct _thing
{
	char* name;
	int age;
	float rate;
};

typedef void* (fnptr) (struct _thing* aThing);
typedef void* (fnp) (int a);
typedef void* (funcptr) (container* cont);

void thingOperation(struct _thing* something)
{
	printf(" >>> '%s'!\n", __func__);
	printf(" \t --> Name: '%s' \t Age: %d \t Rate: %f \n", something->name, something->age, something->rate);
}

void printTable(table* t)
{
	printf(" >>> '%s'!\n", __func__);
	int i, j, k = 0;
	char* name = t->name;
	int rc = t->rowCount;
	int cc = t->columnCount;
	printf(" \t %s\n", "-------------------------------------------------------------------------------------");
	printf(" \t [[  Table.Meta :: Name => '%s' || Row count => %d || Column count => %d ]] \n", name, rc, cc);
	printf(" \t %s\n", "-------------------------------------------------------------------------------------");
	printf(" \t [[ Table.content ]] \n");
	// *********************
	// printf(" \t t->rows[0][2]: '%s' \n", t->rows[0][2]);
	// printf(" \t t->rows[0][4]: '%s' \n", t->rows[0][4]);
	// printf(" \t t->rows[3][0]: '%s' \n", t->rows[3][0]);
	// *********************
	// print2dArray(t->rows, cc, rc);
	// *********************
	printf(" \t %s\n", "-------------------------------------------------------------------------------------");
	printf(" \t idx |");
	for (i = 0; i < cc; i++)
	{
		printf(" \t '%s'|", t->columns[i]);
	}
	printf("\n");
	printf(" \t %s\n", "-------------------------------------------------------------------------------------");
	printf(" \t |");
	for (i = 0; i < rc; i++)
	{
		printf(" %d|", i + 1);
		for (j = 0; j < cc; j++)
		{
			printf(" \t '%s'|", t->rows[0][k]);
			k++;
		}
		if(i < rc - 1)
		{
			printf("\n \t |");
		}
	}
	printf("\n");
	printf(" \t %s\n", "-------------------------------------------------------------------------------------");
	printf(" \t [[ Size %lu bytes -||- Address: %p ]] \n", sizeof(t), t);
	printf(" \t %s\n", "-------------------------------------------------------------------------------------");
}

void printContainer(container* box)
{
	printf(" >>> '%s'!\n", __func__);
	printf(" \t --> Container Name: '%s' & Container Length: %d \n", box->name, box->size);
	printf(" \t --> Container Content: [ { <%s> : <%s> } =>", "Key", "Value");
	for (int i = 0; i < box->size; i++)
	{
		printf(" { '%s' : '%s' }, ", box->collection[i].key, box->collection[i].value);
	}
	puts("]\n");
}

void assignFn()
{
	// Errors happened, check later!
	fnptr* op = &thingOperation;
	// void (*op) (struct _thing*) = &thingOperation;
	struct _thing aSecondPerson;
	aSecondPerson.age = 57;
	op(&aSecondPerson);
}

void decorator(void *fn(int a), int age)
{
	printf("%s\n", "------------------");
	printf("%s function is running\n", __func__);
	printf("%s\n", "------------------");
	fn(age);
	printf("%s\n", "------------------");
}

void decorator2(fnp fn, int age)
{
	printf("%s\n", "********************");
	printf("%s function is running\n", __func__);
	printf("%s\n", "********************");
	fn(age);
	printf("%s\n", "********************");
}

void measurePerformance(funcptr fun, container* c)
{
	printf("%s\n", "****************************************");
	printf(" !!!! %s !!!! \n", __func__);
	printf("%s\n", "****************************************");
	// size of c, time in
	fun(c);
	// memory status, time out
	printf("%s\n", "****************************************");
}

void func(int age)
{
	printf(" >>> '%s'!\n", __func__);
	printf(" \t --> %d\n", age);
}

void printArray(char* arr[], int size)
{
	printf(" >>> '%s'!\n", __func__);
	// ******************************
	printf(" \t --> [");
	for(int i = 0; i < size; i++){
		printf("(arr[%d]: '%c')", i, arr[i]);
		if(i < size - 1){
			printf(", ");
		}
	}
	printf("]\n");
	// ******************************
}

void print2dArray(char** arr[], int columnCount, int rowCount)
{
	printf(" >>> '%s'!\n", __func__);
	// ******************************
	int size = columnCount * rowCount;
	int k = 0;
	printf(" \t --> [");
	for(int i = 0; i < columnCount; i++){
		for(int j = 0; j < rowCount; j++){
			printf("(arr[%d][%d]: '%c')", j, i, arr[j][i]);
			if(k < size - 1){
				printf(", ");
			}
			k++;
		}
	}
	printf("]\n");
	// ******************************
}

table* createTable(char* name, char* columns[], char** rows[], int columnCount, int rowCount)
{
	printf(" >>> '%s'!\n", __func__);
	table* tptr = (table *) malloc(sizeof(table));
	// ******************************
	tptr->name = name;
	tptr->columnCount = columnCount;
	tptr->rowCount = rowCount;
	// ******************************
	// print2dArray(rows, columnCount, rowCount);
	// ******************************
	copyArray(tptr->columns, columns, columnCount);
	copy2dArray(tptr->rows, rows, rowCount, columnCount);
	// ******************************
	// print2dArray(tptr->rows, columnCount, rowCount);
	// ******************************
	printTable(tptr);
	// *********************
	return tptr;
}

void insertRow(table* t, char* rows[])
{
	printf(" >>> '%s'!\n", __func__);
	// ******************************
	int columnCount = t->columnCount;
	int rowCount = t->rowCount;
	int i, j, idx = 0;
	int size = rowCount * columnCount + columnCount;
	int length = rowCount * columnCount;	
	// ******************************
	printArray(rows, columnCount);
	// printf(" \t --> %s, Size of a table: %lu bytes \n", " *** realloc time! *** ", sizeof(table));
	// ******************************
	char*** trows;
	// trows = (char *) realloc(trows, sizeof(t->rows[0][0]) * size);
	trows = (char *) malloc(sizeof(t->rows[0][0]) * size);
	// printf(" \t --> rows[0]: '%c' \n", rows[0]);
	// printf(" \t --> t->rows[0][5]: '%s' \n", t->rows[0][5]);
	// printf(" \t --> length: %d \n", length);
	// printf(" \t --> idx: %d \n", idx);
	// printf(" \t --> t->rows[0][idx] => |");
	// ******************************
	for (i = 0; i < rowCount; i++)
	{
		for (j = 0; j < columnCount; j++)
		{
			// printf("'%s'|", t->rows[0][idx]);
			trows[idx] = t->rows[0][idx];
			// printf(" idx: %d |", idx);
			idx++;
		}
	}
	puts("\n \t ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ ");
	print2dArray(trows, columnCount, rowCount);
	// ******************************
	idx = length;
	for(i = 0; i < columnCount; i++){
		// printf(" \t --> idx: %d \n", idx);
		// printf(" \t --> i: %d, rows[i]: '%c' \n", i, rows[i]);
		// ******************************
		// t->rows[0][idx] = rows[i];
		// printf(" \t --> t->rows[0][%d]: '%s' \n", idx, t->rows[0][idx]);
		// ******************************
		trows[idx] = rows[i];
		// printf(" \t --> trows[%d]: '%c' \n", idx, trows[idx]);
		idx++;
	}
	// ******************************
	// print2dArray(trows, columnCount, rowCount + 1);
	// printArray(trows, size);
	// ******************************
	// puts("t->rows = (char *) realloc(t->rows, sizeof(t->rows[0][0]) * size);");
	// t->rows = realloc(t->rows, sizeof(t->rows[0][0]) * size);
	// ******************************
	copy2dArray(t->rows, trows, rowCount + 1, columnCount);
	t->rowCount = rowCount + 1;
	// ******************************
	printTable(t);
	// ******************************
	printf(" \t --> %s \n", " *** done! *** ");
}

container* createContainer(char* name, int size)
{
	printf(" >>> '%s'!\n", __func__);
	container* cptr = (container *) malloc(sizeof(container));
	cptr->name = name;
	cptr->size = size;
	// *********************
	printf(" \t --> Container {{ Name: '%s', Length: '%d' }} with size %lu bytes in address: %p is created! \n", name, size, sizeof(cptr), cptr);
	return cptr;
}

void initDict(dictionary* dict, char* key, char* value)
{
	printf(" >>> '%s'!\n", __func__);
	dict->key = key;
	dict->value = value;
	printf(" \t --> { Key: '%s', Value: '%s' } Assigned to address: %p \n", key, value, &dict);
}

dictionary* createDict(char* key, char* value)
{
	printf(" >>> '%s'!\n", __func__);
	dictionary* dictptr = (dictionary *) malloc(sizeof(dictionary));
	dictptr->key = key;
	dictptr->value = value;
	printf(" \t --> Dictionary pointer @<%p> { '%s', '%s' } & with size: %lu bytes is created! \n", dictptr, key, value, sizeof(dictptr));
	return dictptr;
}

void showDict(dictionary* inputDict)
{
	printf(" >>> '%s'!\n", __func__);
	char* key = inputDict->key;
	char* value = inputDict->value;
	printf(" \t --> { Key: '%s',  Value: '%s' } \n", key, value);
	printf(" \t --> ( Mem: %p,  Size: %lu bytes ) \n", inputDict, sizeof inputDict);
}

void assignToCollection(dictionary collection[], dictionary* dict, int elementNo)
{
	printf(" >>> '%s'!\n", __func__);
	collection[elementNo].key = dict->key;
	collection[elementNo].value = dict->value;
	printf(" \t --> Dict: { '%s': '%s' } (Mem: %p & Size: %lu bytes)! \n", dict->key, dict->value, dict, sizeof(dict));
	printf(" \t --> { '%s': '%s' } assigned to %d. element in the collection (Mem: %p & Size: %lu bytes)! \n", collection[elementNo].key, collection[elementNo].value, elementNo, &collection, sizeof(collection));
}

void copyArray(char* toArray[], char* fromArray[], int elementCount)
{
	printf(" >>> '%s'!\n", __func__);
	printf(" \t --> %d element will be copied!\n", elementCount);
	for(int i = 0; i < elementCount; i++) {
		printf(" \t --> Copying %d. element: '%s' from source array", i, fromArray[i]);
		toArray[i] = fromArray[i];
		printf("... %d. element is copied to destination array :: '%s'\n", i, toArray[i]);
	}
}

void copy2dArray(char** toArray[], char** fromArray[], int instanceCount, int fieldCount)
{
	printf(" >>> '%s'!\n", __func__);
	printf(" \t --> instanceCount: %d fieldCount: %d \n", instanceCount, fieldCount);
	// ******************************
	memcpy(toArray, fromArray, sizeof(char*) * instanceCount * fieldCount);
	// ******************************
	for(int i = 0; i < fieldCount; i++) {
		for(int j = 0; j < instanceCount; j++) {
			printf(" \t --> fromArray[%d][%d]: '%c'", j, i, fromArray[j][i]);
			printf(" ... toArray[%d][%d]: '%c'\n", j, i, toArray[j][i]);
		}
	}
}

int main(int argc, char const *argv[])
{
	puts(" <=================== Program Started ===================> ");
	/* code */
	// ******************************
	// **** STRUCT POINTER TESTS ****
	// ******************************
	struct _thing aPerson;
	aPerson.name = "This is my name";
	thingOperation(&aPerson);
	// ******************************
	// **** FUNC TYPE TESTS ****
	// ******************************
	// assignFn();
	// ******************************
	// **** DECORATOR TESTS ****
	// ******************************
	// decorator(&func, 45);
	// decorator2(&func, 57);
	// ******************************
	// **** DICTIONARY TESTS ****
	// ******************************
	container context;
	context.name = "Person";
	context.size = 3;
	// ******************************
	dictionary d1;
	dictionary d2;
	// ******************************
	// dictionary d[] = {{"a", "b"}, {"c", "d"}};
	// ******************************
	d1.key = "name";
	d2.key = "age";
	d1.value = "mehmet";
	d2.value = "12";
	dictionary* pd3 = createDict("height", "181cm");
	showDict(pd3);
	// ******************************
	// dictionary c[] = {d1, d2};
	// context.collection = c;
	// context.collection[] = {d1, d2};
	// ******************************
	assignToCollection(context.collection, &d1, 0);
	assignToCollection(context.collection, &d2, 1);
	assignToCollection(context.collection, pd3, 2);
	measurePerformance(&printContainer, &context);
	// ******************************
	// **** CONTAINER TESTS ****
	// ******************************
	dictionary *pd4, *pd5;
	// ******************************
	container* ctxptr = createContainer("newContainer", 2);
	// ******************************
	// dictionary* pd4 = createDict("name", "osman");
	// dictionary* pd5 = createDict("age", "20");
	// ******************************
	pd4 = createDict("name", "osman");
	pd5 = createDict("age", "20");
	// ******************************
	showDict(pd4);
	showDict(pd5);
	// ******************************
	assignToCollection(ctxptr->collection, pd4, 0);
	assignToCollection(ctxptr->collection, pd5, 1);
	// ******************************
	measurePerformance(&printContainer, ctxptr);
	// ******************************
	// **** TABLE TESTS ****
	// ******************************
	// char *fields[] = { "aaa", "bbb", "ccc" };
	// char **instances[] = {{"x", "y", "z"}, {"1", "2", "3"}};
	// ******************************
	// printf(" \t \t !!! fields[1]: %s\n", fields[1]);
	// printf(" \t \t !!! instances[1][1]: %s\n", instances[1][1]);
	// ******************************
	int fieldSize = 3;
	int instanceSize = 2;
	char* fields[3] = { "aaa", "bbb", "ccc" };
	char* instances[2][3] = {{"1aa", "2bb", "3cc"}, {"4aa", "5bb", "6cc"}};
	// ******************************
	// char fields[3][3] = { "aaa", "bbb", "ccc" };
	// char instances[][2][3] = {{"1aa", "2bb", "3cc"}, {"4aa", "5bb", "6cc"}};
	// ******************************
	table* myTable = createTable("myTable", fields, instances, fieldSize, instanceSize);
	// ******************************
	char* toBeInserted[3] = {"7aa", "8bb", "9cc"};
	// printArray(toBeInserted, 3);
	insertRow(myTable, toBeInserted);
	// ******************************
	puts(" <=================== Program End ===================> ");
	// ******************************
	// **** PROGRAM CLEAN UP ****
	// ******************************
	free(pd3);
	free(pd4);
	free(pd5);
	free(ctxptr);
	free(myTable);
	// ******************************
	return 0;
}

/* 
	End of file
*/

