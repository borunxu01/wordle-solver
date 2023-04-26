#ifndef RECCHECK
// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#endif

#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here
bool isvalid(const std::string word, const std::set<std::string>& dict);
bool checkfloating(std::string in, const std::string& floating);
std::set<std::string> simplify_dict(const std::set<std::string>& dict, const std::string& floating, int& len);


// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{


    int len = in.size();
    std::set<std::string> result;
    std::set<std::string> simplified = simplify_dict(dict, floating, len);

    std::set<std::string>::iterator it;
    for (it = simplified.begin(); it != simplified.end(); ++it)
    {
        bool match = true;
        std::string word = *it;
        for (int i = 0; i < len; i++) 
        {
            if (in[i] != '-' && in[i] != word[i]) 
            {
                match = false;
                break;
            }
        }
        if (match) 
        {
            result.insert(word);
        }
    }

    return result;

}

//helper functions here
bool isvalid(const std::string word, const std::set<std::string>& dict)
{
    return dict.find(word) != dict.end();
}

bool checkfloating(std::string in, const std::string& floating)
{
    if (floating == "")
    {
        return 1;
    }
    int found = 0;
    int len = floating.size();
    for (int i = 0; i < len; i++)
    {
        char c = floating[i];
        if (in.find(c) != string::npos)
        {
            found ++;
            in[in.find(c)] = '-';
        }
        else
        {
            ;
        }
    }

    return (found == len);

}

std::set<std::string> simplify_dict(const std::set<std::string>& dict, const std::string& floating, int& len)
{
    std::set<std::string> simplified;
    std::set<std::string>::iterator it;
		for (it = dict.begin(); it != dict.end(); it++)
		{
			if (it->size() == len)
			{
                std::string word = *it;
                if (len == 2)
                {
                    if (isupper(word[0]) || isupper(word[1]))
                    {
                        continue;
                    }
                }

				if (checkfloating(word, floating))
				{
					simplified.insert(word);
				}
			}
		}
		return simplified;
}