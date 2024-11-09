#ifndef INVENTARIO_H
#define INVENTARIO_H
#include <stdio.h>
#include <string.h>
#include "pokemon.h"
#define MAX 100

//teoricamente é p funcionar

typedef struct {
    char name[20];     // Nome do item
    int quantity;      // Quantidade do item
    char effect[100];   // Descrição do efeito do item
} Item;

typedef struct {
    Item items[7];     // Array de 7 itens no inventário
} Inventory;

// Função para inicializar o inventário com itens e quantidades
void initializeInventory(Inventory *inv) {
    // Exemplo de inicialização dos itens
    Item BirdCoin = {"BirdCoin", 1000, "Recurso para trocar por outros itens na loja"};
    Item Alpiste = {"Alpiste", 0, "Recupera 30 HP"};
    Item Melao = {"Melao", 0, "Aumenta o atk do birdmon"};
    Item Gaiola = {"Gaiola", 5, "Usada para capturar Birdmon(com consentimento do governo)"};
    Item Soro = {"Soro", 0, "Cura efeitos negativos"};
    Item Biscoito = {"Revive", 0, "Revive um Birdmon desmaiado com 50% de HP"};
    Item Capacete = {"Capacete", 0, "Aumenta a defesa do birdmon"};

    inv->items[0] = Alpiste;
    inv->items[1] = Melao;
    inv->items[2] = Gaiola;
    inv->items[3] = Soro;
    inv->items[4] = Biscoito;
    inv->items[5] = Capacete;
    inv->items[6] = BirdCoin;
}

// Função para exibir o inventário
void displayInventory(Inventory *inv) {
    printf("Inventario:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d. %s (Quantidade: %d) - %s\n", i, inv->items[i].name, inv->items[i].quantity, inv->items[i].effect);
    }
}
//função p adicionar coisa da loja pro inventario
void adicionarAoInventario(Inventory *inv, const char *itemName) {
    for (int i = 0; i < 6; i++) {
        if (strcmp(inv->items[i].name, itemName) == 0) {
            inv->items[i].quantity++;
            printf("%s adicionado ao inventario. Nova quantidade: %d\n", itemName, inv->items[i].quantity);
            return;
        }
    }
    printf("Item %s nao encontrado no inventario.\n", itemName);
}
void resetarAtributos(tp_pokemon *poke) {
    poke->atq = poke->atqO;
    poke->def = poke->defO;
    poke->agil = poke->agilO;
    printf("Ataque, Defesa e Agilidade foram restaurados aos valores originais. Ataque: %d, Defesa: %d, Agilidade: %d\n", poke->atq, poke->def, poke->agil);
}

void reviverBirdmon(tp_pokemon *poke) {
    if (poke->vida == 0) {
        poke->vida = poke->vidamax / 2;  // Restaura a 50% do HP máximo
        printf("Birdmon revivido com %d HP.\n", poke->vida);
    } else {
        printf("Birdmon ainda está vivo e não precisa ser revivido.\n");
    }
}


int aplicarEfeito(int item, tp_pokemon *poke) {
    if (item == 1) {
        // Efeito de recuperacao de HP
        int hpRecovery = 30;
        poke->vida += hpRecovery;
        printf("HP recuperado em %d pontos. HP atual: %d\n", hpRecovery, poke->vida);
        return 1;
    } else if (item == 2) {
        // Efeito de aumento de ataque
        float atkIncreasePercent = 0.2;  // 20%
        int atkIncrease = poke->atq * atkIncreasePercent;
        poke->atq += atkIncrease;
        printf("Ataque aumentado em %d pontos. Ataque atual: %d\n", atkIncrease, poke->atq);
        return 1;
    } else if (item == 3) {
        // Efeito de aumento de defesa
        float defIncreasePercent = 0.2;  // 20%
        int defIncrease = poke->def * defIncreasePercent;
        poke->def -= defIncrease;
        printf("Defesa aumentada em %d pontos. Defesa atual: %d\n", defIncrease, poke->def);
        return 1;
    } else if (item == 4) {
         resetarAtributos(poke);
         return 1;
        }if (item == 5) {
            reviverBirdmon(poke);
            return 1;
        }else {
        printf("item nao reconhecido, digite novamente.\n");
        return 0;
    }
}



#endif
