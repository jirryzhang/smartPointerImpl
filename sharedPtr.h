//
// Created by Apple on 2018/9/1.
//

#ifndef SMARTPOINTERTEST_SHAREDPTR_H
#define SMARTPOINTERTEST_SHAREDPTR_H
#include <iostream>
#include <memory>

void test() {
    {
        int a = 10;
        std::shared_ptr<int> ptra = std::make_shared<int>(a);
        std::shared_ptr<int> ptra2(ptra); //copy
        std::cout <<"ptra.use_count:"<< ptra.use_count() << std::endl;

        int b = 20;
        int *pb = &a;
        //std::shared_ptr<int> ptrb = pb;  //error
        std::shared_ptr<int> ptrb = std::make_shared<int>(b);
        ptra2 = ptrb; //assign
        pb = ptrb.get(); //获取原始指针

        std::cout <<"ptra.use_count:"<< ptra.use_count() << std::endl;
        std::cout <<"ptrb.use_count:" <<ptrb.use_count() << std::endl;
    }
}
#endif //SMARTPOINTERTEST_SHAREDPTR_H
