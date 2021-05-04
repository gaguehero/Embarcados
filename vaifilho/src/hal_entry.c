/* HAL-only entry function */
#include "hal_data.h"
#include <stdio.h>

extern uint16_t EightBitHistogram(uint16_t width, uint16_t height, uint8_t * p_image, uint16_t * p_histogram);
extern uint16_t width0;
extern uint16_t height0;
extern uint8_t image0;

extern uint16_t width1;
extern uint16_t height1;
extern uint8_t image1;

void hal_entry(void)
{
    /* TODO: add your own code here */
    initialise_monitor_handles();
    uint16_t p_histogram[256];
    uint16_t* retorno;
    //teste 0
    *retorno = EightBitHistogram(width0, height0, &image0, p_histogram);
    //teste 1
    *retorno = EightBitHistogram(width1, height1, &image1, p_histogram);

}
