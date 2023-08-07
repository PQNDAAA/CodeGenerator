#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char * GenerateCharacters(){

    char UppercaseC[26];

    int index = 0;

    int randomI = 0;
    static char randomCharacters[3];

    srand(time(NULL));
    printf("\n");

    for (char i  = 'A'; i <= 'Z'; ++i) {
            UppercaseC[index] = i;
            index++;
    }

    for (int i = 0; i < index; ++i) {
        printf("%c ",UppercaseC[i]);
    }

    for (int i = 0; i < 3; ++i) {
        randomI = rand()%26;
        printf(" |%c |",UppercaseC[randomI]);
        randomCharacters[i] = UppercaseC[randomI];
    }

    return randomCharacters;
}

int * GenerateNumbers(){

    int size = 10;
    int Numbers[size];

    int randomN = 0;
    static int randomNumbers[3];

    srand(time(NULL));
    printf("\n");

    for (int i = 0; i < size; ++i) {
        Numbers[i] = i;
    }
    for (int i = 0; i < size; ++i) {
        printf("%d ", Numbers[i]);
    }
    for (int i = 0; i < 3; ++i) {
        randomN = rand()%10;
        randomNumbers[i] = Numbers[randomN];
    }

    return randomNumbers;

}

void GenerateCode(){

   // printf("%c %d",GenerateCharacters(),GenerateNumbers());

    int * n = GenerateNumbers();
    char * c = GenerateCharacters();

    int randomIndex = 0;

    char * code = "";

    printf("\n");

    for (int i = 0; i < 3; ++i) {
        printf("%d%c",n[i],c[i]);
       // printf("%c",c[i]);
       // code += c[i];
    }

    //printf("%c",code);



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

