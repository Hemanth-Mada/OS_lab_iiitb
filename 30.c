/*    Program Number: 30
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 2 April, 2025
      Description: This program executes a task at a specific time using a Daemon process. 
*/

/* Program Number: 30
Student Name: name; Register Number: IMT2018000
Date:
Description: This program creates a daemon process that runs in the background
and executes a specific task at a predefined time.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>  // For logging

// The task that will be executed at the specified time
void do_scheduled_task() {
    // We could do anything here - just printing a message for demonstration
    printf("Task is now running at the scheduled time!\n");
    
    // Could also write to a log file since daemon output might not be visible
    FILE *log_file = fopen("/tmp/daemon_log.txt", "a");
    if (log_file) {
        fprintf(log_file, "Task executed at: %ld\n", time(NULL));
        fclose(log_file);
    }
}

int main() {
    printf("Starting program to create daemon...\n");
    
    // Create child process
    int child_pid = fork();
    
    // Check if fork worked
    if (child_pid < 0) {
        printf("Error: Could not create fork!\n");
        return 1;
    }
    
    // Parent process exits immediately to allow child to become daemon
    if (child_pid > 0) {
        printf("Parent process exiting. Daemon started with PID: %d\n", child_pid);
        return 0;  // Parent exits successfully
    }
    
    // From here, only the child process continues
    
    // Create new session and process group
    if (setsid() < 0) {
        printf("Failed to create new session\n");
        return 1;
    }
    
    // Change working directory to root (or another suitable directory)
    if (chdir("/tmp") != 0) {  // Using /tmp instead of / as it's more writable
        printf("Failed to change directory\n");
        return 1;
    }
    
    // Reset file creation mask
    umask(0);
    
    // Close standard file descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    
    // Log that daemon has started
    FILE *log = fopen("/tmp/daemon_log.txt", "w");
    if (log) {
        fprintf(log, "Daemon started with PID: %d\n", getpid());
        fclose(log);
    }
    
    // Set the target time (15:30:00 in this example)
    int target_hour = 15;
    int target_min = 30;
    int target_sec = 0;
    
    // For testing purposes, you might want to set the time just a minute from now
    time_t now = time(NULL);
    struct tm *current = localtime(&now);
    
    // Uncomment these lines for testing to set target time to 1 minute from now
    
    target_hour = current->tm_hour;
    target_min = current->tm_min + 1;
    if (target_min >= 60) {
        target_min = 0;
        target_hour++;
    }
    target_sec = 0;
    
    
    // Main daemon loop
    while (1) {
        // Get current time
        time_t now_time = time(NULL);
        struct tm *time_info = localtime(&now_time);
        
        // Check if it's the target time
        if (time_info->tm_hour == target_hour && 
            time_info->tm_min == target_min && 
            time_info->tm_sec == target_sec) {
            
            // Execute our scheduled task
            do_scheduled_task();
            
            // Sleep a bit to avoid multiple executions in the same second
            sleep(2);
        }
        
        // Check time every few seconds to reduce CPU usage
        sleep(5);  // Check less frequently than original
    }
    
    // This code will never be reached, but good practice to return
    return 0;
}