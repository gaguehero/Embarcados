#include "gui/endurer_resources.h"
#include "gui/endurer_specifications.h"

#include "main_thread.h"
#define ESQUERDA 1
#define DIREITA 2


UINT window1_handler(GX_WINDOW *widget, GX_EVENT *event_ptr)
{
    ULONG esquerda = 1;
    ULONG direita = 2;
    ULONG resetar = 3;
    UINT result = gx_window_event_process(widget, event_ptr);
    switch (event_ptr->gx_event_type)
    {
        case GX_SIGNAL(ID_ESQUERDA, GX_EVENT_CLICKED):
                //SE BOTÃO ESQUERDO, MOVER CARRO PRA ESQUERDA
                tx_queue_send(&g_input_queue, &esquerda, TX_WAIT_FOREVER);
                break;
        case GX_SIGNAL(ID_DIREITA, GX_EVENT_CLICKED):
                //SE BOTÃO DIREITO, MOVER CARRO PARA A DIREITA
                tx_queue_send(&g_input_queue, &direita, TX_WAIT_FOREVER);
                break;
        case GX_SIGNAL(ID_RESET1, GX_EVENT_CLICKED):
                //SE BOTÃO DIREITO, MOVER CARRO PARA A DIREITA
                tx_queue_send(&g_input_queue, &resetar, TX_WAIT_FOREVER);
                break;
        default:
            gx_window_event_process(widget, event_ptr);
            break;
    }

    return result;
}



