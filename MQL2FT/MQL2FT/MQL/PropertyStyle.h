#pragma once

#include "color.h"
#include "Enums.h"


struct PropertyStyle
{
	int type = ds_Line;
	int style = -1;
	int width = -1;
	color color = clrNONE;
};