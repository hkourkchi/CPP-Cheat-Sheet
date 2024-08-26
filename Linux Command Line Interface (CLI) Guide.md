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
