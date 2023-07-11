#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat fileStat;

    if (stat("exec.c", &fileStat) == -1) {
        perror("stat");
        return 1;
    }

    printf("File size: %lld bytes\n", (long long)fileStat.st_size);
    printf("File permissions: %o\n", fileStat.st_mode & 0777);
    printf("Owner UID: %d\n", fileStat.st_uid);
    printf("Group GID: %d\n", fileStat.st_gid);
	printf("ST dev: %d\n",fileStat.st_dev); 
    return 0;
}
