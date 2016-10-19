
//**********************************************************
// 代码编辑器
//**********************************************************

// MsgTrade.h: interface for the CMsgTrade class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MSGTRADE_H__0967762A_20BA_4F08_8C15_CA80AE0E2BD2__INCLUDED_)
#define AFX_MSGTRADE_H__0967762A_20BA_4F08_8C15_CA80AE0E2BD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NetMsg.h"

const unsigned short _TRADE_APPLY			= 1;		// 请求交易		to client/server
const unsigned short _TRADE_QUIT			= 2;		// 取消交易		to server
const unsigned short _TRADE_OPEN			= 3;		// 打开交易窗	to client
const unsigned short _TRADE_SUCCESS			= 4;		// 交易成功(同时关闭)		to client
const unsigned short _TRADE_FALSE			= 5;		// 交易失败(同时关闭)		to client
const unsigned short _TRADE_ADDITEM			= 6;		// 加物品		to server(对方收到MSGITEMINFO消息)
const unsigned short _TRADE_ADDMONEY		= 7;		// 加钱			to server
const unsigned short _TRADE_PLAYERTOTALMONEY = 8;		// 钱总数		to client(对方付出金钱总数)
const unsigned short _TRADE_HEROTOTALMONEY	= 9;		// 钱总数		to client(自己金钱总数/每次加钱操作都会返回)
const unsigned short _TRADE_OK				= 10;		// 同意交易		to client/server
const unsigned short _TRADE_ADDITEM_FALSE	= 11;		// 加物品失败	to client

class CMsgTrade : public CNetMsg
{
public:
    CMsgTrade();
    virtual ~CMsgTrade();

public:
    BOOL	Create(OBJID idPlayer, unsigned short usAction);

    BOOL	Create(char* pbufMsg, DWORD dwMsgSize);
    void	Process(void* pInfo);

private:
    typedef struct
    {
        unsigned short	unMsgSize;
        unsigned short	unMsgType;

        union
        {
            OBJID			id;
            DWORD			dwData;
        };
        unsigned short	usAction;
    } MSG_Info;

    MSG_Info* m_pInfo;
};

#endif // !defined(AFX_MSGTRADE_H__0967762A_20BA_4F08_8C15_CA80AE0E2BD2__INCLUDED_)
