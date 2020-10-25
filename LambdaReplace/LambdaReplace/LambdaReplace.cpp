// LambdaReplace.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


struct Task {
    typedef int(*TaskFuncType)(int argc1, int argc2, int argc3, int argc4);

    Task(int argc1, int argc2, TaskFuncType pfunc)
    {
        m_argc1 = argc1;
        m_argc2 = argc2;
        pTask = pfunc;
    }

    TaskFuncType pTask;
    int m_argc1;
    int m_argc2;

    int operator()(int argc3, int argc4)
    {
        return pTask(m_argc1, m_argc2, argc3, argc4);
    }
};

int funcIml(int argc1, int argc2, int argc3, int argc4)
{
    return argc1 + argc2 + argc3 + argc4;
}

int main()
{
    int argc1 = 1;
    int argc2 = 2;


    auto func = [argc1, argc2](int argc3, int argc4){
        return argc1 + argc2 + argc3 + argc4;
    };
    std::cout << func(3, 4) << std::endl;

    Task task(argc1, argc2, funcIml);
    std::cout << task(3, 4) << std::endl;
}

/*
struct Task
{
    typedef returnType(*TaskFuncType)(captureArgcList..., actualArgcList...);
    Task(captureArgcList..., void* pfunc) 
    {
        captureArgcList...;
        pTask = pfunc;
    }

    TaskFuncType pTask;
    captureArgcList...;

    returnType operator()(actualArgcList...)
    {
        return pTask(captureArgcList, actualArgcList...);
    }
};
//
// 将capture list作为Task的参数
// 将[capture list和实际参数]作为参数重新定义函数，此函数可以自定义化
// 用Task 1）缓存capture list 2）构造成形式相同的可调用对象
// 
*/


