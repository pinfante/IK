#include "gmock/gmock.h"
#include "strings.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include "Trie.h"

using std::cout;
using std::endl;

using namespace testing;
using namespace strings;

class Test_Strings : public Test
{
	public:

		vector<string> getWords();
		
};

TEST_F(Test_Strings, reverseString)
{
	string s{"pasquale"};
	reverseString(s, 0, s.size()-1);
	EXPECT_THAT(s, Eq("elauqsap"));
	s = " good nite  ";
	reverseString(s, 0, s.size()-1);
	EXPECT_THAT(s, Eq("  etin doog "));
}

TEST_F(Test_Strings, reverse)
{
	string s{"pasquale"};
	reverse(s, 0, s.size()-1);
	EXPECT_THAT(s, Eq("elauqsap"));
	s = " good nite  ";
	reverse(s, 0, s.size()-1);
	EXPECT_THAT(s, Eq("  etin doog "));
}

TEST_F(Test_Strings, isPalindrone)
{
	EXPECT_THAT(isPalindrone("racecar"), Eq(true));
	EXPECT_THAT(isPalindrone("goddog"), Eq(true));
	EXPECT_THAT(isPalindrone("raceecar"), Eq(true));
	EXPECT_THAT(isPalindrone("racescar"), Eq(false));
}

TEST_F(Test_Strings, isSubString)
{
	EXPECT_THAT(isSubString("racecars", "car"), Eq(4)); 
	EXPECT_THAT(isSubString("racecars", "ace"), Eq(1));
	EXPECT_THAT(isSubString("racecars", "dog"), Eq(-1));
}

TEST_F(Test_Strings, reverse_ordering_of_words)
{
	string s{"  I will do it. "};
	string r{" it. do will I  "};
	EXPECT_THAT(reverse_ordering_of_words(s), Eq(r));
}

TEST_F(Test_Strings, move_letters_to_left)
{
	string s{"a12br37rw98"};
	EXPECT_THAT(move_letters_to_left(s), Eq("abrrw371298"));
	s = "1234abc567rst89";
	EXPECT_THAT(move_letters_to_left(s), Eq("abcrst356741289"));
}

TEST_F(Test_Strings, insertTrie)
{
	Trie trie;
	trie.insert("cat");
	trie.insert("can");
	trie.insert("came");
	trie.insert("dog");
	trie.insert("elephant");

	ASSERT_THAT(trie.find("cat"), NotNull());
	ASSERT_THAT(trie.find("can"), NotNull());
	ASSERT_THAT(trie.find("dog"), NotNull());
	ASSERT_THAT(trie.find("elephant"), NotNull());
	ASSERT_THAT(trie.find("bear"), IsNull());
}

TEST_F(Test_Strings, isMatch)
{
	Trie trie;
	string pattern{};
	EXPECT_THAT(isMatch("bee", "rat"), Eq(false));
	EXPECT_THAT(isMatch("dog", "d.g"), Eq(true)); 
	EXPECT_THAT(isMatch("cat", "c*"), Eq(true)); 
	EXPECT_THAT(isMatch("aab", "c*a*b*"), Eq(true)); 
	EXPECT_THAT(isMatch("aaaaa", ".a*"), Eq(true));
}

