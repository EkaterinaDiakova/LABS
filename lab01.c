#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"
#include "process.h"

int main()
{
	Setup context;
	int n;

	context.polinome_1.p = NULL;
	context.polinome_2.p = NULL;
	context.result.p = NULL;
	context.polinome_1.coefficients = NULL;
	context.polinome_2.coefficients = NULL;
	context.result.coefficients = NULL;
	context.polinome_1.len = 0;
	context.polinome_2.len = 0;
	context.result.len = 0;
	context.polinome_1.type = 1;
	context.polinome_2.type = 1;
	context.result.type = 1;
	context.arg = 0.0;

	char msg[MAX_LENGTH_BUF];
	char* type_msg = "(1 - integer / 2 - float)\nEnter type ";
	char* arg_msg = "(1 - operator_1 / 2 - operator_2)\nChoose operator ";
	char* com_msg = "(1 - operator_1 o operator_2 / 2 - operator_2 o operator_1)\nEnter your choice ";

	while(1)
	{
		string_print(&context.polinome_1);
		string_print(&context.polinome_2);
		string_print(&context.result);

		sprintf(msg,"\nSETUP MENU\n"
							"1.Operator 1:              %s\n"
							"2.Operator 2:              %s\n"
							"3.Type 1:                  %d(1-integer/2-float)\n"
							"4.Type 2:                  %d(1-integer/2-float)\n"
							"5.Argument:                %f\n"
							"\nOperations:\n"
							"6.*                        \n"
							"7.+                        \n"
							"8.Сomputation by argument  \n"
							"9.Composition              \n"
							"\nCurrent result:          %s\n"
							"T.Test                     \n"
							"Q.Quite                    \n",
							context.polinome_1.p,
							context.polinome_2.p,
							context.polinome_1.type,
							context.polinome_2.type,
							context.arg,
							context.result.p);
		switch(menu(msg, 9))
		{
			case 1:
				get_polinome(&context.polinome_1);
				break;
			case 2:
				get_polinome(&context.polinome_2);
				break;
			case 3:
				context.polinome_1.type = menu(type_msg, 2);
				break;
			case 4:
				context.polinome_2.type = menu(type_msg, 2);
				break;
			case 5:
				printf("Enter an argument-> ");
				scanf("%f", &context.arg);
				break;
			case 6:
				multiplicate(&context);
				break;
			case 7:
				sum(&context);
				break;
			case 8:
				n = menu(arg_msg, 2);
				if (n == 1) arg(&context, &context.polinome_1);
				else if (n == 2) arg(&context, &context.polinome_2);
				break;
			case 9:
				n = menu(com_msg, 2);
				if (n == 1)
				{
					arg(&context, &context.polinome_2);
					context.arg = ((float*)context.result.coefficients)[0];
					arg(&context, &context.polinome_1);
				}
				else if (n == 2)
				{
					arg(&context, &context.polinome_1);
					context.arg = ((float*)context.result.coefficients)[0];
					arg(&context, &context.polinome_2);
				}
				break;
			case 36:
				printf("test");
				//test();
				break;
			case 33:
				free(context.polinome_1.coefficients);
				free(context.polinome_1.p);
				free(context.polinome_2.coefficients);
				free(context.polinome_2.p);
				free(context.result.coefficients);
				free(context.result.p);
				return 0;
		}

	}
	return 0;
}
