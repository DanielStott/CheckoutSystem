//Item struct
struct Item
{
    char itemCode;
    unsigned float price;
    SpecialPrice specialPrice;
};

struct SpecialPrice
{
    unsigned int quantity;
    unsigned float specialPrice;
};