#include <stdio.h>
#include <stdlib.h>
// Global variables for the shared buffer and item number
int mutex = 1, full = 0, empty = 3, x = 0;
int main()
{
    int n;
    // Function prototypes for producer and consumer
    void producer();
    void consumer();
    // Function prototypes for wait and signal functions
    int wait(int);
    int signal(int);
    // Display menu options to user
    printf("\n1.Producer\n2.Consumer\n3.Exit");
    // Loop forever to repeatedly show menu options
    while (1)
    {
        // Prompt user for choice
        printf("\nEnter your choice:");
        scanf("%d", &n);
        switch (n)
        {
        // If user chooses 1, call the producer function if buffer is not full
        case 1:
            if ((mutex == 1) && (empty != 0))
                producer();
            else
                printf("Buffer is full=!");
            break;
        // If user chooses 2, call the consumer function if buffer is not empty
        case 2:
            if ((mutex == 1) && (full != 0))
                consumer();
            else
                printf("Buffer is empty=!");
            break;
        // If user chooses 3, exit the program
        case 3:
            exit(0);
            break;
        }
    }
    return 0;
}
// Function to decrement a given semaphore variable
int wait(int s)
{
    return (--s);
}
// Function to increment a given semaphore variable
int signal(int s)
{
    return (++s);
}
// Function that represents a producer thread
void producer()
{
    // Acquire the mutex before accessing shared buffer
    mutex = wait(mutex);
    // Increment the number of full slots in buffer
    full = signal(full);
    // Decrement the number of empty slots in buffer
    empty = wait(empty);
    // Increment the item number produced
    x++;
    // Print message indicating the number of item produced
    printf("\nProducer produces the item %d", x);
    // Release the mutex
    mutex = signal(mutex);
}
// Function that represents a consumer thread
void consumer()
{
    // Acquire the mutex before accessing shared buffer
    mutex = wait(mutex);
    // Decrement the number of full slots in buffer
    full = wait(full);
    // Increment the number of empty slots in buffer
    empty = signal(empty);
    // Print message indicating the number of item consumed
    printf("\nConsumer consumes item %d", x);
    // Decrement the item number consumed
    x--;
    // Release the mutex
    mutex = signal(mutex);
}