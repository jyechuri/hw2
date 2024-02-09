#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include <string>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <queue>

#include "datastore.h"

class MyDataStore : public DataStore
{
    public:
        MyDataStore();
        
        ~MyDataStore();

        /**
         * Adds a product to the data store
         */
        void addProduct(Product *p);

        /**
         * Adds a user to the data store
         */
        void addUser(User *u);

        /**
         * Performs a search of products whose keywords match the given "terms"
         *  type 0 = AND search (intersection of results for each term) while
         *  type 1 = OR search (union of results for each term)
         * For search you can use the setIntersection and setUnion)
         */
        std::vector<Product *> search(std::vector<std::string> &terms, int type);

        /**
         * Reproduce the database file from the current Products and User values
         */
        void dump(std::ostream &ofile);

        void addCart(const std::string &username, Product *);
        void viewCart(const std::string &username);
        void buyCart(const std::string &username);

    private:
        std::map<std::string, std::set <Product *>> prodM;
        
        // map of all users and products resspectively
        std::map<std::string, User *> user;
        std::map<std::string, Product *> prod;

        // std::vector<Product *> prodV;
        std::map<User *, std::vector<Product *>> cartVectMap;
        
};
#endif