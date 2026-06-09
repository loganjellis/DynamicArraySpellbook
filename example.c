#include <stdio.h>
#include <math.h>
#include "vibrant_logs.h"
#include "daspllbk.h"

typedef struct IntList
{
	int *data;
	size_t size;
	size_t capacity;
} IntList;

int main(void)
{
	vl_init();

	IntList myints = {0};
	daspllbk_init(&myints);

	for(size_t i = 0; i < 11; ++i)
		daspllbk_add(&myints, pow(i, 2));

	for(size_t i = 0; i < myints.size; ++i)
		vl_log(VL_DEBUG, "%zu ^ 2 = %d", i, myints.data[i]);

	daspllbk_free(&myints);

	return 0;
}
