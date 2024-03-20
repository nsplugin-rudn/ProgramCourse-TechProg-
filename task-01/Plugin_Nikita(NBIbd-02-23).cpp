#include <iostream>

struct Element {
    double data;
    Element* nextElement;

    Element(double d = 0.0) : data(d), nextElement(nullptr) {}
};

class LinkedList {
private:
    Element* headElement;

public:
    LinkedList() : headElement(nullptr) {}

    void addAtEnd(double data) {
        Element* newElement = new Element(data);
        if (!headElement) {
            headElement = newElement;
        } else {
            Element* current = headElement;
            while (current->nextElement) {
                current = current->nextElement;
            }
            current->nextElement = newElement;
        }
    }

    void addAtStart(double data) {
        Element* newElement = new Element(data);
        newElement->nextElement = headElement;
        headElement = newElement;
    }

    void removeLast() {
        if (!headElement) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        if (!headElement->nextElement) {
            delete headElement;
            headElement = nullptr;
        } else {
            Element* current = headElement;
            while (current->nextElement->nextElement) {
                current = current->nextElement;
            }
            delete current->nextElement;
            current->nextElement = nullptr;
        }
    }

    void removeFirst() {
        if (!headElement) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Element* temp = headElement;
        headElement = headElement->nextElement;
        delete temp;
    }

    void display() const {
        Element* current = headElement;
        while (current) {
            std::cout << "Data: " << current->data << std::endl;
            current = current->nextElement;
        }
    }
    
    void removeAt(int index) {
    if (!headElement) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    if (index == 0) {
        removeFirst();
        return;
    }

    Element* current = headElement;
    Element* previous = nullptr;
    int currentIndex = 0;

    while (current != nullptr && currentIndex < index) {
        previous = current;
        current = current->nextElement;
        currentIndex++;
    }

    if (current == nullptr) {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }

    previous->nextElement = current->nextElement;
    delete current;
    }
    
    void insertAtIndex(int index, double data) {
    if (index < 0) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    if (index == 0) {
        addAtStart(data);
        return;
    }
    Element* newElement = new Element(data);
    Element* current = headElement;
    for (int i = 0; current != nullptr && i < index - 1; ++i) {
        current = current->nextElement;
    }
    if (current == nullptr) {
        std::cout << "Index out of bounds" << std::endl;
        delete newElement;
    } else {
        newElement->nextElement = current->nextElement;
        current->nextElement = newElement;
    }
}
    
    Element* findByIndex(int index) {
        Element* current = headElement;
        int currentIndex = 0;
        while (current != nullptr && currentIndex < index) {
            current = current->nextElement;
            currentIndex++;
        }
        if (currentIndex == index) {
            return current;
        } else {
            return nullptr;
        }
    }

    Element* findByValue(double value) {
        Element* current = headElement;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->nextElement;
        }
        return nullptr;
    }
    
     void updateAt(int index, double newData) {
        if (!headElement) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        
        Element* current = headElement;
        int currentIndex = 0;
        
        while (current != nullptr && currentIndex < index) {
            current = current->nextElement;
            currentIndex++;
        }
        
        if (current == nullptr) {
            std::cout << "Index out of bounds" << std::endl;
        } else {
            current->data = newData;
        }
    }
};
    

int main() {
    LinkedList myList;
    myList.addAtEnd(10);
    myList.addAtStart(20);
    myList.addAtEnd(30);
    myList.display();
    std::cout<<std::endl;
    myList.removeFirst();
    std::cout<<std::endl;
    myList.display();
    std::cout<<std::endl;
    myList.removeLast();
    myList.display();
    
    
    myList.insertAtIndex(1, -1.0);
    myList.addAtEnd(2.0);
    myList.addAtEnd(3.0);

    Element* elementAtIndex1 = myList.findByIndex(1);
    if (elementAtIndex1) {
    std::cout << "Element at index 1: " << elementAtIndex1->data << std::endl;
    }

    Element* elementWithValue2 = myList.findByValue(2.0);
    if (elementWithValue2) {
        std::cout << "Element with value 2.0: " << elementWithValue2->data << std::endl;

    }
    
    myList.updateAt(1, 25);
    myList.display();
    return 0;
}