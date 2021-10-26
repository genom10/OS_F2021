
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct fileData{
    int inode;
    char filename[256];
} fileData;

int main () {
    const DIR *dir = opendir("tmp");
    struct dirent *dirp;
    struct stat filestat;
    char filepath[512];
    char command[128];
    while ((dirp = readdir(dir)) != NULL){
	if (dirp->d_type != 8)
	    continue;
        snprintf(filepath, sizeof(filepath), "tmp/%s", dirp->d_name);
        stat (filepath, &filestat);
        if (filestat.st_nlink >= 2){
            snprintf(command, sizeof(command), "echo ");
            system(command);
            snprintf(command, sizeof(command), "echo file: %s", dirp->d_name);
            system(command);
            snprintf(command, sizeof(command), "find tmp -inum %i", filestat.st_ino);
            system(command);
        }
    }

    closedir(dir);
}
