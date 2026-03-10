#pragma once
#include "Singleton.h"
#include <functional>
#include <map>
#include "const.h"

class HttpConnection;
typedef std::function<void(std::shared_ptr<HttpConnection>)> HttpHandler;
class LogicSystem :public Singleton<LogicSystem>
{
	friend class Singleton<LogicSystem>;
public:
	~LogicSystem();
	//由于端口有读事件、写事件，因此需要分别处理读事件和写事件

	void RegGet(std::string, HttpHandler handler);//注册get请求(即注册读事件)
	bool HandleGet(std::string, std::shared_ptr<HttpConnection>);//处理get请求
	
	void RegPost(std::string, HttpHandler handler);//注册post事件(即注册写事件)
	bool HandlePost(std::string, std::shared_ptr<HttpConnection>);//处理post请求
private:
	LogicSystem();
	std::map<std::string, HttpHandler> _post_handlers;
	std::map<std::string, HttpHandler> _get_handlers;
};

