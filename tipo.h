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

 case 'n':  // Normal
            if(tAlv == 'p') return 2.0;  // Vantagem contra Planta
            if(tAlv == 's') return 0.5;  // Ineficaz contra Sombrio
            return 1.0;  // Dano neutro
        break;

        case 'e':  // Elétrico
            if(tAlv == 'l') return 2.0;  // Vantagem contra Lutador
            if(tAlv == 'a') return 0.5;  // Ineficaz contra Água
            return 1.0;
        break;

        case 'a':  // Água
            if(tAlv == 'e') return 2.0;  // Vantagem contra Elétrico
            if(tAlv == 'p') return 0.5;  // Ineficaz contra Planta
            return 1.0;
        break;

        case 'd':  // Dançarino
            if(tAlv == 's') return 0.5;  // Ineficaz contra Sombrio
            if(tAlv == 'l') return 2.0;  // Vantagem contra Lutador
            return 1.0;
        break;

        case 'l':  // Lutador
            if(tAlv == 'd') return 2.0;  // Vantagem contra Dançarino
            if(tAlv == 'e') return 0.5;  // Ineficaz contra Elétrico
            return 1.0;
        break;

        case 'p':  // Planta
            if(tAlv == 'a') return 2.0;  // Vantagem contra Água
            if(tAlv == 'n') return 0.5;  // Ineficaz contra Normal
            return 1.0;
        break;

        case 's':  // Sombrio
            if(tAlv == 'd') return 2.0;  // Vantagem contra Dançarino
            if(tAlv == 'n') return 0.5;  // Ineficaz contra Normal
            return 1.0;
        break;

        default:
            return 1.0; 
    }
}

#endif

       /* case 'n':
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

#endif */
