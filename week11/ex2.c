#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>


int main(int argc, char *argv[]){
    DIR *dp;
    struct dirent *dirp;
    struct stat filestat;
    char filepath[512];

    dp = opendir("/");
    while ((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);
    exit(EXIT_SUCCESS);
}
