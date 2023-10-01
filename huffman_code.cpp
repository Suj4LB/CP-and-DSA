//Huffman coding to assign bits to a given distribution of variables with their probabilities provided
#include <bits/stdc++.h>
using namespace std;

struct HuffmanNode {
    char data;
    float probability;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
};

typedef struct HuffmanNode HuffmanNode;

HuffmanNode* newNode(char data, float probability) {
    HuffmanNode* node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    node->data = data;
    node->probability = probability;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printHuffmanCodes(HuffmanNode* root, char* code, int top) {
    if (root->left) {
        code[top] = '0';
        printHuffmanCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = '1';
        printHuffmanCodes(root->right, code, top + 1);
    }
    if (!(root->left) && !(root->right)) {
        code[top] = '\0';
        printf("%c: %s\n", root->data, code);
    }
}

void huffmanCodes(char data[], float probability[], int n) {
    HuffmanNode* nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = newNode(data[i], probability[i]);
    }

    while (n > 1) {
        int min1 = 0, min2 = 1;
        if (nodes[min1]->probability > nodes[min2]->probability) {
            int temp = min1;
            min1 = min2;
            min2 = temp;
        }

        for (int i = 2; i < n; i++) {
            if (nodes[i]->probability < nodes[min1]->probability) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->probability < nodes[min2]->probability) {
                min2 = i;
            }
        }

        HuffmanNode* left = nodes[min1];
        HuffmanNode* right = nodes[min2];
        HuffmanNode* parent = newNode('$', left->probability + right->probability);
        parent->left = left;
        parent->right = right;

        nodes[min1] = parent;
        nodes[min2] = nodes[n - 1];
        n--;
    }

    char code[n];
    printHuffmanCodes(nodes[0], code, 0);
}

int main(void) 
{
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    float probability[] = {0.01, 0.09, 0.1, 0.05, 0.15, 0.1, 0.2, 0.02, 0.08, 0.2};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Huffman Codes:\n");
    huffmanCodes(data, probability, n);

    return 0;
}
