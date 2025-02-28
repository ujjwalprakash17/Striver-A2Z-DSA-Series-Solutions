#include <bits/stdc++.h>
using namespace std;

// We will need to create a TrieNode for each of the character storage
class TrieNode {
    public : 
    unordered_map<char, TrieNode *> children; // this is to store word and their respective children
    bool is_end_of_word; // flag that will be marked as true at the end of the word

    TrieNode(){
        is_end_of_word = false; // initialise this by default as false
    }
};

class Trie{
    public : 
    // will be needed a root to start with
    TrieNode *root;
    Trie(){
        root = new TrieNode(); // this means we have initialise with TrieNode as false
    }
    // insert function
    void insert(string word){
        TrieNode *node = root;
        for(char c : word)
        {
            // if not found
            if(node->children.find(c) == node->children.end())
            {
                //then will create a new trieNode 
                node->children[c] = new TrieNode();
            }
            // will move the current Trie to the child TrieNode
            node = node->children[c];
        }
    }
    bool search(string word)
    {
        TrieNode *node = root;
        for(char c : word)
        {
            // if a character is not found
            if(node->children.find(c) == node->children.end())
            {
                // return false;
                return false;
            }
            node = node->children[c];
        }
        // whatever the is_end_of_word will be it will be returned either true or false
        return node->is_end_of_word;
    }
    bool starts_with(string word)
    {
        TrieNode *node = root;
        for(char c : word)
        {
            if(node->children.find(c) == node->children.end())
            {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
};

int main() {
    
    return 0;
}