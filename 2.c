/*    Program Number: 2 
      Student Name: Mada Hemanth; Register Number: IMT2023581 
      Date: 25 March, 2025
      Description: This program runs indefinitely in the background and 
                   traverses the /proc directory to extract process information.  
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

void check_proc() {
    DIR *d;
    struct dirent *de;
    
    d = opendir("/proc");
    if (!d) {
        printf("Error opening /proc\n");
        return;
    }
    
    printf("PID   Name\n");
    while ((de = readdir(d)) != NULL) {
        if (de->d_type == DT_DIR && strspn(de->d_name, "0123456789") == strlen(de->d_name)) {
            char path[256];
            char name[256];
            FILE *f;
            snprintf(path, 256, "/proc/%s/comm", de->d_name);
            
            f = fopen(path, "r");
            if (f) {
                fscanf(f, "%s", name);
                fclose(f);
                printf("%s  %s\n", de->d_name, name);
            }
        }
    }
    closedir(d);
}

int main() {
    while (1) {
        check_proc();
        sleep(5); // wait for 5 seconds
    }
    return 0;
}
