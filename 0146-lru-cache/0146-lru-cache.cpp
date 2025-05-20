#include <unordered_map>
using namespace std;

class LRUCache {
private:
    class Node {
        public: 
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node* head; // dummy head
    Node* tail; // dummy tail

    // helper to remove node
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // helper to insert at front (after head)
    void insertFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0); // dummy head
        tail = new Node(0, 0); // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);         // remove from current position
            insertFront(node);    // move to front
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // key exists: update + move to front
            Node* node = cache[key];
            node->value = value;
            remove(node);
            insertFront(node);
        } else {
            // key doesn't exist: insert new
            if (cache.size() == capacity) {
                // remove least recently used (back of list)
                Node* lru = tail->prev;
                remove(lru);
                cache.erase(lru->key);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            insertFront(newNode);
            cache[key] = newNode;
        }
    }
};
