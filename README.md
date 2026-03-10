# 聊天室（ChatRoom）
## 概要：本项目为C++全栈聊天项目实战，包括PC端QT界面编程，asio异步服务器设计，beast网络库搭建http网关，nodejs搭建验证服务，各服务间用grpc通信，server和client用asio通信等，也包括用户信息的录入等。
## 后端框架：
<img width="1774" height="671" alt="image" src="https://github.com/user-attachments/assets/61dbb433-95fc-45a5-bb4c-529ebe5af870" />
    在获取验证码服务框架中，客户端向网关服务器请求获取验证码，网关服务器接着向验证服务器发起验证请求，由验证服务器调用各大厂商提供的邮箱接口（qq邮箱、新浪邮箱等），由邮箱接口向用户邮箱发送验证码，然后验证服务器通知网关服务器验证码已发送，最后由网关服务器通知客户端注意查收验证码。只不过整个流程站在客户端角度好像是网关服务器发送的验证码。grpc是各服务器之间的服务调用框架，因此需要在服务器中配置grpc。
目前本项目第一季实现的功能较简单，主要是后端实现用户验证服务并搭配前端的按钮点击界面切换等功能。但是通过第一季的学习本人学习到了一些重要的设计思想及实际开发中各服务器之间通信需要考虑的重点。
## 项目总结：本项目后端所涉及的关键技术包括：asio库实现异步编程、并发编程、网络编程等。具体一点的的包括线程池、连接池、TCP通信、线程安全、互斥锁等技术或概念。
## 环境包：
redis、mysql（本地数据库）等：
<img width="467" height="239" alt="image" src="https://github.com/user-attachments/assets/b052054a-7ddb-496f-9d46-62bebf370153" />
node.json：
<img width="602" height="294" alt="image" src="https://github.com/user-attachments/assets/c3e53370-2410-4d70-b3b7-a84757701b00" />
相关软件：Qt、VS、VSCode。（VS暂时不要使用2026版，因为本人在redis配置过程中发现其不兼容2026版，所以本人使用的是2022版的VS）
##鸣谢
在此非常感谢Up主 @恋恋风辰 的教学资源，在此表示鸣谢。🪷🪷🪷


