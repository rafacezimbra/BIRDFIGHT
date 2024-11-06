#ifndef SPRITES_H
#define SPRITES_H
#include <stdio.h>
#include <string.h>
#include "pokemon.h"

#define deslocamentoDoOponente 40
//esta biblioteca serve para guardar as imagens dos passaros

void endl(){
    printf("\n");
}

int numCaracteresDeUmInt(int num){
    //funciona para inteiros nao negativos (ate 9999)
    if(num<10) return 1;
    else if(num<100) return 2;
    else if(num<1000) return 3;
    else return 4;

}

void pnome(tp_pokemon *poke, int ehinimigo, int desloc){ //printa a vida
    if(ehinimigo==1){
        printf("%*c", desloc, ' ');
        printf("%s    Lvl: %d", poke->nome, poke->nivel);
    }
}

void pvida(tp_pokemon *poke, int ehinimigo, int desloc){
    if(ehinimigo==1){
        printf("%*c", desloc, ' ');
        printf("HP: %d/%d", poke->vida, poke->vidamax);
    }
}

void ptipo(tp_pokemon *poke, int ehinimigo, int desloc){
    if(ehinimigo==1){
        printf("%*c", desloc, ' ');
        printf("Tipo: %s", poke->tipo);
    }
}

void printarPokemon(tp_pokemon poke, int ehinimigo){

//ehinimigo = -1 --> printa o pokemon sem status
//ehinimigo = 0 --> printa o pokemon do jogador, com status a direite
//eh inimigo = 1 --> printa o pokemon do inimigo (printa o pokemon, mas espacado para direita, com status a sua esquerda)

int deslocS; //deslocamento para a direita do sprite sem texto
int deslocN; //deslocamento ao printar o nome e nivel do pokemon ex: Kiwi
int deslocT; //deslocamento ao printar o tipo do pokemon ex: Tipo: dancarino
int deslocV; //deslocamento ao printar a vida do pokemon ex: HP: 100/100
int desloc0; //nao desloca nada, serve apenas pro codigo ficar bonitinho

if(ehinimigo == 0 || ehinimigo == -1){
deslocS = 0;
deslocN = 0;
deslocT = 0;
deslocV = 0;
desloc0 = 0;

}else{
deslocS = deslocamentoDoOponente;
deslocN = (deslocamentoDoOponente-(strlen(poke.nome) + 9 + numCaracteresDeUmInt(poke.nivel)));
deslocT = (deslocamentoDoOponente-(6 + strlen(poke.tipo)));
deslocV = (deslocamentoDoOponente-(4 + numCaracteresDeUmInt(poke.vida) + 1 + numCaracteresDeUmInt(poke.vidamax)));
desloc0 = 0;

}

int num = poke.num;
 
printf("\n\n");


switch(num){

    //pikapombo[1]
    case 1:
    pnome(&poke, ehinimigo, deslocN);
    printf("%*c", desloc0, ' '); printf("        xxxxxxxxx                                "); pnome(&poke, ehinimigo+1, deslocN); endl(); ptipo(&poke, ehinimigo, deslocT);
    printf("%*c", desloc0, ' '); printf("       xx        xx                              "); ptipo(&poke, ehinimigo+1, deslocT); endl(); pvida(&poke, ehinimigo, deslocV);
    printf("%*c", desloc0, ' '); printf("      x           xx                             "); pvida(&poke, ehinimigo+1, deslocV); endl();
    printf("%*c", deslocS, ' '); printf("     xx   $   $    x                             \n"); //onde esta "ehinimigo+1" eh para ser printado apenas quando o pokemon for aliado
    printf("%*c", deslocS, ' '); printf("     x             xx               xxxxxxxxxxxxx\n");
    printf("%*c", deslocS, ' '); printf("    xxxxxxxx  xxx   xx               x       xxx \n");
    printf("%*c", deslocS, ' '); printf("  xxx    xxxxxxxxxxxxxxxx            x    xxxx   \n");
    printf("%*c", deslocS, ' '); printf(" xxxxxxxxx   xxx         xxx      xxxxx    xx    \n");
    printf("%*c", deslocS, ' '); printf("            xx       xxxx   x      x       xxx   \n");
    printf("%*c", deslocS, ' '); printf("            x      xxxxxxx   xx xxxx   xxxxx     \n");
    printf("%*c", deslocS, ' '); printf("            x       xxxxx     xxxxx     xx       \n");
    printf("%*c", deslocS, ' '); printf("            xx     xxxxx       xx        xx      \n");
    printf("%*c", deslocS, ' '); printf("             x       xxx        xx    xxxxxx     \n");
    printf("%*c", deslocS, ' '); printf("             xx       xxx        xxxx            \n");
    printf("%*c", deslocS, ' '); printf("              xx               x x               \n");
    printf("%*c", deslocS, ' '); printf("               xx                x               \n");
    printf("%*c", deslocS, ' '); printf("                 xxx          xxx                \n");
    printf("%*c", deslocS, ' '); printf("                    xxxx  xxxx  xx               \n");
    printf("%*c", deslocS, ' '); printf("                     xx xx xx                    \n");
    printf("%*c", deslocS, ' '); printf("                    xxxx  xxxx               \n");
    break;

    //cocatriz[2]
    case 2:
    pnome(&poke, ehinimigo, deslocN);
    printf("%*c", deslocN, ' '); printf("xxxxxxxxx                             xxxxxxxx  x  x x x         "); pnome(&poke, ehinimigo+1, deslocN); endl(); ptipo(&poke, ehinimigo, deslocT);
    printf("%*c", deslocT, ' '); printf("   xx   xxxxxxx                   xxxxx   x    x  x x x          "); ptipo(&poke, ehinimigo+1, deslocT); endl(); pvida(&poke, ehinimigo, deslocV);
    printf("%*c", deslocV, ' '); printf("    xx         xxxx             xxx      xx   xxxxxxxxxx         "); pvida(&poke, ehinimigo+1, deslocV); endl();
    printf("%*c", deslocS, ' '); printf("     xx            xxx         xx       xx   xx        xx        \n");
    printf("%*c", deslocS, ' '); printf("      xx          |  xxxx     xx        x   xx      @   xxx      \n");
    printf("%*c", deslocS, ' '); printf("       x         |  |   xxx   x         x   x             xxxxxx \n");
    printf("%*c", deslocS, ' '); printf("       xx       |  |   |  xxxx          xxxx                   xx\n");
    printf("%*c", deslocS, ' '); printf("        xxxxxxx|  |   |  |   xxx xxxxxxxxx            xxxxxxxxx  \n");
    printf("%*c", deslocS, ' '); printf("    xxx       xxx|   |  |      xxx                  xx           \n");
    printf("%*c", deslocS, ' '); printf("    x  xx       xxxxxxx|                            x            \n");
    printf("%*c", deslocS, ' '); printf("     xx  xx           xxxxxxxx                      x            \n");
    printf("%*c", deslocS, ' '); printf("      x    xx                xxx                    x            \n");
    printf("%*c", deslocS, ' '); printf("        x    x   xxxxxxxxxxxx                      xx            \n");
    printf("%*c", deslocS, ' '); printf("         x  xxxxxx                             xxx               \n");
    printf("%*c", deslocS, ' '); printf("         xxxx            xxxx                 xx                 \n");
    printf("%*c", deslocS, ' '); printf("         xx         xxxxxx   x                x                  \n");
    printf("%*c", deslocS, ' '); printf("        xx      xxxx xx       x               x                  \n");
    printf("%*c", deslocS, ' '); printf("        x     xxxx    xx      xx             xx                  \n");
    printf("%*c", deslocS, ' '); printf("       xx   xxx  xxx   x       xxxxxxxxxxxxxxx                   \n");
    printf("%*c", deslocS, ' '); printf("       x   xx      xx  xx        x         xx                    \n");
    printf("%*c", deslocS, ' '); printf("      xx   x        x   x        x           xx                  \n");
    printf("%*c", deslocS, ' '); printf("      x    xx       x  xx        x            x                  \n");
    printf("%*c", deslocS, ' '); printf("      xx    xxxxxxxx   x         x            x                  \n");
    printf("%*c", deslocS, ' '); printf("       xxx            xx         x            xx                 \n");
    printf("%*c", deslocS, ' '); printf("         xxxx      xxxx        xxxxx         xxxxx               \n");
    printf("%*c", deslocS, ' '); printf("            xxxxxxxx           x x x         x x x           \n");
    break;
    //pato do clube[3]
    case 3:
    pnome(&poke, ehinimigo, deslocN);
    printf("%*c", deslocN, ' '); printf("                              *((((                               "); pnome(&poke, ehinimigo+1, deslocN); endl(); ptipo(&poke, ehinimigo, deslocT);
    printf("%*c", deslocT, ' '); printf("                 ((((   *(((((((((                                "); ptipo(&poke, ehinimigo+1, deslocT); endl(); pvida(&poke, ehinimigo, deslocV);
    printf("%*c", deslocV, ' '); printf("                ((( (((((      (((                                "); pvida(&poke, ehinimigo+1, deslocV); endl();
    printf("%*c", deslocS, ' '); printf("                ((              (((                               \n");
    printf("%*c", deslocS, ' '); printf("              (((                (((                              \n");
    printf("%*c", deslocS, ' '); printf("             ((                   (((                             \n");
    printf("%*c", deslocS, ' '); printf("            (((       (*    (*     (((                            \n");
    printf("%*c", deslocS, ' '); printf("            ((                     ((((((((((((((((((((((((((((   \n");
    printf("%*c", deslocS, ' '); printf("             (                  ((((                       (((((((\n");
    printf("%*c", deslocS, ' '); printf("              ((      ((((((((((         ((((((((((((((       ((((\n");
    printf("%*c", deslocS, ' '); printf("               ((  ((((                (((((((((((((   (((((((((  \n");
    printf("%*c", deslocS, ' '); printf("               ((((((((((((((((((((((((  (((                      \n");
    printf("%*c", deslocS, ' '); printf("            ((((((                      (((                       \n");
    printf("%*c", deslocS, ' '); printf("(((((((((((((((((                       (((                       \n");
    printf("%*c", deslocS, ' '); printf(" ###            (((                     (((                       \n");
    printf("%*c", deslocS, ' '); printf("  ###             (((                   ((                        \n");
    printf("%*c", deslocS, ' '); printf("   ####            (((                ####                        \n");
    printf("%*c", deslocS, ' '); printf("    ####          (((                ###                          \n");
    printf("%*c", deslocS, ' '); printf("     ####        (((               ####                           \n");
    printf("%*c", deslocS, ' '); printf("       #####    (((             #####                             \n");
    printf("%*c", deslocS, ' '); printf("         #########################                                \n");
    printf("%*c", deslocS, ' '); printf("                #            #                                    \n");
    printf("%*c", deslocS, ' '); printf("               ###           ### ##                               \n");
    printf("%*c", deslocS, ' '); printf("              # # #           #####                \n");
    break;
    //flamingoC[4]
    case 4:
    pnome(&poke, ehinimigo, deslocN);
    printf("%*c", deslocN, ' '); printf("     XXXXXX                  "); pnome(&poke, ehinimigo+1, deslocN); endl(); ptipo(&poke, ehinimigo, deslocT);
    printf("%*c", deslocT, ' '); printf("   XXX     X                  "); ptipo(&poke, ehinimigo+1, deslocT); endl(); pvida(&poke, ehinimigo, deslocV);
    printf("%*c", deslocV, ' '); printf("  XX    O   X                  "); pvida(&poke, ehinimigo+1, deslocV); endl();
    printf("%*c", deslocS, ' '); printf(" XXXXX     X                  \n");
    printf("%*c", deslocS, ' '); printf(" XX   XX XXX                  \n");
    printf("%*c", deslocS, ' '); printf("         XXX             X    \n");
    printf("%*c", deslocS, ' '); printf("         XXX X     XX X  X    \n");
    printf("%*c", deslocS, ' '); printf("        XX  X X  XX     XX    \n");
    printf("%*c", deslocS, ' '); printf("       XX               X     \n");
    printf("%*c", deslocS, ' '); printf("        X              X      \n");
    printf("%*c", deslocS, ' '); printf("         X           XXX      \n");
    printf("%*c", deslocS, ' '); printf("         XX X   X XXXXX       \n");
    printf("%*c", deslocS, ' '); printf("            X XXX X           \n");
    printf("%*c", deslocS, ' '); printf("               XXX            \n");
    printf("%*c", deslocS, ' '); printf("             XXX    XX        \n");
    printf("%*c", deslocS, ' '); printf("             XXXXXXXXX        \n");
    printf("%*c", deslocS, ' '); printf("               X    X        \n");
    printf("%*c", deslocS, ' '); printf("               X              \n");
    printf("%*c", deslocS, ' '); printf("              X               \n");
    printf("%*c", deslocS, ' '); printf("           XX X      \n");
    break;
    //galoGuerreiro[5]
    case 5:
    pnome(&poke, ehinimigo, deslocN);
    printf("%*c", deslocN, ' '); printf("           XXXXXX                       "); pnome(&poke, ehinimigo+1, deslocN); endl(); ptipo(&poke, ehinimigo, deslocT);
    printf("%*c", deslocT, ' '); printf("           XX   X                       "); ptipo(&poke, ehinimigo+1, deslocT); endl(); pvida(&poke, ehinimigo, deslocV);
    printf("%*c", deslocV, ' '); printf("         XXXXXX XXX                     "); pvida(&poke, ehinimigo+1, deslocV); endl();
    printf("%*c", deslocS, ' '); printf("        XX   XXX   XX           X       \n");
    printf("%*c", deslocS, ' '); printf("        XXXXX X    _XXX         X       \n");
    printf("%*c", deslocS, ' '); printf("              X    @ XXX       XX       \n");
    printf("%*c", deslocS, ' '); printf("              X     XXX >      XX       \n");
    printf("%*c", deslocS, ' '); printf("              X      X        XXX       \n");
    printf("%*c", deslocS, ' '); printf("          XX XX     XXXXX     XXX       \n");
    printf("%*c", deslocS, ' '); printf("        XXX              X    XXX       \n");
    printf("%*c", deslocS, ' '); printf("       X                 X    XXX       \n");
    printf("%*c", deslocS, ' '); printf("       XX                 X   XXX       \n");
    printf("%*c", deslocS, ' '); printf("       XX     X              XXXXXXX    \n");
    printf("%*c", deslocS, ' '); printf("       XX    X   XXXXX X X   X XXX      \n");
    printf("%*c", deslocS, ' '); printf("        X    X XXXX  XXX XX      X      \n");
    printf("%*c", deslocS, ' '); printf("       X     X  XX    X   X   XXXXX     \n");
    printf("%*c", deslocS, ' '); printf("       X        XX    X  XX             \n");
    printf("%*c", deslocS, ' '); printf("       X X XXXXXXXX   X                 \n");
    printf("%*c", deslocS, ' '); printf("            X    XXXX                   \n");
    printf("%*c", deslocS, ' '); printf("            X       X                   \n");
    printf("%*c", deslocS, ' '); printf("            X       X                   \n");
    printf("%*c", deslocS, ' '); printf("            XXXXX   XXXXX               \n");
    printf("%*c", deslocS, ' '); printf("              X      XX                 \n");
    printf("%*c", deslocS, ' '); printf("               X       X       \n");
    break;
    //galinhaPintadinha[6]
    case 6:
    pnome(&poke, ehinimigo, deslocN);
    printf("%*c", deslocN, ' '); printf("                 XXX                   "); pnome(&poke, ehinimigo+1, deslocN); endl(); ptipo(&poke, ehinimigo, deslocT);
    printf("%*c", deslocT, ' '); printf("                XX  X   XXXXX           "); ptipo(&poke, ehinimigo+1, deslocT); endl(); pvida(&poke, ehinimigo, deslocV);
    printf("%*c", deslocV, ' '); printf("                X  X XXXX   X           "); pvida(&poke, ehinimigo+1, deslocV); endl();
    printf("%*c", deslocS, ' '); printf("          XXXXX X XXX     XXX           \n");
    printf("%*c", deslocS, ' '); printf("          X   XXXXXX     XXX XX         \n");
    printf("%*c", deslocS, ' '); printf("            XXXXX  XXXXX X    X         \n");
    printf("%*c", deslocS, ' '); printf("          XXX          XXXXXXXX         \n");
    printf("%*c", deslocS, ' '); printf("         XX              XX             \n");
    printf("%*c", deslocS, ' '); printf("         X                XX            \n");
    printf("%*c", deslocS, ' '); printf("        XX                 XX           \n");
    printf("%*c", deslocS, ' '); printf("        X  @ XX   @         X           \n");
    printf("%*c", deslocS, ' '); printf("       XX XXXXX             X           \n");
    printf("%*c", deslocS, ' '); printf("      XX   XX X             XX          \n");
    printf("%*c", deslocS, ' '); printf("     X XX    X XX       X    X   XXXX   \n");
    printf("%*c", deslocS, ' '); printf("    XX  X    XXX        X    XXXXXX XX  \n");
    printf("%*c", deslocS, ' '); printf("    X   X          \\   XX   XX  XXXXX  \n");
    printf("%*c", deslocS, ' '); printf("     XXXXX          |    XXXXX X XXXX   \n");
    printf("%*c", deslocS, ' '); printf("         X          |       X     XXXX  \n");
    printf("%*c", deslocS, ' '); printf("         XX         |       X X XXX     \n");
    printf("%*c", deslocS, ' '); printf("       XXXXXXX   XXXXXX                \n");
    break;
    //ticoliro[7]
    case 7:
    pnome(&poke, ehinimigo, deslocN);
    printf("%*c", deslocN, ' '); printf("                    xxx                "); pnome(&poke, ehinimigo+1, deslocN); endl(); ptipo(&poke, ehinimigo, deslocT);
    printf("%*c", deslocT, ' '); printf("               xxxx  xxxxxxx           "); ptipo(&poke, ehinimigo+1, deslocT); endl(); pvida(&poke, ehinimigo, deslocV);
    printf("%*c", deslocS, ' '); printf("       xxxx   xxxxx   xxxx   x         "); pvida(&poke, ehinimigo+1, deslocV); endl();
    printf("%*c", deslocV, ' '); printf("          xxxx  xx xxxx xxxxxx         \n"); 
    printf("%*c", deslocS, ' '); printf("      xxxxxxxxxx xxx  xx     x         \n");
    printf("%*c", deslocS, ' '); printf("    xxxx       xx           x          \n");
    printf("%*c", deslocS, ' '); printf("              xxxxxxxxxx  xx           \n");
    printf("%*c", deslocS, ' '); printf("             xx        xx x            \n");
    printf("%*c", deslocS, ' '); printf("            xx           x             \n");
    printf("%*c", deslocS, ' '); printf("           xx)))))   )))) xx           \n");
    printf("%*c", deslocS, ' '); printf("          xx))   )) ))   ))xx          \n");
    printf("%*c", deslocS, ' '); printf("          x  ) @  )))) @ )  x          \n");
    printf("%*c", deslocS, ' '); printf("         xx   )))))  )))))  xx         \n");
    printf("%*c", deslocS, ' '); printf("         x                   x         \n");
    printf("%*c", deslocS, ' '); printf("         xx        v         x         \n");
    printf("%*c", deslocS, ' '); printf("           xx               xx         \n");
    printf("%*c", deslocS, ' '); printf("            xxxx           xx          \n");
    printf("%*c", deslocS, ' '); printf("               xxxxxx   xxxx           \n");
    printf("%*c", deslocS, ' '); printf("                     xxxx          \n");
    break;
    //dodo[8]
    case 8:
    pnome(&poke, ehinimigo, deslocN);
    printf("%*c", deslocN, ' '); printf("                       xxxxxxxxxxx                                                  "); pnome(&poke, ehinimigo+1, deslocN); endl(); ptipo(&poke, ehinimigo, deslocT);
    printf("%*c", deslocT, ' '); printf("                      xx         xx                                                 "); ptipo(&poke, ehinimigo+1, deslocT); endl(); pvida(&poke, ehinimigo, deslocV);
    printf("%*c", deslocV, ' '); printf("                     xx           xx                                                "); pvida(&poke, ehinimigo+1, deslocV); endl();
    printf("%*c", deslocS, ' '); printf("                   xx   xxxx       x                                                \n");
    printf("%*c", deslocS, ' '); printf("                 xxx   xx          x                                                \n");
    printf("%*c", deslocS, ' '); printf("              xxxx                xx                                                \n");
    printf("%*c", deslocS, ' '); printf("         xxxxxxx                  x       xxxxxxxxx                                 \n");
    printf("%*c", deslocS, ' '); printf("       xxxxxxxxx                 xx xxxxxxx       xxxxxxxx                          \n");
    printf("%*c", deslocS, ' '); printf("      xxxxxxxxxxxxxxxxxxx       xxxxx                    xxxxxx                     \n");
    printf("%*c", deslocS, ' '); printf("      xxxxxxxxxx        x       xx                            xxxx      xxxxx       \n");
    printf("%*c", deslocS, ' '); printf("      xxxxxxxx          xx    xxx                                xxxx  xx   xx      \n");
    printf("%*c", deslocS, ' '); printf("      xxxxxx             x   xx               xxx                   xxx      xx     \n");
    printf("%*c", deslocS, ' '); printf("      xxxxxx              x xx                   xxx                 xx xxx   xx    \n");
    printf("%*c", deslocS, ' '); printf("      xxxxx               xxx               xx     xxx               xxxx xx  x     \n");
    printf("%*c", deslocS, ' '); printf("                           xx                 xx     xx              x  xxxx  xx    \n");
    printf("%*c", deslocS, ' '); printf("                           x                   xxx    x              x  x xxx  x    \n");
    printf("%*c", deslocS, ' '); printf("                           x                     xxx  x              x  xxx xx x    \n");
    printf("%*c", deslocS, ' '); printf("                         xxx                       xxxx              x  x x  xxxx   \n");
    printf("%*c", deslocS, ' '); printf("                           xxxxx                                     x  xx x        \n");
    printf("%*c", deslocS, ' '); printf("                               xxxxxx                               x     xxxx      \n");
    printf("%*c", deslocS, ' '); printf("                                    xxxxxx                        xxx        x      \n");
    printf("%*c", deslocS, ' '); printf("                                          xxxxxx   x            xxx                 \n");
    printf("%*c", deslocS, ' '); printf("                                             x  xxxxxxxxxxxxxxxxx                   \n");
    printf("%*c", deslocS, ' '); printf("                                             x    x                                 \n");
    printf("%*c", deslocS, ' '); printf("                                             x    x                                 \n");
    printf("%*c", deslocS, ' '); printf("                                             x    x                                 \n");
    printf("%*c", deslocS, ' '); printf("                                     xxx    xx    x                                 \n");
    printf("%*c", deslocS, ' '); printf("                                       xxxxxx     x                                 \n");
    printf("%*c", deslocS, ' '); printf("                                    xxxxxxxx xxxxxx    \n");                              
    break;
    //rolinha [9]
    case 9:
    pnome(&poke, ehinimigo, deslocN);
    printf("%*c", deslocN, ' '); printf("          xxxxxxxxx                                                  "); pnome(&poke, ehinimigo+1, deslocN); endl(); ptipo(&poke, ehinimigo, deslocT);
    printf("%*c", deslocT, ' '); printf("         xx    xxxxx                                                 "); ptipo(&poke, ehinimigo+1, deslocT); endl(); pvida(&poke, ehinimigo, deslocV);
    printf("%*c", deslocV, ' '); printf("        xx         xxx   xxxxxxxxxxxxxx                              "); pvida(&poke, ehinimigo+1, deslocV); endl();
    printf("%*c", deslocS, ' '); printf("        x            xx xx            xxxxx                          \n");
    printf("%*c", deslocS, ' '); printf("       xx             xxx                  xx                        \n");
    printf("%*c", deslocS, ' '); printf("   xxxxx            xxx    zzzzzz            xxx                     \n");
    printf("%*c", deslocS, ' '); printf("  xxxxxxxxxxx     xx            zzzzz          xxx                   \n");
    printf("%*c", deslocS, ' '); printf("            x    x                  zzzz         xxx                 \n");
    printf("%*c", deslocS, ' '); printf("            xxxxx                      zzz       xxxx                \n");
    printf("%*c", deslocS, ' '); printf("               xx                        zz       x xx               \n");
    printf("%*c", deslocS, ' '); printf("               xx           zzzz zzzzzz   z       x  xx              \n");
    printf("%*c", deslocS, ' '); printf("                xx                    zzzzzz     xx   xx             \n");
    printf("%*c", deslocS, ' '); printf("                 xx                             xx     xx            \n");
    printf("%*c", deslocS, ' '); printf("                  xx                           xx       xx           \n");
    printf("%*c", deslocS, ' '); printf("                    xxx                      xxx         xxx         \n");
    printf("%*c", deslocS, ' '); printf("                       xxxxxx            xxxx xxxxx        xx        \n");
    printf("%*c", deslocS, ' '); printf("                         xx  xxxxxxxxxxxxx        xxxxxx    xxxx     \n");
    printf("%*c", deslocS, ' '); printf("                    xxxxxx   x                         xxxxxx  xxx   \n");
    printf("%*c", deslocS, ' '); printf("                         xxxxx                              xxxxxx   \n");
    break;
    //joao[10]
    case 10:
    pnome(&poke, ehinimigo, deslocN);
    printf("%*c", deslocN, ' '); printf("                                         "); pnome(&poke, ehinimigo+1, deslocN); endl(); ptipo(&poke, ehinimigo, deslocT);
    printf("%*c", deslocT, ' '); printf("                             x           "); ptipo(&poke, ehinimigo+1, deslocT); endl(); pvida(&poke, ehinimigo, deslocV);
    printf("%*c", deslocS, ' '); printf("                  xx      xxx   xx   x   "); pvida(&poke, ehinimigo+1, deslocV); endl();
    printf("%*c", deslocV, ' '); printf("                   xxxxxxxx xxxxxxxxxx   \n"); 
    printf("%*c", deslocS, ' '); printf("                            x  xx        \n");
    printf("%*c", deslocS, ' '); printf("                          xxxxxxxxx      \n");
    printf("%*c", deslocS, ' '); printf("                       xxx        xx     \n");
    printf("%*c", deslocS, ' '); printf("        x     xx     xxx           xx    \n");
    printf("%*c", deslocS, ' '); printf("       xxx   xxxx    x      T   T   x    \n");
    printf("%*c", deslocS, ' '); printf("       x xx xx xx    xx             x    \n");
    printf("%*c", deslocS, ' '); printf("       x  xxx  x      x             x    \n");
    printf("%*c", deslocS, ' '); printf("       x  xx  xx      xx    xxxx   xxx   \n");
    printf("%*c", deslocS, ' '); printf("  xxxxxx  x  xx       xxxx   xx   xx x   \n");
    printf("%*c", deslocS, ' '); printf("  x   xx xx xx         x x       xx xx   \n");
    printf("%*c", deslocS, ' '); printf("  x    xxx  x          x  xxxxxxxx  x    \n");
    printf("%*c", deslocS, ' '); printf("  xx    x   x         xx    xxx     xx   \n");
    printf("%*c", deslocS, ' '); printf("   xx       xxx            xx xx     x   \n");
    printf("%*c", deslocS, ' '); printf("    xx        xxxx         x    x        \n");
    printf("%*c", deslocS, ' '); printf("     xx           xxxx    xx    xx       \n");
    printf("%*c", deslocS, ' '); printf("      xx             xxx xx       xx     \n");
    printf("%*c", deslocS, ' '); printf("       xx            xxxx          x     \n");
    printf("%*c", deslocS, ' '); printf("        xxx       xxxx  x          x     \n");
    printf("%*c", deslocS, ' '); printf("          xx   xxxx     x          x     \n");
    printf("%*c", deslocS, ' '); printf("           xxxxx       xx          x     \n");
    printf("%*c", deslocS, ' '); printf("                                    \n");
    break;
    //canarinhoS[11]
    case 11:
    pnome(&poke, ehinimigo, deslocN);
    printf("%*c", deslocN, ' '); printf("     xxxxxxxx                                "); pnome(&poke, ehinimigo+1, deslocN); endl(); ptipo(&poke, ehinimigo, deslocT);
    printf("%*c", deslocT, ' '); printf("  xxxx      xxxx                             "); ptipo(&poke, ehinimigo+1, deslocT); endl(); pvida(&poke, ehinimigo, deslocV);
    printf("%*c", deslocV, ' '); printf("  x   x      x  xx                           \n"); pvida(&poke, ehinimigo+1, deslocV); endl();
    printf("%*c", deslocS, ' '); printf(" x   x x    x x   x                          \n");
    printf("%*c", deslocS, ' '); printf(" x  x @ x  x @ x  xx                         \n");
    printf("%*c", deslocS, ' '); printf(" x                 x                         \n");
    printf("%*c", deslocS, ' '); printf(" x       xxx       x     xxxxxxx             \n");
    printf("%*c", deslocS, ' '); printf(" x    xxxxxxxx     x     xx    xxx           \n");
    printf("%*c", deslocS, ' '); printf(" xx      xxx       x      xxx    xx          \n");
    printf("%*c", deslocS, ' '); printf("  x       x       xx        xx     xx        \n");
    printf("%*c", deslocS, ' '); printf("  xx             xx         xxx     xx       \n");
    printf("%*c", deslocS, ' '); printf("   xx          xxx            xx     xxx     \n");
    printf("%*c", deslocS, ' '); printf("    xxxxxxxxxxxx          xxx xxxx     xx    \n");
    printf("%*c", deslocS, ' '); printf("      x      xx          xx      xx     xx   \n");
    printf("%*c", deslocS, ' '); printf("      x       x       xxx         xx     xx  \n");
    printf("%*c", deslocS, ' '); printf("      x       xxx  xxxx         xxxxx     xx \n");
    printf("%*c", deslocS, ' '); printf("     xx          xxx         xxx    xxxx  xx \n");
    printf("%*c", deslocS, ' '); printf("     x       xxxx      xxxxxx          xxxx  \n");
    printf("%*c", deslocS, ' '); printf("       xxxxxx  xxxxxxxx\n");
    break;
    //Corvo emo gotico[12]
    case 12:
    pnome(&poke, ehinimigo, deslocN);
    printf("%*c", deslocN, ' '); printf("              XXXXXXXX XXXX               "); pnome(&poke, ehinimigo+1, deslocN); endl(); ptipo(&poke, ehinimigo, deslocT);
    printf("%*c", deslocT, ' '); printf("                 XXX@@@@@@@@XXX            "); ptipo(&poke, ehinimigo+1, deslocT); endl(); pvida(&poke, ehinimigo, deslocV);
    printf("%*c", deslocV, ' '); printf("                  X@@@@@@@X_   XXX         "); pvida(&poke, ehinimigo+1, deslocV); endl();
    printf("%*c", deslocS, ' '); printf("                  X@X@@@@XX0\\     X        \n");
    printf("%*c", deslocS, ' '); printf("                 XXX@@XXXX    XXXXXX       \n");
    printf("%*c", deslocS, ' '); printf("       XXXXXXXX     XX X      XX           \n");
    printf("%*c", deslocS, ' '); printf("         XXXXXXXXXX   XX     X             \n");
    printf("%*c", deslocS, ' '); printf("          XXX     XXXXX       X            \n");
    printf("%*c", deslocS, ' '); printf("            XX                X            \n");
    printf("%*c", deslocS, ' '); printf("             X XX             XX           \n");
    printf("%*c", deslocS, ' '); printf("             XXXXXX            X           \n");
    printf("%*c", deslocS, ' '); printf("              XXX XXXXX       XX           \n");
    printf("%*c", deslocS, ' '); printf("                XXX X   XX   X             \n");
    printf("%*c", deslocS, ' '); printf("                   XXXXXXXXXX              \n");
    printf("%*c", deslocS, ' '); printf("                    XX   X                 \n");
    printf("%*c", deslocS, ' '); printf("                     X   XX                \n");
    printf("%*c", deslocS, ' '); printf("                    X    X                 \n");
    printf("%*c", deslocS, ' '); printf("                   XXX  XXX           \n");
    break;
    //papaLeguas[13]
    case 13:
    pnome(&poke, ehinimigo, deslocN);
    printf("%*c", deslocN, ' '); printf("                                             X                          "); pnome(&poke, ehinimigo+1, deslocN); endl(); ptipo(&poke, ehinimigo, deslocT);
    printf("%*c", deslocT, ' '); printf("                                              XXXXXXXX                  "); ptipo(&poke, ehinimigo+1, deslocT); endl(); pvida(&poke, ehinimigo, deslocV);
    printf("%*c", deslocV, ' '); printf("                                                 XX  XXXX               "); pvida(&poke, ehinimigo+1, deslocV); endl();
    printf("%*c", deslocS, ' '); printf("                                                  XXX    X              \n");
    printf("%*c", deslocS, ' '); printf("                                              XXXXXXX X XXXX X          \n");
    printf("%*c", deslocS, ' '); printf("                                                 X XXXX      XXX        \n");
    printf("%*c", deslocS, ' '); printf("        XXXXXX                                  XXXX         @ XXX      \n");
    printf("%*c", deslocS, ' '); printf("          X X XX                       XXXXXXX X                XXXXXXXX  \n");
    printf("%*c", deslocS, ' '); printf("            XX XXX X            XXXXXXXX           X XXXX X XXXXXX      \n");
    printf("%*c", deslocS, ' '); printf("     XXXXXXXXXXX     XXXXXXX XXXXX         XX   XX                      \n");
    printf("%*c", deslocS, ' '); printf("          XXXXXXXXXX    XX        XXXXX XXX     X                       \n");
    printf("%*c", deslocS, ' '); printf("                   XXXXXXX           X        XX                        \n");
    printf("%*c", deslocS, ' '); printf("                           XXXXXXXXXXXXXXX  XX                          \n");
    printf("%*c", deslocS, ' '); printf("                          XX            XXXX                            \n");
    printf("%*c", deslocS, ' '); printf("                        XX                 X                            \n");
    printf("%*c", deslocS, ' '); printf("                        X                 XX                            \n");
    printf("%*c", deslocS, ' '); printf("                         XX           XXXXX                             \n");
    printf("%*c", deslocS, ' '); printf("                          XXXXXXXXXXXXX            \n");
    break;
    //picaPau[14]
    case 14:
    pnome(&poke, ehinimigo, deslocN);
    printf("%*c", deslocN, ' '); printf("        xxx                     "); pnome(&poke, ehinimigo+1, deslocN); endl(); ptipo(&poke, ehinimigo, deslocT);
    printf("%*c", deslocT, ' '); printf("        xxxxxxxx                "); ptipo(&poke, ehinimigo+1, deslocT); endl(); pvida(&poke, ehinimigo, deslocV);
    printf("%*c", deslocV, ' '); printf("           xxx  xxx   xxx       "); pvida(&poke, ehinimigo+1, deslocV); endl();
    printf("%*c", deslocS, ' '); printf("  xxxxxxxxx  xxx   xxx x xx     \n");
    printf("%*c", deslocS, ' '); printf("    xxxx  xxxx xx    xxxx xx    \n");
    printf("%*c", deslocS, ' '); printf("       xxxx   xxx      xx   x   \n");
    printf("%*c", deslocS, ' '); printf("          xxx   xx           x  \n");
    printf("%*c", deslocS, ' '); printf("            xxx              xx \n");
    printf("%*c", deslocS, ' '); printf("              xx              x \n");
    printf("%*c", deslocS, ' '); printf("               x  @@   @@     x \n");
    printf("%*c", deslocS, ' '); printf("               x  @@   @@    xx \n");
    printf("%*c", deslocS, ' '); printf("    xxx       xx             x  \n");
    printf("%*c", deslocS, ' '); printf("     xxxxxx   xx           xxx  \n");
    printf("%*c", deslocS, ' '); printf("      xx  xxxxx          xxx    \n");
    printf("%*c", deslocS, ' '); printf("       xxx     xx       xx      \n");
    printf("%*c", deslocS, ' '); printf("         xxxxxxxx      xx       \n");
    printf("%*c", deslocS, ' '); printf("               xx    xxx        \n");
    printf("%*c", deslocS, ' '); printf("               TxTTTxx          \n");
    printf("%*c", deslocS, ' '); printf("             TTTx   xTTT        \n");
    printf("%*c", deslocS, ' '); printf("           TTTTTTTTTTTTTTT      \n");
    break;
    //recruta[15]
    case 15:
    pnome(&poke, ehinimigo, deslocN);
    printf("%*c", deslocN, ' '); printf("          xxxxxxxxxxxx          "); pnome(&poke, ehinimigo+1, deslocN); endl(); ptipo(&poke, ehinimigo, deslocT);
    printf("%*c", deslocT, ' '); printf("         xx xxxxxxxxxxx         "); ptipo(&poke, ehinimigo+1, deslocT); endl(); pvida(&poke, ehinimigo, deslocV);
    printf("%*c", deslocV, ' '); printf("        xx    xxxxx    x        "); pvida(&poke, ehinimigo+1, deslocV); endl();
    printf("%*c", deslocS, ' '); printf("        x              xx   xx  \n");
    printf("%*c", deslocS, ' '); printf("        x   @@    @@    x   xx  \n");
    printf("%*c", deslocS, ' '); printf("        xx  @@    @@    x   xx  \n");
    printf("%*c", deslocS, ' '); printf("       xxx              xx xxx  \n");
    printf("%*c", deslocS, ' '); printf("      xx x     xxxx      xxxxx  \n");
    printf("%*c", deslocS, ' '); printf("    xx   x      xx       x xx   \n");
    printf("%*c", deslocS, ' '); printf("   xx xxxx               xxx    \n");
    printf("%*c", deslocS, ' '); printf("  xx xx  x               xx     \n");
    printf("%*c", deslocS, ' '); printf("  xxx    x               x      \n");
    printf("%*c", deslocS, ' '); printf("         x               x      \n");
    printf("%*c", deslocS, ' '); printf("         xx              x      \n");
    printf("%*c", deslocS, ' '); printf("         xxxx           xx      \n");
    printf("%*c", deslocS, ' '); printf("       xxxxxxxxxxxxxxxxxxxx     \n");
    printf("%*c", deslocS, ' '); printf("      xxxxxxx      xxxxxxx     \n");
    break;
    //kiwi[16]
    case 16:
    pnome(&poke, ehinimigo, deslocN);
    printf("%*c", deslocN, ' '); printf("                               xxxxxxx             "); pnome(&poke, ehinimigo+1, deslocN); endl(); ptipo(&poke, ehinimigo, deslocT);
    printf("%*c", deslocT, ' '); printf("                         xxxxxx      xxxx          "); ptipo(&poke, ehinimigo+1, deslocT); endl(); pvida(&poke, ehinimigo, deslocV);
    printf("%*c", deslocV, ' '); printf("                      xxxx               xxx       "); pvida(&poke, ehinimigo+1, deslocV); endl();
    printf("%*c", deslocS, ' '); printf("                   xxx                     xx      \n");
    printf("%*c", deslocS, ' '); printf("          xxxxxxxxx                         xx     \n");
    printf("%*c", deslocS, ' '); printf("        xxx   xxxx                           xx    \n");
    printf("%*c", deslocS, ' '); printf("        x  x   xx                             x    \n");
    printf("%*c", deslocS, ' '); printf("        x      xx                             x    \n");
    printf("%*c", deslocS, ' '); printf("       xxxxxxxxxxx                            x    \n");
    printf("%*c", deslocS, ' '); printf("      xx xx      xx                           x    \n");
    printf("%*c", deslocS, ' '); printf("     xx  x        xx                          x    \n");
    printf("%*c", deslocS, ' '); printf("    xx  xx         xx                       xxx    \n");
    printf("%*c", deslocS, ' '); printf("   xx xxx            xx                    xx      \n");
    printf("%*c", deslocS, ' '); printf("  xx xx               xxx                 xx       \n");
    printf("%*c", deslocS, ' '); printf(" xxxxx                   xxx            xxx        \n");
    printf("%*c", deslocS, ' '); printf("  xx                    xx  xxxxxxxxxxxxx          \n");
    printf("%*c", deslocS, ' '); printf("                       xx        x                 \n");
    printf("%*c", deslocS, ' '); printf("                    xxxx      xxx       \n"); 
    break;
    default: break;
    }
}
#endif