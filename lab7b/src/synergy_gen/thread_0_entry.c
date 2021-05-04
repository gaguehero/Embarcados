/* generated thread source file - do not edit */
#include "thread_0_entry.h"

TX_THREAD thread_0_entry;
void thread_0_entry_create(void);
static void thread_0_entry_func(ULONG thread_input);
static uint8_t thread_0_entry_stack[1024] BSP_PLACE_IN_SECTION_V2(".stack.thread_0_entry") BSP_ALIGN_VARIABLE_V2(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void *p_instance, void *p_data);
void tx_startup_common_init(void);
TX_MUTEX mutex_0;
TX_EVENT_FLAGS_GROUP event_flags_0;
TX_QUEUE queue_0;
static uint8_t queue_memory_queue_0[800];
TX_SEMAPHORE semaphore_0;
extern bool g_ssp_common_initialized;
extern uint32_t g_ssp_common_thread_count;
extern TX_SEMAPHORE g_ssp_common_initialized_semaphore;

void thread_0_entry_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_ssp_common_thread_count++;

    /* Initialize each kernel object. */
    UINT err_mutex_0;
    err_mutex_0 = tx_mutex_create (&mutex_0, (CHAR *) "Mutex 0", TX_NO_INHERIT);
    if (TX_SUCCESS != err_mutex_0)
    {
        tx_startup_err_callback (&mutex_0, 0);
    }
    UINT err_event_flags_0;
    err_event_flags_0 = tx_event_flags_create (&event_flags_0, (CHAR *) "Event Flags 0");
    if (TX_SUCCESS != err_event_flags_0)
    {
        tx_startup_err_callback (&event_flags_0, 0);
    }
    UINT err_queue_0;
    err_queue_0 = tx_queue_create (&queue_0, (CHAR *) "Queue 0", 2, &queue_memory_queue_0,
                                   sizeof(queue_memory_queue_0));
    if (TX_SUCCESS != err_queue_0)
    {
        tx_startup_err_callback (&queue_0, 0);
    }
    UINT err_semaphore_0;
    err_semaphore_0 = tx_semaphore_create (&semaphore_0, (CHAR *) "Semaphore 0", 1);
    if (TX_SUCCESS != err_semaphore_0)
    {
        tx_startup_err_callback (&semaphore_0, 0);
    }

    UINT err;
    err = tx_thread_create (&thread_0_entry, (CHAR *) "Thread 0", thread_0_entry_func, (ULONG) NULL,
                            &thread_0_entry_stack, 1024, 1, 1, 0, TX_AUTO_START);
    if (TX_SUCCESS != err)
    {
        tx_startup_err_callback (&thread_0_entry, 0);
    }
}

static void thread_0_entry_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    SSP_PARAMETER_NOT_USED (thread_input);

    /* Initialize common components */
    tx_startup_common_init ();

    /* Initialize each module instance. */

    /* Enter user code for this thread. */
    thread_0_entry_entry ();
}
