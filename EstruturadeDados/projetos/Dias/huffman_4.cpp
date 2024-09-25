#include <iostream>
#include <queue>
#include <unordered_map>
#include <fstream>
using namespace std;

// A Tree node
struct Node
{
    char ch;
    int freq;
    Node *left, *right;
};

Node *getNode(char ch, int freq, Node *left, Node *right)
{
    Node *node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

struct comp
{
    bool operator()(Node *l, Node *r)
    {
        return l->freq > r->freq;
    }
};

void encode(Node *root, string str, unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr)
        return;

    if (!root->left && !root->right)
    {
        huffmanCode[root->ch] = str;
        return;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void decode(Node *root, int &index, string str)
{
    if (root == nullptr)
    {
        return;
    }

    if (!root->left && !root->right)
    {
        cout << root->ch;
        return;
    }

    index++;

    if (str[index] == '0')
        decode(root->left, index, str);
    else
        decode(root->right, index, str);
}

struct TreeStep
{
    int stepNumber;
    string treeRepresentation;
};

string readFromFileAndBuildFrequencyMap(const string &filename, unordered_map<char, int> &freq)
{
    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        cerr << "Erro ao abrir o arquivo: " << filename << endl;
        exit(1);
    }

    string text;
    char ch;
    while (inputFile.get(ch))
    {
        text += ch;
        freq[ch]++;
    }

    inputFile.close();
    return text;
}

void writeTreeStepsToFile(const string &filename, const vector<TreeStep> &steps)
{
    ofstream outputFile(filename);

    if (!outputFile.is_open())
    {
        cerr << "Erro ao abrir o arquivo: " << filename << endl;
        exit(1);
    }

    for (const auto &step : steps)
    {
        outputFile << "Passo " << step.stepNumber << ":\n";
        outputFile << step.treeRepresentation << "\n\n";
    }

    outputFile.close();
}

void printHCodes(Node *root, string str, ofstream &outfile)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        outfile << root->ch << "(" << root->freq << ")";
        return;
    }

    outfile << root->freq << ":";
    printHCodes(root->left, str + "0", outfile);
    outfile << ":";
    printHCodes(root->right, str + "1", outfile);
}

void buildHuffmanTreeFromFile(const string &filename, const string &outputTreeFilename)
{
    unordered_map<char, int> freq;
    string text = readFromFileAndBuildFrequencyMap(filename, freq);

    priority_queue<Node *, vector<Node *>, comp> pq;
    vector<TreeStep> treeSteps;

    int stepNumber = 1;

    for (auto pair : freq)
    {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    ofstream outfile(outputTreeFilename);

    while (pq.size() != 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        int sum = left->freq + right->freq;
        Node *newNode = getNode('$', sum, left, right);

        pq.push(newNode);

        // Adaptação para imprimir passo a passo no arquivo de saída
        outfile << "Passo " << stepNumber++ << ":\n";
        printHCodes(newNode, "", outfile);
        outfile << "\n\n";

        TreeStep step;
        step.stepNumber = stepNumber++;
        step.treeRepresentation = "Parent (Freq=" + to_string(sum) + ") <- Left (Freq=" + to_string(left->freq) + ") | Right (Freq=" + to_string(right->freq) + ")";
        treeSteps.push_back(step);
    }

    outfile.close();

    Node *root = pq.top();

    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cerr << "Uso: " << argv[0] << " <input_file> <output_tree_file>\n";
        return 1;
    }

    string inputFilename = argv[1];
    string outputTreeFilename = argv[2];

    buildHuffmanTreeFromFile(inputFilename, outputTreeFilename);

    return 0;
}
