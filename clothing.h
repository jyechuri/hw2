#ifndef CLOTHING_H
#define CLOTHING_H

#include <string>
#include <iostream>
#include <set>

#include "product.h"
#include "util.h"

class Clothing : public Product
{
    private:
        std::string brand_;
        std::string size_;
        
    public:
        Clothing(const std::string category, const std::string name, double price, int qty, const std::string brand, const std::string size);
        ~Clothing();

        /**
        * Returns the appropriate keywords that this product should be associated with
        */
        std::set<std::string> keywords() const;

        /**
         * Returns a string to display the product info for hits of the search
         */
        std::string displayString() const;

        /**
         * Outputs the product info in the database format
         */
        void dump(std::ostream &os) const;

        /**
         * Accessors and mutators
         */
        //std::string getSize() const;
        //std::string getBrand() const;
};
#endif