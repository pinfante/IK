#ifndef _DIAMETER_OF_TREE_H_
#define _DIAMETER_OF_TREE_H_

#include<string>
#include<vector>

using std::string;
using std::vector;

struct Node
{
	Node(int v = 0) : val{v}{}

	int val;
	vector<Node> ch;
};


class TreeDiameter
{
	public:
	
		TreeDiameter(const string& s);
	
		int diameterOfTree() const;

		void createNodes(const string& s);

		Node createChNode(const string& s, int& k);

		int findMaxPath(const Node& n) const;

	private:

		int readVal(const string& s, int& k);

		Node m_root;

};

#endif
