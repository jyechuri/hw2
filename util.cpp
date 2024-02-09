#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/

/*
    keyword to be any string of 2 or more characters. If such a word has
    punctuation it should be split at each punctuation character and the
    resulting substrings (of 2 or more characters) should be used as keywords.
    EXAMPLES:
        Men's should yield just a keyword of Men
        J. would not yield any keyword since the remaining substring J is only 1 character
        I'll would yield just ll since that substring is 2 or more characters
*/
std::set<std::string> parseStringToWords(string rawWords)
{
    
    std::set<std::string> allWordS; // set filled with all the word

    std::string lowerCase = convToLower(rawWords); // CHECK THIS if needed

    //trim(lowerCase); // remove extra space at from and back

    // read input from associates string
    stringstream inSS(lowerCase);
    std::string keyWord = "";
    while (inSS >> keyWord)
    {
        int punct = 0;
        for (int i = 0; i < keyWord.size(); i++)
        {
            if (ispunct(keyWord[i])) // ispunct(keyWord[i]) || isspace(keyWord[i])
            {
                std::string newSub = keyWord.substr(punct, i - punct);
                punct = i + 1;
                if (newSub.size() > 1)
                {
                    allWordS.insert(newSub);
                }
            }
        }
        std::string anotherSub = keyWord.substr(punct, keyWord.size());
        if (anotherSub.size() > 1)
        {
            allWordS.insert(anotherSub);
        }
    }
    return allWordS;
    /*
    set<string> allWordS; // set filled with all the word

    string lowerCase = convToLower(rawWords); // CHECK THIS if needed

    trim(lowerCase); // remove extra space at from and back

    // read input from associates string
    stringstream inSS(lowerCase);

    for (int i = 0; i < lowerCase.size(); ++i)
    {
        // replace punctuations with spaces
        if (ispunct(lowerCase[i]))
        {
            lowerCase[i] = ' ';
        }
    }
    string keyWord = "";
    // read each word one at a time
    while (inSS >> keyWord)
    {
        // make sure size is greater than 1
        if (keyWord.size() > 1)
        {
            allWordS.insert(keyWord);
        }
    }
    return allWordS;*/
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s)
{
    s.erase(s.begin(),
            std::find_if(s.begin(),
                         s.end(),
                         std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s)
{
    s.erase(
        std::find_if(s.rbegin(),
                     s.rend(),
                     std::not1(std::ptr_fun<int, int>(std::isspace)))
            .base(),
        s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s)
{
    return ltrim(rtrim(s));
}