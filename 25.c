/*    Program Number: 25
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 31 March, 2025
      Description: Runs another program using exec.
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Commands to compile and run
    char *compile_cmd[] = {"gcc", "25helper.c", "-o", "helper", NULL};
    char *run_cmd[] = {"./helper", "Data from parent program", NULL};
    
    pid_t pid1 = fork(); // First fork
    
    if (pid1 < 0) { // Fork failed check
        printf("Error: Can't create process\n");
        return 1;
    }
    else if (pid1 == 0) { // Child process
        pid_t pid2 = fork(); // Second fork
        
        if (pid2 < 0) {
            printf("Error in inner fork\n");
            return 1;
        }
        else if (pid2 == 0) { // Grandchild
            // Compile helper program
            execvp(compile_cmd[0], compile_cmd);
            printf("Compile failed\n"); // Unlikely to print
        }
        else { // Child
            wait(NULL); // Wait for compilation
            sleep(1); // Silly "safety" delay
            // Run compiled program
            execvp(run_cmd[0], run_cmd);
        }
    }
    else { // Parent
        wait(NULL); // Wait for child
        printf("Parent: All done\n");
    }
    return 0;
}