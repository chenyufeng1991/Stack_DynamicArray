

//
//  StackFunction.h
//  Stack_DynamicArray
//
//  Created by chenyufeng on 16/3/6.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

#include <stdio.h>

void createStack(int size);
void destroyStack();
void push(int value);
void pop();
int top();
int isEmpty();
int isFull();
void printStack();