#include <iostream>
#include <cstdio>
#include <libproc.h>
#include <libgen.h>
#include <unistd.h>

using namespace std;

int main() {

    char pathbuf[PROC_PIDPATHINFO_MAXSIZE];

    if (proc_pidpath(getpid(), pathbuf, sizeof(pathbuf)) > 0) {
        printf("Executable path: %s\n", pathbuf);
        printf("Executable directory: %s\n", dirname(pathbuf));
    } else {
        printf("Failed to retrieve executable path.\n");
    }

    FILE *fd = fopen("../README.md", "r");

    // Check if the file was opened successfully
    if (fd == nullptr) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    const int BUFF_SIZE = 1000;
    char buff[BUFF_SIZE + 1];
    size_t bytesRead = fread(buff, 1, BUFF_SIZE, fd);
    buff[bytesRead] = '\0'; // Null-terminate the read data

    // Print with padding
    printf("%.1000s", buff); // Print up to 100 characters with left-padding

    fclose(fd);

    return 0;
}
