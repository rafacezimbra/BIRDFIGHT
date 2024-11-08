#include <stdio.h>
#include "inventario.h"
#include "loja.h"

int main() {
    Inventory playerInventory;
    int BirdCoin = 100;

    initializeInventory(&playerInventory);

  
    displayInventory(&playerInventory);

    loja(&playerInventory, &BirdCoin);

    displayInventory(&playerInventory);

    return 0;
}
