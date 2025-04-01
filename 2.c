/*    Program Number: 2
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 25 March, 2025
      Description: This program runs indefinitely in the background and
                   traverses the /proc directory to extract process information.
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

void get_process_info(const char *pid)
{
    char path[100];
    char buffer[1024];
    FILE *fp;

    sprintf(path, "/proc/%s/comm", pid);
    fp = fopen(path, "r");
    if (fp)
    {
        if (fgets(buffer, sizeof(buffer), fp) != NULL)
        {
            buffer[strcspn(buffer, "\n")] = 0;
            printf("PID: %s, Name: %s\n", pid, buffer);
        }
        fclose(fp);
    }

    sprintf(path, "/proc/%s/status", pid);
    fp = fopen(path, "r");
    if (fp)
    {
        while (fgets(buffer, sizeof(buffer), fp))
        {
            if (strncmp(buffer, "State:", 6) == 0)
            {
                buffer[strcspn(buffer, "\n")] = 0;
                printf("  Status: %s\n", buffer + 7);
                break;
            }
        }
        fclose(fp);
    }
    printf("\n");
}

int main()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }
    if (pid > 0)
    {
        printf("Parent process exiting. Child running in background.\n");
        exit(0);
    }
    setsid();
    while (1)
    {
        DIR *dir = opendir("/proc");
        if (!dir)
        {
            perror("opendir failed");
            return 1;
        }

        struct dirent *entry;
        int count = 0;
        while ((entry = readdir(dir)) != NULL && count < 5)
        {
            if (entry->d_type == DT_DIR && strspn(entry->d_name, "0123456789") == strlen(entry->d_name))
            {
                get_process_info(entry->d_name);
                count++;
            }
        }
        closedir(dir);
        sleep(5);
    }
    return 0;
}