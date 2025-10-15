#include <iostream>
#include <string>
using namespace std;

struct OrderItem {
    string item_name;
    int quantity;
    OrderItem* next;
    OrderItem(const string& name, int qty): item_name(name), quantity(qty), next(nullptr) {}
};

struct Order {
    int order_id;
    OrderItem* items_head;
    Order* next;
    Order(int id): order_id(id), items_head(nullptr), next(nullptr) {}
    void add_item(const string& name, int qty) {
        OrderItem* new_item = new OrderItem(name, qty);
        if (!items_head) items_head = new_item;
        else {
            OrderItem* temp = items_head;
            while (temp->next) temp = temp->next;
            temp->next = new_item;
        }
    }
    ~Order() {
        while (items_head) {
            OrderItem* temp = items_head;
            items_head = items_head->next;
            delete temp;
        }
    }
};

class OrderQueue {
private:
    Order* front;
    Order* end;
public:
    OrderQueue(): front(nullptr), end(nullptr) {}
    bool is_empty() { return front == nullptr; }
    void enqueue(Order* order) {
        if (end == nullptr) front = end = order;
        else {
            end->next = order;
            end = order;
        }
        end->next = nullptr;
    }
    Order* dequeue() {
        if (is_empty()) return nullptr;
        Order* temp = front;
        front = front->next;
        if (front == nullptr) end = nullptr;
        temp->next = nullptr;
        return temp;
    }
    void print_orders() {
        Order* temp = front;
        while (temp != nullptr) {
            cout << "Order ID: " << temp->order_id << "\n";
            OrderItem* item = temp->items_head;
            while (item != nullptr) {
                cout << item->item_name << " x " << item->quantity << "\n";
                item = item->next;
            }
            temp = temp->next;
        }
    }
};

int main() {
    OrderQueue order_queue;
    Order* order1 = new Order(101);
    order1->add_item("Burger", 2);
    order1->add_item("Fries", 1);
    Order* order2 = new Order(102);
    order2->add_item("Pizza", 1);
    order2->add_item("Soda", 3);
    order_queue.enqueue(order1);
    order_queue.enqueue(order2);
    order_queue.print_orders();
    Order* processed = order_queue.dequeue();
    if (processed != nullptr) {
        cout << "Processed Order ID: " << processed->order_id << "\n";
        delete processed;
    } else cout << "No orders to process.\n";
    order_queue.print_orders();
    while (!order_queue.is_empty()) delete order_queue.dequeue();
    return 0;
}

