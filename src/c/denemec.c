#include <stdio.h>

void addHello(char input_string[], int input_size);

int main()
{
	int size = 5;
	char myInput[12];
	int counter = 0;
	printf("Input <%d> characters\n", size);
	while(counter < size)
	{
		scanf("%1s", &myInput[counter]);
		counter++;
	}
	printf("Your input: '%s'\n", myInput);
	addHello(myInput, size);
	printf("Your output: '%s'\n", myInput);
	return 0;
}

void addHello(char input_string[], int input_size)
{
	int size = 7, fullSize = input_size + size, temp;
	char oldString[fullSize], myHello[] = "Hello, ";
	printf("This will be added to your input: %s\n", myHello);
	int j;
	for (j = 0; j < size; j++)
	{
		oldString[j] = myHello[j];
	}
	// printf("oldString 1: '%s'\n", oldString);
	for (j = 0; j < input_size; j++)
	{
		temp = size + j;
		// printf("oldString <%d>: '%c'\t", temp, oldString[temp]);
		oldString[temp] = input_string[j];
		// printf("--> '%c'\n", oldString[temp]);
	}
	// printf("oldString 2: '%s'\n", oldString);
	// printf("Input String 1: '%s'\n", input_string);
	for (j = 0; j < fullSize; j++)
	{
		// printf("input_string <%d>: '%c'\t", j, input_string[j]);
		input_string[j] = oldString[j];
		// printf("--> '%c'\n", input_string[j]);
	}
	// printf("Input String 2: '%s'\n", input_string);
}