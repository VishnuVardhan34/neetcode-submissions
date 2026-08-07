class LRUCache {
private:
    struct Node {
        int key, value;
        Node *prev, *next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;
    unordered_map<int, Node*> mp;

    Node *head, *tail;

    // Remove a node from the list
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert node right after head (Most Recently Used)
    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        // Dummy head and tail nodes
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // Move accessed node to front
        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];
            node->value = value;

            remove(node);
            insert(node);
            return;
        }

        // New node
        Node* node = new Node(key, value);

        mp[key] = node;
        insert(node);

        // Capacity exceeded
        if (mp.size() > capacity) {

            Node* lru = tail->prev;

            remove(lru);

            mp.erase(lru->key);

            delete lru;
        }
    }
};