#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>


void printdir(DIR *dir, bool onlydir, bool onlyfiles);


int main(int argc, char *argv[])
{
    DIR *dir;

    char* dirpath = ".";
    dir = opendir(dirpath);
    if (dir == NULL)
    {
        perror("No se pudo acceder a la carpeta");
        return 1;
    }
//    while((entrada = readdir(dir)) != NULL)
//    {
//        printf("%s\n", entrada->d_name);
//    }
    bool onlydir = false;
    bool onlyfiles = false;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-d") == 0)
        {
            onlydir = true;
        }
        else if (strcmp(argv[i], "-f") == 0)
        {
            onlyfiles = true;
        }

    }

    printdir(dir, onlydir, onlyfiles);


    closedir(dir);
    return 0;
}

void printdir(DIR *dir, bool onlydir, bool onlyfiles)
{
    struct dirent *entrada;
    while ((entrada = readdir(dir)) != NULL){
        if (onlydir){
            if (entrada->d_type == DT_DIR)
            {
                printf("%s\n", entrada->d_name);
            }
        } else if (onlyfiles){
            if (entrada->d_type == DT_REG)
            {
                printf("%s\n", entrada->d_name);
            }
        }
        else
        {
            printf("%s\n", entrada->d_name);
        }
    }
}