#ifndef MYLIB_H
#define MYLIB_H
// ******************************
// **** MACROS ****
// ******************************
#define fail() printf("Out of memory")
// ******************************
// **** CONSTANTS ****
// ******************************
#define MAX_COLUMN_NAME 128
#define MAX_COLUMN_COUNT 64
#define MAX_ROW_CONTENT 256
#define MAX_ROW_COUNT 100
#define SIZE 1024
// ******************************
// **** ENUMS ****
// ******************************
enum DataType {str=0, integer=1, character=2};
// ******************************
// **** STRUCTS ****
// ******************************
typedef struct {
	char** names;
	int* numbers;
	int size;
} namesNumbers;

typedef struct {
	char* date;
	char* time;
	int day;
	int seconds;
} datetime;
// ******************************
// **** FUNCTION TYPES ****
// ******************************
typedef void* (ptrfunc) (namesNumbers* nano);
// ******************************
// **** FUNCTIONS ****
// ******************************
void printIntAsStr(void* msg);
void echoData(void* msg, enum DataType dt);
void splitScreen();
void printArray(void* arr[], int size, enum DataType dt);
void printElement(int i, void* elem, enum DataType dt);
void acknowledge(char* msg);
void alert(char* msg);
void yaz(const char *fmt, ...);
void throw(char* msg);
void log_data(char* msg);
// void showLog(int mdl, char const* type, ...);
// void printFormatted(char const* fmt, va_list arg);
void printIntArgsBiggerThanZero(int arg1, ...);
void p_args(int argCount, ...);
int get_sum(int argCount, ...);
char* formattedStr(const char *fmt, ...);
void echo(const char *fmt, ...);
void variable(const char *format, ...);
void printSome(const char* format, ...);
// ******************************
// void createCircle(int x, int y, int r);
// void createRectangle(int x1, int y1, int x2, int y2);
// ******************************
void printMemorySize(void* obj);
void measurePerformance(ptrfunc fun, namesNumbers* nn);
datetime* getDateTime();
int getDateTimeDelta(datetime* datetime1, datetime* datetime2);
// ******************************
namesNumbers* createGenericData(char** names, int* numbers, int size);
void printGenericData(namesNumbers* nn);
// ******************************
void clear(void* p);
// ******************************
// void getPC();
// ******************************
// static void on_activate (GtkApplication *app);
// int openUI();
// ******************************


#endif

/* ============ EOF ============ */