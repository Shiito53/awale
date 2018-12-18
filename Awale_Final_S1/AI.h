#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct sTree_s
{
	int m_data;
	struct sTree_s * sTreeSon[6];

}sTree;


void freeNode(sTree ** p_pRoot);
sTree * Create_sTree(int p_value);