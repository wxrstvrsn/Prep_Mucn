//
// Created by wxrstvrsn on 26.06.2023.
//

#pragma once

#include <stdexcept>

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node *next;

        Node(const T &value) : data(value), next(nullptr) {};
    };

    Node *head;

public:
    LinkedList<T>() : head(nullptr) {};

    ~LinkedList() {
        clear();
    }

    //! Add new element in head
    void add(const T &value);

    //! Checks if linked list is empty
    bool isEmpty() const;

    //! Remove element from head
    void remove();

    //! Add given list to end of *this list
    LinkedList<T> &operator+=(const LinkedList<T> &other);

    //! Prefix deleting head element
    LinkedList<T> &operator--();

    //! Postfix deleting head element
    LinkedList<T> &operator--(int);

    //! Destroy linked list
    void clear();

    //! Print function
    friend std::ostream &operator<<(std::ostream &out, const LinkedList &linkedListPrint) {
        Node *tempNode = linkedListPrint.head;
        while(tempNode != nullptr) {
            out << tempNode->data << " ";
            tempNode = tempNode->next;
        }

        return out;
    }


};

template<typename T>
void LinkedList<T>::add(const T &value) {
    Node *tempNode = new Node(value);
    tempNode->next = head;
    head = tempNode;
}

template<typename T>
bool LinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template<typename T>
void LinkedList<T>::remove() {
    if(isEmpty()) {
        throw std::runtime_error("LinkedList is empty");
    }
    Node *tempNode = head;
    head = head->next;
    delete tempNode;
}

template<typename T>
LinkedList<T> &LinkedList<T>::operator+=(const LinkedList<T> &other) {
    if(other.isEmpty()) {
        return *this;
    }
    if(isEmpty()) {
        head = other.head;
    } else {
        Node *tempThisHead = head;
        while(tempThisHead->next != nullptr) {
            tempThisHead = tempThisHead->next;
        }

        Node *otherHead = other.head;
        while(otherHead != nullptr) {
            tempThisHead->next = new Node(otherHead->data);
            tempThisHead = tempThisHead->next;
            otherHead = otherHead->next;
        }
    }

    return *this;
}

template<typename T>
LinkedList<T> &LinkedList<T>::operator--() {
    remove();
    return *this;
}

template<typename T>
LinkedList<T> &LinkedList<T>::operator--(int) {
    Node *tempNode = head;
    remove();
    return tempNode;
}

template<typename T>
void LinkedList<T>::clear() {
    while (!isEmpty()) {
        remove();
    }
}


