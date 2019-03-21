#ifndef PROYECTO2_LIST_H
#define PROYECTO2_LIST_H

#include<stdio.h>
#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    void create(int);
    void traverse(int);
}*p = NULL, *head = NULL, *q = NULL, *np = NULL;
int c = 0;

void node::create(int x)
{
    np = new node;
    np->data = x;
    np->next = NULL;
    if (c == 0)
    {
        head = np;
        p = head;
        p->next = head;
        c++;
    }
    else if (c == 1)
    {
        p = head;
        q = p;
        if (np->data < p->data)
        {
            np->next = p;
            head = np;
            p->next = np;
        }
        else if (np->data > p->data)
        {
            p->next = np;
            np->next = head;
        }
        c++;
    }
    else
    {
        p = head;
        q = p;
        if (np->data < p->data)
        {
            np->next = p;
            head = np;
            do
            {
                p = p->next;
            }
            while (p->next != q);
            p->next=head;
        }
        else if (np->data > p->data)
        {
            while (p->next !=head && q->data < np->data)
            {
                q = p;
                p = p->next;
                if (p->next == head  && (p->data < np->data))
                {
                    p->next = np;
                    np->next = head;
                }
                else if (np->data < p->data)
                {
                    q->next = np;
                    np->next = p;
                    break;
                }
            }
        }
    }
}
void node::traverse(int i)
{
    node *t = head;
    int c = 0;
    while (c <= i - 1)
    {
        cout<<t->data<<"\t";
        t = t->next;
        c++;
    }
}

#endif //PROYECTO2_LIST_H
