#ifndef PROCESS_H_
#define PROCESS_H_

#define MAX_LENGTH_BUF 1080

typedef struct
{
	void* coefficients;
	int type;
	int len;
	char* p;
}Polinome;

typedef struct
{
	Polinome polinome_1;
	Polinome polinome_2;
	Polinome result;
	float arg;

}Setup;

void string_print(Polinome* polinome);
void get_polinome(Polinome* polinome);
int menu(char* msg, int n);
void sum(Setup* context);
void multiplicate(Setup* context);
void arg(Setup* context, Polinome* polinome);


#endif /* PROCESS_H_ */
