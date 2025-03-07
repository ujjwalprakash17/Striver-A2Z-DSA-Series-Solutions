#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    int wordCnt;
    TrieNode()
    {
        wordCnt = 0;
    }
};

class Trie
{
private:
    int countWordFromLastChar(TrieNode *node)
    {
        if (!node)
            return 0;
        int cnt = node->wordCnt;
        for (auto &child : node->children)
        {
            cnt += countWordFromLastChar(child.second);
        }
        return cnt;
    }

    bool eraseHelper(string &word, TrieNode *node, int depth)
    {
        if (depth == word.size())
        {
            if (node->wordCnt > 0)
            {
                node->wordCnt--;
                return node->children.empty() && node->wordCnt == 0;
            }
            return false;
        }

        char c = word[depth];
        //if a character not found
        if (node->children.find(c) == node->children.end())
        {
            return false;
        }

        bool shouldDeleteCurrentNode = eraseHelper(word, node->children[c], depth + 1);

        if (shouldDeleteCurrentNode)
        {
            delete node->children[c];
            node->children.erase(c);
            return node->children.empty() && node->wordCnt == 0;
        }
        return false;
    }

public:
    TrieNode *root;

    Trie()
    {
        // Write your code here.
        root = new TrieNode();
    }

    void insert(string &word)
    {
        // Write your code here.
        TrieNode *node = root;
        for (char c : word)
        {
            if (node->children.find(c) == node->children.end())
            {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->wordCnt++;
    }

    int countWordsEqualTo(string &word)
    {
        // Write your code here.
        int ans = 0;
        TrieNode *node = root;
        for (char c : word)
        {
            if (node->children.find(c) == node->children.end())
            {
                return 0;
            }
            node = node->children[c];
        }
        return node->wordCnt;
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        int ans = 0;
        TrieNode *node = root;
        for (char c : word)
        {
            if (node->children.find(c) == node->children.end())
            {
                return 0;
            }
            node = node->children[c];
        }
        ans = countWordFromLastChar(node);
    }

    void erase(string &word)
    {
        // Write your code here.
        eraseHelper(word, root, 0);
    }
};

int main()
{

    return 0;
}