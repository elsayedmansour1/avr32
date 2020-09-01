#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "GIE_Register.h"
#include "GIE_Interface.h"



void GIE_VidEnable(void)
{
	SET_BIT(SREG, 7);
}
void GIE_VidDisable(void)
{
	CLR_BIT(SREG, 7);
}
