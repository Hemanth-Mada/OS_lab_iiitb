#    Program Number: 1 
#    Student Name: Mada Hemanth; Register Number: IMT2023581 
#    Date: 25 March, 2025
#    Description: This script creates different file types using shell commands:
#                 soft link, hard link, and FIFO.

#!/bin/bash

if [ $# -lt 1 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

FILENAME=$1

touch "$FILENAME"
echo "File '$FILENAME' created."

ln -s "$FILENAME" "symbolic_link"
echo "Symbolic link 'symbolic_link' created."

ln "$FILENAME" "hard_link"
echo "Hard link 'hard_link' created."

mkfifo "named_pipe"
echo "Named pipe 'named_pipe' created."
