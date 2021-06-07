#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "process.h"

#define MAX_BUF 1080

void test_process(FILE* fp, Setup* context)
{
	char str[MAX_BUF];

	string_print(context->polinome_1);
	printf("%s\n", context->polinome_1.p);
	string_print(context->polinome_2);
	printf("%s\n", context->polinome_2.p);

	sum(context);
	string_print(context->result);
	printf("\nSUM\nCurrent result: %s\n", context->result.p);
	fgets(fp, context->result.len, str);
	printf("Expected result: %s\n", str);

	multiplicate(context);
	string_print(context->result);
	printf("\nMULTIPLICATE\nCurrent result: %s\n", context->result.p);
	fgets(fp, context->result.len, str);
	printf("Expected result: %s\n", str);

	arg(context, context->polinome_1);
	string_print(context->result);
	printf("\nCOMPUTING BY ARGUMENT (pol_1)\nCurrent result: %s\n", context->result.p);
	fgets(fp, context->result.len, str);
	printf("Expected result: %s\n", str);

	arg(context, context->polinome_2);
	string_print(context->result);
	printf("\nCOMPUTING BY ARGUMENT (pol_2)\nCurrent result: %s\n", context->result.p);
	fgets(fp, context->result.len, str);
	printf("Expected result: %s\n", str);

	arg(&context, &context->polinome_2);
	context->arg = ((float*)context->result.coefficients)[0];
	arg(&context, &context->polinome_1);
	string_print(context->result);
	printf("\nCOMPOSITION 1 o 2 (pol_2)\nCurrent result: %s\n", context->result.p);
	fgets(fp, context->result.len, str);
	printf("Expected result: %s\n", str);

	arg(&context, &context->polinome_1);
	context->arg = ((float*)context->result.coefficients)[0];
	arg(&context, &context->polinome_2);
	string_print(context->result);
	printf("\nCOMPOSITION 2 o 1  (pol_2)\nCurrent result: %s\n", context->result.p);
	fgets(fp, context->result.len, str);
	printf("Expected result: %s\n", str);

}

int main()
{
	Polinome* pol_1;
	Polinome* pol_2;
	Polinome* pol_3;
	Polinome* pol_4;
	Setup* context;

	int i = 0;
	int tmp_int;
	int tmp_float;


	pol_1->type = 1;
	pol_2->type = 2;
	pol_3->type = 1;
	pol_4->type = 2;

	FILE * fp = fopen("input_data.txt","r");
	if(!fp) printf("Error open data.txt\n");
	else
	{
		while (!feof(fp))
		{
		    if (fscanf(fp, "%d", &tmp_int) != 1) continue;
		    i++;
		    pol_1->len = i;
		    pol_1->coefficients = realloc(pol_1->coefficients, i*sizeof(int));
		    ((int*)pol_1->coefficients)[pol_1->len] = tmp_int;
		}
		i = 0;
		while (!feof(fp))
		{
			if (fscanf(fp, "%f", &tmp_float) != 1) continue;
			i++;
			pol_2->len = i;
			pol_2->coefficients = realloc(pol_2->coefficients, i*sizeof(float));
			((float*)pol_2->coefficients)[pol_2->len] = tmp_float;
		}
		i = 0;
		while (!feof(fp))
		{
			if (fscanf(fp, "%d", &tmp_int) != 1) continue;
			i++;
			pol_3->len = i;
			pol_3->coefficients = realloc(pol_3->coefficients, i*sizeof(int));
			((int*)pol_3->coefficients)[pol_3->len] = tmp_int;
		}
		i = 0;
		while (!feof(fp))
		{
			if (fscanf(fp, "%f", &tmp_float) != 1) continue;
			i++;
			pol_4->len = i;
			pol_4->coefficients = realloc(pol_4->coefficients, i*sizeof(float));
			((float*)pol_4->coefficients)[pol_4->len] = tmp_float;
		}
		if (!feof(fp))
		{
			if (fscanf(fp, "%f", &context->arg) != 1) context->arg = 0;
		}
		context->polinome_1 = pol_1;
		context->polinome_2 = pol_2;
		test_process(fp, context);

		context->polinome_1 = pol_1;
		context->polinome_2 = pol_3;
		test_process(fp, context);

		context->polinome_1 = pol_2;
		context->polinome_2 = pol_4;
		test_process(fp, context);

		context->polinome_1 = pol_3;
		context->polinome_2 = pol_4;
		test_process(fp, context);

	}

	return 0;
}
