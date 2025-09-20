#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    const char *path = (argc > 1) ? argv[1] : ".";
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);
    if (!dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        struct stat st;
        char fullpath[4096];

        // Build full path for lstat
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        if (lstat(fullpath, &st) == -1) {
            perror("lstat");
            continue;
        }

        // File type
        char type = '?';
        if (S_ISREG(st.st_mode)) type = '-';
        else if (S_ISDIR(st.st_mode)) type = 'd';
        else if (S_ISLNK(st.st_mode)) type = 'l';

        // Owner / group
        struct passwd *pw = getpwuid(st.st_uid);
        struct group  *gr = getgrgid(st.st_gid);

        // Time
        char *time_str = ctime(&st.st_mtime);
        time_str[strlen(time_str)-1] = '\0'; // remove newline

        // Print info (like ls -l but simpler)
        printf("%c %5ld %s %s %8ld %s %s\n",
               type,
               (long)st.st_nlink,
               pw ? pw->pw_name : "unknown",
               gr ? gr->gr_name : "unknown",
               (long)st.st_size,
               time_str,
               entry->d_name);
    }

    if (closedir(dir) == -1) {
        perror("closedir");
        exit(EXIT_FAILURE);
    }

    return 0;
}




