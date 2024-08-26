# CLI Command Comparison: Windows vs. Linux

| **Function**                      | **Windows Command**                       | **Linux Command**                          |
|-----------------------------------|-------------------------------------------|--------------------------------------------|
| **Change Directory**              | `cd [directory]`                          | `cd [directory]`                           |
| **List Files and Directories**    | `dir`                                      | `ls`                                       |
| **Display Current Directory**     | `echo %cd%`                                | `pwd`                                      |
| **Copy File**                     | `copy [source] [destination]`             | `cp [source] [destination]`                |
| **Move/Rename File**              | `move [source] [destination]`             | `mv [source] [destination]`                |
| **Delete File**                   | `del [filename]`                          | `rm [filename]`                            |
| **Remove Directory**              | `rmdir [directory]`                       | `rmdir [directory]`                        |
| **Create Directory**              | `mkdir [directory]`                       | `mkdir [directory]`                        |
| **Display File Content**          | `type [filename]`                         | `cat [filename]`                           |
| **Open File in Notepad**          | `notepad [filename]`                      | `nano [filename]` or `vi [filename]`       |
| **Change File Permissions**       | `icacls [filename] /grant [username]:[permissions]` | `chmod [permissions] [filename]` |
| **Take Ownership of File**        | `takeown /f [filename]`                   | `chown [user] [filename]`                  |
| **List Running Processes**        | `tasklist`                                | `ps aux`                                   |
| **Kill Process by PID**           | `taskkill /PID [PID]`                     | `kill [PID]`                               |
| **Kill Process by Name**          | `taskkill /IM [process_name]`            | `pkill [process_name]`                     |
| **Ping a Host**                   | `ping [host]`                             | `ping [host]`                              |
| **Display Network Configuration** | `ipconfig`                                | `ifconfig` or `ip a`                       |
| **Trace Route to Host**           | `tracert [host]`                          | `traceroute [host]`                        |
| **Fetch Data from URL**           | `curl [url]`                              | `curl [url]`                               |
| **Display System Information**    | `systeminfo`                              | `uname -a` or `lsb_release -a`             |
| **Show Disk Space Usage**         | `wmic logicaldisk get size,freespace,caption` | `df -h`                                   |
| **Open Task Manager**             | `taskmgr`                                 | `htop` or `top`                            |
| **Search Files**                  | `dir [pattern] /s`                        | `find [directory] -name [pattern]`         |
| **Search Pattern in File**        | `findstr [pattern] [file]`                | `grep [pattern] [file]`                    |
| **Create Archive**                | `tar -cf [archive_name.tar] [directory]`  | `tar -cf [archive_name.tar] [directory]`   |
| **Extract Archive**               | `tar -xf [archive_name.tar]`              | `tar -xf [archive_name.tar]`               |
| **Compress File**                 | `compact /c [filename]`                  | `gzip [filename]`                          |
| **Decompress File**               | `compact /u [filename]`                  | `gunzip [filename]`                        |
| **Add New User**                  | `net user [username] /add`                | `adduser [username]`                       |
| **Change User Password**          | `net user [username] [password]`          | `passwd [username]`                        |
| **Run Command as Different User** | `runas /user:[username] [command]`       | `su - [username] -c "[command]"`           |
| **Shutdown Computer**             | `shutdown /s /t [seconds]`                | `shutdown -h now` or `poweroff`            |
