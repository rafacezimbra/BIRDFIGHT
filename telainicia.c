#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void menu(){
printf("|| *********    *******  *******       ********                ************* *******       *********   ***      *** *************** ||\n"); 
printf("|| ***********   *****  **********    **     ***               *************  *****   ***************  ***      *** *************** ||\n");
printf("|| **      ****   ***   **      **    **       ***             ***             ***    ************     ***      ***       ***       ||\n"); 
printf("|| **       ***   ***   **   ****     **        ***            ***             ***   ****              ***      ***       ***       ||\n"); 
printf("|| **        **   ***   **   ***      **         **            ***             ***   ****              ***      ***       ***       ||\n");
printf("|| **       **    ***   *******       **         **   ******   ***********     ***   ***               ************       ***       ||\n");
printf("|| **  ******     ***   ********      **         **   ******   ***********     ***   ***               ************       ***       ||\n");
printf("|| **       **    ***   ***  ****     **         **            ***             ***   ***       *****   ***      ***       ***       ||\n");
printf("|| **        **   ***   ***   ****    **         **            ***             ***   ***       ******  ***      ***       ***       ||\n");
printf("|| **       ***   ***   ***    ****   **        ***            ***             ***    ***          *** ***      ***       ***       ||\n");
printf("|| **    *****    ***   ***     ***   **       ***             ***             ***     *****      **** ***      ***       ***       ||\n");
printf("|| **********    *****  ***      ***  **     *****             ***            *****     *************  ***      ***       ***       ||\n");
printf("|| ********     ******* ***      ***   *********               ***           *******      *********    ***      ***       ***       ||\n");
printf("||                                                                                                                                  ||\n");
printf("||                                               SELECIONE SEUS TRÊS BIRDMONS:                                                      ||\n");
printf("||                                                                                                                                  ||\n");
printf("||                      1- Pikapombo              |  2- Cocatriz              |  3- Pato do Clube                                   ||\n");
printf("||                      4- Flamingo Capoeirista   |  5- Galo Guerreiro        |  6- Galinha Pintadinha                              ||\n");
printf("||                      7- Ticoliro               |  8- Dodo                  |  9- Rolinha                                         ||\n");
printf("||                      10- Joao                  |  11- Canarinho Sambista   |  12- Corvo Emo Gotico                               ||\n");
printf("||                      13- Papaleguas            |  14- Pica-Pau             |  15- Recruta                                        ||\n");
printf("||                                                |  16- Kiwi                 |                                                     ||\n");
printf("||                                                                                                                                  ||\n");
printf("||                                                                                                                                  ||\n");
printf("||                                                EQUIPE DE %s                                                                      ||\n", nomeUsuario);
printf("||                                              * %s                                                                                ||\n", poke[birdmonUsuario1].nome);
printf("||                                              * %s                                                                                ||\n", poke[birdmonUsuario2].nome);
printf("||                                              * %s                                                                                ||\n", poke[birdmonUsuario3].nome);
}

void escolha1(){
printf("Primeiro Birdmon: ");
scanf("%d", birdmonUsuario1);

#ifdef _WIN32
        system("cls");
    #else
        system("clear"); 
    #endif

        printf("%s:\n", poke[birdmonUsuario1].nome);
        printf("%s:\n", poke[birdmonUsuario1].tipo);
        printf("Vida: %d\n", poke[birdmonUsuario1].vida); 
        printf("Ataque: %d\n", poke[birdmonUsuario1].atq);
        printf("Defesa: %f\n", poke[birdmonUsuario1].def);
        printf("Agilidade: %d\n", poke[birdmonUsuario1].agi); 

printf("\n");
printf("Você deseja manter %s no seu time? (S/N)", poke[birdmonUsuario1].nome);
scanf("%c", &resp);

}
void escolha2(){

}

void escolha3(){

}


int main (void) {
    tp_pokemon poke[17];
    char nomeUsuario[15];
    int birdmonUsuario1, birdmonUsuario2, birdmonUsuario3;
    char resp;
    
    
    printf("O mundo dos Birdmon é um mundo cheio de mistérios...\n");
    sleep (3);
    printf("Você acaba de se mudar para a cidade de Xique-Xique, Bahia.\n");
    sleep (4);
    printf("Qual o seu nome? ");
    scanf("%s", nomeUsuario);
    printf("%s, que belo nome. Seja bem-vindo(a) ao BirdFight!\n", nomeUsuario);
    sleep (6);

printf("\n");
printf("\n");

// LIMPAR TELA
#ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

menu(); //menu

// ESCOLHA DO BIRDMON 1
escolha1();

if(resp == "S") {
    // adc pokemon na fila 
}

else if(resp == "N"){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    return escolha1;
}

printf("Segundo Birdmon:  ");
scanf("%d", birdmonUsuario2);

        printf("%s", poke[birdmonUsuario2].nome);
        printf("Vida: %d\n", poke[birdmonUsuario2].vida); 
        printf("Ataque: %d", poke[birdmonUsuario2].atq);
        printf("Defesa: %f", poke[birdmonUsuario2].def);
        printf("Agilidade: %d", poke[birdmonUsuario2].agi); 
        
printf("\n");
printf("Você deseja manter %s no seu time? (S/N)", poke[birdmonUsuario1].nome);
scanf("%c", &resp);

if("")


printf("Terceiro Birdmon: ");
scanf("%d", birdmonUsuario3)
return 0;
}
