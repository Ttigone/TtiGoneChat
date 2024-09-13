# TtiGoneChat

The project is inspired by the Telegram desktop project

The design tool for uml is StartUml


## 三方库支持

| 三方库名称   | 版本号     | 应用位置              | 三方库协议类型 |
| ------------ | ---------- | --------------------- | -------------- |
| microsoft GSL| 4.0.0			| 通用工具库            | MIT            |
| QWindowKit   | 4.0.0			| 窗口标题栏            | MIT            |
| QsLog				 | 4.0.0			| debug 日志						| MIT            |
| qt-material  | 4.0.0			| 自定义组件库					| MIT            |
| cppdap       | NA         | C++调试适配器协议 SDK | Apache 2.0     |
| QScintilla   | 2.14       | 智能编辑器界面组件    | GPLv3          |
| lexilla      | 5.14       | 智能编辑器词法分析库  | HPND           |
| qtermwidget  | 0.14.1     | 终端组件库            | GPLV2+ BSD3    |
| GitQlient    | tag/v1.4.3 | Git展示客户端         | LGPL-2.1+      |
| json-rpc-cpp | 1.4.1      | 通信中间件            | MIT            |
| DTK          | 5.6.8.9    | 界面显示              | LGPLv3+        |


## 数据库设计

history_data: 存储历史聊天信息的表

字段:
- uuid: 用户唯一标识
- msg_uid: 消息唯一标识
- sender_id: 发送者唯一标识
- receiver_id: 接收者唯一标识
- message: 消息内容
- timestamp: 时间戳

<font color = Coral> 0 号 uuid 代表本地用户 </font>


根据 uuid 分组, 找到本地用户与某一用户的所有聊天记录. 然后根据 sender_id 和 receiver_id 找到发送者和接收者的信息, 以及消息内容和时间戳.
至于 msg_id, 则是为了标识消息的唯一性, 以便于查找消息记录.
