#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dir;

    struct dirent *entrada;

    dir = opendir(argv[1]);
    if (dir == NULL)
    {
        perror("No se pudo acceder a la carpeta");
        return 1;
    }

    while((entrada = readdir(dir)) != NULL)
    {
        printf("%s\n", entrada->d_name);
    }

    closedir(dir);
    return 0;
}