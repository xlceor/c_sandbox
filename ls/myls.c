#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>

bool onlydir = false;
bool onlyfiles = false;
bool showhide = false;

void preprocess(DIR *dir);


int main(int argc, char *argv[])
{
    DIR *dir;

    char* dirpath = ".";
//    while((entrada = readdir(dir)) != NULL)
//    {
//        printf("%s\n", entrada->d_name);
//    }

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-a") == 0){
            showhide = true;
        }
        if (strcmp(argv[i], "-d") == 0)
        {
            onlydir = true;
        }
        else if (strcmp(argv[i], "-f") == 0)
        {
            onlyfiles = true;
        }
        if (onlyfiles && onlydir){
            perror("No se pueden filtrar por archivos y directorios al mismo tiempo\n");
            return 1;
        } else {
            dirpath = argv[i];
        }

    }

    dir = opendir(dirpath);
    if (dir == NULL)
    {
        perror("No se pudo acceder a la carpeta");
        return 1;
    }
    preprocess(dir);
    closedir(dir);
    return 0;
}

void printitems(char *entrada)
{
    if(!showhide){
        if (entrada[0] != '.'){
            printf("%s\n", entrada);
        }
    } else {
        printf("%s\n", entrada);
    }
}

void preprocess(DIR *dir)
{
    struct dirent *entrada;
    while ((entrada = readdir(dir)) != NULL){
        if (onlydir){
            if (entrada->d_type == DT_DIR)
            {
                printitems(entrada->d_name);
            }
        } else if (onlyfiles){
            if (entrada->d_type == DT_REG)
            {
                printitems(entrada->d_name);
            }
        }
        else
        {
            printitems(entrada->d_name);
        }
    }
}