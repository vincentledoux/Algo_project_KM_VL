#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX 10000

typedef struct point{

char title;
double lattitude;
double longitude;
}point
;

void openAndRead(char fileName)
{
      FILE* myFile = NULL
      char chaine[TAILLE_MAX];
      myFile = fopen(fileName);

      if(myFile != NULL){
            while(fgets(chaine, TAILLE_MAX, fichier) != NULL)
            {

            }

      }
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
