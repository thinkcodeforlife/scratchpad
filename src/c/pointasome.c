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
// #include <threads.h>
// #include <regex.h>
// #include <sys/socket.h>
// #include <sys/types.h>



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

void operationX(struct _thing* something)
{
	printf(" --> Name: '%s' \t Age: %d \t Rate: %f \n", something->name, something->age, something->rate);
}

void printContainer(container* box)
{
	printf("%s\n", "****************************************");
	printf(" --> <%s> | \t  <%s> \t |\n", "Container", "Size");
	printf("%s\n", "****************************************");
	printf(" --> '%s' \t | \t  %d \t |\n", box->name, box->size);
	printf("%s\n", "****************************************");
	printf(" --> <%s> \t | \t  <%s> \t |\n", "Key", "Value");
	printf("%s\n", "****************************************");
	for (int i = 0; i < box->size; i++)
	{
		printf(" --> '%s' \t | \t  '%s' |\n", box->collection[i].key, box->collection[i].value);
	}
	printf("%s\n", "****************************************");
}

void assignFn()
{
	fnptr* op = &operationX;
	// void (*op) (struct _thing*) = &operationX;
	struct _thing aSecondPerson;
	aSecondPerson.age = 57;
	op(&aSecondPerson);
}

void decorator(void *fn(int a), int age)
{
	printf("%s\n", "------------------");
	printf("%s\n", "Function is running");
	printf("%s\n", "------------------");
	fn(age);
	printf("%s\n", "------------------");
}

void decorator2(fnp fn, int age)
{
	printf("%s\n", "********************");
	printf("%s\n", "Function is running");
	printf("%s\n", "********************");
	fn(age);
	printf("%s\n", "********************");
}

void decorator3(funcptr fun, container* c)
{
	printf("%s\n", "<<<<<<<<<<<<<<<<<<<<<<<< Function >>>>>>>>>>>>>>>>>>>>>>>>>>");
	fun(c);
	printf("%s\n", "<<<<<<<<<<<<<<<<<<<<<<<<---------->>>>>>>>>>>>>>>>>>>>>>>>>>");
}

void func(int age)
{
	printf(" --> %d\n", age);
}

void initDict(dictionary* dict, char* key, char* value)
{
	dict->key = key;
	dict->value = value;
}

dictionary* createDict(char* key, char* value)
{
	printf("%s\n", "****************************************");
	printf(" **** %s **** \n", "createDict");
	printf("%s\n", "****************************************");
	dictionary dict;
	dictionary* dictptr;
	printf("%s\n", key);
	printf("%s\n", value);
	dict.key = key;
	dict.value = value;
	printf("%s\n", dict.key);
	printf("%s\n", dict.value);
	printf("dict pointer: %p\n", &dict);
	// puts(dict);
	dictptr = &dict;
	// return &dict;
	return dictptr;
}

void showDict(dictionary* inputDict)
{
	char* key = inputDict->key;
	char* value = inputDict->value;
	printf("%s\n", "****************************************");
	printf(" **** %s **** \n", "showDict");
	printf("%s\n", "****************************************");
	printf(" --> <%s> | \t  <%s> \t |\n", "Key", "Value");
	printf("%s\n", "****************************************");
	printf(" --> '%s' \t | \t  '%s' \t |\n", key, value);
	printf("%s\n", "****************************************");
}

void collectionAssigner(dictionary collection[], dictionary* dict, int elementNo)
{
	collection[elementNo].key = dict->key;
	collection[elementNo].value = dict->value;
}

int main(int argc, char const *argv[])
{
	/* code */
	struct _thing aPerson;
	aPerson.name = "This is my name";
	operationX(&aPerson);
	printf("%s\n", "This is test regex!");
	// ******************************
	// assignFn();
	// ******************************
	decorator(&func, 45);
	decorator2(&func, 57);
	// ******************************
	container context;
	context.name = "Person";
	context.size = 3;
	// ******************************
	dictionary d1;
	dictionary d2;
	dictionary d3;
	// ******************************
	// dictionary d[] = {{"a", "b"}, {"c", "d"}};
	// ******************************
	d1.key = "name";
	d2.key = "age";
	d1.value = "mehmet";
	d2.value = "12";
	dictionary* pd3 = createDict("height", "181cm");
	printf("%p\n", pd3);
	printf("pd3->key :: %s\n", pd3->key);
	printf("pd3->value :: %s\n", pd3->value);
	d3 = *pd3;
	printf("d3.key :: %s\n", d3.key);
	showDict(pd3);
	// exit(-1);
	// ******************************
	// dictionary c[] = {d1, d2};
	// context.collection = c;
	// context.collection[] = {d1, d2};
	// ******************************
	// int size = 2;
	// for (int i = 0; i < size; i++)
	// {
	// 	context.collection[i].key = d1;
	// }
	// ******************************
	collectionAssigner(context.collection, &d1, 0);
	collectionAssigner(context.collection, &d2, 1);
	collectionAssigner(context.collection, &d3, 2);
	printf("%s\n", "decorator3 time!");
	decorator3(&printContainer, &context);
	// ******************************
	return 0;
}

// End of file