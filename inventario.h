#ifndef INVENTARIO_H
#define INVENTARIO_H
#include <stdio.h>
#include <string.h>
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
        printf("%s (Quantidade: %d) - %s\n", inv->items[i].name, inv->items[i].quantity, inv->items[i].effect);
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
void resetarAtributos(int *atq, int *def, int *atqO, int *defO, int *agil, int *agilO) {
    *atq = *atqO;
    *def = *defO;
    *agil = *agilO;
    printf("Ataque, Defesa e Agilidade foram restaurados aos valores originais. Ataque: %d, Defesa: %d, Agilidade: %d\n", *atq, *def, *agil);
}

void reviverBirdmon(int *vida, int vidamax) {
    if (*vida == 0) {
        *vida = vidamax / 2;  // Restaura a 50% do HP máximo
        printf("Birdmon revivido com %d HP.\n", *hp);
    } else {
        printf("Birdmon ainda está vivo e não precisa ser revivido.\n");
    }
}


void aplicarEfeito(Item item, int *vida, int *atq, int *def, int *agil) {
    if (strcmp(item.name, "Alpiste") == 0) {
        // Efeito de recuperacao de HP
        int hpRecovery = 30;
        *hp += hpRecovery;
        printf("HP recuperado em %d pontos. HP atual: %d\n", hpRecovery, *hp);
    } else if (strcmp(item.name, "Melao") == 0) {
        // Efeito de aumento de ataque
        float atkIncreasePercent = 0.2;  // 20%
        int atkIncrease = *atk * atkIncreasePercent;
        *atk += atkIncrease;
        printf("Ataque aumentado em %d pontos. Ataque atual: %d\n", atkIncrease, *atk);
    } else if (strcmp(item.name, "Capacete") == 0) {
        // Efeito de aumento de defesa
        float defIncreasePercent = 0.2;  // 20
        *def -= defIncrease;
        printf("Defesa aumentada em %d pontos. Defesa atual: %d\n", defIncrease, *def);
    } else if (strcmp(item.name, "Soro") == 0) {
         resetarAtributos(atq, def, atqO, defO, agil, agilO);
        }if (strcmp(item.name, "Pena da Vida") == 0) {
            reviverBirdmon(&poke[].vida, poke[].vidamax);
        }else {
        printf("Efeito do item nao reconhecido: %s\n", item.name);
    }
}



#endif
