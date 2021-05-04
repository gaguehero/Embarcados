#include "thread_0_entry.h"

/* Thread 0 entry function */
void thread_0_entry_entry(void)
{
    UINT    status;
    ULONG   thread_0_counter;

    /* This thread simply sits in while-forever-sleep loop.  */
    while(1)
    {
        /* Increment the thread counter.  */
        thread_0_counter++;

        /* Sleep for 10 ticks.  */
        tx_thread_sleep(10);

        /* Set event flag 0 to wakeup thread 5.  */
        status =  tx_event_flags_set(&event_flags_0, 0x1, TX_OR);

        /* Check status.  */
        if (status != TX_SUCCESS)
            break;
    }
}
