#ifndef TIPO_H
#define TIPO_H

int multiplicadorDeTipo(char tipoAtacante[], char tipoAlvo[]){

    //normal ganha planta perde sombrio
    //eletrico ganha lutador perde agua
    //agua ganha eletirco perde planta
    //dancarino perde sombrio ganha lutador
    //lutador ganha dancarino perde eletrico
    //planta ganha agua perde normal
    //sombrio perde normal ganha dancarino

    //return 4 -> vantagem
    //return 2 -> sem vantagem
    //return 1 -> desvantagem 

    char tAtk = tipoAtacante[0];
    char tAlv = tipoAlvo[0];

    switch(tAtk){

        case 'n':
            if(tAlv == 'p') return 4;
            if(tAlv == 's') return 1;
            else return 2;
        break;

        case 'e':
            if(tAlv == 'l') return 4;
            if(tAlv == 'a') return 1;
            else return 2;
        break;

        case 'a':
            if(tAlv == 'e') return 4;
            if(tAlv == 'p') return 1;
            else return 2;
        break;

        case 'd':
            if(tAlv == 's') return 4;
            if(tAlv == 'l') return 1;
            else return 2;
        break;

        case 'l':
            if(tAlv == 'd') return 4;
            if(tAlv == 'e') return 1;
            else return 2;
        break;

        case 'p':
            if(tAlv == 'a') return 4;
            if(tAlv == 'n') return 1;
            else return 2;
        break;

        case 's':
            if(tAlv == 's') return 4;
            if(tAlv == 'd') return 1;
            else return 2;
        break;

    }

}

#endif 