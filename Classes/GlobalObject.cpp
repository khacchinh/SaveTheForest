#include "GlobalObject.h"

static GlobalObject *s_Instance = NULL;
GlobalObject::GlobalObject()
{
	_hightScoreList.clear();
}
GlobalObject::~GlobalObject()
{
	
}

GlobalObject* GlobalObject::getInstance()
{
	if (!s_Instance)
	{
		s_Instance = new (std::nothrow) GlobalObject();
		s_Instance->init();

	}
	return s_Instance;
}
void GlobalObject::init()
{
	_hightScoreList.clear();
	for (int i = 0; i < 10; i++)
	{
		std::string key = StringUtils::format("HightScore_%d", i);
		unsigned int value = UserDefault::getInstance()->getIntegerForKey(key.c_str());
		_hightScoreList.push_back(value);
	}
}
void GlobalObject::sortScore()
{
	for (int i = 0; i < _hightScoreList.size() - 2; i++)
	{
		for (int j = _hightScoreList.size() - 1; j > i; j--){
			if (_hightScoreList.at(i) < _hightScoreList.at(j)){
				unsigned int temp = _hightScoreList.at(i);
				_hightScoreList.at(i) = _hightScoreList.at(j);
				_hightScoreList.at(j) = temp;
			}
		}
	}
	for (int i = 0; i <=_hightScoreList.size()-1; i++)
	{
		std::string key = StringUtils::format("HightScore_%d", i);
		UserDefault::getInstance()->setIntegerForKey(key.c_str(),_hightScoreList.at(i));
	}
}
void GlobalObject::addNewHigtScore(unsigned int value)
{
	/*
	if (_hightScoreList.size() < 10)
	{
		_hightScoreList.push_back(value);
		std::string key = StringUtils::format("HightScore_%d", _hightScoreList.size()-1);
		UserDefault::getInstance()->setIntegerForKey(key.c_str(), value);
		sortScore();
	}
	else
	{*/
		if (value > _hightScoreList.back()&&value!=_hightScoreList.at(0))
		{
			_hightScoreList.back() = value;
			std::string key = StringUtils::format("HightScore_%d", _hightScoreList.size() - 1);
			UserDefault::getInstance()->setIntegerForKey(key.c_str(), value);
			sortScore();
		}
			
	//}
}
std::vector<unsigned int> GlobalObject::getHightScoreList()
{
	return _hightScoreList;
}
void GlobalObject::destroy()
{
	if (s_Instance)
	{
		_hightScoreList.clear();
		delete s_Instance;
		s_Instance = NULL;
	}
}