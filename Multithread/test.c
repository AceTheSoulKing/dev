#include <stdio.h>
// #include <stdlib.h>

void file()
{
    FILE *fptr;

    fptr = fopen("filename.txt", "w");

    char data[100] = "Data from the program"
                     "using c";

    if (fptr == NULL)
        printf("File is not found\n");
    else
    {
        printf("The file is opened\n");
        fputs(data, fptr);
        fputs("\n", fptr);
        fseek(fptr, -6, SEEK_END);
        fputs("Boopathi", fptr);

        fclose(fptr);

        printf("Writting the data to the file was successfull\n");
    }
}

int main()
{
    file();
}