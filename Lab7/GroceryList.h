//GroceryList.h, 117928226, George Paul Robert - Class defintions

#include <iostream>

class GroceryList {
    private:
        std::string name;
        int barcode;
        double tax;
        double cost;

    public:
        std::string getName() const;
        int getBarcode() const;
        double getTax() const;
        double getCost() const;
        bool setName(std::string _name);
        bool setBarcode(int _barcode);
        bool setCost(double _cost);
        bool evaluateTax(char taxable);
};
