#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <errno.h>
#include <signal.h>
// ******************************
#include <Windows.h>
// ******************************
/**** TODO: Download this libs! ****/
// #include <graphics.h>
// #include <threads.h>
// #include <regex.h>
// #include <sys/socket.h>
// #include <sys/types.h>
// #include <mysql.h>
// #include <gtk/gtk.h>
// ******************************
#include "mylib.h"
// ******************************



// ************************************************************
// **** UI ****
// ************************************************************
// static void on_activate (GtkApplication *app)
// {
//   // Create a new window
//   GtkWidget *window = gtk_application_window_new (app);
//   // Create a new button
//   GtkWidget *button = gtk_button_new_with_label ("Hello, World!");
//   // When the button is clicked, destroy the window passed as an argument
//   g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
//   gtk_container_add (GTK_CONTAINER (window), button);
//   gtk_widget_show_all (window);
// }

// int openUI()
// {
// 	GtkApplication *app = gtk_application_new ("com.example.GtkApplication",
// 	                                         G_APPLICATION_FLAGS_NONE);
// 	g_signal_connect (app, "activate", G_CALLBACK (on_activate), NULL);
// 	return g_application_run (G_APPLICATION (app), argc, argv);
// }

// ************************************************************
// **** PRINTS ****
// ************************************************************
void printIntAsStr(void* msg)
{
	char* buf[255];
	itoa(msg, buf, 10);
	printf(" \t --> '%s'\n", buf);
}

void echoData(void* msg, enum DataType dt)
{
	switch(dt) {
	   case str:
	      printf(" \t --> '%s'\n", msg);
	      break;
	   case integer:
	      printf(" \t --> %d\n", msg);
	      break;
	  	case character:
	      printf(" \t --> '%c'\n", msg);
	      break;
	}
}

void printElement(int i, void* elem, enum DataType dt)
{
	switch(dt) {
	   case str:
	      printf("'%s'", elem);
	      break;
	   case integer:
	      printf("%d", elem);
	      break;
	  	case character:
	      printf("'%c'", elem);
	      break;
	}
}

void splitScreen()
{
	printf(" \t %s\n", "-------------------------------------------------------------------------------------");
}

void printMemorySize(void* obj)
{
	printf(" >>> '%s' => { ", __func__);
	printf(" Size %lu bytes -||- Address: %p ", sizeof(obj), obj);
	printf(" }\n");
}

void printArray(void* arr[], int size, enum DataType dt)
{
	printf(" >>> '%s' => [ ", __func__);
	// ******************************
	for(int i = 0; i < size; i++){
		printElement(i, arr[i], dt);
		if(i < size - 1){
			printf(", ");
		}
	}
	printf(" ]\n");
	// ******************************
}

void printGenericData(namesNumbers* nn)
{
	printf(" >>> '%s' => { \n", __func__);
	printArray(nn->names, nn->size, str);
	printArray(nn->numbers, nn->size, integer);
	// for(int i = 0; i < nn->size; i++){
	// 	echoData(nn->names[i], str);
	// 	echoData(nn->numbers[i], integer);
	// }
	printf(" }\n");
}

void acknowledge(char* msg)
{
	printf(" \t ---> %s... \n", msg);
}

void alert(char* msg)
{
	printf(" \t <---------------------  %s  ---------------------> \n", msg);
}

void yaz(const char *fmt, ...)
{
	printf("(");
    /* ------------ stdarg.h functions to parse any number of arguments (dynamic size parameters)  ------------ */
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
    printf(")\n");
}

void echo(const char *fmt, ...)
{
	/* ------ vars ------ */
	int bufferSize = 500;
    char buffer[bufferSize];
    /* ------ main ------ */
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, bufferSize, fmt, args);
    va_end(args);
    /* ------ end ------ */
    printf(" \t ---> %s \n", buffer);
}

char* formattedStr(const char *fmt, ...)
{
	printf(" >>> '%s' \n", __func__);
	alert("Starting to format string!");
	/* ------ vars ------ */
	int bufferSize = 100;
	int tabSize = 13;
	char *b = (char*) malloc(sizeof(char*));
    char buffer[bufferSize];
    char* tab = "         --->";
    acknowledge("Variables and constants are defined");
    strcpy(buffer, tab);
    acknowledge("Tab is included");
    /* ------ main ------ */
    va_list args;
    acknowledge("Buffer becomes ready");
    va_start(args, fmt);
    vsnprintf(&buffer[tabSize], bufferSize - tabSize, fmt, args);
    /* ------ end ------ */
    va_end(args);
    alert("String formatted!");
    b = buffer;
    return b;
}

void printSome(const char* format, ...)
{
    char dest[1024 * 16];
    fprintf(stdout, " \t $format = '%s' \n", format);
    va_list argptr;
    va_start(argptr, format);
    vsprintf(dest, format, argptr);
    va_end(argptr);
    fprintf(stdout, " \t $dest = '%s' \n", dest);
    // TODO: Merge printSome & variable funcs
}

