#include <string>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <iomanip>


#include "util.h"
#include "mydatastore.h"
#include "datastore.h"
#include "user.h"

MyDataStore::MyDataStore() 
: DataStore()
{

}

MyDataStore ::~MyDataStore()
{
    // destructor to clear out everything 
    // clear product
    std::map<std::string, Product *>::iterator itP;
    for (itP = prod.begin(); itP != prod.end(); ++itP)
    {
        delete itP->second;
    }
    // clear users
    std::map<std::string, User *>::iterator itU;
    for(itU = user.begin(); itU != user.end(); ++itU)
    {
        delete itU->second;
    }
}

void MyDataStore::addProduct(Product *p)
{
    std::set<std::string> addKeyM = p -> keywords();
    std::set<std::string>::iterator it;

    // add product to the data store
    for (it = addKeyM.begin(); it != addKeyM.end(); ++it)
    {
      prodM[*it].insert(p);
    }
    prod.insert(std::make_pair(p->getName(), p));
   
}

void MyDataStore::addUser(User *u)
{
    user.insert(std::make_pair(u->getName(), u));

    //std::vector<Product *> getUserP;
    //cartVectMap.insert(std::make_pair(u, getUserP));
}

/**
 * Performs a search of products whose keywords match the given "terms"
 *  type 0 = AND search (intersection of results for each term) while
 *  type 1 = OR search (union of results for each term)
 * For search you can use the setIntersection and setUnion)
 */
std::vector<Product *> MyDataStore::search(std::vector<std::string> &terms, int type)
{
    std::vector<Product *> searchVector;
    if (terms.size() == 0 )
    {
        return searchVector;
    }
    std::set<Product *> set1;
    std::set<Product *> set2;

    set1 = prodM[terms[0]];

    for(unsigned int i = 1; i< terms.size(); i++)
    {
        if(type == 0) // AND - setIntersection
        {
            //  set1 = prodM[terms[0]];
            set2 = prodM[terms[i]];
            set1 = setIntersection(set1,set2);
        }
        else if (type == 1) // OR - setUnion
        {
            set2 = prodM[terms[i]];
            set1 = setUnion(set1, set2);
        }
    }
    std::set<Product *>::iterator it;
    for (it = set1.begin(); it != set1.end(); it++)
    {
        searchVector.push_back(*it);
    }
    return searchVector;
    
}

void MyDataStore::dump(std::ostream &ofile)
{
    ofile << "<products>" << std::endl;
    std::map<std::string, Product *>::iterator itP;
    for (itP = prod.begin(); itP != prod.end(); itP++)
    {
        ((itP)->second)->dump(ofile);
    }
    //ofile<< std::endl;
    ofile << "</products>" << std::endl;
    ofile << "<users>" << std::endl;

    std::map<std::string, User *>::iterator itU;

    for (itU = user.begin(); itU != user.end(); ++itU)
    {
        ((itU)->second)->dump(ofile);
    }
    //ofile<< std::endl;
    ofile << "</users>" << std::endl;
    
}

void MyDataStore::addCart(const std::string &username, Product * product)
{
    if (user.find(username) == user.end())
    {
        std::cout << "Invalid request";
        //return;
    }
    else
    {
        cartVectMap[user[username]].push_back(product); // insert into vector of the cartMap
    }

}

// CHECK THIS
void MyDataStore::viewCart(const std::string &username)
{
  
    if (user.find(username) == user.end())
    {
        std::cout << "Invalid username";
        return;
    }
    User *newUser = user.find(username)->second;

    std::vector<Product *> allItems = cartVectMap[newUser];

    int itemsNum = 1;
    std::vector<Product *>::iterator it;
    for (it = allItems.begin(); it != allItems.end(); ++it)
    {
        std::cout << "Item " << itemsNum << "\n" << (*it)->displayString() << std::endl;
        itemsNum++;
    }

}

void MyDataStore::buyCart(const std::string &username)
{
    if (user.find(username) == user.end())
    {
        std::cout << "Invalid username" << std::endl;
        return;
    } 
    else
    {
      // Make sure to change the original one to
      std::vector<Product*>& tempCart = cartVectMap[user[username]];
      unsigned int i = 0;
      while(i < tempCart.size())
      {
        Product* p = tempCart[i];
        // check price and balance as well as quantitiy
        if(p->getPrice() <= user[username] -> getBalance() && p->getQty() > 0)
        {
            user[username] -> deductAmount(p->getPrice());//deduct amount
            p->subtractQty(1); // reduce quanitity
            tempCart.erase(tempCart.begin() + i); // remove item at index
        }
        else 
        {
          ++i;
        }
      } 

    }
}