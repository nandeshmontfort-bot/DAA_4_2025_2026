#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Node {
public:
    int freq;
    char ch;
    Node* left;
    Node* right;
    Node(char character, int f) {
        this->ch = character;
        this->freq = f;
        left = nullptr;
        right = nullptr;
    }
};
struct CompareNodes
{
    bool operator()(Node* a, Node* b)
    {
        return a->freq > b->freq;
    }
};

string getCode(vector<pair<char, string>>& codes, char c) {
    for (int i = 0; i < codes.size(); i++)
    {
        if (codes[i].first == c) {
            return codes[i].second;
        }
    }
    return "";
}

void generateCodes(Node* root, string curr, vector<pair<char, string>>& codes) {
    if (root == nullptr)
    return;
    if (root->left == nullptr && root->right == nullptr)
    {
        if (curr == "")
        {
            codes.push_back(make_pair(root->ch, "0"));
        }
        else
        {
            codes.push_back(make_pair(root->ch, curr));
        }
        return;
    }
    generateCodes(root->left, curr + '0', codes);
    generateCodes(root->right, curr + '1', codes);
}
string decode(Node* root, string encodedStr)
{
    string decodedResult = "";
    Node* curr = root;
    for (char bit : encodedStr)
    {
        if (bit == '0')
            curr = curr->left;
        else
            curr = curr->right;
        if (!curr->left && !curr->right) {
            decodedResult += curr->ch;
            curr = root;
        }
    }
    return decodedResult;
}

void encode(string str, string s, vector<int>& f)
{
    int N = f.size();
    priority_queue<Node*, vector<Node*>, CompareNodes> pq;
    for (int i = 0; i < N; i++)
    pq.push(new Node(s[i], f[i]));
    
    while (pq.size() > 1)
    {
        Node* l = pq.top();
        pq.pop();
        Node* r = pq.top();
        pq.pop();
        Node* newNode = new Node(' ', l->freq + r->freq);
        newNode->left = l;
        newNode->right = r;
        pq.push(newNode);
    }
    Node* root = pq.top();
    vector<pair<char, string>> huffmanCodes;
    generateCodes(root, "", huffmanCodes);
    cout << "\nHuffman Codes" << endl;
    for (int i = 0; i < N; i++)
    {
        string code = getCode(huffmanCodes, s[i]);
        cout << s[i] << " : " << code << endl;
    }
    string encoded = "";
    for (char c : str) {
        encoded += getCode(huffmanCodes, c);
    }

    cout << "\nEncoded String: ";
    cout << encoded << endl;
    string decoded = decode(root, encoded);
    cout << "Decoded String: " << decoded << endl;
}


int main()
{
    string str;
    cout << "Enter the characters in lower case: ";
    cin >> str;
    int count=0;
    vector<int> f;
    int counts[26] = {0};
    string s;
    for(char ch : str)
    {
        counts[ch - 'a']++;
        if(counts[ch - 'a']==1)
        s=s+ch;
    }
    for (char ch : s)
    {
        if(counts[ch-'a']!=0)
        f.push_back(counts[ch - 'a']);
    }
    encode(str, s, f);
}
