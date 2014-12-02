#include <iostream>
#include <string>

using namespace std;

class trieNode
{
    public:
        trieNode() : terminable(0), nodeSize(0) { for(int i = 0; i < 26; ++i) children[i] = NULL; }
        ~trieNode()
        {
            for(int i = 0; i < 26; ++i)
            {
                delete children[i];
                children[i] = NULL;
            }
        }
    public:
        bool terminable;         //存储以此结点为结尾的字串的个数
        int nodeSize;                //记录此结点孩子的个数
        trieNode* children[26];    //该数组记录指向孩子的指针
};


class trie
{
    public:
        typedef trieNode Node;
        typedef trieNode* pNode;
        trie() : root(new Node) {}

        //template<class Iterator>
        void insert(string str)
        {
            int pos = 0;
            pNode cur = root; //当前节点设置为根节点
            while(str[pos]!='\0')
            {
                if (!cur->children[str[pos]%26]) //若当前字符找不到匹配，则新建节点
                {
                    cur->children[str[pos]%26] = new Node; 
                }
                //当前节点的子节点数加一
                ++cur->nodeSize;
                cur = cur->children[str[pos]%26]; //将当前节点设置为当前字符对应的子节点
                
                ++pos;
            }
            cur->terminable = true; //设置存放最后一个字符的节点的可终止标志为真
        };

        //template<class Iterator>
        int find(string str)
        {
            int pos = 0;
            pNode cur = root; //当前节点设置为根节点
            while(str[pos]!='\0')
            {
                if (cur->children[str[pos]%26])
                {
                    cur = cur->children[str[pos]%26];
                }
                else
                    return 0;
                 //将当前节点设置为当前字符对应的子节点
                ++pos;
            }
            return cur->nodeSize;

        };

    public:
        pNode root;
};



int main(int argc, char const *argv[])
{
    /* code */


    trie t;

    // int n,l;
    
    // cin >> n;
    // while(n--){
    //     string sn;
    //     cin >> sn;
    //     t.insert(sn);
    // }
    // cin >> l;
    // while(l--){
    //     string sl;
    //     cin >> sl;
    //     cout << t.find(sl) << endl;
    // }

    string a1 = "babaab";
    string a2 = "babbbaaaa";
    string a3 = "abba";
    string a4 = "aaaaabaa";
    string a5 = "babaababb";
    string a6 = "abbaababb";
    string a7 = "bbbaababb";


    t.insert(a1);
    t.insert(a2);
    t.insert(a3);
    t.insert(a4);
    t.insert(a5);
    t.insert(a6);
    t.insert(a7);

    string b1 = "babb";
    cout << t.find(b1) << endl;
    printf("%d\n",t.find("babaab"));
    //printf("%d\n", t.root->nodeSize);
    printf("%d\n", t.find("bab"));
    printf("%d\n",t.find("bb"));
    printf("%d\n",t.find("bbabbaab"));
    printf("%d\n",t.find("ab"));
    printf("%d\n",t.find("aaaaa"));


    return 0;
}