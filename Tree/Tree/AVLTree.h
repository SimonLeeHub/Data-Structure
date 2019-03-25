/*!
* \brief 平衡二叉树类 
* 
* 树节点中包含高度信息，每个节点的左子树和右子树的高度最多差1；
* 空节点高度为零，叶子节点高度为1
* 
* \author Lee
* \date 2019.03.19
*/
#pragma once
#include "treeoperation.h"
struct AVLT_Node;
typedef AVLT_Node *AVLT_Position;
typedef AVLT_Node *AVLT_Tree;
struct AVLT_Node
{
	ElementType element;
	AVLT_Tree left;
	AVLT_Tree right;
	int height;
};
class CAVLTree :
	public CTreeOperation
{
public:
	CAVLTree(void);
	~CAVLTree(void);

	vTree createTree(void);	//O(1)
	vPosition find(ElementType X, vTree T);	//O(logN)
	vPosition findMin(vTree T);	//O(logN)
	vPosition findMax(vTree T);	//O(logN)
	vTree insert(ElementType X, vTree T);	//O(logN)
	vTree deleteX(ElementType X, vTree T);	//O(logN)
	vTree deleteTree(vTree T);	//O(N)

	// 基本辅助函数
	int treeHeight(vTree T);	//O(1)
	vPosition leftChild(vPosition P);	//O(1)
	vPosition rightChild(vPosition P);	//O(1)
	ElementType retrieve(vPosition P);	//O(1)

private:
	AVLT_Tree Lrotate(AVLT_Tree oldT);    //左单旋（在较高右子树的右侧插入）
	AVLT_Tree Rrotate(AVLT_Tree oldT);    //右单旋（在较高左子树的左侧插入）
	AVLT_Tree LRrotate(AVLT_Tree oldT);    //左右双旋（在较高左子树的右侧插入）
	AVLT_Tree RLrotate(AVLT_Tree oldT);    //右左双旋（在较高右子树的左侧插入）
};

