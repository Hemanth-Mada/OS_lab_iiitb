/*    Program Number: 15
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 26 March, 2025
      Description: This program displays the environmental variables of the user
                   using the environ variable.
*/

#include <unistd.h>

int main()
{
    extern char **environ;
    int i = 0;

    // Loop through the environment variables
    while (environ[i])
    {
        // Write the current environment variable to standard output
        write(1, environ[i], 100);
        write(1, "\n", 1);
        i++;
    }

    return 0;
}
