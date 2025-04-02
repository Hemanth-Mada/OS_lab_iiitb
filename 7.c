/*    Program Number: 7
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 25 March, 2025
      Description: This program copies the contents of file1 into file2,
                   mimicking the behavior of the cp command.
*/

#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
   int src, dest;
   char buf[50];
   long int n;

   src = open(argv[1], O_RDONLY);
   dest = open(argv[2], O_CREAT | O_WRONLY, 0700);

   while ((n = read(src, buf, 50)) > 0)
   {
      write(dest, buf, n);
   }

   close(src);
   close(dest);

   return 0;
}
