#include <iostream>

struct ListItem {
    int value;
    ListItem *next;
};

class List  {
private:
    ListItem *head = nullptr;
    ListItem *tail = nullptr;


public:


    [[nodiscard]] bool isEmpty() const { return head == nullptr; }
    [[nodiscard]] int size() const {
        const ListItem *current = head;
        int size = 1;
        while (current->next != nullptr) {
            current = current->next;
            size++;
        }
        return size;
    }
    void append(const int value) {
        auto *node = new ListItem;
        node->value = value;
        node->next = nullptr;

        if (isEmpty()) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    void insert(const int value) {
        auto *node = new ListItem;
        node->value = value;
        node->next = head;
        if (isEmpty()) {
            head = node;
            tail = node;
        }
        else {
            node->next = head;
            head = node;
        }
    }

    void print() const {
        ListItem *current = head;
        std::cout << "Head -> ";
        while (current != nullptr) {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }

    int operator[](int index) const {
        ListItem *current = head;

        if (index > size()-1 || index < 0) {
            throw std::out_of_range("Index is out of range");
        }
        try {
            int i = 0;
            while (i < index) {
                current = current->next;
                i++;
            }
            return current->value;
        }
        catch (...){
            throw std::out_of_range("Index is out of range");
        }
    }

    ~List() {
        const ListItem *current = head;
        while (current != nullptr) {
            ListItem *next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    List list;
    std::cout << "Is empty: " << list.isEmpty() << "\n";

    list.append(10);
    list.append(20);
    list.append(30);

    list.print();
    std::cout << "Is empty: " << list.isEmpty() << "\n";
    std::cout << "Size:" << list.size() << "\n";

    list.insert(40);
    list.print();
    std::cout << "Size:" << list.size() << "\n";

    std::cout << "Element of list[0]: " << list[0] << "\n";
    std::cout << "Element of list[1]: " << list[1] << "\n";
    std::cout << "Element of list[2]: " << list[2] << "\n";
    std::cout << "Element of list[3]: " << list[3] << "\n";
    return 0;
}