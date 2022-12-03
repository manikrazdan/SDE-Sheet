#include <bits/stdc++.h> 
struct Node {
    Node* links[26];
    int cntPrefix=0;
    int cntEnd=0;
    bool containsKey(char c) {
        return (links[c-'a']!=NULL);
    }
    Node* nextNode(char c) {
        return links[c-'a'];
    }
    void setKey(char c) {
        links[c-'a']=new Node();
    }
    void incPrefix() {
        cntPrefix++;
    }
    void incEnd() {
        cntEnd++;
    }
    void decPrefix() {
        cntPrefix--;
    }
    void decEnd() {
        cntEnd--;
    }
    int prefix() {
        return cntPrefix;
    }
    int end() {
        return cntEnd;
    }
};
class Trie{
private:
    Node* node=new Node();
public:
    Trie(){
        
    }
    void insert(string &word){
        int n=word.size();
        Node* temp=node;
        for (int i=0;i<n;i++) {
            char c=word[i];
            if (!temp->containsKey(c)) {
                temp->setKey(c);
            }
            temp=temp->nextNode(c);
            temp->incPrefix();
        }
        temp->incEnd();
    }
    int countWordsEqualTo(string &word){
        int n=word.size();
        Node* temp=node;
        for (int i=0;i<n;i++) {
            char c=word[i];
            if (!temp->containsKey(c)) {
                return 0;
            }
            temp=temp->nextNode(c);
        }
        return (temp->end());
    }
    int countWordsStartingWith(string &word){
        int n=word.size();
        Node* temp=node;
        for (int i=0;i<n;i++) {
            char c=word[i];
            if (!temp->containsKey(c)) {
                return 0;
            }
            temp=temp->nextNode(c);
        }
        return temp->prefix();
    }
    void erase(string &word){
        int n=word.size();
        Node* temp=node;
        for (int i=0;i<n;i++) {
            char c=word[i];
            temp=temp->nextNode(c);
            temp->decPrefix();
        }
        temp->decEnd();
    }
};
