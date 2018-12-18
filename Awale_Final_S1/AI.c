#include "AI.h"

// Création d'un node
sTree * Create_sTree(int p_value) {


	sTree * p_pRoot;
	p_pRoot = (sTree*)malloc(sizeof(sTree));

	p_pRoot->m_data = p_value;
	for (int i = 0; i < 6; i++)
	{
		p_pRoot->sTreeSon[i] = NULL;
	}
	return p_pRoot;
}

// Libération de l'arbre
void freeNode(sTree ** p_pRoot)
{

	if (!(*p_pRoot))
	{
		return;
	}
	freeNode(&((*p_pRoot)->sTreeSon[0]));
	freeNode(&((*p_pRoot)->sTreeSon[1]));
	freeNode(&((*p_pRoot)->sTreeSon[2]));
	freeNode(&((*p_pRoot)->sTreeSon[3]));
	freeNode(&((*p_pRoot)->sTreeSon[4]));
	freeNode(&((*p_pRoot)->sTreeSon[5]));

	free(*p_pRoot);
	*p_pRoot = NULL;
	return;
}

// Création du quadtree avec compression
//void createQuadTree(quadTreeNode ** p_proot, color ** matrix, dword height, dword x, dword y, int threshold)
//{
//	// Donne aux feuilles la valeur du pixel en RVB
//	if (height == 1)
//	{
//		(*p_proot)->pixel[0] = matrix[y][x][0];
//		(*p_proot)->pixel[1] = matrix[y][x][1];
//		(*p_proot)->pixel[2] = matrix[y][x][2];
//	}
//
//	// Descend l'arbre en divisant les carrés par 2
//	else
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			(*p_proot)->children[i] = createTreeNode();
//		}
//
//		createQuadTree(&((*p_proot)->children[0]), matrix, (height / 2), x, (y + height / 2), threshold);
//		createQuadTree(&((*p_proot)->children[1]), matrix, (height / 2), x, y, threshold);
//		createQuadTree(&((*p_proot)->children[2]), matrix, (height / 2), (x + height / 2), y, threshold);
//		createQuadTree(&((*p_proot)->children[3]), matrix, (height / 2), (x + height / 2), (y + height / 2), threshold);
//
//		// Compression simple avec élaguage
//		/*if ((*p_proot)->children[0]->pixel[0] == (*p_proot)->children[1]->pixel[0] && (*p_proot)->children[1]->pixel[0] == (*p_proot)->children[2]->pixel[0] && (*p_proot)->children[2]->pixel[0] == (*p_proot)->children[3]->pixel[0])
//		{
//			if ((*p_proot)->children[0]->pixel[1] == (*p_proot)->children[1]->pixel[1] && (*p_proot)->children[1]->pixel[1] == (*p_proot)->children[2]->pixel[1] && (*p_proot)->children[2]->pixel[1] == (*p_proot)->children[3]->pixel[1])
//			{
//				if ((*p_proot)->children[0]->pixel[2] == (*p_proot)->children[1]->pixel[2] && (*p_proot)->children[1]->pixel[2] == (*p_proot)->children[2]->pixel[2] && (*p_proot)->children[2]->pixel[2] == (*p_proot)->children[3]->pixel[2])
//				{
//					if ((*p_proot)->children[0]->children == NULL && (*p_proot)->children[1]->children == NULL && (*p_proot)->children[2]->children == NULL && (*p_proot)->children[3]->children == NULL)
//					{
//						for (int i = 0; i < 4; i++)
//						{
//							free(&((*p_proot)->children[i]));
//						}
//					}
//				}
//			}
//		}*/
//
//		// Fait la moyenne des valeurs RVB des enfants 
//		(*p_proot)->pixel[0] = ((*p_proot)->children[0]->pixel[0] + (*p_proot)->children[1]->pixel[0] + (*p_proot)->children[2]->pixel[0] + (*p_proot)->children[3]->pixel[0]) / 4;
//		(*p_proot)->pixel[1] = ((*p_proot)->children[0]->pixel[1] + (*p_proot)->children[1]->pixel[1] + (*p_proot)->children[2]->pixel[1] + (*p_proot)->children[3]->pixel[1]) / 4;
//		(*p_proot)->pixel[2] = ((*p_proot)->children[0]->pixel[2] + (*p_proot)->children[1]->pixel[2] + (*p_proot)->children[2]->pixel[2] + (*p_proot)->children[3]->pixel[2]) / 4;
//
//		// Compression destructive
//		if (labs((int)(((*p_proot)->children[0]->pixel[0]) - ((*p_proot)->children[1]->pixel[0]))) <= threshold && labs((int)(((*p_proot)->children[1]->pixel[0]) - ((*p_proot)->children[2]->pixel[0]))) <= threshold && labs((int)(((*p_proot)->children[2]->pixel[0]) - ((*p_proot)->children[3]->pixel[0]))) <= threshold &&
//			labs((int)(((*p_proot)->children[0]->pixel[1]) - ((*p_proot)->children[1]->pixel[1]))) <= threshold && labs((int)(((*p_proot)->children[1]->pixel[1]) - ((*p_proot)->children[2]->pixel[1]))) <= threshold && labs((int)(((*p_proot)->children[2]->pixel[1]) - ((*p_proot)->children[3]->pixel[1]))) <= threshold &&
//			labs((int)(((*p_proot)->children[0]->pixel[2]) - ((*p_proot)->children[1]->pixel[2]))) <= threshold && labs((int)(((*p_proot)->children[1]->pixel[2]) - ((*p_proot)->children[2]->pixel[2]))) <= threshold && labs((int)(((*p_proot)->children[2]->pixel[2]) - ((*p_proot)->children[3]->pixel[2]))) <= threshold &&
//			!(*p_proot)->children[0]->children[0] && !(*p_proot)->children[0]->children[1] && !(*p_proot)->children[0]->children[2] && !(*p_proot)->children[0]->children[3] &&
//			!(*p_proot)->children[1]->children[0] && !(*p_proot)->children[1]->children[1] && !(*p_proot)->children[1]->children[2] && !(*p_proot)->children[1]->children[3] &&
//			!(*p_proot)->children[2]->children[0] && !(*p_proot)->children[2]->children[1] && !(*p_proot)->children[2]->children[2] && !(*p_proot)->children[2]->children[3] &&
//			!(*p_proot)->children[3]->children[0] && !(*p_proot)->children[3]->children[1] && !(*p_proot)->children[3]->children[1] && !(*p_proot)->children[2]->children[1])
//		{
//			for (int i = 0; i < 4; i++)
//			{
//				free((*p_proot)->children[i]);
//				(*p_proot)->children[i] = NULL;
//
//			}
//		}
//
//	}
//}

// Affichage du quadtree

//void PrintQuadTree(quadTreeNode *n, int depth)
//
//{
//	for (int i = 0; i < depth; i++)
//	{
//		printf("\t");
//	}
//
//
//	if (n->children[0] == NULL)
//	{
//		printf("%d %d %d\n\n", n->pixel[0], n->pixel[1], n->pixel[2]);
//		return;
//	}
//
//	else if (n->children[0] != NULL)
//	{
//		printf("%d %d %d\n\n", n->pixel[0], n->pixel[1], n->pixel[2]);
//
//		for (int i = 0; i < 4; i++)
//		{
//
//			PrintQuadTree(n->children[i], depth + 1);
//		}
//
//		return;
//	}
//}

