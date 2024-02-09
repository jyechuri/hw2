#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>

/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T> &s1, std::set<T> &s2)
{
    // checks if s1 is in s2
    std::set<T> intersectS;

    typename std::set<T>::iterator it;

    for (it = s1.begin(); it != s1.end(); ++it)
    {
        if (s2.find(*it) != s2.end()) // found in set2
        {
            intersectS.insert(*it);
        }
    }
    return intersectS;
}

template <typename T>
std::set<T> setUnion(std::set<T> &s1, std::set<T> &s2)
{

    std::set<T> unionS = s2; // includes all items from s2 already

    typename std::set<T>::iterator itS1;

    // add items from s1 if not found in unionS already
    for (itS1 = s1.begin(); itS1 != s1.end(); ++itS1)
    {
        if (unionS.find(*itS1) == unionS.end()) // not found item in unionS
        {
            unionS.insert(*itS1);
        }
    }
    return unionS;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s);

// Removes any trailing whitespace
std::string &rtrim(std::string &s);

// Removes leading and trailing whitespace
std::string &trim(std::string &s);
#endif
