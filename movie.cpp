#include <string>
#include <iostream>
#include <set>
#include <iomanip>

#include "movie.h"
#include "util.h"

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating)
    : Product(category, name, price, qty),
      genre_(genre),
      rating_(rating)
{
}

Movie::~Movie()
{
}

std::set<std::string> Movie::keywords() const
{
    std::set<std::string> keys = parseStringToWords(name_);
    keys.insert(convToLower(genre_));

    return keys;

    /*std::set<std::string> keys;

    std::set<std::string> set1 = parseStringToWords(name_);
    std::set<std::string> set2 = parseStringToWords(genre_);

    keys = setUnion(set1, set2); */
}

std::string Movie::displayString() const
{
    std::string displayClothing;

    displayClothing = name_ + "\n" + "Genre: " + genre_ + " Rating: " + rating_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";

    return displayClothing;
}

void Movie::dump(std::ostream &os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ <<std::endl;
}

/*std::string Movie::getRating() const
{
    return rating_;
}

std::string Movie::getGenre() const
{
    return genre_;
} */