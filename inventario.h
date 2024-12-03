#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <stdio.h>
#include <string.h>
#include "pokemon.h"
#define MAX 100

typedef struct {
    char name[20];     // Nome do item
    int quantity;      // Quantidade do item
    char effect[100];  // Descrição do efeito do item
} Item;

typedef struct {
    Item items[7];     // Array de 7 itens no inventário
} Inventory;

// Função para inicializar o inventário com itens e quantidades
void initializeInventory(Inventory *inv) {
    // Inicialização dos itens
    Item BirdCoin = {"BirdCoin", 1000, "Recurso para trocar por outros itens na loja"};
    Item Alpiste = {"Alpiste", 0, "Recupera 30 HP"};
    Item Melao = {"Melao", 0, "Aumenta o ataque do birdmon"};
    Item Gaiola = {"Gaiola", 5, "Usada para capturar Birdmon (com consentimento do governo)"};
    Item Soro = {"Soro", 0, "Cura efeitos negativos"};
    Item Biscoito = {"Biscoito", 0, "Revive um Birdmon desmaiado com 50% de HP"};
    Item Capacete = {"Capacete", 0, "Aumenta a defesa do birdmon"};

    inv->items[0] = Alpiste;
    inv->items[1] = Melao;
    inv->items[2] = Capacete;
    inv->items[3] = Soro;
    inv->items[4] = Biscoito;
    inv->items[5] = Gaiola;
    inv->items[6] = BirdCoin;
}

// Função para exibir o inventário
void displayInventory(Inventory *inv) {
    printf("Inventario:\n");
    for (int i = 0; i < 7; i++) { // Corrigido para iterar até 7 itens
        printf("%d. %s (Quantidade: %d) - %s\n", i + 1, inv->items[i].name, inv->items[i].quantity, inv->items[i].effect);
    }
}

// Função para adicionar um item da loja ao inventário
void adicionarAoInventario(Inventory *inv, const char *itemName) {
    for (int i = 0; i < 7; i++) { // Corrigido para iterar até 7 itens
        if (strcmp(inv->items[i].name, itemName) == 0) {
            inv->items[i].quantity++;
            printf("%s adicionado ao inventario. Nova quantidade: %d\n", itemName, inv->items[i].quantity);
            return;
        }
    }
    printf("Item %s nao encontrado no inventario.\n", itemName);
}

// Funções adicionais para manipular Pokémon
void resetarAtributos(tp_pokemon *poke) {
    poke->atq = poke->atqO;
    poke->def = poke->defO;
    poke->agil = poke->agilO;
    printf("Ataque, Defesa e Agilidade foram restaurados aos valores originais. Ataque: %d, Defesa: %d, Agilidade: %d\n", poke->atq, poke->def, poke->agil);
}

void listarBirdmons(tp_pokemon *poke) {
    int numBirdmons = 6;
    printf("Escolha um Birdmon para reviver:\n");
    for (int i = 0; i < numBirdmons; i++) {
        printf("%d. %s (Vida: %d / %d)\n", i + 1, poke[i].nome, poke[i].vida, poke[i].vidamax);
    }
}

void reviverBirdmon(tp_pokemon *poke) {

    listarBirdmons(poke);
    int numBirdmons = 6;
    int escolha;
    printf("Digite o numero do Birdmon que deseja reviver: ");
    scanf("%d", &escolha);
    
    if (escolha > 0 && escolha <= numBirdmons) {
        tp_pokemon *poke = &poke[escolha]; 
        if (poke->vida == 0) {
            poke->vida = poke->vidamax / 2; // Restaura a 50% do HP máximo
            printf("%s revivido com %d HP.\n", poke->nome, poke->vida);
        } else {
            printf("%s ainda esta vivo e nao precisa ser revivido.\n", poke->nome);
        }
    } else {
        printf("Escolha invalida.\n");
    }
}

int temItem(int numItem, Inventory *inv) { // Checa se o jogador tem pelo menos uma unidade daquele item para utilizá-lo
    if (inv->items[numItem].quantity > 0) return 1;
    
    printf("Voce nao tem esse item.\n");
    return 0;
}

int aplicarEfeito(int itemIndex, tp_pokemon *poke, Inventory *inv) { // Aplica o efeito de um item no inventário
    if (temItem(itemIndex, inv)) { // Testa se o jogador tem o item antes de aplicar os efeitos
        if (itemIndex == 0) { // Alpiste
            int hpRecovery = 30;
            poke->vida += hpRecovery;
            printf("HP recuperado em %d pontos. HP atual: %d\n", hpRecovery, poke->vida);
            return 1;
        } else if (itemIndex == 1) { // Melão
            float atkIncreasePercent = 0.2; // Aumento de ataque de 20%
            int atkIncrease = poke->atq * atkIncreasePercent;
            poke->atq += atkIncrease;
            printf("Ataque aumentado em %d pontos. Ataque atual: %d\n", atkIncrease, poke->atq);
            return 1;
        } else if (itemIndex == 2) { // Capacete
            float defIncreasePercent = 0.2; // Aumento de defesa de 20%
            int defIncrease = poke->def * defIncreasePercent;
            poke->def += defIncrease; // Corrigido para aumentar a defesa
            printf("Defesa aumentada em %d pontos. Defesa atual: %d\n", defIncrease, poke->def);
            return 1;
        } else if (itemIndex == 3) {
            resetarAtributos(poke);
            return 1;
        } else if (itemIndex == 4) {
            reviverBirdmon(poke);
            return 1;
        } else if (itemIndex == 5) {
            printf("Esse item eh utilizado a partir do menu.\n");
            return 0;
        } else {
            printf("Item nao reconhecido. Digite novamente.\n");
            return 0;
        }
    }
    
    return 0; // Se o jogador não tiver o item, volta.
}

#endif
