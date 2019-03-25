/*!
* \brief 伸展树类 
* 
* 查找时会将被查找元素推至树根，并返回树根指针，同时也是被查找元素的指针；
* 删除时，将被查找元素推至树根，删除，然后将左子树（如存在）中的最大值推至左子树的树根，
* 此时左子树的树根即为没有右孩子的节点，然后将右子树的树根作为左子树树根的右孩子，
* 
* 
* \author Lee
* \date 2019.03.19
*/
#pragma once
#include "treeoperation.h"
struct SPT_Node;
typedef SPT_Node *SPT_Position;
typedef SPT_Node *SPT_Tree;
struct SPT_Node
{
	ElementType element;
	SPT_Tree left;
	SPT_Tree right;
};
class CSpalyTree :
	public CTreeOperation
{
public:
	CSpalyTree(void);
	~CSpalyTree(void);

	vTree createTree(void);	//O(1)
	vPosition find(ElementType X, vTree T);	//O(logN)
	vPosition findMin(vTree T);	//O(logN)
	vPosition findMax(vTree T);	//O(logN)
	vTree insert(ElementType X, vTree T);	//O(logN)
	vTree deleteX(ElementType X, vTree T);	//O(logN)
	vTree deleteTree(vTree T);	//O(N)

	// 基本辅助函数
	int treeHeight(vTree T);	//O(N)
	vPosition leftChild(vPosition P);	//O(1)
	vPosition rightChild(vPosition P);	//O(1)
	ElementType retrieve(vPosition P);	//O(1)

private:
	SPT_Position findInside(ElementType X, SPT_Tree SPT);	//递归查找，返回节点位置
	SPT_Tree splay(SPT_Position P, SPT_Tree oldT);    //将P位置的节点变为伸展树的根
	SPT_Tree Lrotate(SPT_Tree oldT);    //左单旋
	SPT_Tree Rrotate(SPT_Tree oldT);    //右单旋
};

