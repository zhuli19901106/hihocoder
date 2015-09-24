// A practice on Trie
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 26;

typedef struct TrieNode {
    int c;
    TrieNode *p[N];
    
    TrieNode(int _c = 0) {
        c = _c;
        memset(p, 0, sizeof(p));
    }
} TrieNode;

void insertWord(TrieNode *r, char s[])
{
    int n = strlen(s);
    if (n == 0) {
        return;
    }
    
    TrieNode *p = r;
    ++p->c;
    int i;
    for (i = 0; i < n; ++i) {
        if (p->p[s[i] - 'a'] == NULL) {
            p->p[s[i] - 'a'] = new TrieNode();
        }
        p = p->p[s[i] - 'a'];
        ++p->c;
    }
}

int countWord(TrieNode *r, char s[])
{
    int n = strlen(s);
    TrieNode *p = r;
    int i;
    
    for (i = 0; i < n; ++i) {
        p = p->p[s[i] - 'a'];
        if (p == NULL) {
            return 0;
        }
    }
    return p->c;
}

int main()
{
    int n;
    TrieNode *r = new TrieNode();
    char s[100];
    
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%s", s);
        insertWord(r, s);
    }
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%s", s);
        printf("%d\n", countWord(r, s));
    }
    
    return 0;
}