void variable(const char *format, ...)
{
    va_list args;
    int count;

    va_start(args, format);

    count = 0;
    while (*format != '\0') {
        switch (*format++) {
            case 's':
                fprintf(stdout, "arg[%d]: %s\n", count, va_arg(args, const char *));
                break;
            case 'd':
                fprintf(stdout, "arg[%d]: %d\n", count, va_arg(args, int));
                break;
            case 'f':
                fprintf(stdout, "arg[%d]: %f\n", count, va_arg(args, double));
                break;
        }
        count += 1;
    }
    va_end(args);
}

void throw(char* msg)
{
	/* ------------ Throw error by simply printing the error and exit ------------ */
	printf(" \t '%s'!?\n", msg);
	exit(errno);
	// perror(msg);
}

void log_data(char* msg)
{
	/* ------------ simple logging ------------ */
	printf(" >>> '%s' => { \n", __func__);
	alert("Starting to log");
	FILE *log_file;
	log_file = fopen("log", "a");
	if (log_file) acknowledge("Empty log file successfully opened");
	// ******************************
	fputs(msg, log_file);
	acknowledge("Your message is entered to the file");
	// ******************************
	fclose(log_file);
	alert("Log file is closed");
	printf(" }\n");
}

char* get_logs()
{
	/* ------ read logs start ------ */
	printf(" >>> '%s' => { \n", __func__);
	alert("Opening log file");
	/* ------ Create a buffer with certain size ------ */
	// int bufferSize = 255;
	// char buff[bufferSize];
	/* ------ Open in 'r' (read) mode ------ */
	FILE *log_file;
	log_file = fopen("log", "r");
	/* ------ Checking errors ------ */
	if (log_file == NULL) throw("Error opeing file, exiting program!");
	if (log_file) acknowledge("The log file successfully opened");
	/* ------ Actual reading ------ */
	// fgets(buff, bufferSize, log_file);	/*** Only 1 line ***/
	// ******************************
	long size;
	// size = fsize(log_file);				/*** Maybe Unix only ***/
	// ******************************
	fseek(log_file, 0, SEEK_END); 			/*** Good utilisation of 'f' (file) funcs ***/
	size = ftell(log_file);
	fseek(log_file, 0, SEEK_SET);
	// fcontent = malloc(size);
	// fread(fcontent, 1, size, log_file);
	/* ------ Reading character by character ------ */
	char c;
	char chars[size];
	int i = 0;
	while((c = getc(log_file)) != EOF) {
	    // putchar(c);
	    chars[i] = c;
	    i++;
	}
	/* ------ Reading is done ------ */
	acknowledge("Log file is read");	
	fclose(log_file);
	alert("Log file is closed");
	/* ------ Finish ------ */
	printf(" }\n");
	// return buff;
	return chars;
}

void printIntArgsBiggerThanZero(int arg1, ...)
{
	printf(" >>> '%s' => [ ", __func__);
	va_list ap;
	int i;
	// ******************************
	va_start(ap, arg1);
	// ****************************** 
	for (i = arg1; i > 0; i = va_arg(ap, int))
		printf("%d, ", i);
	// ******************************
	printf("]\n");
	va_end(ap);
}

void p_args(int argCount, ...)
{
	printf(" >>> '%s' => { \n", __func__);
	alert("Arguments beginning!");
	int i;
	va_list ap;
	// ******************************
	va_start(ap, argCount);
	acknowledge("va_start");
	printf(" \t *** argCount=%d *** \n", argCount);
	// ******************************
	for (i = 0; i < argCount; i++)
		printf(" \t <%d. arg: '%s'> \n", i, va_arg(ap, int));
	// ******************************
	va_end(ap);
	acknowledge("va_end");
	// ******************************
	alert("Arguments End");
	printf(" }\n");
}

// int get_sum(int argCount, ...)
// {
// 	printf(" >>> '%s' :: ", __func__);
// 	va_list ap;
// 	int i;
// 	int sum = 0;
// 	// ******************************
// 	va_start(ap, argCount); //va_start used to start before accessing arguments
// 	// ******************************
// 	for(i = 0; i < argCount; i++) {
// 		printf(" ...get_sum %d %d\n", i, va_arg(ap, int));
// 		sum += va_arg(ap, int);
// 	}
// 	// ******************************
// 	va_end(ap); //va_end used after completing access of arguments
// 	// ******************************
// 	return sum;
// }


// ************************************************************
// **** GRAPIHCS ****
// ************************************************************
// void createCircle(int x, int y, int r)
// {
// 	// gm is Graphics mode which is 
//     // a computer display mode that 
//     // generates image using pixels. 
//     // DETECT is a macro defined in 
//     // "graphics.h" header file 
//     int gd = DETECT, gm; 
  
//     // initgraph initializes the 
//     // graphics system by loading a 
//     // graphics driver from disk 
//     initgraph(&gd, &gm, ""); 
  
//     // circle function 
//     circle(x, y, r);
  
//     getch(); 
  
//     // closegraph function closes the 
//     // graphics mode and deallocates 
//     // all memory allocated by 
//     // graphics system . 
//     closegraph(); 
  
