#include <bits/stdc++.h> 
struct Node {
    Node* links[26];
    bool flag=false;
    bool containsKey(char c) {
        return (links[c-'a']!=NULL);
    }
    Node* nextNode(char c) {
        return links[c-'a'];
    }
    void setKey(char c) {
        links[c-'a']=new Node();
    }
    void setEnd() {
        flag=true;
    }
    bool isEnd() {
        return flag;
    }
};
class Trie {
private:
    Node* node=new Node();
public:
    Trie() {

    }
    void insert(string word) {
        int n=word.size();
        Node* temp=node;
        for (int i=0;i<n;i++) {
            char c=word[i];
            if (!temp->containsKey(c)) {
                temp->setKey(c);
            }
            temp=temp->nextNode(c);
        }
        temp->setEnd();
    }
    bool func(string word) {
        int n=word.size();
        Node* temp=node;
        for (int i=0;i<n;i++) {
            char c=word[i];
            temp=temp->nextNode(c);
            if (!temp->isEnd()) return false;
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    Trie *trie=new Trie();
    for (int i=0;i<n;i++) {
        trie->insert(a[i]);
    }
    string ans;
    for (int i=0;i<n;i++) {
        if (trie->func(a[i])) {
            if (a[i].size()>ans.size()) {
                ans=a[i];
            }
            else if (a[i].size()==ans.size()) {
                if (a[i]<ans) ans=a[i];
            }
        }
    }
    if (ans.size()==0) return "None";
    return ans;
}
