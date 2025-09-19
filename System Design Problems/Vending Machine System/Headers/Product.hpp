#include <cstdlib>

class Product{
private:
    int product_id , slot_number , price;
public:
    Product(int slot , int price);
    
    int get_product_id();
    int get_slot_number();
    int get_price();
};