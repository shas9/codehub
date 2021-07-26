#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <string_view>
#include <set>
#include <bits/stdc++.h>

using namespace std;

using std::cout;
using std::string;
using svector = std::vector<string>;        // string vector
using ivector = std::vector<std::size_t>;   // index vector
using sview = std::string_view;             // string_view
using iset = std::set<std::size_t>;         // index set



inline bool isSubStringOf(sview str, sview substr){
    return str.find(substr) != string::npos;
}


inline bool startsWith(sview str, sview prefix) {
    return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
}


// prepare alphabet by removing junk
svector prepare(const svector& letters, const string& word)
{
    svector result = letters;

    //remove duplicate strings
    std::sort(result.begin(), result.end());
    result.erase( std::unique( result.begin(), result.end() ),   result.end() );

    for(auto it = result.begin() ; it != result.end(); ) {
        if (it->empty())                    //remove empty strings
            it = result.erase(it);
        else if(!isSubStringOf(word, *it))  //remove strings that don't appear in word
            it = result.erase(it);
        else
            ++it;
    }
    return result;
}


// vector of lengths of letters that prefix str
ivector prefixLengths(sview str, const svector& letters)
{
    ivector result;
    for(auto& prefix : letters)
        if(startsWith(str, prefix))
            result.push_back(prefix.size());

    return result;
}


// return view of string advanced by i chars
sview advanceViewOf(std::size_t i, const string& str)
{
    sview view(str);
    view.remove_prefix(i);
    return view;
}


// return set of indices into word for all prefixes
iset nextIndexSet(const iset& indices, const string& word, const svector& letters)
{
    iset result;
    for(std::size_t i : indices){
        for(std::size_t length : prefixLengths(advanceViewOf(i, word), letters))
            result.insert(i + length);
    }
    return result;
}


const string word = "aab";
const std::size_t wordLength = word.size();
const svector letters = { "a", "ab", "b", "aab"};


int main(int, char**)
{
    svector alphabet = prepare(letters, word);
    iset indices = {0};

    do{
        bool success = indices.find(wordLength) != indices.end();
        if(success){
            cout << "success\n";
            return 0;
        }
        indices = nextIndexSet(indices, word, letters);
    }while(!indices.empty());

    cout << "fail\n";

    return 0;
}
