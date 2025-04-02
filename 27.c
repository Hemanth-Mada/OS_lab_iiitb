/*    Program Number: 27
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 1 April, 2025
      Description: This program retrieves and displays the maximum and minimum
                   real-time priority values for SCHED_FIFO scheduling policy.
*/

#include <stdio.h>
#include <sched.h>
#include <unistd.h>

int main()
{

    int lowest_priority;
    int highest_priority;

    lowest_priority = sched_get_priority_min(SCHED_FIFO);
    sleep(1);
    highest_priority = sched_get_priority_max(SCHED_FIFO);

    if (lowest_priority < 0 || highest_priority < 0)
    {
        printf("Error getting priority values\n");
        return 1;
    }

    printf("For SCHED_FIFO policy:\n");
    printf("Minimum priority value: %d\n", lowest_priority);
    printf("Maximum priority value: %d\n", highest_priority);

    return 0;
}