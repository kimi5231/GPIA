﻿#include <iostream>
#include "List.h"

int main()
{
    List li;

    li.AddAtTail(1);
    Node* node = li.AddAtTail(2);
    li.AddAtTail(3);

    li.Print();

    li.Remove(node);

    li.Print();
}