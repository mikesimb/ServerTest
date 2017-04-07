#pragma once
#include "ZQ_Thread.h"
typedef struct tagThreadMsgNode
{
	char*							  ImBuf;
	WORD						  ImBufLen;
	WORD						  ImCmd;
	WORD						  Imdent;
	WORD						  ImHandle;
	tagThreadMsgNode*   Next;
}ThreadMsgNode,*pThreadMsgNode;

class CMainThrad :public CZQ_Thread
{
public:
	CMainThrad();
	~CMainThrad();
	void FromClientMsg(WORD wHandle, WORD wCmd, char* buf, int Buflen);
	void FromDBMsg(WORD wHandle, WORD wCmd, char * buf, int Buflen);
protected:
	void Execute();
private:
	void ClearAllMsg();
	void DispenseGateMessage();
	void DispenseDBMessage();


private:
	unsigned long    m_Event;
	int                      m_SessionID;
	pThreadMsgNode * m_TopCMNode;
	pThreadMsgNode * m_BotCMNode;

	CRITICAL_SECTION   m_GateCS;
	CRITICAL_SECTION   m_DBCS;

	static CMainThrad* g_MainThread;

	
};

