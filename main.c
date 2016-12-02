#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX 10000

typedef struct point{

char title;
double lattitude;
double longitude;
}point;

/*
void openAndRead(char fileName)
{
      FILE* myFile = NULL
      char chaine[TAILLE_MAX];
      myFile = fopen(fileName);

      if(myFile != NULL){
            while(fgets(chaine, TAILLE_MAX, fichier) != NULL)
            {
                while()

            }

            fclose(myFile);

      }
}
*/

static void display_file(const char *file_name)
{
    FILE *f = fopen(file_name, "r");      // open the specified file
    if (f != NULL)
    {
        int c;

        while ((c = fgetc(f)) != EOF)     // read character from file until EOF
        {
            putchar(c);                   // output character
        }
        fclose(f);
    }
}

int main()
{
    display_file("Cites.csv");

    printf("Hello world!\n");
    return 0;
}
