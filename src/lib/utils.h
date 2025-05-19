#ifndef UTILS_H
#define UTILS_H

typedef struct {
    const char* name;
    const char* description;
    void (*func)(void);
} callable_func;

typedef void(*func_ptr)(void);

extern void print_title(int size);
extern func_ptr func_choose_exec(const char* menuTitle, int count, ...);

#endif
