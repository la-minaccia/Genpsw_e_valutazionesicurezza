#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 17
#define ALFABETO 26

int checkMaiuscola(char mai[], char p[]);
int checkMinuscola(char min[], char p[]);
int main(){
    srand(time(NULL));
    int scelta =0;
    char password[N] = {'c'};
    char maiuscola[ALFABETO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char minuscola[ALFABETO] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    do{

        printf("Scegli:\n 1. generare password causalmente\n 2. Inserisci password per verificare la sicurezza\nInserisci:");
        scanf("%d", &scelta);
        if(scelta != 1 && scelta != 2)
            printf("hai sbagliato\n");

    } while(scelta != 1 && scelta != 2);
    switch(scelta){
        case 2:
            printf("Inserisci la password (max 16 caratteri):\t");
            scanf("%16s", password);

            
            if (checkMaiuscola(maiuscola, password) == 1) printf("\nHa almeno 1 maiuscola\n");
            else printf("Non ha una maiuscola\n");
            if (checkMinuscola(minuscola, password) == 1) printf("Ha almeno 1 minuscola\n");
            else printf("Non ha una minuscola\n");

            break;



    }
    for (int i = 0; password[i] != '\0'; i++)
        printf("%c", password[i]);


    return 0;
}


int checkMaiuscola(char mai[], char p[]) {
    for (int i = 0; p[i] != '\0'; i++)
        for (int j = 0; j < ALFABETO; j++)
            if(p[i] == mai[j]) return (1);
    return (0);
}

int checkMinuscola(char min[], char p[]) {
    for (int i = 0; p[i] != '\0'; i++)
        for (int j = 0; j < ALFABETO; j++)
            if(p[i] == min[j]) return (1);
    return (0);
}