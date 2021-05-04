#include "sender2.h"
#include "blinky_thread.h"

/* Sender1 entry function */
void sender2_entry(void)
{
    /* TODO: add your own code here */
    /* LED type structure */
    bsp_leds_t leds;
    /* LED state variable */
    ioport_level_t level = IOPORT_LEVEL_HIGH;
    /* Get LED information for this board */
    R_BSP_LedsGet(&leds);
    UINT    status;
    ULONG sender2_counter=0;
    ULONG sender2_messages_sent=0;
    while (1)
    {
        sender2_counter++;
        /* Get the mutex with suspension.  */
        status =  tx_mutex_get(&g_new_mutex0, TX_WAIT_FOREVER);

        /* Check status.  */
        if (status != TX_SUCCESS){
            // acende LED vermelho
            level = IOPORT_LEVEL_HIGH;
            g_ioport.p_api->pinWrite(leds.p_leds[1], level);
            break;}

        /* Get the mutex again with suspension.  This shows
           that an owning thread may retrieve the mutex it
           owns multiple times.  */
        status =  tx_mutex_get(&g_new_mutex0, TX_WAIT_FOREVER);

        /* Check status.  */
        if (status != TX_SUCCESS){
            level = IOPORT_LEVEL_HIGH;
            g_ioport.p_api->pinWrite(leds.p_leds[1], level);
            break;}


        //se LED vermelho aceso, apaga
        if(IOPORT_LEVEL_HIGH == level)
        {
            level = IOPORT_LEVEL_LOW;
        }
        g_ioport.p_api->pinWrite(leds.p_leds[1], level);

        //acende LED amarelo
        g_ioport.p_api->pinWrite(leds.p_leds[2], IOPORT_LEVEL_HIGH);

        //envia mensagem
        status =  tx_queue_send(&g_new_queue0, &sender2_messages_sent, TX_WAIT_FOREVER);

        /* Check completion status.  */
        if (status != TX_SUCCESS)
            break;

        sender2_messages_sent++;

        /* Sleep for 60 ticks to hold the mutex.  */
        tx_thread_sleep(60);

        /* Release the mutex.  */
        status =  tx_mutex_put(&g_new_mutex0);

        /* Check status.  */
        if (status != TX_SUCCESS)
            break;

        /* Release the mutex again.  This will actually
           release ownership since it was obtained twice.  */
        status =  tx_mutex_put(&g_new_mutex0);

        /* Check status.  */
        if (status != TX_SUCCESS)
            break;
        //apaga LED amarelo
        g_ioport.p_api->pinWrite(leds.p_leds[2], IOPORT_LEVEL_LOW);
    }
}
