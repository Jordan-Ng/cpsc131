#include <vector>
#include "GroceryItem.hpp"

int main()
{
    std::cout << "Welcome to Kroger. Place grocery items into your shopping cart by entering each item's information. \n"
              << "    enclose string entries in quotes, separate fields with commas \n"
              << "    for example: \"00016000306707\", \"Berry Crocker\", \"Betty Crocker Chocolate Chunk Cookie Mix\", 17.19 \n"
              << "    Enter CTL-Z (Windows) or CTL-D (Linux) to quit \n\n";

    std::vector<GroceryItem *> shoppingCart;
    GroceryItem groceryItem;

    while (std::cout << "Enter UPC, Product Brand, Product Name, and Price\n", std::cin >> groceryItem)
    {
        shoppingCart.push_back(new GroceryItem(std::move(groceryItem)));
        std::cout << shoppingCart.back() << std::endl;
        std::cout << "Item added to shopping cart: " << *shoppingCart.back() << std::endl;
    }

    std::cout << "\n\nHere is an itemized list of the items in your shopping cart:\n";
    for (auto i = shoppingCart.crbegin(); i < shoppingCart.crend(); i++)
    {
        std::cout << **i << "\n";
        delete *i;
    }

    return 0;
}
