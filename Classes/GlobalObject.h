#ifndef _GLOBAL_OBJECT__
#define _GLOBAL_OBJECT__
using namespace std;
using namespace cocos2d;

class GlobalObject :public Ref
{
	std::vector<unsigned int> _hightScoreList;
public:
	//static GlobalObject *s_Instance;
	static GlobalObject *getInstance();
	void addNewHigtScore(unsigned int value);
	std::vector<unsigned int> getHightScoreList();
	void init();
	void sortScore();
	GlobalObject();
	~GlobalObject();
	void destroy();
};
#endif