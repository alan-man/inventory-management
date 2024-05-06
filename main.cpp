#include "inventoryClass.h"

int main(){

    Product p1(1,"Chocolate",5.99,200,"Food","00-00-2024");
    Inventory inventory;

    inventory.addProduct(p1);
    double total = inventory.getTotalInventoryValue();

    cout << "total : $"<< total << endl; 

    Product p2(2,"Cheese",2.99,100,"Food","00-00-2024");
    inventory.addProduct(p2);
    Product *p3 = inventory.findProduct(1);
    cout << "id = " << p3->getID() << endl;

    cout << endl;
    inventory.saveInvFile("tmp.txt");

    Inventory inv2;
    inv2.loadInvFile("tmp.txt");
    inv2.printInv();
    cout << endl;


    inv2.sortQuantity();
    inv2.printInv();

    try {
        inv2.removeProduct(3);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

