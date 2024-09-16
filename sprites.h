#ifndef SPRITES_H
#define SPRITES_H
#include <stdio.h>
#include "pokemon.h"

//esta biblioteca serve para guardar as imagens dos passaros


void printarPokemon(tp_pokemon poke){

int num = poke.num;

printf("\n");

switch(num){

    
    //pikapombo[1]
    case 1:
    printf("        xxxxxxxxx                                \n");
    printf("       xx        xx                              \n");
    printf("      x           xx                             \n");
    printf("     xx   $   $    x                             \n");
    printf("     x             xx               xxxxxxxxxxxxx\n");
    printf("    xxxxxxxx  xxx   xx               x       xxx \n");
    printf("  xxx    xxxxxxxxxxxxxxxx            x    xxxx   \n");
    printf(" xxxxxxxxx   xxx         xxx      xxxxx    xx    \n");
    printf("            xx       xxxx   x      x       xxx   \n");
    printf("            x      xxxxxxx   xx xxxx   xxxxx     \n");
    printf("            x       xxxxx     xxxxx     xx       \n");
    printf("            xx     xxxxx       xx        xx      \n");
    printf("             x       xxx        xx    xxxxxx     \n");
    printf("             xx       xxx        xxxx            \n");
    printf("              xx               x x               \n");
    printf("               xx                x               \n");
    printf("                 xxx          xxx                \n");
    printf("                    xxxx  xxxx  xx               \n");
    printf("                     xx xx xx                    \n");
    printf("                    xxxx  xxxx               \n");
    break;

    //cocatriz[2]
    case 2:
    printf("xxxxxxxxx                             xxxxxxxx  x  x x x         \n");
    printf("   xx   xxxxxxx                   xxxxx   x    x  x x x          \n");
    printf("    xx         xxxx             xxx      xx   xxxxxxxxxx         \n");
    printf("     xx            xxx         xx       xx   xx        xx        \n");
    printf("      xx          |  xxxx     xx        x   xx      @   xxx      \n");
    printf("       x         |  |   xxx   x         x   x             xxxxxx \n");
    printf("       xx       |  |   |  xxxx          xxxx                   xx\n");
    printf("        xxxxxxx|  |   |  |   xxx xxxxxxxxx            xxxxxxxxx  \n");
    printf("    xxx       xxx|   |  |      xxx                  xx           \n");
    printf("    x  xx       xxxxxxx|                            x            \n");
    printf("     xx  xx           xxxxxxxx                      x            \n");
    printf("      x    xx                xxx                    x            \n");
    printf("        x    x   xxxxxxxxxxxx                      xx            \n");
    printf("         x  xxxxxx                             xxx               \n");
    printf("         xxxx            xxxx                 xx                 \n");
    printf("         xx         xxxxxx   x                x                  \n");
    printf("        xx      xxxx xx       x               x                  \n");
    printf("        x     xxxx    xx      xx             xx                  \n");
    printf("       xx   xxx  xxx   x       xxxxxxxxxxxxxxx                   \n");
    printf("       x   xx      xx  xx        x         xx                    \n");
    printf("      xx   x        x   x        x           xx                  \n");
    printf("      x    xx       x  xx        x            x                  \n");
    printf("      xx    xxxxxxxx   x         x            x                  \n");
    printf("       xxx            xx         x            xx                 \n");
    printf("         xxxx      xxxx        xxxxx         xxxxx               \n");
    printf("            xxxxxxxx           x x x         x x x           \n");
    break;
    //pato do clube[3]
    case 3:
    printf("                              *((((                               \n");
    printf("                 ((((   *(((((((((                                \n");
    printf("                ((( (((((      (((                                \n");
    printf("                ((              (((                               \n");
    printf("              (((                (((                              \n");
    printf("             ((                   (((                             \n");
    printf("            (((       (*    (*     (((                            \n");
    printf("            ((                     ((((((((((((((((((((((((((((   \n");
    printf("             (                  ((((                       (((((((\n");
    printf("              ((      ((((((((((         ((((((((((((((       ((((\n");
    printf("               ((  ((((                (((((((((((((   (((((((((  \n");
    printf("               ((((((((((((((((((((((((  (((                      \n");
    printf("            ((((((                      (((                       \n");
    printf("(((((((((((((((((                       (((                       \n");
    printf(" ###            (((                     (((                       \n");
    printf("  ###             (((                   ((                        \n");
    printf("   ####            (((                ####                        \n");
    printf("    ####          (((                ###                          \n");
    printf("     ####        (((               ####                           \n");
    printf("       #####    (((             #####                             \n");
    printf("         #########################                                \n");
    printf("                #            #                                    \n");
    printf("               ###           ### ##                               \n");
    printf("              # # #           #####                \n");
    break;
    //flamingoC[4]
    case 4:
    printf("     XXXXXX                  \n");
    printf("   XXX     X                  \n");
    printf("  XX    O   X                  \n");
    printf(" XXXXX     X                  \n");
    printf(" XX   XX XXX                  \n");
    printf("         XXX             X    \n");
    printf("         XXX X     XX X  X    \n");
    printf("        XX  X X  XX     XX    \n");
    printf("       XX               X     \n");
    printf("        X              X      \n");
    printf("         X           XXX      \n");
    printf("         XX X   X XXXXX       \n");
    printf("            X XXX X           \n");
    printf("               XXX            \n");
    printf("             XXX    XX        \n");
    printf("             XXXXXXXXX        \n");
    printf("               X    X        \n");
    printf("               X              \n");
    printf("              X               \n");
    printf("           XX X      \n");
    break;
    //galoGuerreiro[5]
    case 5:
    printf("           XXXXXX                       \n");
    printf("           XX   X                       \n");
    printf("         XXXXXX XXX                     \n");
    printf("        XX   XXX   XX           X       \n");
    printf("        XXXXX X    _XXX         X       \n");
    printf("              X    @ XXX       XX       \n");
    printf("              X     XXX ►      XX       \n");
    printf("              X      X        XXX       \n");
    printf("          XX XX     XXXXX     XXX       \n");
    printf("        XXX              X    XXX       \n");
    printf("       X                 X    XXX       \n");
    printf("       XX                 X   XXX       \n");
    printf("       XX     X              XXXXXXX    \n");
    printf("       XX    X   XXXXX X X   X XXX      \n");
    printf("        X    X XXXX  XXX XX      X      \n");
    printf("       X     X  XX    X   X   XXXXX     \n");
    printf("       X        XX    X  XX             \n");
    printf("       X X XXXXXXXX   X                 \n");
    printf("            X    XXXX                   \n");
    printf("            X       X                   \n");
    printf("            X       X                   \n");
    printf("            XXXXX   XXXXX               \n");
    printf("              X      XX                 \n");
    printf("               X       X       \n");
    break;
    //galinhaPintadinha[6]
    case 6:
    printf("                 XXX                   \n");
    printf("                XX  X   XXXXX           \n");
    printf("                X  X XXXX   X           \n");
    printf("          XXXXX X XXX     XXX           \n");
    printf("          X   XXXXXX     XXX XX         \n");
    printf("            XXXXX  XXXXX X    X         \n");
    printf("          XXX          XXXXXXXX         \n");
    printf("         XX              XX             \n");
    printf("         X                XX            \n");
    printf("        XX                 XX           \n");
    printf("        X  @ XX   @         X           \n");
    printf("       XX XXXXX             X           \n");
    printf("      XX   XX X             XX          \n");
    printf("     X XX    X XX       X    X   XXXX   \n");
    printf("    XX  X    XXX        X    XXXXXX XX  \n");
    printf("    X   X          \\   XX   XX  XXXXX  \n");
    printf("     XXXXX          |    XXXXX X XXXX   \n");
    printf("         X          |       X     XXXX  \n");
    printf("         XX         |       X X XXX     \n");
    printf("       XXXXXXX   XXXXXX                \n");
    break;
    //ticoliro[7]
    case 7:
    printf("                    xxx                \n");
    printf("               xxxx  xxxxxxx           \n");
    printf("          xxxx  xx xxxx xxxxxx         \n");
    printf("       xxxx   xxxxx   xxxx   x         \n");
    printf("      xxxxxxxxxx xxx  xx     x         \n");
    printf("    xxxx       xx           x          \n");
    printf("              xxxxxxxxxx  xx           \n");
    printf("             xx        xx x            \n");
    printf("            xx           x             \n");
    printf("           xx)))))   )))) xx           \n");
    printf("          xx))   )) ))   ))xx          \n");
    printf("          x  ) @  )))) @ )  x          \n");
    printf("         xx   )))))  )))))  xx         \n");
    printf("         x                   x         \n");
    printf("         xx        ▼         x         \n");
    printf("           xx               xx         \n");
    printf("            xxxx           xx          \n");
    printf("               xxxxxx   xxxx           \n");
    printf("                     xxxx          \n");
    break;
    //dodo[8]
    case 8:
    printf("                       xxxxxxxxxxx                                                  \n");
    printf("                      xx         xx                                                 \n");
    printf("                     xx           xx                                                \n");
    printf("                   xx   xxxx       x                                                \n");
    printf("                 xxx   xx          x                                                \n");
    printf("              xxxx                xx                                                \n");
    printf("         xxxxxxx                  x       xxxxxxxxx                                 \n");
    printf("       xxxxxxxxx                 xx xxxxxxx       xxxxxxxx                          \n");
    printf("      xxxxxxxxxxxxxxxxxxx       xxxxx                    xxxxxx                     \n");
    printf("      xxxxxxxxxx        x       xx                            xxxx      xxxxx       \n");
    printf("      xxxxxxxx          xx    xxx                                xxxx  xx   xx      \n");
    printf("      xxxxxx             x   xx               xxx                   xxx      xx     \n");
    printf("      xxxxxx              x xx                   xxx                 xx xxx   xx    \n");
    printf("      xxxxx               xxx               xx     xxx               xxxx xx  x     \n");
    printf("                           xx                 xx     xx              x  xxxx  xx    \n");
    printf("                           x                   xxx    x              x  x xxx  x    \n");
    printf("                           x                     xxx  x              x  xxx xx x    \n");
    printf("                         xxx                       xxxx              x  x x  xxxx   \n");
    printf("                           xxxxx                                     x  xx x        \n");
    printf("                               xxxxxx                               x     xxxx      \n");
    printf("                                    xxxxxx                        xxx        x      \n");
    printf("                                          xxxxxx   x            xxx                 \n");
    printf("                                             x  xxxxxxxxxxxxxxxxx                   \n");
    printf("                                             x    x                                 \n");
    printf("                                             x    x                                 \n");
    printf("                                             x    x                                 \n");
    printf("                                     xxx    xx    x                                 \n");
    printf("                                       xxxxxx     x                                 \n");
    printf("                                    xxxxxxxx xxxxxx    \n");                              
    break;
    //rolinha [9]
    case 9:
    printf("          xxxxxxxxx                                                  \n");
    printf("         xx    xxxxx                                                 \n");
    printf("        xx         xxx   xxxxxxxxxxxxxx                              \n");
    printf("        x            xx xx            xxxxx                          \n");
    printf("       xx             xxx                  xx                        \n");
    printf("   xxxxx            xxx    zzzzzz            xxx                     \n");
    printf("  xxxxxxxxxxx     xx            zzzzz          xxx                   \n");
    printf("            x    x                  zzzz         xxx                 \n");
    printf("            xxxxx                      zzz       xxxx                \n");
    printf("               xx                        zz       x xx               \n");
    printf("               xx           zzzz zzzzzz   z       x  xx              \n");
    printf("                xx                    zzzzzz     xx   xx             \n");
    printf("                 xx                             xx     xx            \n");
    printf("                  xx                           xx       xx           \n");
    printf("                    xxx                      xxx         xxx         \n");
    printf("                       xxxxxx            xxxx xxxxx        xx        \n");
    printf("                         xx  xxxxxxxxxxxxx        xxxxxx    xxxx     \n");
    printf("                    xxxxxx   x                         xxxxxx  xxx   \n");
    printf("                         xxxxx                              xxxxxx   \n");
    break;
    //joao[10]
    case 10:
    printf("                                    \n");
    printf("                             x           \n");
    printf("                   xxxxxxxx xxxxxxxxxx   \n");
    printf("                  xx      xxx   xx   x   \n");
    printf("                            x  xx        \n");
    printf("                          xxxxxxxxx      \n");
    printf("                       xxx        xx     \n");
    printf("        x     xx     xxx           xx    \n");
    printf("       xxx   xxxx    x      T   T   x    \n");
    printf("       x xx xx xx    xx             x    \n");
    printf("       x  xxx  x      x             x    \n");
    printf("       x  xx  xx      xx    xxxx   xxx   \n");
    printf("  xxxxxx  x  xx       xxxx   xx   xx x   \n");
    printf("  x   xx xx xx         x x       xx xx   \n");
    printf("  x    xxx  x          x  xxxxxxxx  x    \n");
    printf("  xx    x   x         xx    xxx     xx   \n");
    printf("   xx       xxx            xx xx     x   \n");
    printf("    xx        xxxx         x    x        \n");
    printf("     xx           xxxx    xx    xx       \n");
    printf("      xx             xxx xx       xx     \n");
    printf("       xx            xxxx          x     \n");
    printf("        xxx       xxxx  x          x     \n");
    printf("          xx   xxxx     x          x     \n");
    printf("           xxxxx       xx          x     \n");
    printf("                                    \n");
    break;
    //canarinhoS[11]
    case 11:
    printf("     xxxxxxxx                                \n");
    printf("  xxxx      xxxx                             \n");
    printf("  x   x      x  xx                           \n");
    printf(" x   x x    x x   x                          \n");
    printf(" x  x @ x  x @ x  xx                         \n");
    printf(" x                 x                         \n");
    printf(" x       xxx       x     xxxxxxx             \n");
    printf(" x    xxxxxxxx     x     xx    xxx           \n");
    printf(" xx      xxx       x      xxx    xx          \n");
    printf("  x       x       xx        xx     xx        \n");
    printf("  xx             xx         xxx     xx       \n");
    printf("   xx          xxx            xx     xxx     \n");
    printf("    xxxxxxxxxxxx          xxx xxxx     xx    \n");
    printf("      x      xx          xx      xx     xx   \n");
    printf("      x       x       xxx         xx     xx  \n");
    printf("      x       xxx  xxxx         xxxxx     xx \n");
    printf("     xx          xxx         xxx    xxxx  xx \n");
    printf("     x       xxxx      xxxxxx          xxxx  \n");
    printf("       xxxxxx  xxxxxxxx\n");
    break;
    //Corvo emo gotico[12]
    case 12:
    printf("              XXXXXXXX XXXX               \n");
    printf("                 XXX@@@@@@@@XXX            \n");
    printf("                  X@@@@@@@X_   XXX         \n");
    printf("                  X@X@@@@XX0\\     X        \n");
    printf("                 XXX@@XXXX    XXXXXX       \n");
    printf("       XXXXXXXX     XX X      XX           \n");
    printf("         XXXXXXXXXX   XX     X             \n");
    printf("          XXX     XXXXX       X            \n");
    printf("            XX                X            \n");
    printf("             X XX             XX           \n");
    printf("             XXXXXX            X           \n");
    printf("              XXX XXXXX       XX           \n");
    printf("                XXX X   XX   X             \n");
    printf("                   XXXXXXXXXX              \n");
    printf("                    XX   X                 \n");
    printf("                     X   XX                \n");
    printf("                    X    X                 \n");
    printf("                   XXX  XXX           \n");
    break;
    //papaLeguas[13]
    case 13:
    printf("                                            X                          \n");
    printf("                                              XXXXXXXX                  \n");
    printf("                                                 XX  XXXX               \n");
    printf("                                                  XXX    X              \n");
    printf("                                              XXXXXXX X XXXX X          \n");
    printf("                                                 X XXXX      XXX        \n");
    printf("        XXXXXX                                  XXXX         @ XXX      \n");
    printf("          X X XX                       XXXXXXX X                XXXXXXXX  \n");
    printf("            XX XXX X            XXXXXXXX           X XXXX X XXXXXX      \n");
    printf("     XXXXXXXXXXX     XXXXXXX XXXXX         XX   XX                      \n");
    printf("          XXXXXXXXXX    XX        XXXXX XXX     X                       \n");
    printf("                   XXXXXXX           X        XX                        \n");
    printf("                           XXXXXXXXXXXXXXX  XX                          \n");
    printf("                          XX            XXXX                            \n");
    printf("                        XX                 X                            \n");
    printf("                        X                 XX                            \n");
    printf("                         XX           XXXXX                             \n");
    printf("                          XXXXXXXXXXXXX            \n");
    break;
    //picaPau[14]
    case 14:
    printf("        xxx              \n");
    printf("        xxxxxxxx                \n");
    printf("           xxx  xxx   xxx       \n");
    printf("  xxxxxxxxx  xxx   xxx x xx     \n");
    printf("    xxxx  xxxx xx    xxxx xx    \n");
    printf("       xxxx   xxx      xx   x   \n");
    printf("          xxx   xx           x  \n");
    printf("            xxx              xx \n");
    printf("              xx              x \n");
    printf("               x  @@   @@     x \n");
    printf("               x  @@   @@    xx \n");
    printf("    xxx       xx             x  \n");
    printf("     xxxxxx   xx           xxx  \n");
    printf("      xx  xxxxx          xxx    \n");
    printf("       xxx     xx       xx      \n");
    printf("         xxxxxxxx      xx       \n");
    printf("               xx    xxx        \n");
    printf("               ┬x┬┬┬xx          \n");
    printf("             ┬┬┬x   x┬┬┬        \n");
    printf("             ┬┬┬┬┬┬┬┬┬┬┬      \n");
    break;
    //recruta[15]
    case 15:
    printf("          xxxxxxxxxxxx          \n");
    printf("         xx xxxxxxxxxxx         \n");
    printf("        xx    xxxxx    x        \n");
    printf("        x              xx   xx  \n");
    printf("        x   @@    @@    x   xx  \n");
    printf("        xx  @@    @@    x   xx  \n");
    printf("       xxx              xx xxx  \n");
    printf("      xx x     xxxx      xxxxx  \n");
    printf("    xx   x      xx       x xx   \n");
    printf("   xx xxxx               xxx    \n");
    printf("  xx xx  x               xx     \n");
    printf("  xxx    x               x      \n");
    printf("         x               x      \n");
    printf("         xx              x      \n");
    printf("         xxxx           xx      \n");
    printf("       xxxxxxxxxxxxxxxxxxxx     \n");
    printf("      xxxxxxx      xxxxxxx     \n");
    break;
    //kiwi[16]
    case 16:
        printf("                        xxxxxxx             \n");
    printf("                         xxxxxx      xxxx          \n");
    printf("                      xxxx               xxx       \n");
    printf("                   xxx                     xx      \n");
    printf("          xxxxxxxxx                         xx     \n");
    printf("        xxx   xxxx                           xx    \n");
    printf("        x  x   xx                             x    \n");
    printf("        x      xx                             x    \n");
    printf("       xxxxxxxxxxx                            x    \n");
    printf("      xx xx      xx                           x    \n");
    printf("     xx  x        xx                          x    \n");
    printf("    xx  xx         xx                       xxx    \n");
    printf("   xx xxx            xx                    xx      \n");
    printf("  xx xx               xxx                 xx       \n");
    printf(" xxxxx                   xxx            xxx        \n");
    printf("  xx                    xx  xxxxxxxxxxxxx          \n");
    printf("                       xx        x                 \n");
    printf("                    xxxx      xxx       \n"); 
    break;
    default: break;
    }
}
#endif