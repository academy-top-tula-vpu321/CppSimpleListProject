#include <iostream>

template <typename T>
struct Node
{
    T value;
    Node<T>* next;
};

template <typename T>
void PushBack(Node<T>*& head, T value)
{
    Node<T>* nodeNew{ new Node<T> };
    nodeNew->value = value;
    nodeNew->next = head;
    head = nodeNew;
}

template <typename T>
void PushFront(Node<T>*& head, T value)
{
    if (!head)
        PushBack(head, value);
    else
    {
        Node<T>* nodeLast{ head };
        while (nodeLast->next)
            nodeLast = nodeLast->next;

        Node<T>* nodeNew{ new Node<T> };
        nodeNew->value = value;
        nodeNew->next = nullptr;
        nodeLast->next = nodeNew;
    }
    
}

template <typename T>
void Insert(Node<T>*& head, T value, int index)
{
    if (index <= 0)
    {
        PushBack(head, value);
        return;
    }

    int size{};
    Node<T>* nodeCurr{ head };
    while (nodeCurr)
    {
        size++;
        nodeCurr = nodeCurr->next;
    }
    if (index >= size)
    {
        PushFront(head, value);
        return;
    }

    nodeCurr = head;
    for (int i = 0; i < index - 1; i++)
        nodeCurr = nodeCurr->next;
    Node<T>* nodeNew{ new Node<T> };
    nodeNew->value = value;
    nodeNew->next = nodeCurr->next;
    nodeCurr->next = nodeNew;
}

template <typename T>
int PopBack(Node<T>*& head)
{
    int value = head->value;
    Node<T>* nodeDel{ head };
    head = head->next;
    delete nodeDel;

    return value;
}

template <typename T>
int PopFront(Node<T>*& head)
{
    if (!head->next)
        return PopBack(head);

    Node<T>* nodeCurr{ head };
    while (nodeCurr->next->next)
        nodeCurr = nodeCurr->next;
    int value = nodeCurr->next->value;
    delete nodeCurr->next;
    nodeCurr->next = nullptr;

    return value;
}

template <typename T>
int Remove(Node<T>*& head, int index)
{
    return 0;
}

template <typename T>
void PrintList(Node<T>* head)
{
    while (head)
    {
        std::cout << head->value << "\n";
        head = head->next;
    }
}

int main()
{
    Node<float>* head{ nullptr };
    PushBack(head, 100.0f);
    PushBack(head, 200.f);
    PushBack<float>(head, 300);

    PushFront<float>(head, 400);

    Insert<float>(head, 500, 2);
    PrintList(head);

    std::cout << "back: " << PopBack(head) << "\n\n";
    PrintList(head);
    std::cout << "front: " << PopFront(head) << "\n\n";
    PrintList(head);
    std::cout << "back: " << PopBack(head) << "\n\n";
    PrintList(head);
    std::cout << "front: " << PopFront(head) << "\n\n";
    PrintList(head);
    std::cout << "front: " << PopFront(head) << "\n\n";
    PrintList(head);

    
}
