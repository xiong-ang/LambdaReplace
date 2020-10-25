# LambdaReplace
A Lambda Replace Method in C++

```c++
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
```
