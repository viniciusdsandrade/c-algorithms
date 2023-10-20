#include <stdbool.h>
#include <stdio.h>
#include <locale.h>
#include "global.h"

#define MAX_EXERCISES 10

int exercise01(void) {

    const char *nomeArquivoOrigem = "C:\\Users\\vinic\\OneDrive\\�rea de Trabalho\\CStudy\\Algorithms-and-Data-Structure-in-C\\lista_7_C_files\\exe01.txt";
    bool verify = verificarArquivo(nomeArquivoOrigem);

    if (verify)
        printf("File exists!\n");
    else
        printf("File does not exist!\n");

    return 0;
}

int exercise02(void) {

    const char *nomeArquivoOrigem = "C:\\Users\\vinic\\OneDrive\\�rea de Trabalho\\CStudy\\Algorithms-and-Data-Structure-in-C\\lista_7_C_files\\exe01.txt";
    imprimirConteudoArquivo(nomeArquivoOrigem);
    printf("\n");

    return 0;
}

int exercise03(void) {

    FILE *arq1;
    char aux, nomeArq[20];

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArq);
    arq1 = fopen(nomeArq, "r");
    if (arq1 == NULL) {
        printf("Error opening file!\n");
        return 1;
    } else {
        printf("dados do arquivo %s\n", nomeArq);
        while (fscanf(arq1, "%c", &aux) != EOF) {
            printf("%c", aux);
        }
    }
    fclose(arq1);

    return 0;
}

int exercise04(void) {

    const char *nomeArquivoOrigem = "C:\\Users\\vinic\\OneDrive\\�rea de Trabalho\\CStudy\\Algorithms-and-Data-Structure-in-C\\lista_7_C_files\\exe01.txt";
    const char *nomeArquivoDestino = "C:\\Users\\vinic\\OneDrive\\�rea de Trabalho\\CStudy\\Algorithms-and-Data-Structure-in-C\\lista_7_C_files\\exe03.txt";

    copiarArquivo(nomeArquivoOrigem, nomeArquivoDestino);

    bool verify = compareFiles(nomeArquivoOrigem, nomeArquivoDestino);

    if (verify)
        printf("Files are equal!\n");
    else
        printf("Files are not equal!\n");

    return 0;
}

int exercise05(void) {




    return 0;
}

int exercise06(void) {
    printf("\nExercise 06:\n");
    return 0;
}

int exercise07(void) {
    printf("\nExercise 07:\n");
    return 0;
}

int exercise08(void) {
    printf("\nExercise 08:\n");
    return 0;
}

int exercise09(void) {
    printf("\nExercise 09:\n");
    return 0;
}

int exercise10(void) {
    printf("\nExercise 10:\n");
    return 0;
}


int displayMenuAndGetChoice(void) {
    printf("Exercise 01:\n");
    printf("Exercise 02:\n");
    printf("Exercise 03:\n");
    printf("Exercise 04:\n");
    printf("Exercise 05:\n");
    printf("Exercise 06:\n");
    printf("Exercise 07:\n");
    printf("Exercise 08:\n");
    printf("Exercise 09:\n");
    printf("Exercise 10:\n");
    printf("Enter the number of the exercise you want to execute: ");

    int choice;
    scanf("%d", &choice);
    return choice;
}

void executeExercise(int choice) {
    switch (choice) {
        case 1:
            exercise01();
            break;
        case 2:
            exercise02();
            break;
        case 3:
            exercise03();
            break;
        case 4:
            exercise04();
            break;
        case 5:
            exercise05();
            break;
        case 6:
            exercise06();
            break;
        case 7:
            exercise07();
            break;
        case 8:
            exercise08();
            break;
        case 9:
            exercise09();
            break;
        case 10:
            exercise10();
            break;
        default:
            printf("Invalid option!\n");
            break;
    }
}

bool getExitChoice(void) {
    int exitChoice;
    do {
        printf("Do you want to exit?\n"
               "Enter (1) for Yes or (0) for No: ");
        scanf("%d", &exitChoice);
    } while (exitChoice != 0 && exitChoice != 1);
    return exitChoice;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    bool exitProgram = false;

    do {
        int choice = displayMenuAndGetChoice();

        if (choice >= 1 && choice <= MAX_EXERCISES) {
            executeExercise(choice);
        } else {
            printf("Invalid option!\n");
        }
        exitProgram = getExitChoice();
    } while (!exitProgram);
    printf("Thank you for using the program!\n");
    return 0;
}