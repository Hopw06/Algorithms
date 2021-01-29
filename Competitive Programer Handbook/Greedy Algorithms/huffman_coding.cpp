#include<iostream>
using namespace std;

struct _node {
    int freq;
    char character;
    struct _node* left;
    struct _node* right;
};
typedef struct _node Node;

int n;
char s[1000];

// using heap to build huffman tree
Node* heap[1000];
int szHeap = 1;

void swap(int i, int j)
{
    Node* tmp = heap[i];
    heap[i] = heap[j];
    heap[j] = tmp;
}

void upHeap(int p)
{
    int i = p / 2;
    while(i > 0)
    {
        if(heap[p]->freq < heap[i]->freq)
        {
            swap(p, i);
            p = i;
            i = i / 2;
        }
        else
        {
            break;
        }
    }
}

void downHeap(int p)
{
    while(2*p < szHeap)
    {
        int min = p;
        int left = 2*p;
        int right = 2*p + 1;
        if (left < szHeap && heap[left]->freq < heap[min]->freq)
        {
            min = left;
        }
        if (right < szHeap && heap[right]->freq < heap[min]->freq)
        {
            min = right;
        }
        if(min != p)
        {
            swap(p, min);
            p = min;
        }
        else
        {
            break;
        }
    }
}

Node* getMinHeap()
{
    swap(1, szHeap - 1);
    szHeap = szHeap - 1;
    downHeap(1);
    return heap[szHeap];
}

char bits[100];
int b = 0;

void printHuffmanCode(Node* huffmanTree)
{
    if(huffmanTree->left == NULL && huffmanTree->right == NULL)
    {
        bits[b++] = 0;
        cout << huffmanTree->character << ": " <<  bits << endl;
        b--;
        return;
    }
    bits[b++] = '0';
    printHuffmanCode(huffmanTree->left);
    b--;

    bits[b++] = '1';
    printHuffmanCode(huffmanTree->right);
    b--;
}

int main()
{
    cin >> n >> s;
    int freqs[26];
    for(int i = 0; i < 26; i++)
    {
        freqs[i] = 0;
    }
    for(int i = 0; i < n; i++)
    {
        freqs[s[i] - 65] ++;
    }
    for(int i = 0; i < 26; i++)
    {
        if(freqs[i] != 0)
        {
            heap[szHeap] = new Node;
            heap[szHeap]->freq = freqs[i];
            heap[szHeap]->character = (char) (i + 65);
            upHeap(szHeap);
            szHeap++;
        }
    }
    while(szHeap > 2)
    {
        Node* min1 = getMinHeap();
        Node* min2 = getMinHeap();
        Node* newNode = NULL;
        newNode = new Node;
        newNode->freq = min1->freq + min2->freq;
        newNode->left = min1;
        newNode->right = min2;
        heap[szHeap] = newNode;
        upHeap(szHeap);
        szHeap++;
    }
    printHuffmanCode(heap[1]);
    return 0;
}