#include "gmock/gmock.h"
#include "LRUCache.h"

using namespace testing;

class Test_LRUCache : public Test
{
	public:

		Test_LRUCache();

		LRUCache m_cache;
};

Test_LRUCache::Test_LRUCache() : m_cache{2}{}

TEST_F(Test_LRUCache, testvalues)
{
	m_cache.setQuery(5,11);
	EXPECT_THAT(m_cache.getQuery(5), Eq(11));
	m_cache.setQuery(10,22);
	EXPECT_THAT(m_cache.getQuery(5), Eq(11));
	m_cache.setQuery(15,33);
	EXPECT_THAT(m_cache.getQuery(10), Eq(-1));
	m_cache.setQuery(5,55);
	EXPECT_THAT(m_cache.getQuery(5), Eq(55));
}
