#pragma once

#include <iostream>

using namespace std;

template<class T>

class clsDblLinkedList
{
protected:
    int _Size = 0;
public:
    class Node
    {
    public:
        T value;
        Node* next;
        Node* prev;
    };


    Node* head = NULL;


    void PrintNodeDetails()
    {

        if (head->prev != NULL)
            cout << head->prev->value;
        else
            cout << "NULL";

        cout << " <--> " << head->value << " <--> ";

        if (head->next != NULL)
            cout << head->next->value << "\n";
        else
            cout << "NULL";

    }
    // Print the linked list
    void PrintListDetails()

    {
        cout << "\n\n";
        while (head != NULL) {
            PrintNodeDetails();
            head = head->next;
        }
    }
    /*  void PrintList()
      {
          cout << "NULL <--> ";
          while (head != NULL) {
              cout << head->value << " <--> ";
              head = head->next;
          }
          cout << "NULL";

      }*/

    void InsertDAtBeginning(T Value)
    {
        Node* New = new Node();
        New->value = Value;
        New->next = head;
        New->prev = NULL;
        if (head != NULL)
        {
            head->prev = New;
        }
        head = New;
        _Size++;
    }

    Node* FindNode(T Value)
    {
        Node* Current = head;
        while (Current != NULL)
        {
            if (Current->value == Value)
                return Current;

            Current = Current->next;
        }
        return NULL;
    }


    Node* GetNode(int Index)
    {
        Node* Current = head;
        int Count = 0;
        if (Index > _Size - 1 || Index < 0)
            return NULL;

        while (Current != NULL && (Current->next != NULL))
        {
            if (Count == Index)
                break;

            Current = Current->next;
            Count++;
        }
        return Current;
    }

    void InsertAfter(Node* Current, T Value)
    {
        Node* New = new Node();
        New->value = Value;
        New->prev = Current;
        New->next = Current->next;

        if (Current->next != NULL)
        {
            Current->next->prev = New;
        }
        Current->next = New;
        _Size++;

    }


    void InsertAtEnd(T Value)
    {
        Node* New = new Node();
        New->value = Value;
        New->next = NULL;
        if (head == NULL)
        {
            New->prev = NULL;
            head = New;
        }
        else
        {
            Node* Current = head;
            while (Current->next != NULL)
            {
                Current = Current->next;
            }
            Current->next = New;
            New->prev = Current;
        }
        _Size++;

    }

    void Delete(T Value)
    {
        Node* Current = FindNode(head, Value);
        if (head == NULL || Current == NULL)
            return;

        if (head == Current)
            head = Current->next;

        if (Current->next != NULL)
            Current->next->prev = Current->prev;

        if (Current->prev != NULL)
            Current->prev->next = Current->next;


        delete Current;
    }


    void DeleteNode(Node*& Current)
    {
        if (head == NULL || Current == NULL)
            return;

        if (head == Current)
            head = Current->next;

        if (Current->next != NULL)
            Current->next->prev = Current->prev;

        if (Current->prev != NULL)
            Current->prev->next = Current->next;


        delete Current;
        _Size--;

    }

    void DeleteFirstNode()
    {

        if (head == NULL)
        {
            return;
        }
        Node* Nw = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete Nw;
        _Size--;
    }

    void DeleteLastNode()
    {
        if (head == NULL)
        {
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Node* N = head;
        while (N->next->next != NULL)
        {
            N = N->next;
        }
        Node* C = N->next;

        N->next = NULL;
        delete C;
        _Size--;

    }


    T GetItem(int Index)
    {
        Node* Reslte = GetNode(Index);
        if (Reslte != NULL)
            return (Reslte->value);
             
     }
    // Print the linked list
    void PrintList()
    {
        Node* Current = head;
        while (Current != NULL)
        {
            cout << Current->value << " ";
            Current = Current->next;
        }
        cout << "\n";
    }
    int Size()
    {
        return _Size;
    }
    bool IsEmpty()
    {
        return(_Size == 0 ? true : false);
    }
    void Cleare()
    {
        while (_Size > 0)
        {
            DeleteFirstNode();
        }
    }

    void MyReverse()
    {
        clsDblLinkedList NN;
        Node* Temp = head;
        while (Temp != NULL)
        {
            NN.InsertDAtBeginning(Temp->value);
            Temp = Temp->next;
        }
        Cleare();
        head = NN.head;
    }

    void Reverse()
    {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != nullptr)
        {
            head = temp->prev;
        }
    }

    bool UpdateItem(int Index, T NewValue)
    {
        Node* ItemNode = GetNode(Index);
        if (ItemNode != NULL)
        {
            ItemNode->value = NewValue;
            return true;
        }
        else
            return false;
    }
    bool InsertAfter(int Index, T Value)
    {
        Node* ItemNode = GetNode(Index);
        if (ItemNode != NULL)
        {
            InsertAfter(ItemNode, Value);
            return true;
        }
        else
            return false;
    }

};

