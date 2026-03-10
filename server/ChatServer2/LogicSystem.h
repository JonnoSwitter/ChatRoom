#pragma once
#include "Singleton.h"
#include <queue>
#include <thread>
#include "CSession.h"
#include <map>
#include <functional>
#include "const.h"
#include <json/json.h>
#include <json/value.h>
#include <json/reader.h>
#include <unordered_map>
#include "data.h"
#include "ChatGrpcClient.h"

typedef  function<void(shared_ptr<CSession>, const short &msg_id, const string &msg_data)> FunCallBack;
class LogicSystem:public Singleton<LogicSystem>
{
	friend class Singleton<LogicSystem>;
public:
	~LogicSystem();
	void PostMsgToQue(shared_ptr < LogicNode> msg);
private:
	LogicSystem();
	void DealMsg();
	void RegisterCallBacks();
	void LoginHandler(shared_ptr<CSession>, const short &msg_id, const string &msg_data);
	bool GetBaseInfo(std::string base_key, int uid, std::shared_ptr<UserInfo>& userinfo);
	void SearchInfo(std::shared_ptr<CSession> session, const short& msg_id, const string& msg_data);
	void AddFriendApply(std::shared_ptr<CSession> session, const short& msg_id, const string& msg_data);
	bool isPureDigit(const std::string& str);
	void GetUserByUid(std::string uid_str, Json::Value& rtvalue);
	void GetUserByName(std::string name, Json::Value& rtvalue);
	bool GetFriendApplyInfo(int to_uid, std::vector<std::shared_ptr<ApplyInfo>>& list);
	std::thread _worker_thread;
	std::queue<shared_ptr<LogicNode>> _msg_que;
	std::mutex _mutex;
	std::condition_variable _consume;
	bool _b_stop;
	std::map<short, FunCallBack> _fun_callbacks;
};

bool LogicSystem::GetFriendApplyInfo(int to_uid, std::vector<std::shared_ptr<ApplyInfo>>& list) {
	//从mysql获取好友申请列表
	return MysqlMgr::GetInstance()->GetApplyList(to_uid, list, 0, 10);
}
