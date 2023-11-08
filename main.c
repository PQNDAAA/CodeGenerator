#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int limitSize = 32;

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(char arr[], int size) {
    srand(time(0));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

char Random_Number(int index){

    char charset[10] = "0123456789";

    return charset[index];

}

char Random_Character(int index){

    int indexCharacter = 0;
    char uppercaseCharacter[26];

    for (char i  = 'A'; i <= 'Z'; ++i) {
        uppercaseCharacter[indexCharacter] = i;
        indexCharacter++;
    }

    return uppercaseCharacter[index];
}

void GenerateCode(int number){
    srand(time(NULL));

    for (int i = 0; i < number; ++i) {

        char code[limitSize];

        int randomNumberSize = rand() % 24;
        int saveNumberSize = randomNumberSize;

        int characterSize = limitSize - saveNumberSize;

        int randomIndex = 0;

        for (int i = 0; i < limitSize; ++i) {
            code[i] = '\0';
        }

        for (int i = 0; i < saveNumberSize; ++i) {
            randomIndex = rand() % 10;
            code[i] = Random_Number(randomIndex);
        }
        for (int i = saveNumberSize; i < limitSize; ++i) {
            randomIndex = rand() % 26;
            //printf("%c",Random_Character(randomIndex));
            code[i] = Random_Character((randomIndex));
        }

        shuffle(code, limitSize);

        for (int i = 0; i < limitSize; ++i) {
            printf("%c", code[i]);
        }
        printf("\n-----------------------\n");
    }

}

void StartingChoice() {
    int choice;
    int num;
    printf("Do you want a code?\n");
    printf("1 - YES\n");
    printf("2 - NO\n");

    scanf("%d",&choice);

        switch (choice) {
            case 1:
                printf("How many codes?\n");
                scanf("%d", &num);
                printf("We're generating a code...\n");
                GenerateCode(num);
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

