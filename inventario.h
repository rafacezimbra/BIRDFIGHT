#ifndef INVENTARIO_H
#define INVENTARIO_H
#include <stdio.h>
#include <string.h>

#include "inventario.h"
#define MAX 100

//teoricamente é p funcionar

typedef struct {
    char name[20];     // Nome do item
    int quantity;      // Quantidade do item
    char effect[100];   // Descrição do efeito do item
} Item;

typedef struct {
    Item items[6];     // Array de 6 itens no inventário
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
}

// Função para exibir o inventário
void displayInventory(Inventory *inv) {
    printf("Inventário:\n");
    for (int i = 0; i < 6; i++) {
        printf("%s (Quantidade: %d) - %s\n", inv->items[i].name, inv->items[i].quantity, inv->items[i].effect);
    }
}
//função p adicionar coisa da loja pro inventario
void adicionarAoInventario(Inventory *inv, const char *itemName) {
    for (int i = 0; i < 6; i++) {
        if (strcmp(inv->items[i].name, itemName) == 0) {
            inv->items[i].quantity++;
            printf("%s adicionado ao inventário. Nova quantidade: %d\n", itemName, inv->items[i].quantity);
            return;
        }
    }
    printf("Item %s não encontrado no inventário.\n", itemName);
}

#endif