#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int numberSize = 0;
int limitSize = 32;
int characterSize = 0;

char * GenerateCharacters(){
    srand(time(NULL));

    char UppercaseC[26];

    int size = limitSize - numberSize;
    characterSize = size;

    int index = 0;

    char* characters = (char*) malloc(sizeof(char )* (size+1));

    for (char i  = 'A'; i <= 'Z'; ++i) {
            UppercaseC[index] = i;
            index++;
    }

    if (characters == NULL) {
        fprintf(stderr, "Erreur d'allocation de memoire.\n");
        exit(1);
    }

    for(int i = 0; i < size; ++i){
        int randomI = rand() % 26;
        characters[i] = UppercaseC[randomI];
        //printf("%s",characters[i]);
    }

   characters[size] = '\0';

    return characters;
}

int * GenerateNumbers(){

    srand(time(NULL));

    int size = rand()%24;
    numberSize = size;
    int* numbers = (int*)malloc(size * sizeof(int));

    if (numbers == NULL) {
        fprintf(stderr, "Erreur d'allocation de memoire.\n");
        exit(1);
    }

    for (int i = 0; i < size; ++i) {
            numbers[i] = rand()%10;
      // printf("%d",numbers[i]);
    }

    return numbers;

}

void GenerateCode(){

    int *n = GenerateNumbers();

    char code[32];

    printf("%d", n);
    free(n);

    char *c = GenerateCharacters();

    if(c != NULL){
        printf("%s\n", c);
        free(c);
    } else {
        fprintf(stderr, "Erreur lors de la génération de la séquence.\n");
    }
  // code[i] = n[i];

}

void StartingChoice() {
    int choice;
    printf("Do you want a code?\n");
    printf("1 - YES\n");
    printf("2 - NO\n");

    scanf("%d",&choice);

        switch (choice) {
            case 1:
                printf("We're generating a code...\n");
                GenerateCode();
                break;
            case 2:
                printf("Goodbye!\n");
                break;
            default:
                printf("This is not correct\n");
        }
}

int main() {
    StartingChoice();
    return 0;
}

