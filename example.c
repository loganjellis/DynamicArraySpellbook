#include <stdio.h>
#include <math.h>
#include "vibrant_logs.h"
#include "dynamic_array_spellbook.h"

int main(void)
{
	vl_init();

	dynas_float_arr floats = {0};
	dynas_init(&floats);

	for(size_t i = 0; i < 10; ++i)
	{
		dynas_add(&floats, (float) (i + 1) * 0.5f);
	}

	for(size_t i = 0; i < floats.size; ++i)
	{
		vl_log(VL_DEBUG, "floats[%zu] = %f", i, floats.data[i]);
	}

	dynas_free(&floats);

	return 0;
}
