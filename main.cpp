#include <iostream>
#include <vector>

#include "Shop.h"

int main()
{

    //Vector of available items
    std::vector<Shop::item> items = {{'A', 50, {3, 140}}, {'B', 35, {2, 60}}, {'C', 25, {0,0}}, {'D', 12, {0,0}}};

    //Initialisation of Shop class
    Shop *Tesco = new Shop(&items);

    //Print out available products with prices
    Tesco->ListAvailableProducts();

    //Front end system asking user to add items to shopping cart
    while(true)
    {
        std::string code = "";
        std::cout << "Type \"checkout\" to finish." << std::endl;
        std::cout << "Please enter an item to add:" << std::endl;
        std::cin >> code;

        //Exits upon user request with total price
        if(code == "exit" || code == "checkout")
        {
            std::cout << "Total Price: " << Tesco->CalculateCart();
            return 0;
        }//Makes sure user is entered a charater.
        else if(isalpha(code[0]))
        {
            //Add item to shopping cart else error.
            if(Tesco->AddToCart(toupper(code[0])))
            {
                std::cout << "Item successfully added to cart. " << std::endl;
                std::cout << "New total price: " << Tesco->CalculateCart() << std::endl;
                break;
            }
        }

        //Output error
        std::cout << "Failed to add item to cart. Please try a valid item code." << std::endl;
    }
}


