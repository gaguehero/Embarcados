#include "rx_thread.h"
#include "blinky_thread.h"

/* RX Thread entry function */
void rx_thread_entry(void)
{
    ULONG   received_message=0;
    ULONG   tx_messages_received=0;
    ULONG   tx_counter=0;
    UINT    status;

        /* This thread retrieves messages placed on the queue by thread 1.  */
        while(1)
        {

            /* Increment the thread counter.  */
            tx_counter++;

            /* Retrieve a message from the queue.  */
            status = tx_queue_receive(&g_new_queue0, &received_message, TX_WAIT_FOREVER);

            /* Check completion status and make sure the message is what we
               expected.  */
            if ((status != TX_SUCCESS))
                break;

            /* Otherwise, all is okay.  Increment the received message count.  */
            tx_messages_received++;
        }
}
