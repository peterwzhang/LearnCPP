#include <array>
#include <iostream>
#include <numeric>

    enum Items{
        item_health_pot,
        item_torch,
        item_arrow,
        total_items
    };

using inventory_t = std::array<int, Items::total_items>;

int countTotalItems(const inventory_t& inventory){
    return std::reduce(inventory.begin(), inventory.end());
}

int countSpecificItem(const inventory_t& inventory, Items itemtype){
    return inventory[itemtype];
}

int main(){
    std::array<int, Items::total_items> inventory { 2, 5, 10 };
    std::cout << countTotalItems(inventory) << " total item\n";
    std::cout << countSpecificItem(inventory, Items::item_torch) << " torches\n";
    return 0;
}