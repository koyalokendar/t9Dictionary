#include<bits/stdc++.h>
#include<fstream>
using namespace std;
const int size = 10;
int calc(string s);
struct TrieNode
{
    struct TrieNode *children[size];
    bool isEndOfWord;
    priority_queue<string>s;
    //string res;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < size; i++)
        pNode->children[i] = NULL;

    return pNode;
}

void insert(struct TrieNode *root, string key,string word)
{
    struct TrieNode *pCrawl = root;
    int i;
    for ( i = 0; i < key.length() /*&& key[i]!='('*/; i++)
    {
        int index = key[i] - 48;
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
    pCrawl->s.push(word);
    //int n=key.length();
    //pCrawl->res=key.substr(i,n-i);
}
vector<string> search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    vector<string>str;
	str.push_back("no");str.push_back("word");str.push_back("possible");
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i]-48;
        if (!pCrawl->children[index])
            return str;

        pCrawl = pCrawl->children[index];
    }

    if(pCrawl != NULL && pCrawl->isEndOfWord)
	{
		vector<string>output;
		priority_queue<string>q=pCrawl->s;
		while(!q.empty())
		{
			output.push_back(q.top());
			q.pop();
		}
		return output;
	}
	else
	  return str;
}
string getlower(string s)
{
	for(int i=0;i<s.length();i++)
	{
		s[i]=tolower(s[i]);
	}
	return s;
}
string changetocode(string words)
{
	map<char,char>mp;
	mp['a']='2';mp['b']='2';mp['c']='2';mp['d']='3';mp['e']='3';mp['f']='3';mp['g']='4';mp['h']='4';mp['i']='4';mp['j']='5';mp['k']='5';mp['l']='5';mp['m']='6';mp['n']='6';mp['o']='6';
	mp['p']='7';mp['q']='7';mp['r']='7';mp['s']='7';mp['t']='8';mp['u']='8';mp['v']='8';mp['w']='9';mp['x']='9';mp['y']='9';mp['z']='9';
	string res="";
	for(int i=0;i<words.length();i++)
	{
		res=res+mp[words[i]];
	}
	return res;
}
int main()
{
    struct TrieNode *root = getNode();
    char words[20];
	FILE *inf = fopen("dictionary.txt", "r");
	int i=0;
	while (!feof(inf) && i<100000)
	{
		fgets(words, 30 , inf);
		//cout<<words;
		words[strlen(words) - 1] = '\0';
		string res=changetocode(words);
		insert(root,res, words);
		i++;
	}
	string s;
	cin>>s;
    vector<string>output=search(root,s);
    for(int i=0;i<output.size();i++)
    {
    	cout<<output[i]<<endl;
	}
    return 0;
}