//     return NULL;
// }

// void createRectangle(int x1, int y1, int x2, int y2)
// {
// 	// gm is Graphics mode which is a computer display 
//     // mode that generates image using pixels. 
//     // DETECT is a macro defined in "graphics.h" header file 
//     int gd = DETECT, gm; 
  
//     // location of left, top, right, bottom 
//     int left = x1, top = y1; 
//     int right = x2, bottom = y2; 
  
//     // initgraph initializes the graphics system 
//     // by loading a graphics driver from disk 
//     initgraph(&gd, &gm, ""); 
  
//     // rectangle function 
//     rectangle(left, top, right, bottom); 
  
//     getch(); 
  
//     // closegraph function closes the graphics 
//     // mode and deallocates all memory allocated 
//     // by graphics system . 
//     closegraph(); 
  
//     return NULL;
// }
// ************************************************************


// ************************************************************
// **** DATE & TIME ****
// ************************************************************
datetime* getDateTime()
{
	printf(" >>> '%s'!\n", __func__);
	char target[SIZE];
	datetime* ptrdt;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int year = tm.tm_year;
	int month = tm.tm_mon;
	int day = tm.tm_mday;
	int hour = tm.tm_hour;
	int minute = tm.tm_min;
	int sec = tm.tm_sec;
	int seconds = hour * 3600 + minute * 60 + sec;
	// ptrdt->date = strcat(year, ":", month, ":", day);
	ptrdt->date = snprintf(target, sizeof(target), year, ":", month, ":", day);
	ptrdt->day = day;
	ptrdt->time = snprintf(target, sizeof(target), hour, ":", minute, ":", sec);
	ptrdt->seconds = seconds;
	return ptrdt;
}

int getDateTimeDelta(datetime* datetime1, datetime* datetime2)
{
	printf(" >>> '%s'!\n", __func__);
	int seconds;
	int dayDelta = datetime2->day - datetime1->day;
	int secondsDelta = datetime2->seconds - datetime1->seconds;
	if(dayDelta > 0) dayDelta = dayDelta * 24 * 60 * 60;
	seconds = dayDelta + secondsDelta;
	return seconds;
}


// ************************************************************
// **** DECORATORS ****
// ************************************************************
void measurePerformance(ptrfunc fun, namesNumbers* nn)
{
	printf("%s\n", "****************************************");
	printf(" !!!! %s !!!! \n", __func__);
	printf("%s\n", "****************************************");
	datetime* d1 = (datetime*) malloc(sizeof(datetime));
	datetime* d2 = (datetime*) malloc(sizeof(datetime));
	// ******************************************
	int delta;
	d1 = getDateTime();
	printMemorySize(nn);
	// ******************************************
	fun(nn);
	// ******************************************
	d2 = getDateTime();
	delta = getDateTimeDelta(d1, d2);
	echoData(delta, integer);
	// ******************************************
	// getPC();
	free(d1);
	free(d2);
	printf("%s\n", "****************************************");
}

// void debugDecorate(ptrfunc fun, int argc, ...)
// {
// 	printf(" >>> '%s' => { \n", __func__);
// 	// ******************************************
// 	fun(...);
// 	// ******************************************
// 	printf(" }\n");
// }


// ************************************************************
// **** CLEANING ****
// ************************************************************
void clear(void* p)
{
	free(p);
}


// ************************************************************
// **** GENERIC DATA MANIPULATION ****
// ************************************************************
namesNumbers* createGenericData(char* names[], int numbers[], int size)
{
	printf(" >>> '%s'!\n", __func__);
	alert("Generic start!");
	/* ------ Start ------ */
	acknowledge("Allocating memory for names and numbers");
	namesNumbers* data = (namesNumbers *) malloc(sizeof(namesNumbers) * size);
	/* ------ Copy values into the generic container's memory ------ */
	acknowledge("Copying values into memory and print the arrays");
	memcpy(data->names, names, sizeof(char*) * size);
	memcpy(data->numbers, numbers, sizeof(int*) * size);
	data->size = size;
	/* ------ End ------ */
	alert("Generic data created!");
	return data;
}


// ************************************************************
// **** PC ****
// ************************************************************
// BOOL GetProcessTimes(
//   HANDLE     hProcess,
//   LPFILETIME lpCreationTime,
//   LPFILETIME lpExitTime,
//   LPFILETIME lpKernelTime,
//   LPFILETIME lpUserTime
// );

// void getPC()
// {
// 	FILETIME idleTime;
// 	FILETIME kernelTime;
// 	FILETIME userTime;
// 	BOOL res = GetSystemTimes( &idleTime, &kernelTime, &userTime );
// 	usr = userTime - last_userTime;
// 	ker = kernelTime - last_kernelTime;
// 	idl = idleTime - last_idleTime;
// 	sys = kerl + usr;
// 	cpu = int( (sys - idl) *100 / sys );
// 	printf("%d \n", cpu);
// 	// printf("%d\n", GetProcessTimes("opera"));
// }

/* ============ EOF ============ */