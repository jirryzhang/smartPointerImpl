//
// Created by Apple on 2018/9/1.
//

#ifndef SMARTPOINTERTEST_CIRCLEREF_SHPTR_H
#define SMARTPOINTERTEST_CIRCLEREF_SHPTR_H
#include <iostream>
#include <memory>

class Child;
class Parent;

class Parent {
private:
    std::shared_ptr<Child> ChildPtr;
public:
    void setChild(std::shared_ptr<Child> child) {
        this->ChildPtr = child;
    }

    void doSomething() {
        if (this->ChildPtr.use_count()) {

        }
    }

    ~Parent() {
    }
};

class Child {
private:
    std::shared_ptr<Parent> ParentPtr;
public:
    void setPartent(std::shared_ptr<Parent> parent) {
        this->ParentPtr = parent;
    }
    void doSomething() {
        if (this->ParentPtr.use_count()) {

        }
    }
    ~Child() {
    }
};

void test() {
    std::weak_ptr<Parent> wpp;
    std::weak_ptr<Child> wpc;
    {
        std::shared_ptr<Parent> p(new Parent);
        std::shared_ptr<Child> c(new Child);
        p->setChild(c);
        c->setPartent(p);
        wpp = p;
        wpc = c;
        std::cout << p.use_count() << std::endl; // 2
        std::cout << c.use_count() << std::endl; // 2
    }
    std::cout << wpp.use_count() << std::endl;  // 1
    std::cout << wpc.use_count() << std::endl;  // 1
}
#endif //SMARTPOINTERTEST_CIRCLEREF_SHPTR_H