vector<string> Test_Strings::getWords()
{
	return vector<string>{"engulf","engulfed","engulfing","engulfment","engulfs","Engvall","enhaemospore","enhallow","enhalo","enhaloed","enhaloes","enhaloing","enhalos","enhamper","enhance","enhanced","enhancement","enhancements","enhancement's","enhancer","enhancers","enhances","enhancing","enhancive","enhappy","enharbor","enharbour","enharden","enhardy","enharmonic","enharmonical","enharmonically","enhat","enhaulse","enhaunt","enhazard","enhearse","enheart","enhearten","enheaven","enhedge","enhelm","enhemospore","enherit","enheritage","enheritance","Enhydra","Enhydrinae","Enhydris","reswarm","reswear","reswearing","resweat","resweep","resweeping","resweeten","reswell","reswept","reswill","reswim","reswore","Reszke","ret","Reta","retable","retables","retablo","retabulate","retabulated","retabulating","retack","retacked","retackle","retacks","retag","retagged","retags","retail","retailable","retailed","retailer","retailers","retailing","retailment","retailor","retailored","retailoring","retailors","retails","retain","retainability","retainable","retainableness","retainal","retainder","retained","retainer","retainers","retainership","retaining","retainment","retains","retake","retaken","retaker","retakers","retakes","retaking","retal","retaliate","retaliated","retaliates","retaliating","retaliation","retaliationist","retaliations","retaliative","retaliator","retaliatory","retaliators","retalk","retally","retallies","retama","retame","retan","retanned","retanner","retanning","retape","retaped","retapes","retaping","retar","retard","retardance","retardant","retardants","retardate","retardates","retardation","retardations","retardative","retardatory","retarded","retardee","retardence","retardent","retarder","retarders","retarding","retardingly","retardive","retardment","retards","retardure","retare","retarget","retariff","retarred","retarring","retaste","retasted","retastes","retasting","retation","retattle","retaught","retax","retaxation","retaxed","retaxes","retaxing","retch","retched","retches","retching","retchless"};
}

TEST_F(Test_Strings, findWords)
{
	auto words{getWords()};
	Trie trie;

	for(const auto& word : words)
		trie.insert(word);

	string prefix{"retax"};
	auto matched{trie.findWords(prefix)};
	ASSERT_THAT(matched.empty(), Eq(false));
	std::sort(matched.begin(), matched.end());
	EXPECT_THAT(matched[0], Eq("retax"));
	EXPECT_THAT(matched[1], Eq("retaxation"));
	EXPECT_THAT(matched[2], Eq("retaxed"));
	EXPECT_THAT(matched[3], Eq("retaxes"));
	EXPECT_THAT(matched[4], Eq("retaxing"));

	prefix = "engulf";
	matched = trie.findWords(prefix);
	ASSERT_THAT(matched.empty(), Eq(false));
	std::sort(matched.begin(), matched.end());
	EXPECT_THAT(matched[0], Eq("engulf"));
	EXPECT_THAT(matched[1], Eq("engulfed"));
	EXPECT_THAT(matched[2], Eq("engulfing"));
	EXPECT_THAT(matched[3], Eq("engulfment"));
	EXPECT_THAT(matched[4], Eq("engulfs"));
}

TEST_F(Test_Strings, createLpsTable)
{
	auto table(createLpsTable("abc"));
	ASSERT_THAT(table.size(), Eq(3));
	EXPECT_THAT(table[0], Eq(0));
	EXPECT_THAT(table[1], Eq(0));
	EXPECT_THAT(table[2], Eq(0));

	table = createLpsTable("aaa");
	ASSERT_THAT(table.size(), Eq(3));
	EXPECT_THAT(table[0], Eq(0));
	EXPECT_THAT(table[1], Eq(1));
	EXPECT_THAT(table[2], Eq(2));

	table = createLpsTable("aaaba");
	ASSERT_THAT(table.size(), Eq(5));
	EXPECT_THAT(table[0], Eq(0));
	EXPECT_THAT(table[1], Eq(1));
	EXPECT_THAT(table[2], Eq(2));
	EXPECT_THAT(table[3], Eq(0));
	EXPECT_THAT(table[4], Eq(1));

	table = createLpsTable("abcdabca");
	ASSERT_THAT(table.size(), Eq(8));
	EXPECT_THAT(table[0], Eq(0));
	EXPECT_THAT(table[1], Eq(0));
	EXPECT_THAT(table[2], Eq(0));
	EXPECT_THAT(table[3], Eq(0));
	EXPECT_THAT(table[4], Eq(1));
	EXPECT_THAT(table[5], Eq(2));
	EXPECT_THAT(table[6], Eq(3));
	EXPECT_THAT(table[7], Eq(1));

	table = createLpsTable("aabaabaaa");
	ASSERT_THAT(table.size(), Eq(9));
	EXPECT_THAT(table[0], Eq(0));
	EXPECT_THAT(table[1], Eq(1));
	EXPECT_THAT(table[2], Eq(0));
	EXPECT_THAT(table[3], Eq(1));
	EXPECT_THAT(table[4], Eq(2));
	EXPECT_THAT(table[5], Eq(3));
	EXPECT_THAT(table[6], Eq(4));
	EXPECT_THAT(table[7], Eq(5));
	EXPECT_THAT(table[8], Eq(2));
}

