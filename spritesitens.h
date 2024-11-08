#ifndef SPRITESITENS_H
#define SPRITESITENS_H
#include <stdio.h>
#define MAX 100

void spritesItens(int num){
switch(num){

//alpiste
case 1:
printf("|-------------| \n");
printf("|   ALPISTE   | \n");
printf("|-------------| \n");
printf("|:::::::::::::| \n");
printf("|:::::::::::::| \n");
printf("|:::::::::::::| \n");
printf("|-------------| \n");
break;


//melão
case 2: 
printf("          --MM \n");
printf("      MM##MM:: \n");
printf("    MMMM####++ \n");
printf("    ####MM@@++ \n");
printf("  MM##MM##  ## \n");
printf("@@--      MM   \n"); 
printf("  ########     \n");    
break;

//gaiola
case 3:
printf("xxxxxxxxxxxxx \n");
printf("x  x  x  x  x \n");
printf("x  x  x  x  x \n");
printf("x  x  x  x  x \n");
printf("x  x  x  x  x \n");
printf("x  x  x  x  x \n");
printf("xxxxxxxxxxxxx \n");
break;

//soro
case 4:
printf("  ___   \n");
printf(" |   |  \n");
printf(" _| |_  \n");
printf("|_____| \n");
printf("|─────| \n");
printf("|_____| \n");
break;

//biscoito
case 5:
printf("    *******       \n");
printf("  ***  @   ****   \n");
printf(" ** @    @   ***  \n");
printf(" *    @    @  **  \n");
printf(" *  @        ***  \n");
printf(" **     @   ***   \n");
printf("   **********     \n");
break;

//capacete
case 6:
printf(" #######  \n");
printf("##      # \n");
printf("#    #### \n");
printf("#   ##  | \n");
printf("#   #___| \n");
printf(" ####     \n");
break;

}
}

#endif