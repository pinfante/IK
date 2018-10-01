#include "diameter_of_a_tree.h"
#include<algorithm>

TreeDiameter::TreeDiameter(const string& s)
{
	createNodes(s);
}

int TreeDiameter::diameterOfTree() const
{
	vector<int> paths;
	for(auto& n : m_root.ch)
		paths.push_back(findMaxPath(n));	

	if(paths.empty())return m_root.val;
	if(paths.size() == 1)return m_root.val + paths[0];

	std::partial_sort(paths.begin(), paths.begin() + 2, paths.end(), std::greater<int>());
	return m_root.val + paths[0] + paths[1];
}


int TreeDiameter::findMaxPath(const Node& n) const
{
	if(n.ch.empty())return n.val;

	vector<int> pathVals;

	for(auto& chNode : n.ch)
		pathVals.push_back(findMaxPath(chNode));

	return n.val + *std::max_element(pathVals.begin(), pathVals.end());
}

void TreeDiameter::createNodes(const string& s)
{
	if(s.empty())return;

	int k{1};
	m_root.val = readVal(s, k);
	k += 1;
	int numCh{readVal(s, k)}; 

	for(int i{0}; i < numCh; ++i)
	{
		k += 1;
		m_root.ch.push_back(createChNode(s, k));
	}
}

Node TreeDiameter::createChNode(const string& s, int& k)
{
	if(s[k] == '{')++k;

	Node curr(readVal(s, k));
	++k;

	int numCh{readVal(s, k)}; 
	for(int i{0}; i < numCh; ++i)
	{
		++k;
		curr.ch.push_back(createChNode(s, k));		
	}

	return curr;
}

int TreeDiameter::readVal(const string& s, int& k)
{
	string v;
	while(k < static_cast<int>(s.size()) && s[k] != ',')
		v += s[k++];

	return stoi(v);
}
