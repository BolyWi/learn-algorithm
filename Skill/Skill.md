# Skill
> 记录日常的编程技巧

- 指针常量和常量指针的区别
```c
    // 指针常量 指针本身是一个常量 指针的指向不能更改，指针指向的值可以更改
    {
        int a = 10, b = 20;
        int *const p = &a;
        *p = 15; // OK
//      p = &b; // ERROR 
        printf("指针常量：*p = %d p = %p\r\n", *p, p);
    }
    // 常量指针 指向一个常量值 指针的指向可以更改，指针指向的值不能更改
    {
        int a = 10, b = 20;
        const int *p = &a;
//      *p = 15; // ERROR
        p = &b;
        printf("常量指针：*p = %d p = %p\r\n", *p, p);
    }
    // 两者结合 指针的指向和指针指向的值都不能更改
    {
        int a = 10, b = 20;
        const int *const p = &a;
//      *p = 15; // ERROR
//      p = &b;  // ERROR
        printf("常量指针：*p = %d p = %p\r\n", *p, p);
    }
```

- 所有递归算法都可以转化为迭代算法