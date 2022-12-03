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
    bool search(string word) {
        int n=word.size();
        Node* temp=node;
        for (int i=0;i<n;i++) {
            char c=word[i];
            if (!temp->containsKey(c)) {
                return false;
            }
            temp=temp->nextNode(c);
        }
        return (temp->isEnd());
    }
    bool startsWith(string prefix) {
        int n=prefix.size();
        Node* temp=node;
        for (int i=0;i<n;i++) {
            char c=prefix[i];
            if (!temp->containsKey(c)) {
                return false;
            }
            temp=temp->nextNode(c);
        }
        return true;
    }
};
