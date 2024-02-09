#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Main has began! \n");

    const char *maps_file_path = "/proc/self/maps";

    FILE *maps_file = fopen(maps_file_path, "r");

    if (maps_file == NULL) {
        perror("wrong directory");
        return EXIT_FAILURE;
    }
    // else

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Contents of %s:\n", maps_file_path);
    while ((read = getline(&line, &len, maps_file)) != -1) {
        printf("%s", line);
    }

    free(line);
    fclose(maps_file);

    return EXIT_SUCCESS;
}
