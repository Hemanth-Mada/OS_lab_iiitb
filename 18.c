/*    Program Number: 18
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 3 April, 2025
      Description: This program creates a file and writes records in it.
      ./a.out q18.c
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct record
{
    int num;
    char *name;
} rec;

int main(int argc, char *argv[])
{
    // Open the file specified in the command line argument for writing
    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);

    // Allocate memory for three records
    rec *myrec1 = (rec *)malloc(sizeof(rec));
    rec *myrec2 = (rec *)malloc(sizeof(rec));
    rec *myrec3 = (rec *)malloc(sizeof(rec));

    // Initialize the records
    myrec1->name = "stud1";
    myrec1->num = 1;

    myrec2->name = "stud2";
    myrec2->num = 2;

    myrec3->name = "stud3";
    myrec3->num = 3;

    // Write the records to the file
    printf("Writing record1 : %d %s\n", myrec1->num, myrec1->name);
    lseek(fd, 0, SEEK_END);
    write(fd, myrec1, sizeof(rec));

    printf("Writing record2 : %d %s\n", myrec2->num, myrec2->name);
    lseek(fd, 0, SEEK_END);
    write(fd, myrec2, sizeof(rec));

    printf("Writing record3 : %d %s\n", myrec3->num, myrec3->name);
    lseek(fd, 0, SEEK_END);
    write(fd, myrec3, sizeof(rec));

    // Close the file descriptor
    close(fd);

    // Free the allocated memory for the records
    free(myrec1);
    free(myrec2);
    free(myrec3);
}
