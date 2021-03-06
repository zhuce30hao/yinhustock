
#pragma once

#include "StructKlineView.h"
#include "FoxDriver.h"

#define MAX_COUNT_CDAT1		30

class CTaiShanDoc;

class CSharesCompute  
{
public:
	CSharesCompute();
	virtual ~CSharesCompute();
private:
	CTaiShanDoc   *m_MainDocument;

public:
	static CString GetIndexSymbol(int nKind);
	static int GetMarketKind(int nKind);

public:
	void AddDataCdat1(CReportData* p);
	SymbolKindArr m_dataArr[2];
	void SetMainDocument(CTaiShanDoc *m_MainDoc ) { m_MainDocument = m_MainDoc;}   
	void chk_rdp(CReportData  *Cdat,float NewPrice);                                    
	void UpdateHs(CReportData  *Cdat, short Curr_Min);                                   
	void SendCuoHeDataToDialog(CReportData *Cdat);                                 
	short GetStockMinute(time_t time,int mode);                               



	void StockDataUpdate(RCV_REPORT_STRUCTEx* pReport);
	void StockItemUpdate(CReportData* Cdat, RCV_REPORT_STRUCTEx* pReport);



protected:
	int CheckStockDaytime(RCV_HISTORY_STRUCTEx* pHistory, int nCount, int nIndex);

public:
	void StockDataDayUpdate(RCV_HISTORY_STRUCTEx* pHistory, int nCount);
	void StockDataMinUpdate(RCV_MINUTE_STRUCTEx* pMinute, int nCount);
	void StockDataPowerUpdate(RCV_POWER_STRUCTEx* pPower, int nCount);

	// 更新飞狐格式的分笔数据
	void StockDataTickUpdate(FOX_TICK* pTick, int nCount);
};
