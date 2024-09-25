//                      ImplementationOfTrie.cpp

#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode *Arr[26];
    bool isEndOfWord;
};

struct TrieNode *getNode(){
    struct TrieNode * newNode = new TrieNode();
    newNode->isEndOfWord = false;
    for(int i = 0; i < 26 ; i++){
        newNode->Arr[i] = NULL;
    }
    return newNode;
}

int main(){
   struct TrieNode *root = getNode();
   for(int i = 0 ; i < 26 ;i++){
    cout<<root->Arr[i]<<" ";
   }
   return 0;
}