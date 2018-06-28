//
// Created by stott on 28/06/18.
//

#include <vector>
#include <iostream>
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

#ifndef CHECKOUTSYSTEM_SHOP_H
#define CHECKOUTSYSTEM_SHOP_H


class Shop
{
public:
    struct specialPrice
    {
        unsigned int quantity;
        unsigned int specialPrice;
    };

    struct item
    {
        char code;
        unsigned int price;
        struct specialPrice sPrice;
    };

    Shop(std::vector<item> *items);
    bool AddToCart(char itemToAdd);
    int CalculateCart();
    void ListAvailableProducts();


private:
    struct cartItem
    {
        char code;
        unsigned int quantity;
    };
    std::vector<item> *items;
    std::vector<cartItem> shoppingCart;

};


#endif //CHECKOUTSYSTEM_SHOP_H
