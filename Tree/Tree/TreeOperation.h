/*!
* \brief 树的基本操作接口类 
* 
* 包含创建空树（1）、查找元素（3）、插入元素（1）、删除元素（1）和删除树（1）共七种基本操作
* 
* \author Lee
* \date 2019.03.18
*/
#pragma once
typedef int ElementType;
typedef void *vPosition;
typedef void *vTree;
class CTreeOperation
{
public:
	CTreeOperation(void);
	virtual ~CTreeOperation(void);
	
	virtual vTree createTree(void) = 0;
	virtual vPosition find(ElementType X, vTree T) = 0;
	virtual vPosition findMin(vTree T) = 0;
	virtual vPosition findMax(vTree T) = 0;
	virtual vTree insert(ElementType X, vTree T) = 0;
	virtual vTree deleteX(ElementType X, vTree T) = 0;
	virtual vTree deleteTree(vTree T) = 0;

	// 基本辅助函数
	virtual int treeHeight(vTree T) = 0;
	virtual vPosition leftChild(vPosition P) = 0;
	virtual vPosition rightChild(vPosition P) = 0;
	virtual ElementType retrieve(vPosition P) = 0;

public:
	std::string description;
};

