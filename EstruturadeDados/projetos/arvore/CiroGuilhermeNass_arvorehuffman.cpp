#include <iostream>
#include <queue>
#include <unordered_map> // É uma estrutura de dados que armazena pares chave-valor, onde as chaves são únicas e mapeadas para valores
#include <fstream> // Monta os arquivos de entrada e saida
using namespace std;

// Estrutura do nó da árvore de Huffman
struct Node {
    char data; // Caractere armazenado no nó
    unsigned freq; // Frequência do caractere
    Node *left, *right; // Ponteiros para os filhos esquerdo e direito do nó
};

// Função para criar um novo nó da árvore de Huffman
Node* createNode(char data, unsigned freq, Node* left, Node* right) {
    Node* node = new Node();
    node->data = data;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

// Estrutura de comparação para a fila de prioridade na construção da árvore
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq; // Comparação de frequência para a fila de prioridade
    }
};

// Função para imprimir a representação da árvore de Huffman
void printHCodes(Node* root, string str, ofstream &outfile) {
    if (!root) // Caso o ponteiro for nulo
        return;

    // Se é um nó folha
    if (root->left == nullptr && root->right == nullptr) {
        outfile << root->data << "(" << root->freq << ")"; // Imprime caractere e sua frequência
        return;
    }

    // Se é um nó intermediário
    outfile << root->freq << ":"; // Imprime a frequência do nó intermediário
    printHCodes(root->left, str + "0", outfile); // Percorre à esquerda (0) na árvore
    outfile << ":";
    printHCodes(root->right, str + "1", outfile); // Percorre à direita (1) na árvore
}

// Função para construir a árvore de Huffman
void buildHuffmanTree(string textFile, string outputFile) {
    ifstream infile(textFile);

    unordered_map<char, unsigned> freq; // Mapa para armazenar a frequência de cada caractere
    char ch;
    while (infile >> noskipws >> ch) { // lê o infile sem pular espaços e armazena em ch
        freq[ch]++; // Contagem da frequência de cada caractere no arquivo de entrada
    }                   //Se o caractere ainda não estiver presente no mapa, ele é inserido com um valor inicial de 1.
                        //Se o caractere já estiver presente no mapa, o valor correspondente é incrementado em 1 para aumentar a contagem de frequência desse caractere.
    infile.close();

    // Fila de prioridade para construir a árvore de Huffman
    priority_queue<Node*, vector<Node*>, compare> pq;
    for (auto pair : freq) { // Auto pair é uma forma de iterar sobre todos os pares chave-valor
        pq.push(createNode(pair.first, pair.second, nullptr, nullptr)); // Cria um nó para cada caractere com sua frequência
                                                                            // Pair.first = caractere (chave)
                                                                            // Pair.second = frequência (valor)
                                                                            // Ponteiros esquerdo e direito iniciam como nullptr
    }                                                                       

    ofstream outfile(outputFile); // Abre o arquivo de saída

    // Loop para construir a árvore de Huffman
    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop(); // Recebe o nó com o .top de menor frequência da fila de prioridade e o remove
        Node *right = pq.top(); pq.pop(); // Recebe o próximo nó com o .top de menor frequência da fila de prioridade e o remove

        unsigned sum = left->freq + right->freq; // Soma das frequências dos dois nós
        Node* newNode = createNode('$', sum, left, right); // Cria um nó pai com a soma das frequências
                                                           // O $ é apenas uma representação para um nó intermediário
        pq.push(newNode); // Adiciona o novo nó à fila de prioridade

        // Imprime o passo da construção da árvore no arquivo de saída
        printHCodes(newNode, "", outfile); 
        outfile << endl;
    }

    Node* root = pq.top(); // Obtém a raiz da árvore de Huffman
    printHCodes(root, "", outfile); // Imprime a árvore final no arquivo de saída

    outfile.close(); // Fecha o arquivo de saída
}
// Função que percorre a arvore e atribui códigos aos caracteres
void encodeData(Node* root, string &currentCode, unordered_map<char, string> &huffmanCodes) {
    if (root == nullptr) { // Caso nulo
        return;
    }

    // Se for um nó folha, armazena o código Huffman atual no mapa
    if (root->left == nullptr && root->right == nullptr) {
        huffmanCodes[root->data] = currentCode;
    }

    // Percorre à esquerda adicionando 0
    currentCode.push_back('0');
    encodeData(root->left, currentCode, huffmanCodes);
    currentCode.pop_back(); // Remove o último caractere

    // Percorre à direita adicionando 1
    currentCode.push_back('1');
    encodeData(root->right, currentCode, huffmanCodes);
    currentCode.pop_back(); // Remove o último caractere
}

