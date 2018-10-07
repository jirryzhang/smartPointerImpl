//
// Created by Apple on 2018/9/1.
//

#ifndef SMARTPOINTERTEST_UNIQUEPTR_H
#define SMARTPOINTERTEST_UNIQUEPTR_H
#include <iostream>
#include <memory>

int test() {
    {
        std::unique_ptr<int> uptr(new int(10));  //绑定动态对象
        //std::unique_ptr<int> uptr2 = uptr;  //不能賦值
        //std::unique_ptr<int> uptr2(uptr);  //不能拷貝
        std::unique_ptr<int> uptr2 = std::move(uptr); //轉換所有權
        uptr2.release(); //释放所有权
    }
    //超過uptr的作用域，內存釋放
}
#endif //SMARTPOINTERTEST_UNIQUEPTR_H
