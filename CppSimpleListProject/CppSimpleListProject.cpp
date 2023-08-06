#include <iostream>

struct Node
{
    int value;
    Node* next;
};

void PushBack(Node*& head, int value)
{
    Node* nodeNew{ new Node };
    nodeNew->value = value;
    nodeNew->next = head;
    head = nodeNew;
}

void PushFront(Node*& head, int value)
{
    if (!head)
        PushBack(head, value);
    else
    {
        Node* nodeLast{ head };
        while (nodeLast->next)
            nodeLast = nodeLast->next;

        Node* nodeNew{ new Node };
        nodeNew->value = value;
        nodeNew->next = nullptr;
        nodeLast->next = nodeNew;
    }
    
}

void Insert(Node*& head, int value, int index)
{
    if (index <= 0)
    {
        PushBack(head, value);
        return;
    }

    int size{};
    Node* nodeCurr{ head };
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
    Node* nodeNew{ new Node };
    nodeNew->value = value;
    nodeNew->next = nodeCurr->next;
    nodeCurr->next = nodeNew;
}

int PopBack(Node*& head)
{
    int value = head->value;
    Node* nodeDel{ head };
    head = head->next;
    delete nodeDel;

    return value;
}

int PopFront(Node*& head)
{
    if (!head->next)
        return PopBack(head);

    Node* nodeCurr{ head };
    while (nodeCurr->next->next)
        nodeCurr = nodeCurr->next;
    int value = nodeCurr->next->value;
    delete nodeCurr->next;
    nodeCurr->next = nullptr;

    return value;
}

int Remove(Node*& head, int index)
{

}

void PrintList(Node* head)
{
    while (head)
    {
        std::cout << head->value << "\n";
        head = head->next;
    }
}



int main()
{
    Node* head{ nullptr };
    PushBack(head, 100);
    PushBack(head, 200);
    PushBack(head, 300);

    PushFront(head, 400);

    Insert(head, 500, 2);
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
