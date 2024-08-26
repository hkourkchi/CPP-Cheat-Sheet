# Linux Command Line Interface (CLI) Guide

## 1. Navigation Commands

- **`pwd`**: Prints the current working directory.
- **`ls`**: Lists the files and directories in the current directory.
- **`cd [directory]`**: Changes the current directory to the specified directory.

## 2. File and Directory Management

- **`touch [filename]`**: Creates an empty file with the specified name.
- **`mkdir [directory]`**: Creates a new directory.
- **`cp [source] [destination]`**: Copies files or directories from the source to the destination.
- **`mv [source] [destination]`**: Moves or renames files or directories.
- **`rm [filename]`**: Removes a file. Use `rm -r [directory]` to remove a directory and its contents.

## 3. Viewing and Editing Files

- **`cat [filename]`**: Displays the contents of a file.
- **`nano [filename]`**: Opens a file in the Nano text editor.
- **`vim [filename]`**: Opens a file in the Vim text editor.
- **`less [filename]`**: Allows scrolling through the contents of a file.

## 4. Permissions and Ownership

- **`chmod [permissions] [filename]`**: Changes the file permissions.
- **`chown [owner]:[group] [filename]`**: Changes the ownership of a file or directory.

## 5. Process Management

- **`ps`**: Displays the currently running processes.
- **`top`**: Shows an interactive view of system processes.
- **`kill [PID]`**: Terminates a process by its Process ID (PID).
- **`killall [process_name]`**: Terminates all processes with the specified name.

## 6. Networking

- **`ping [host]`**: Sends ICMP echo requests to a network host.
- **`ifconfig`**: Displays or configures network interfaces (deprecated in favor of `ip`).
- **`ip addr`**: Displays network interfaces and IP addresses.
- **`wget [url]`**: Downloads files from the web.

## 7. System Information

- **`uname -a`**: Displays detailed information about the system.
- **`df -h`**: Shows disk space usage in a human-readable format.
- **`free -h`**: Displays memory usage in a human-readable format.

## 8. Searching

- **`find [directory] -name [filename]`**: Searches for files by name.
- **`grep [pattern] [file]`**: Searches for a specific pattern in a file.

## 9. Archiving and Compression

- **`tar -cvf [archive_name.tar] [directory]`**: Creates a `.tar` archive.
- **`tar -xvf [archive_name.tar]`**: Extracts a `.tar` archive.
- **`gzip [file]`**: Compresses a file using gzip.
- **`gunzip [file.gz]`**: Decompresses a gzip-compressed file.

## 10. User Management

- **`adduser [username]`**: Adds a new user.
- **`passwd [username]`**: Changes the password for a user.
- **`su [username]`**: Switches to another user account.
- **`sudo [command]`**: Runs a command with superuser privileges.



# Specialized Linux CLI Commands for File and Folder Management

| **Function**                           | **Command**                                          | **Description**                                              |
|----------------------------------------|------------------------------------------------------|--------------------------------------------------------------|
| **List Files and Directories**         | `ls`                                                | Lists all files and directories in the current directory.   |
| **Change Directory**                   | `cd [directory]`                                    | Changes the current directory to the specified directory.   |
| **Display Current Directory**          | `pwd`                                               | Displays the current working directory.                     |
| **Create New Directory**               | `mkdir [directory]`                                | Creates a new directory.                                    |
| **Remove Empty Directory**             | `rmdir [directory]`                                | Removes an empty directory.                                 |
| **Remove Directory and Contents**      | `rm -r [directory]`                                | Removes a directory and all of its contents.                |
| **Copy File**                          | `cp [source] [destination]`                         | Copies a file from the source to the destination.           |
| **Copy Directory and Contents**        | `cp -r [source] [destination]`                      | Copies a directory and its contents, including subdirectories. |
| **Move/Rename File**                   | `mv [source] [destination]`                         | Moves or renames a file.                                    |
| **Move/Rename Directory**              | `mv [source] [destination]`                         | Moves or renames a directory and its contents.              |
| **Delete File**                        | `rm [filename]`                                    | Deletes a specified file.                                   |
| **Delete Multiple Files**              | `rm [pattern]`                                    | Deletes multiple files matching the specified pattern.      |
| **Delete Directory and Contents**      | `rm -r [directory]`                                | Removes a directory and all of its contents.                |
| **Rename File or Directory**           | `mv [oldname] [newname]`                           | Renames a file or directory.                                |
| **Find Files and Directories**         | `find [directory] -name [pattern]`                  | Searches for files and directories matching the pattern in the specified directory. |
| **Search Text in Files**               | `grep [pattern] [file]`                            | Searches for a specific text pattern in a file.             |
| **Display File Content**               | `cat [filename]`                                  | Displays the contents of a file.                            |
| **Compare Files**                     | `diff [file1] [file2]`                              | Compares two files and displays the differences.            |
| **Create Archive**                    | `tar -cf [archive_name.tar] [directory]`            | Creates a `.tar` archive of a directory.                    |
| **Extract Archive**                   | `tar -xf [archive_name.tar]`                        | Extracts a `.tar` archive.                                 |
| **Compress File**                     | `gzip [filename]`                                  | Compresses a file to `.gz` format.                          |
| **Decompress File**                   | `gunzip [filename]`                                | Decompresses a `.gz` file.                                 |
| **List Archive Contents**             | `tar -tf [archive_name.tar]`                        | Lists the contents of a `.tar` archive.                     |
| **Copy Directory Tree**               | `cp -r [source] [destination]`                      | Copies a directory tree with all subdirectories and files.  |
| **Get File Attributes**               | `ls -l [filename]`                                 | Displays detailed attributes of a file.                     |
| **Change File Permissions**            | `chmod [permissions] [filename]`                    | Changes the file permissions.                              |
| **Change File Ownership**              | `chown [user]:[group] [filename]`                   | Changes the owner and group of a file.                      |


