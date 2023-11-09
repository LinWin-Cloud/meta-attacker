# Meta Attack DDOS安全软件
Meta Attack安全软件，是一款设计入门即入狱的DDOS软件，简单而且容易上手，很容易使得新手在没有系统学习Linux以及网络安全的情况下入门即入狱。包括了基础的 死亡之Ping,资源攻击,Http请求攻击,tcp洪水等.

21世纪，是计算机与网络的世界，是信息与数据的时代，是智能化与自动化的爆发。但是在机遇与技术快速更新的背景下，黑客、漏洞、网络竞争正在与时俱进。```DDOS```即 ```分布式拒绝服务攻击```，简单粗暴的方法，却造成了数以万计的经济损失与伤害。

## 中华人民共和国关于计算机网络安全的刑法

1、破坏计算机信息系统罪：该罪规定在《刑法》第二百八十六条，是指违反国家规定，对计算机信息系统功
能进行删除、修改、增加、干扰，造成计算机信息系统不能正常运行，后果严重的，处五年以下有期徒刑或者
拘役；后果特别严重的，处五年以上有期徒刑。

2、非法控制计算机信息系统罪：非法控制计算机信息系统罪是指对国家事务、国防建设、尖端科学技术领域以
外的计算机信息系统实施非法控制，情节严重的行为。根据刑法第285条第二款的规定，犯本罪的，处三年以
有期徒刑或者拘役，并处或者单处罚金；情节特别严重的，处三年以上七年以下有期徒刑，并处罚金。


3、提供侵入、非法控制计算机信息系统程序、工具罪：是指提供专门用于侵入、非法控制计算机信息系统的程
序、工具，或者明知他人实施侵入、非法控制计算机信息系统的违法犯罪行为而为其提供程序、工具，情节
重的行为。犯本罪的，处三年以下有期徒刑或者拘役，并处或者单处罚金；情节特别严重的，处三年以上七年
以下有期徒刑，并处罚金。 


## 模块:
- death_ping
- http_attack
- tcp_flood
- network_resource_attack

## 信息
- 软件名称: Meta Attack
- 软件作者: 王相卿
- 编写语言: C++
- 开源地址: https://github.com/LinWin-Cloud/meta_attack
- 适用平台: Linux , Android Termax终端环境下
- 支持架构: Linux-amd64 , Android-aarch64

## 运行
> git clone https://gitee.com/LinWin-Cloud/meta-attacker

> cd meta-attacker/bin

> ./meta_attacker

## 帮助
```

>> HELP <<

    help 			=== Show the Help information.
    use [payload name] 		=== Use the payload you're select.
    show [payload name] 	=== Show the information of the payload your select.
    exit 			=== Quit from the console.

>> Payload Name <<

    death_ping
    http_attack
    tcp_flood
    network_resource_attack

```

