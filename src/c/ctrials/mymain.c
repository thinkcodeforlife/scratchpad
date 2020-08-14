// #include <stdlib.h>

#include "mylib.h"


int main(int argc, char const *argv[])
{
	/* ---------------- declarations ---------------- */
	int size = 3;
	// ******************************************
	// char* names[] = {"adnan", "osi", "meli"};
	// ******************************************
	char** names = (char*) calloc(size, sizeof(char) * size);
	if (!names) fail();
	names[0] = "adnan";
	names[1] = "osi";
	names[2] = "meli";
	yaz(" x %s -- %s ", names[0], names[1]);
	// ******************************************
	char* msg = formattedStr(" msg :: %s -- %s", names[0], names[1]);
	echo(" echo => '%s'", msg);
	echo(msg);
	echoData(msg, str);
	echo("bu bir deneme");
	// ******************************************
	p_args(3, names[0], names[1], "durbea");
	// ******************************************
	// int numbers[] = {30, 24, 43};
	// ******************************************
	int* numbers = (int*) calloc(size, sizeof(int) * size);
	if (!numbers) fail();
	numbers[0] = 30;
	numbers[1] = 24;
	numbers[2] = 43;
	// ******************************************
	char* msg2 = formattedStr(" formattedStr::numbers %d -- %d", numbers[0], numbers[1]);
	echo("msg2 :: %s", msg2);
	puts(msg2);
	// ******************************************
	printIntArgsBiggerThanZero(numbers[0], numbers[1]);
	// ******************************************
	// int somesum = get_sum(2, numbers[0], numbers[1]);
	// echo(" somesum | %d\n", somesum);
	// ******************************************
	// variable(9, "adnan");
	// variable("ozom", 15);
	// ******************************************
	printSome("deneme 1 %s", "dur");
	printSome("deneme 2");
	printSome("deneme %d", 3);
	// ******************************************
	// p_args(3, numbers[0], numbers[1], 4);
	// echo(5);
 	// ******************************************
 	// createRectangle(150, 150, 450, 450);
 	// ******************************************
	int no[] = {8, 99, 54};
	/* ---------------- Program Start ---------------- */
	puts(" <=================== Program Started ===================> ");
	// printf("\t --> numbers[1]::%p -- %d \n", numbers, numbers[1]);
	// printf("\t --> names[1]::%p -- %s \n", names, names[1]);
	// printf("\t --> no::%p -- %d \n", no, no[2]);
	// printf("\t --> 2[no]::%d \n", 2[no]);
	// printf("\t --> *(no + 1)::%d \n", *(no + 1));
	// echoData(size, integer);
	/* ---------------- main ---------------- */
	namesNumbers* mynn = createGenericData(names, numbers, size);
	printGenericData(mynn);
	puts(" <=================== Program End ===================> ");
	/* ---------------- cleaning ---------------- */
	clear(mynn);
	clear(numbers);
	clear(names);
	clear(msg);
	/* ---------------- Program End ---------------- */
	return 0;
}

/* ============ EOF ============ */