TEST_F(Test_Strings, KMP)
{
	auto res = KMP("aaa", "bbb");
	EXPECT_THAT(res[0], Eq(-1));

	res = KMP("apple", "le");
	EXPECT_THAT(res[0], Eq(3));

	res = KMP("abxabcabcaby", "abcaby");
	EXPECT_THAT(res[0], Eq(6));

	res = KMP("abxabcabcabybcdaxfgabcabystrp", "abcaby");
	ASSERT_THAT(res.size(), Eq(2));
	EXPECT_THAT(res[0], Eq(6));
	EXPECT_THAT(res[1], Eq(19));

	res = KMP("Our business is our business, none of your business", "business");
	ASSERT_THAT(res.size(), Eq(3));
	EXPECT_THAT(res[0], Eq(4));
	EXPECT_THAT(res[1], Eq(20));
	EXPECT_THAT(res[2], Eq(43));

	res = KMP("Our business is our business, none of your business", "our");
	ASSERT_THAT(res.size(), Eq(2));
	EXPECT_THAT(res[0], Eq(16));
	EXPECT_THAT(res[1], Eq(39));

	res = KMP("Our business is our business, none of your business", "daisy");
	EXPECT_THAT(res[0], Eq(-1));

	res = KMP("AABAACAABAA", "AAB");
	ASSERT_THAT(res.size(), Eq(2));
	EXPECT_THAT(res[0], Eq(0));
	EXPECT_THAT(res[1], Eq(6));

	res = KMP("aaaaaab", "a");
	ASSERT_THAT(res.size(), Eq(6));
	EXPECT_THAT(res[0], Eq(0));
	EXPECT_THAT(res[1], Eq(1));
	EXPECT_THAT(res[2], Eq(2));
	EXPECT_THAT(res[3], Eq(3));
	EXPECT_THAT(res[4], Eq(4));
	EXPECT_THAT(res[5], Eq(5));

	res = KMP("CCCCCCCCCC", "CC");
	ASSERT_THAT(res.size(), Eq(9));
	EXPECT_THAT(res[0], Eq(0));
	EXPECT_THAT(res[1], Eq(1));
	EXPECT_THAT(res[2], Eq(2));
	EXPECT_THAT(res[3], Eq(3));
	EXPECT_THAT(res[4], Eq(4));
	EXPECT_THAT(res[5], Eq(5));
	EXPECT_THAT(res[6], Eq(6));
	EXPECT_THAT(res[7], Eq(7));
	EXPECT_THAT(res[8], Eq(8));
}

TEST_F(Test_Strings, longestSubStrWith2DistChars)
{
	EXPECT_THAT(longestSubStrWith2DistChars("eceba"), Eq("ece"));
	EXPECT_THAT(longestSubStrWith2DistChars("aaaaaaaabbbbbbb"), Eq("aaaaaaaabbbbbbb"));
	EXPECT_THAT(longestSubStrWith2DistChars("ttttttttt"), Eq(""));
}

TEST_F(Test_Strings, neuronyms)
{
	auto res{neuronyms("nailed")};
	ASSERT_THAT(res.empty(), Eq(false));
	EXPECT_THAT(res[0], Eq("n4d"));
	EXPECT_THAT(res[1], Eq("n3ed"));
	EXPECT_THAT(res[2], Eq("na3d"));
	EXPECT_THAT(res[3], Eq("n2led"));
	EXPECT_THAT(res[4], Eq("na2ed"));
	EXPECT_THAT(res[5], Eq("nai2d"));

	res = neuronyms("batch");
	ASSERT_THAT(res.empty(), Eq(false));
	EXPECT_THAT(res[0], Eq("b3h"));
	EXPECT_THAT(res[1], Eq("b2ch"));
	EXPECT_THAT(res[2], Eq("ba2h"));
}
