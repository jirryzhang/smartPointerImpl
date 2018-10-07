//
// Created by Apple on 2018/9/1.
//

#ifndef SMARTPOINTERTEST_WEAKPTR_H
#define SMARTPOINTERTEST_WEAKPTR_H
#include <iostream>
#include <memory>

void test() {
    {
        std::shared_ptr<int> sh_ptr = std::make_shared<int>(10);
        std::cout << "sh_ptr.use_count:"<<sh_ptr.use_count() << std::endl;

        std::weak_ptr<int> wp(sh_ptr);
        std::cout << "wp.use_count:"<<wp.use_count() << std::endl;

        if(!wp.expired()){
            std::shared_ptr<int> sh_ptr2 = wp.lock(); //get another shared_ptr
            std::cout << "wp.use_count:"<<wp.use_count() << std::endl;
            *sh_ptr = 100;
        }
    }
    //delete memory
}
#endif //SMARTPOINTERTEST_WEAKPTR_H
