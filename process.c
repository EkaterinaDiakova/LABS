#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "process.h"

void string_print(Polinome* polinome)
{
	int exp;
	char tmpStr[MAX_LENGTH_BUF];
	int len = 0;
	if(polinome->p != NULL) polinome->p[0] = '\0';

	for(exp = 0; exp < polinome->len; exp++)
	{
		if (polinome->type == 1)
		{
			sprintf(tmpStr,"(%d)x^%d+", ((int *)polinome->coefficients)[exp], exp);
		}else
		{
			sprintf(tmpStr,"(%f)x^%d+",((float*)polinome->coefficients)[exp], exp);
		}
		len += strlen(tmpStr);
		polinome->p = realloc(polinome->p, (len));
		strcat(polinome->p, tmpStr);
	}
	if(polinome->p != NULL)
	{
		len = strlen(polinome->p) - 1;
		polinome->p[len] = 0;//удаление последнего +
	}
}


void get_polinome(Polinome* polinome)
{
		char buf[81] = {0};
		int flag = 0;
	    int n = 0;
	    float tmp_float;
	    int tmp_int;
	    polinome->len = 0;


	while(1)
	{
		printf("Enter a%d->", polinome->len);
		flag = 0;
		do
		{
			n = scanf("%80[^\n]", buf);
			if (n < 0)
			{
					return;
			}
			else if (n > 0)
			{
				flag = 1;
				if (polinome->type == 1)
				{
					if(strchr(buf,'.') != NULL)
					{
						printf("Invalid data type!\n");
						continue;
					}
					tmp_int = atoi(buf);
					polinome->coefficients = realloc(polinome->coefficients, sizeof(int)*(polinome->len + 1));
				}
				else if (polinome->type == 2)
				{
					tmp_float = atof(buf);
					polinome->coefficients = realloc(polinome->coefficients, sizeof(float)*(polinome->len + 1));
				}

				if(polinome->coefficients == NULL)
				{
					break;
				}
				if (polinome->type == 1) ((int*)polinome->coefficients)[polinome->len++] = tmp_int;
				else if (polinome->type == 2) ((float*)polinome->coefficients)[polinome->len++] = tmp_float;
			}
			else
			{
				scanf("%*c");
				if(flag == 0) return;
			}

		} while(n > 0);

	}
}

int menu(char* msg, int n)
{
    char* error = "";
    int choice, j;

    j = 0;

    do {
    	printf("%s", error);
		error = "\nYou're wrong. Try again!\n";
		printf("%s", msg);
		printf("\nMake your choice> ");
		choice = getchar() - '0';
		if (((choice == 33) || (choice == 36)) && (n > 2)) return choice;
		while (getchar() != '\n') j++;
		if(j != 0) continue;
    } while (choice < 1 || choice > n);
    return choice;
}

void sum(Setup* context)
{
	int i;
	Polinome *pl_max = &context->polinome_1;
	Polinome *pl_min = &context->polinome_2;

	if(pl_max->len < pl_min->len)
	{
		pl_max = pl_min;
		pl_min = &context->polinome_1;
	}

	if((pl_max->type == 2) || (pl_min->type == 2))
	{
		context->result.coefficients = realloc(context->result.coefficients, sizeof(float)*(pl_max->len));
		context->result.type = 2;
	}
	else
	{
		context->result.coefficients = realloc(context->result.coefficients, sizeof(float)*(pl_max->len));
	}

	for(i = 0; i < pl_max->len; i++)
	{
		if((pl_max->type == 1) && (pl_min->type == 1))
		((int*)context->result.coefficients)[i] = ((int*)pl_max->coefficients)[i] + ((i < pl_min->len) ? ((int*)pl_min->coefficients)[i] : 0);

		else if((pl_max->type == 1) && (pl_min->type == 2))
		((float*)context->result.coefficients)[i] = ((int*)pl_max->coefficients)[i] + ((i < pl_min->len) ? ((float*)pl_min->coefficients)[i] : 0.0);

		else if((pl_max->type == 2) && (pl_min->type == 1))
		((float*)context->result.coefficients)[i] = ((float*)pl_max->coefficients)[i] + ((i < pl_min->len) ? ((int*)pl_min->coefficients)[i] : 0);

		else if((pl_max->type == 2) && (pl_min->type == 2))
		((float*)context->result.coefficients)[i] = ((float*)pl_max->coefficients)[i] + ((i < pl_min->len) ? ((float*)pl_min->coefficients)[i] : 0.0);
	}
	context->result.len = i;
}

void multiplicate(Setup* context)
{
	int i, j;
	int res_len;
	int flag = context->polinome_1.type * context->polinome_2.type;

	res_len = context->polinome_1.len * context->polinome_2.len;

	if(flag == 1)
	{
		context->result.coefficients = realloc(context->result.coefficients, sizeof(int)*(res_len));
		for(i = 0; i < res_len; i++)
		{
			((int*)context->result.coefficients)[i] = 0;
			context->result.type = 1;
		}
	}
	else if(flag == 2)
	{
		context->result.coefficients = realloc(context->result.coefficients, sizeof(float)*(res_len));
		for(i = 0; i < res_len; i++)
		{
			((float*)context->result.coefficients)[i] = 0;
			context->result.type = 2;
		}
	}

	for(i = 0; i < context->polinome_1.len; i++)
	{
		for(j = 0; j < context->polinome_2.len; j++)
		{
			if((context->polinome_1.type == 1) && (context->polinome_2.type == 1))
			((int*)context->result.coefficients)[i+j] += ((int*)context->polinome_1.coefficients)[i] * ((int*)context->polinome_2.coefficients)[j];

			else if((context->polinome_1.type == 1) && (context->polinome_2.type == 2))
			((float*)context->result.coefficients)[i+j] += ((int*)context->polinome_1.coefficients)[i] * ((float*)context->polinome_2.coefficients)[j];

			else if((context->polinome_1.type == 2) && (context->polinome_2.type == 1))
			((float*)context->result.coefficients)[i+j] += ((float*)context->polinome_1.coefficients)[i] * ((int*)context->polinome_2.coefficients)[j];

			else if((context->polinome_1.type == 2) && (context->polinome_2.type == 2))
			((float*)context->result.coefficients)[i+j] += ((float*)context->polinome_1.coefficients)[i] * ((float*)context->polinome_2.coefficients)[j];
		}
	}
	if(context->result.type == 1)
	{
		while(((int*)context->result.coefficients)[res_len - 1] == 0) res_len--;
	} else if(context->result.type == 2)
	{
		while(((float*)context->result.coefficients)[res_len - 1] == 0) res_len--;
	}

	context->result.len = res_len;
}

void arg(Setup* context, Polinome* polinome)
{
	int i;

	context->result.coefficients = realloc(context->result.coefficients, sizeof(float)*1);
	((float*)context->result.coefficients)[0] = 0;

	for(i = 0; i < polinome->len; i++)
	{
		if(polinome->type == 1)
		((float*)context->result.coefficients)[0] += (pow(context->arg, i)) * ((int*)polinome->coefficients)[i];
		else if(polinome->type == 2)
		((float*)context->result.coefficients)[0] += (pow(context->arg, i)) * ((float*)polinome->coefficients)[i];
	}
	context->result.len = 1;
	context->result.type = 2;
}
