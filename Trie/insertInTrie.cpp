//                  insertInTrie.cpp

#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode *Arr[26];
    bool isEndOfWord;
};

struct TrieNode *getNode(){
    struct TrieNode *newNode = new TrieNode();
    newNode->isEndOfWord = false;
    for(int i = 0 ; i < 26 ; i++){
        newNode->Arr[i] = NULL;
    }
    return newNode;
}

void insert(struct TrieNode *root , string key){
    struct TrieNode *cur = root;
    for(int i = 0 ; i < key.size() ; i++){
        if(cur->Arr[key[i]-'a'] == NULL){
            struct TrieNode *newN = new TrieNode();
            cur->Arr[key[i]-'a'] = newN;
            cur = newN;
        }
        else{
            cur = cur->Arr[key[i]-'a'];
        }
    }
    cur->isEndOfWord = true;
}

bool searchKey(struct TrieNode* root , string key){
    struct TrieNode * cur = root;
    for(int i = 0 ; i < key.size() ; i++){
        if(cur->Arr[key[i]-'a'] == NULL){
            return false;
        }
        else{
            cur = cur->Arr[key[i]-'a'];
        }
    }
    if(cur->isEndOfWord == true){
        return true;
    }
    return false;
}

int main(){
    int i = 0; 
   struct TrieNode *root = getNode();
   vector<string> vec = {"rishi","rex","rishabh","rishikesh","harikesh","raghav"};
   for(i = 0 ; i < vec.size() ; i++){
        insert(root,vec[i]);
   }
   cout<<searchKey(root,"rishi")<<endl;
   cout<<searchKey(root,"rish")<<endl;
   cout<<searchKey(root,"rishabh")<<endl;
   cout<<searchKey(root,"rishab")<<endl;
   cout<<searchKey(root,"rex")<<endl;
   cout<<searchKey(root,"r")<<endl;
   cout<<searchKey(root,"harikesh")<<endl;
   cout<<searchKey(root,"hari")<<endl;
   cout<<searchKey(root,"raghav")<<endl;
   return 0;
}