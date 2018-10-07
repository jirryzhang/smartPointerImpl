//
// Created by Apple on 2018/9/1.
//

#ifndef SMARTPOINTERTEST_CIRCLEREF_ORGPTR_H
#define SMARTPOINTERTEST_CIRCLEREF_ORGPTR_H
#include <iostream>
#include <memory>

class Child;
class Parent;

class Parent {
private:
    Child* myChild;
public:
    void setChild(Child* ch) {
        this->myChild = ch;
    }

    void doSomething() {
        if (this->myChild) {

        }
    }

    ~Parent() {
        delete myChild;
    }
};

class Child {
private:
    Parent* myParent;
public:
    void setPartent(Parent* p) {
        this->myParent = p;
    }
    void doSomething() {
        if (this->myParent) {

        }
    }
    ~Child() {
        delete myParent;
    }
};

int test() {
    {
        Parent* p = new Parent;
        Child* c =  new Child;
        p->setChild(c);
        c->setPartent(p);
        delete c;  //only delete one
    }
    return 0;
}
#endif //SMARTPOINTERTEST_CIRCLEREF_ORGPTR_H
