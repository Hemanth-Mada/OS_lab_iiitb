/*    Program Number: 6
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 25 March, 2025
      Description: This program reads input from STDIN and prints it to STDOUT
                   using only read and write system calls.
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char buffer[100] = {};

    read(STDIN_FILENO, buffer, 100);
    write(STDOUT_FILENO, buffer, 100);


}
