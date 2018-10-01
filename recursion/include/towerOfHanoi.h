#ifndef _TOWER_OF_HANOI_H_
#define _TOWER_OF_HANOI_H_

#include<deque>
#include<vector>

using std::deque;
using std::vector;

//HW #6
class TowerOfHanoi
{
	public:

		TowerOfHanoi(int no_of_disks);	

		const vector<vector<int>>& getSteps() const {return m_steps;}

	private:

		void towerOfHanoi(int no_of_disks);
		void towerOfHanoi(int k, deque<int>& src, deque<int>& aux, deque<int>& des);

		void moveTower();

		void recordSteps();

		deque<int>  		m_src;
		deque<int>  		m_aux;
		deque<int>  		m_dest;
		vector<vector<int>> m_steps;


};

#endif
