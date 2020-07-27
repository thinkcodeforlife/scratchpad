#include <stdio.h>

void addHello(char input_string[], int input_size);

int main()
{
	int size = 5;
	char myInput[13];
	int counter = 0;
	printf("Input %d characters\n", size);
	while(counter < size)
	{
		scanf("%1s", &myInput[counter]);
		counter++;
	}
	printf("Your input: %s\n", myInput);
	addHello(myInput, size);
	return 0;
}

void addHello(char input_string[], int input_size)
{
	int size = 7;
	char myHello[] = "Hello, ";
	char oldString[13];
	printf("This will be added to your input: %s\n", myHello);
	int j;
	for (j = 0; j < size; j++)
	{
		oldString[j] = myHello[j];
	}
	printf("oldString 1: %s\n", oldString);
	for (j = 0; j < input_size; j++)
	{
		oldString[size + j] = input_string[j];
	}
	printf("oldString 2: %s\n", oldString);
	
	for (j = 0; j < input_size; j++)
	{
		input_string[j] = oldString[j];
	}
	// for (int i = 0; i < size; i++)
	// {
	// 	input_string[input_size + i + 1] = myHello[i];
	// }
	printf("Input String 2: %s\n", input_string);
}