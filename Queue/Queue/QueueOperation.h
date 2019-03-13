/*!
* \brief 队列基本操作接口类
* 
* 包含初始化（1）、入队（1）、出队（1）、队头元素（1）、队头元素并出队（1）、清空队列（1）以及判空（1）、判满（1）共8种基本操作 
* 
* \author Lee 
* \date 2019.03.13
*/
#pragma once
typedef int ElementType;
typedef void *vQueue;
class CQueueOperation
{
public:
	CQueueOperation(void);
	virtual ~CQueueOperation(void);
	virtual vQueue createQueue() = 0;    //创建空队列
	virtual bool isEmpty(vQueue Q) = 0;    //判断队列是否为空
	virtual bool isFull(vQueue Q) = 0;   //判断队列是否已满
	virtual void enqueue(ElementType X, vQueue Q) = 0;    //入队
	virtual void dequeue(vQueue Q) = 0;    //出队
	virtual ElementType front(vQueue Q) = 0;    //返回队头元素
	virtual ElementType frontAndDequeue(vQueue Q) = 0;    //返回对头元素并出队
	virtual void deleteQueue(vQueue Q) = 0;    //清空队列

public:
	std::string description;
};

