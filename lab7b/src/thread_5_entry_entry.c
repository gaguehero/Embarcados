#include "thread_5_entry.h"
#include "thread_0_entry.h"

/* Thread 5 entry function */
void thread_5_entry_entry(void)
{
    UINT    status;
    ULONG   actual_flags;
    ULONG   thread_5_counter;


    /* This thread simply waits for an event in a forever loop.  */
    while(1)
    {

        /* Increment the thread counter.  */
        thread_5_counter++;

        /* Wait for event flag 0.  */
        status =  tx_event_flags_get(&event_flags_0, 0x1, TX_OR_CLEAR,
                                                    &actual_flags, TX_WAIT_FOREVER);

        /* Check status.  */
        if ((status != TX_SUCCESS) || (actual_flags != 0x1))
            break;
    }
}