// Função que vai contruir a arvore ja com os caracteres compactados
void compressFile(string inputFile, string outputFile) { //controi a arvore com os bits comprimidos
    ifstream infile(inputFile);

    unordered_map<char, unsigned> freq; // Mapa para armazenar a frequência de cada caractere
    char ch;
    while (infile >> noskipws >> ch) { // lê o infile sem pular espaços e armazena em ch
        freq[ch]++; // Contagem da frequência de cada caractere no arquivo de entrada
    }                   //Se o caractere ainda não estiver presente no mapa, ele é inserido com um valor inicial de 1.
                        //Se o caractere já estiver presente no mapa, o valor correspondente é incrementado em 1 para aumentar a contagem de frequência desse caractere.
    infile.close();

    // Fila de prioridade para construir a árvore de Huffman
    priority_queue<Node*, vector<Node*>, compare> pq;
    for (auto pair : freq) { // Auto pair é uma forma de iterar sobre todos os pares chave-valor
        pq.push(createNode(pair.first, pair.second, nullptr, nullptr)); // Cria um nó para cada caractere com sua frequência
                                                                            // Pair.first = caractere (chave)
                                                                            // Pair.second = frequência (valor)
                                                                            // Ponteiros esquerdo e direito iniciam como nullptr
    }                                                                       

    ofstream outfile(outputFile); // Abre o arquivo de saída

    // Loop para construir a árvore de Huffman
    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop(); // Recebe o nó com o .top de menor frequência da fila de prioridade e o remove
        Node *right = pq.top(); pq.pop(); // Recebe o próximo nó com o .top de menor frequência da fila de prioridade e o remove

        unsigned sum = left->freq + right->freq; // Soma das frequências dos dois nós
        Node* newNode = createNode('$', sum, left, right); // Cria um nó pai com a soma das frequências
                                                           // O $ é apenas uma representação para um nó intermediário
        pq.push(newNode); // Adiciona o novo nó à fila de prioridade

        // Imprime o passo da construção da árvore no arquivo de saída
        printHCodes(newNode, "", outfile); 
        outfile << endl;
    }

    Node* root = pq.top(); // Obtém a raiz da árvore de Huffman
    printHCodes(root, "", outfile); // Imprime a árvore final no arquivo de saída

    unordered_map<char, string> huffmanCodes;
    string currentCode;
    encodeData(root, currentCode, huffmanCodes);

    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    while (inFile.get(ch)) {
        // Escreve os códigos Huffman correspondentes no arquivo de saída
        outFile << huffmanCodes[ch];
    }

    inFile.close();
    outFile.close();
}

// Função principal do programa
int main(int argc, char *argv[]) { // argc = o número de argumentos passados na linha de comando e argv = é um array de strings que contém os argumentos passados na linha de comando
    if (argc != 3) {
        cout << "Uso: " << argv[0] << " e arquivo_entrada.txt arquivo_saida.txt" << endl;
        return 1;
    }

    string inputFile = argv[1]; // Nome do arquivo de entrada
    string outputFile = argv[2]; // Nome do arquivo de saída

    buildHuffmanTree(inputFile, outputFile); // Chama a função para construir a árvore de Huffman

    cout << "Construcao da arvore de Huffman concluida e gravada em " << outputFile << endl; // Mensagem de conclusão

    return 0;
}
