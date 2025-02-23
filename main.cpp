#include <iostream>

struct ListItem {
    int value;
    ListItem *next;
};

class List {
private:
    ListItem *head = nullptr;
    ListItem *tail = nullptr;

public:
    [[nodiscard]] bool isEmpty() const { return head == nullptr; }

    void append(int value) {
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
    void insert(int value) {
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


    void print_all() {
        ListItem *current = head;
        while (current != nullptr) {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
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
    std::cout<<std::to_string(list.isEmpty());
    list.append(10);
    list.append(20);
    list.append(30);

    list.print_all();

    list.insert(40);
    std::cout<<std::to_string(list.isEmpty());
    list.print_all();

    return 0;
}