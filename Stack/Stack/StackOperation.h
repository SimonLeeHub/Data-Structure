/*!
* \brief 栈基本操作接口类
* 
* 包含初始化（1）、压栈（1）、栈顶（1）、出栈（1）、栈顶并出栈（1）、判空（1）、判满（1）以及删除栈（1）共8个基本操作
* 
* \author Lee
* \date 2019.03.13
*/
#pragma once
typedef int ElementType;
typedef void *vStack;
class CStackOperation
{
public:
	CStackOperation(void);
	virtual ~CStackOperation(void);
	virtual vStack createStack(void) = 0;	//创建栈
	virtual bool isEmpty(vStack S) = 0;	//判断栈是否为空
	virtual bool isFull(vStack S) = 0;	//判断栈是否已满
	virtual void push(ElementType X, vStack S) = 0;	//压栈
	virtual void pop(vStack S) = 0;	//出栈
	virtual ElementType top(vStack S) = 0;	 //返回栈顶元素
	virtual ElementType topAndPop(vStack S) = 0;	//返回栈顶元素并出栈
	virtual void deleteStack(vStack S) = 0;	//清空栈

public:
	std::string description;
};

