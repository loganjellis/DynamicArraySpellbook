#include <stdio.h>
#include <math.h>
#include "vibrant_logs.h"
#include "daspllbk.h"

int main(void)
{
	vl_init();

	daspllbk_int_arr myints = {0};
	daspllbk_init(&myints);

	daspllbk_add_n(&myints, int, 0, 1, 2, 3, 4);

	for(size_t i = 0; i < myints.size; ++i)
	{
		vl_log(VL_DEBUG, "myints[%zu] = %d", i, myints.data[i]);
	}

	daspllbk_int_arr ints_sub = {0};
	daspllbk_init(&ints_sub);

	daspllbk_get_sub_arr(&myints, 0, myints.size, &ints_sub); // range_bytes = 2 * sizeof(int) (2 * 4 = 8 bytes to copy)

	for(size_t i = 0; i < ints_sub.size; ++i)
	{
		vl_log(VL_DEBUG, "ints_sub[%zu] = %d", i, ints_sub.data[i]);
	}

	daspllbk_free(&ints_sub);
	daspllbk_free(&myints);

	return 0;
}
