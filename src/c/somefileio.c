#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

void acknowledge(char msg[]);
void alert(char msg[]);
void echo(const char *fmt, ...);
void throw(char msg[]);
void log_data(char msg[]);

/* ------------ code to open txt files :) ------------ */
int main()
{
	/* ------------ Started! ------------ */
	alert("Program started!");

	int bufferSize = 255;
	int inputSize = 100;

	char buff[bufferSize];
	char yourInput[inputSize];

	char filePath[] = "data.txt";

	echo("You can enter a string to the file '%s' as #%d characters long", filePath, inputSize);
	scanf("%[^\n]%*c", &yourInput);
	echo("Your input is '%s'", yourInput);

	/* FILE *fopen( const char * filename, const char * mode ); */
	FILE *fp;

	/* ------------ Read file ------------ */
	acknowledge("Reading the file");
	fp = fopen(filePath, "r");

	if(fp == NULL)
	{
		throw("Error opeing file, exiting program!");   
	}
	
	// fscanf(fp, "%s", buff);		/* char fscanf( FILE *fp, ??? ); */
   	// printf("1 : %s\n", buff);

   	fgets(buff, 255, (FILE*)fp); 	/* char *fgets( char *buf, int n, FILE *fp ); */
   	printf("\t Line 1: %s\n", buff );

   	fgets(buff, 255, (FILE*)fp);
   	printf("\t Line 2: %s\n", buff );
 
   	fclose(fp);

   	/* ------------ Write (in first-delete-all mode) file ------------ */
   	acknowledge("Writing into the file in first-delete-all mode");
   	fp = fopen(filePath, "w");

	fprintf(fp, "fprintf 1: '%s'...\n", yourInput);		/* int fprintf( FILE *fp, ?? ); */
	fputs("fputs 1...\n", fp);							/* int fputs( const char *s, FILE *fp ); */

	fclose(fp);

	/* ------------ Write (in append mode) file ------------ */
	acknowledge("Writing into the file in append mode");
	fp = fopen(filePath, "a");
	fprintf(fp, "append mode --> fprintf 2\n");
	fputs("append mode --> fputs 2\n", fp);

	fclose(fp);

	/* ------------ Read file (Line by line) ------------ */
	acknowledge("Reading the file again");
	fp = fopen(filePath, "r");

	fgets(buff, 255, (FILE*)fp);
   	printf("\t Line 1: %s\n", buff );

   	fgets(buff, 255, (FILE*)fp);
   	printf("\t Line 2: %s\n", buff );

   	fgets(buff, 255, (FILE*)fp);
   	printf("\t Line 3: %s\n", buff );

   	fgets(buff, 255, (FILE*)fp);
   	printf("\t Line 4: %s\n", buff );
 
   	fclose(fp);

   	alert("Program finished!");
   	/* ------------ Finished! ------------ */
	return 0;
}

void acknowledge(char msg[])
{
	printf(" ---> %s\n", msg);
}

void alert(char msg[])
{
	printf(" ---------------------  %s  --------------------- \n", msg);
}

void echo(const char *fmt, ...)
{
    char buffer[4096];
    /* ------------ stdarg.h functions to parse any number of arguments (dynamic size parameters)  ------------ */
    va_list args;
    va_start(args, fmt);
    int rc = vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    /* ------------ print the formatted buffer ------------ */
    printf("\t %s \n", buffer);
}

void throw(char msg[])
{
	/* ------------ Throw error by simply printing the error and exit ------------ */
	printf("\t '%s'\n", msg);
	exit(1);
}

// void log_data(string inputData, log_level_t log_level)
// FILE *log_file = (level == LOG_ERROR) ? err_log : info_log;

void log_data(char msg[])
{
	/* ------------ simple logging ------------ */
	FILE *log_file;
	log_file = fopen("log", "w");
	fputs(msg, log_file);
	fclose(log_file);
}

/* End of script */