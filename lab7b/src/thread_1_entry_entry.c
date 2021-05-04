#include "thread_1_entry.h"
#include "thread_0_entry.h"

/* Thread 1 entry function */
void thread_1_entry_entry(void)
{
    ULONG   thread_1_counter;
    ULONG   thread_1_messages_sent;
    UINT    status;


    /* This thread simply sends messages to a queue shared by thread 2.  */
    while(1)
    {

        /* Increment the thread counter.  */
        thread_1_counter++;

        /* Send message to queue 0.  */
        status =  tx_queue_send(&queue_0, &thread_1_messages_sent, TX_WAIT_FOREVER);

        /* Check completion status.  */
        if (status != TX_SUCCESS)
            break;

        /* Increment the message sent.  */
        thread_1_messages_sent++;
    }
}
