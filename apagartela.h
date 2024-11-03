#ifndef APAGARTELA_H //if not define
#define APAGARTELA_H

void apagarTela(){
    #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
}

#endif