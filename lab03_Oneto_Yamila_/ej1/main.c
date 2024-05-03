#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

void sorted_phrase(char sorted[], char letters[], unsigned indexes[], unsigned int length)
{
    for (unsigned int i = 0; i < length; i++)
    {

        if (indexes[i] < indexes[i + 1])
        {   
            sorted[indexes[i]] = letters[i];
            
        }
        else
        {
            sorted[indexes[i]] = letters[i];
        }
    }
}
char *parse_filepath(int argc, char *argv[])
{

    char *result = NULL;

    bool valid_args_count = (argc == 2);

    if (!valid_args_count)
    {
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size)
{
    FILE *fl;
    unsigned int size = 0u;
    fl = fopen(path, "r");
    if (fl != NULL)
    {
        while (feof(fl) == 0 && size < max_size)
        {
            fscanf(fl, " %u  ->  *%c* ", &indexes[size], &letters[size]);
            size++;
        }
    }
    else
    {
        printf("Error en abrir el archivo \n");
        return -1;
    }
    fclose(fl);
    return size;
}

static void dump(char a[], unsigned int length)
{
    printf("\"");
    for (unsigned int j = 0u; j < length; j++)
    {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

int main(int argc, char *argv[])
{
    char *file = NULL;
    file = parse_filepath(argc, argv);
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    unsigned int length = data_from_file(file, indexes, letters, MAX_SIZE);
    char sorted[MAX_SIZE];

    sorted_phrase(sorted, letters, indexes, length);
    dump(sorted, length);

    return EXIT_SUCCESS;
}
