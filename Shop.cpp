//
// Created by stott on 28/06/18.
//

#include "Shop.h"

//On class initialisation add shop items to available item list
Shop::Shop(std::vector<item> *shopItems)
{
    items = shopItems;
}

//Adds item to shopping cart
bool Shop::AddToCart(char itemToAdd)
{
    //Loops over shopping cart
    for(cartItem &cItem : shoppingCart)
    {
        //Checks if item already exists inside shopping cart
        if (cItem.code == itemToAdd)
        {
            //Increases quantity of item
            cItem.quantity++;
            return true;
        }
    }

    //loops over product item list
    for (item &pItem : *items)
    {
        //Checks that itemToAdd is inside item list.
        if (pItem.code == itemToAdd)
        {
            //Adds item to shopping cart
            shoppingCart.push_back({itemToAdd, 1});
            return true;
        }
    }

    //Returns false if item does not exist in product list
    return false;
}

//Calculates the total price of items in the shopping cart
int Shop::CalculateCart()
{
    unsigned int price = 0;

    //loops through shopping cart
    for(cartItem &itemInCart : shoppingCart)
    {
        //loops through product list
        for (item &productItem : *items)
        {
            //checks if shopping cart item is equal to product
            if(itemInCart.code == productItem.code)
            {
                //checks item in cart has a special price and has required quantity for special price
                if(productItem.sPrice.quantity != 0 && itemInCart.quantity >= productItem.sPrice.quantity)
                {
                    //Calculates total of items in shopping cart
                    int divisibleBy = itemInCart.quantity / productItem.sPrice.quantity;
                    int remainder = itemInCart.quantity % productItem.sPrice.quantity;

                    price += divisibleBy * productItem.sPrice.specialPrice;
                    price += remainder * productItem.price;

                }
                else
                {
                    price += itemInCart.quantity * productItem.price;
                }
            }
        }
    }
    return price;
}

//Lists all available products and returns as string
void Shop::ListAvailableProducts() {

    std::cout << "| ITEM CODE | PRICE | SPECIAL PRICE | \n" ;
    for(item &productItem : *items)
    {
        std::cout << "| " << productItem.code << " | " << productItem.price
                << " | " << productItem.sPrice.quantity << " for " << productItem.sPrice.specialPrice
                  << " |" << std::endl;

    }

}

