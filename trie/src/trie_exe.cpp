#include "trie.h"

int main(int args, const char *argv[])
{
    Trie tr;
    tr.insert("jam");
    tr.insert("rental");
    tr.insert("beer");
    std::cout<<tr.search("jan")<<std::endl;
    std::cout<<tr.search("rent")<<std::endl;
}