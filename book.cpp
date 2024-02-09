#include <string>
#include <iostream>
#include <set>
#include <iomanip>

#include "book.h"

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string author, const std::string isbn) 
    :Product(category, name, price, qty), 
    author_(author), 
    isbn_(isbn)
{

}

Book::~Book()
{

}

std::set<std::string> Book::keywords() const
{
    std::set<std::string> keys;

    std::set<std::string> set1 = parseStringToWords(name_);
    std::set<std::string> set2 = parseStringToWords(author_);

    keys = setUnion(set1,set2);
    keys.insert(isbn_);

    return keys;
}

std::string Book::displayString() const
{
    std::string displayBook = "";

    displayBook = name_ + "\n" + "Author: " + author_ + " ISBN: " + isbn_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";

    return displayBook;
}

void Book::dump(std::ostream &os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << std::endl;
}

/*std::string Book::getAuthor() const
{
    return author_;
}

std::string Book::getISBN() const
{
    return isbn_;
}*/