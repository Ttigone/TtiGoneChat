# TtiGoneChat

The project is inspired by the Telegram desktop project

The design tool for uml is StartUml


## ������֧��

| ����������   | �汾��     | Ӧ��λ��              | ������Э������ |
| ------------ | ---------- | --------------------- | -------------- |
| microsoft GSL| 4.0.0			| ͨ�ù��߿�            | MIT            |
| QWindowKit   | 4.0.0			| ���ڱ�����            | MIT            |
| QsLog				 | 4.0.0			| debug ��־						| MIT            |
| qt-material  | 4.0.0			| �Զ��������					| MIT            |
| cppdap       | NA         | C++����������Э�� SDK | Apache 2.0     |
| QScintilla   | 2.14       | ���ܱ༭���������    | GPLv3          |
| lexilla      | 5.14       | ���ܱ༭���ʷ�������  | HPND           |
| qtermwidget  | 0.14.1     | �ն������            | GPLV2+ BSD3    |
| GitQlient    | tag/v1.4.3 | Gitչʾ�ͻ���         | LGPL-2.1+      |
| json-rpc-cpp | 1.4.1      | ͨ���м��            | MIT            |
| DTK          | 5.6.8.9    | ������ʾ              | LGPLv3+        |


## ���ݿ����

history_data: �洢��ʷ������Ϣ�ı�

�ֶ�:
- uuid: �û�Ψһ��ʶ
- msg_uid: ��ϢΨһ��ʶ
- sender_id: ������Ψһ��ʶ
- receiver_id: ������Ψһ��ʶ
- message: ��Ϣ����
- timestamp: ʱ���

<font color = Coral> 0 �� uuid �������û� </font>


���� uuid ����, �ҵ������û���ĳһ�û������������¼. Ȼ����� sender_id �� receiver_id �ҵ������ߺͽ����ߵ���Ϣ, �Լ���Ϣ���ݺ�ʱ���.
���� msg_id, ����Ϊ�˱�ʶ��Ϣ��Ψһ��, �Ա��ڲ�����Ϣ��¼.
