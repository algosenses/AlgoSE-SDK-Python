#ifndef ALGO_ORDER_H
#define ALGO_ORDER_H

#include <string.h>
#include "Defines.h"

namespace AlgoSE
{

typedef struct {
    enum {
        ParamId_Start = 0,

        // Global parameters
        LowerLimit_PriceTicks,
        UpperLimit_PriceTicks,
        Float_PriceTicks,
        TimeToLive_Ms,
        CloseAction_TimeToLive_Ms,
        PriceCancel_SeekBestPrice,

        // Normal phase parameters
        NormalPhase_PriceType,
        NormalPhase_CloseAction_PriceType,
        NormalPhase_Order_TimeInforce,
        NormalPhase_CloseAction_Order_TimeInforce,
        NormalPhase_LowerCancel_PriceTicks,
        NormalPhase_UpperCancel_PriceTicks,
        NormalPhase_CloseAction_LowerCancel_PriceTicks,
        NormalPhase_CloseAction_UpperCancel_PriceTicks,
        NormalPhase_CancelTime_Ms,
        NormalPhase_CloseAction_CancelTime_Ms,

        // Catch phase parameters
        CatchPhase_PriceType,
        CatchPhase_CloseAction_PriceType,
        CatchPhase_Order_TimeInforce,
        CatchPhase_CloseAction_Order_TimeInforce,
        CatchPhase_LowerCancel_PriceTicks,
        CatchPhase_UpperCancel_PriceTicks,
        CatchPhase_CloseAction_LowerCancel_PriceTicks,
        CatchPhase_CloseAction_UpperCancel_PriceTicks,
        CatchPhase_CancelTime_Ms,
        CatchPhase_CloseAction_CancelTime_Ms,

        ParamId_End
    };
} AlgoParamID;

#define LowerLimit_PriceTicks_ParamName                             "LowerLimit_PriceTicks"
#define UpperLimit_PriceTicks_ParamName                             "UpperLimit_PriceTicks"
#define Float_PriceTicks_ParamName                                  "Float_PriceTicks"
#define TimeToLive_Ms_ParamName                                     "TimeToLive_Ms"
#define CloseAction_TimeToLive_Ms_ParamName                         "CloseAction_TimeToLive_Ms"
#define PriceCancel_SeekBestPrice_ParamName                         "PriceCancel_SeekBestPrice"
#define NormalPhase_PriceType_ParamName                             "NormalPhase_PriceType"
#define NormalPhase_CloseAction_PriceType_ParamName                 "NormalPhase_CloseAction_PriceType"
#define NormalPhase_Order_TimeInforce_ParamName                     "NormalPhase_Order_TimeInforce"
#define NormalPhase_CloseAction_Order_TimeInforce_ParamName         "NormalPhase_CloseAction_Order_TimeInforce"
#define NormalPhase_LowerCancel_PriceTicks_ParamName                "NormalPhase_LowerCancel_PriceTicks"
#define NormalPhase_UpperCancel_PriceTicks_ParamName                "NormalPhase_UpperCancel_PriceTicks"
#define NormalPhase_CloseAction_LowerCancel_PriceTicks_ParamName    "NormalPhase_CloseAction_LowerCancel_PriceTicks"
#define NormalPhase_CloseAction_UpperCancel_PriceTicks_ParamName    "NormalPhase_CloseAction_UpperCancel_PriceTicks"
#define NormalPhase_CancelTime_Ms_ParamName                         "NormalPhase_CancelTime_Ms"
#define NormalPhase_CloseAction_CancelTime_Ms_ParamName             "NormalPhase_CloseAction_CancelTime_Ms"
#define CatchPhase_PriceType_ParamName                              "CatchPhase_PriceType"
#define CatchPhase_CloseAction_PriceType_ParamName                  "CatchPhase_CloseAction_PriceType"
#define CatchPhase_Order_TimeInforce_ParamName                      "CatchPhase_Order_TimeInforce"
#define CatchPhase_CloseAction_Order_TimeInforce_ParamName          "CatchPhase_CloseAction_Order_TimeInforce"
#define CatchPhase_LowerCancel_PriceTicks_ParamName                 "CatchPhase_LowerCancel_PriceTicks"
#define CatchPhase_UpperCancel_PriceTicks_ParamName                 "CatchPhase_UpperCancel_PriceTicks"
#define CatchPhase_CloseAction_LowerCancel_PriceTicks_ParamName     "CatchPhase_CloseAction_LowerCancel_PriceTicks"
#define CatchPhase_CloseAction_UpperCancel_PriceTicks_ParamName     "CatchPhase_CloseAction_UpperCancel_PriceTicks"
#define CatchPhase_CancelTime_Ms_ParamName                          "CatchPhase_CancelTime_Ms"
#define CatchPhase_CloseAction_CancelTime_Ms_ParamName              "CatchPhase_CloseAction_CancelTime_Ms"

typedef struct {
    //�����µ��׶�ί�м����ͣ�1Ϊ���¼ۣ�2Ϊ���ּ�, 3Ϊ�û�ָ����
    int NormalPhase_PriceType;
    //�����µ��׶�ƽ�ֵ�ί�м����ͣ�1Ϊ���¼ۣ�2Ϊ���ּ�, 3Ϊ�û�ָ����
    int NormalPhase_CloseAction_PriceType;
    //�����µ��׶α�����ʱЧ���ͣ�1Ϊ��ͨ������2ΪFOK��3ΪFAK
    int NormalPhase_Order_TimeInforce;
    //�����µ��׶�ƽ�ֵ���ʱЧ���ͣ�1Ϊ��ͨ������2ΪFOK��3ΪFAK
    int NormalPhase_CloseAction_Order_TimeInforce;

    //׷���׶�ί�м����ͣ�1Ϊ���¼ۣ�2Ϊ���ּ�, 3Ϊ�û�ָ����
    int CatchPhase_PriceType;
    //׷���׶�ƽ�ֵ�ί�м����ͣ�1Ϊ���¼ۣ�2Ϊ���ּ�, 3Ϊ�û�ָ����
    int CatchPhase_CloseAction_PriceType;
    //׷���׶α�����ʱЧ���ͣ�1Ϊ��ͨ������2ΪFOK��3ΪFAK
    int CatchPhase_Order_TimeInforce;
    //׷���׶�ƽ�ֵ���ʱЧ���ͣ�1Ϊ��ͨ������2ΪFOK��3ΪFAK
    int CatchPhase_CloseAction_Order_TimeInforce;

    //�㷨���۸�ֵ����
    int LowerLimit_PriceTicks;
    //�㷨���۸�ֵ����
    int UpperLimit_PriceTicks;

    //�㷨��������������
    int Cancelation_Num_Limit;

    //ί�м۸�������������ʱ�����ϸ�������������ʱ�����¸�������
    //���Ը��ż۸񱨼۴Ӷ���߳ɽ�����
    //���Ϊ���������෴���򸡶��۸�
    int Float_PriceTicks;

    // ���۸�����������䶯�ҳ����۸񳷵���Χʱ���Ƿ񳷵���׷��0�������� ��0������׷
    // ���۸�����������䶯ʱ��������׷���ܻ�õ����ųɽ��ۣ���Ҳ�п��ܴ����������
    int PriceCancel_SeekBestPrice;

    //�����µ��׶μ۸񳷵�����
    int NormalPhase_LowerCancel_PriceTicks;
    //�����µ��׶μ۸񳷵�����
    int NormalPhase_UpperCancel_PriceTicks;

    //�����µ��׶�ƽ�ֵ��۸񳷵�����
    int NormalPhase_CloseAction_LowerCancel_PriceTicks;
    //�����µ��׶�ƽ�ֵ��۸񳷵�����
    int NormalPhase_CloseAction_UpperCancel_PriceTicks;

    //׷���׶μ۸񳷵�����
    int CatchPhase_LowerCancel_PriceTicks;
    //׷���׶μ۸񳷵�����
    int CatchPhase_UpperCancel_PriceTicks;

    //׷���׶�ƽ�ֵ��۸񳷵�����
    int CatchPhase_CloseAction_LowerCancel_PriceTicks;
    //׷���׶�ƽ�ֵ��۸񳷵�����
    int CatchPhase_CloseAction_UpperCancel_PriceTicks;

    //�����µ��׶�ʱ�䳷��������
    int NormalPhase_CancelTime_Ms;
    //�����µ��׶�ƽ�ֵ�ʱ�䳷��������
    int NormalPhase_CloseAction_CancelTime_Ms;
    //׷���׶�ʱ�䳷��������
    int CatchPhase_CancelTime_Ms;
    //׷���׶�ƽ�ֵ�ʱ�䳷��������
    int CatchPhase_CloseAction_CancelTime_Ms;

    //�㷨�����ʱ�������(��ʱ��ֵ)
    int TimeToLive_Ms;
    //ƽ���㷨�����ʱ�������(��ʱ��ֵ)
    int CloseAction_TimeToLive_Ms;
} Params;

// Ĭ��ÿ������󳷵�����
#define  DEFAULT_MAX_CANCEL_COUNT       (50)

// Ĭ��ÿ�������ִ�д���
#define DEFAULT_MAX_EXEC_COUNT          (50)

// Ĭ��ʱ�䳷��������
#define DEFAULT_CANCLE_TIME_MS          (1000)

// Ĭ���㷨�����ʱ��
#define DEFAULT_LIVE_TO_TIME_MS         (5000)

// Ĭ���㷨���۸񳷵���������
#define DEFAULT_UPPER_CANCEL_PRICE_TICKS    (5)

// Ĭ���㷨���۸񳷵���������
#define DEFAULT_LOWER_CANCEL_PRICE_TICKS    (5)

// Ĭ�ϼ۸񸡶�����������׳ɽ��ļ۸��򸡶����򵥼۸��ϸ��������۸��¸�
#define DEFAULT_FLOAT_PRICE_TICK        (0)

// ִ�м۸�����
enum {
    EXEC_LASTPRICE = 1,  //�������³ɽ���
    EXEC_BIDASKPRICE,    //�����̿ڼ�
    EXEC_USER_SPECIFIED, //�û�ָ���۸�
};

typedef struct _ParamsBlock
{
    _ParamsBlock()
    {
        memset(&m_params, 0, sizeof(Params));

        m_params.NormalPhase_PriceType = EXEC_LASTPRICE;
        m_params.NormalPhase_CloseAction_PriceType = EXEC_LASTPRICE;
        m_params.NormalPhase_Order_TimeInforce = TimeInForce::GTD;
        m_params.NormalPhase_CloseAction_Order_TimeInforce = TimeInForce::GTD;

        m_params.CatchPhase_PriceType = EXEC_BIDASKPRICE;
        m_params.CatchPhase_CloseAction_PriceType = EXEC_BIDASKPRICE;
        m_params.CatchPhase_Order_TimeInforce = TimeInForce::GTD;
        m_params.CatchPhase_CloseAction_Order_TimeInforce = TimeInForce::GTD;

        m_params.Float_PriceTicks = DEFAULT_FLOAT_PRICE_TICK;
        m_params.PriceCancel_SeekBestPrice = 1;

        m_params.Cancelation_Num_Limit = DEFAULT_MAX_CANCEL_COUNT;

        m_params.NormalPhase_LowerCancel_PriceTicks = DEFAULT_LOWER_CANCEL_PRICE_TICKS;
        m_params.NormalPhase_UpperCancel_PriceTicks = DEFAULT_UPPER_CANCEL_PRICE_TICKS;
        m_params.NormalPhase_CloseAction_LowerCancel_PriceTicks = DEFAULT_LOWER_CANCEL_PRICE_TICKS;
        m_params.NormalPhase_CloseAction_UpperCancel_PriceTicks = DEFAULT_UPPER_CANCEL_PRICE_TICKS;

        m_params.CatchPhase_LowerCancel_PriceTicks = DEFAULT_LOWER_CANCEL_PRICE_TICKS;
        m_params.CatchPhase_UpperCancel_PriceTicks = DEFAULT_UPPER_CANCEL_PRICE_TICKS;
        m_params.CatchPhase_CloseAction_LowerCancel_PriceTicks = DEFAULT_LOWER_CANCEL_PRICE_TICKS;
        m_params.CatchPhase_CloseAction_UpperCancel_PriceTicks = DEFAULT_UPPER_CANCEL_PRICE_TICKS;

        m_params.NormalPhase_CancelTime_Ms = DEFAULT_CANCLE_TIME_MS;
        m_params.CatchPhase_CancelTime_Ms = DEFAULT_CANCLE_TIME_MS;
        m_params.NormalPhase_CloseAction_CancelTime_Ms = DEFAULT_CANCLE_TIME_MS;
        m_params.CatchPhase_CloseAction_CancelTime_Ms = DEFAULT_CANCLE_TIME_MS;
        m_params.TimeToLive_Ms = DEFAULT_LIVE_TO_TIME_MS;
        m_params.CloseAction_TimeToLive_Ms = DEFAULT_LIVE_TO_TIME_MS;
    }

    //�㷨���������ýӿ�

    //����ִ�м۸�����
    // 1. EXCE_LASTPRICE��     �������¼�ִ��
    // 2. EXCE_BIDASKPRICE��   ���������̿ڼ�ִ��
    // 3. EXEC_USER_SPECIFIED�������û�ָ����
    void set_NormalPhase_PriceType(int type)
    {
        if (type != EXEC_LASTPRICE &&
            type != EXEC_BIDASKPRICE &&
            type != EXEC_USER_SPECIFIED) {
            return;
        }

        m_params.NormalPhase_PriceType = type;
    }

    inline int get_NormalPhase_PriceType() const
    {
        return m_params.NormalPhase_PriceType;
    }

    inline int get_Cancelation_Num_Limit() const
    {
        return m_params.Cancelation_Num_Limit;
    }

    void set_Cancelation_Num_Limit(int num)
    {
        m_params.Cancelation_Num_Limit = num;
    }

    void set_NormalPhase_CloseAction_PriceType(int type)
    {
        if (type != EXEC_LASTPRICE &&
            type != EXEC_BIDASKPRICE &&
            type != EXEC_USER_SPECIFIED) {
            return;
        }

        m_params.NormalPhase_CloseAction_PriceType = type;
    }

    inline int get_NormalPhase_CloseAction_PriceType() const
    {
        return m_params.NormalPhase_CloseAction_PriceType;
    }

    void set_NormalPhase_Order_TimeInforce(int type)
    {
        if (type != TimeInForce::GTD && 
            type != TimeInForce::FOK && 
            type != TimeInForce::IOC) {
            return;
        }

        m_params.NormalPhase_Order_TimeInforce = type;
    }

    inline int get_NormalPhase_Order_TimeInforce() const
    {
        return m_params.NormalPhase_Order_TimeInforce;
    }

    void set_NormalPhase_CloseAction_Order_TimeInforce(int type)
    {
        if (type != TimeInForce::GTD &&
            type != TimeInForce::FOK &&
            type != TimeInForce::IOC) {
            return;
        }

        m_params.NormalPhase_CloseAction_Order_TimeInforce = type;
    }

    inline int get_NormalPhase_CloseAction_Order_TimeInforce() const
    {
        return m_params.NormalPhase_CloseAction_Order_TimeInforce;
    }

    void set_CatchPhase_PriceType(int type)
    {
        if (type != EXEC_LASTPRICE &&
            type != EXEC_BIDASKPRICE &&
            type != EXEC_USER_SPECIFIED) {
            return;
        }

        m_params.CatchPhase_PriceType = type;
    }

    inline int get_CatchPhase_PriceType() const
    {
        return m_params.CatchPhase_PriceType;
    }

    void set_CatchPhase_CloseAction_PriceType(int type)
    {
        if (type != EXEC_LASTPRICE &&
            type != EXEC_BIDASKPRICE &&
            type != EXEC_USER_SPECIFIED) {
            return;
        }

        m_params.CatchPhase_CloseAction_PriceType = type;
    }

    inline int get_CatchPhase_CloseAction_PriceType() const
    {
        return m_params.CatchPhase_CloseAction_PriceType;
    }

    void set_CatchPhase_Order_TimeInforce(int type)
    {
        if (type != TimeInForce::GTD &&
            type != TimeInForce::FOK &&
            type != TimeInForce::IOC) {
            return;
        }

        m_params.CatchPhase_Order_TimeInforce = type;
    }

    inline int get_CatchPhase_Order_TimeInforce() const
    {
        return m_params.CatchPhase_Order_TimeInforce;
    }

    void set_CatchPhase_CloseAction_Order_TimeInforce(int type)
    {
        if (type != TimeInForce::GTD &&
            type != TimeInForce::FOK &&
            type != TimeInForce::IOC) {
            return;
        }

        m_params.CatchPhase_CloseAction_Order_TimeInforce = type;
    }

    inline int get_CatchPhase_CloseAction_Order_TimeInforce() const
    {
        return m_params.CatchPhase_CloseAction_Order_TimeInforce;
    }

    void set_LowerLimit_PriceTicks(int num)
    {
        if (num < 0) {
            return;
        }

        m_params.LowerLimit_PriceTicks = num;
    }

    inline int get_LowerLimit_PriceTicks() const
    {
        return m_params.LowerLimit_PriceTicks;
    }

    void set_UpperLimit_PriceTicks(int num)
    {
        if (num < 0) {
            return;
        }

        m_params.UpperLimit_PriceTicks = num;
    }

    inline int get_UpperLimit_PriceTicks() const
    {
        return m_params.UpperLimit_PriceTicks;
    }

    void set_Float_PriceTicks(int num)
    {
        m_params.Float_PriceTicks = num;
    }

    inline int get_Float_PriceTicks() const
    {
        return m_params.Float_PriceTicks;
    }

    void set_PriceCancel_SeekBestPrice(bool onoff)
    {
        if (onoff) {
            m_params.PriceCancel_SeekBestPrice = 1;
        } else {
            m_params.PriceCancel_SeekBestPrice = 0;
        }
    }

    inline int get_PriceCancel_SeekBestPrice() const
    {
        return m_params.PriceCancel_SeekBestPrice;
    }

    void set_NormalPhase_LowerCancel_PriceTicks(int num)
    {
        if (num < 0) {
            return;
        }

        m_params.NormalPhase_LowerCancel_PriceTicks = num;
    }

    inline int get_NormalPhase_LowerCancel_PriceTicks() const
    {
        return m_params.NormalPhase_LowerCancel_PriceTicks;
    }

    void set_NormalPhase_UpperCancel_PriceTicks(int num)
    {
        if (num < 0) {
            return;
        }

        m_params.NormalPhase_UpperCancel_PriceTicks = num;
    }

    inline int get_NormalPhase_UpperCancel_PriceTicks() const
    {
        return m_params.NormalPhase_UpperCancel_PriceTicks;
    }

    void set_NormalPhase_CloseAction_LowerCancel_PriceTicks(int num)
    {
        if (num < 0) {
            return;
        }

        m_params.NormalPhase_CloseAction_LowerCancel_PriceTicks = num;
    }

    inline int get_NormalPhase_CloseAction_LowerCancel_PriceTicks() const
    {
        return m_params.NormalPhase_CloseAction_LowerCancel_PriceTicks;
    }

    void set_NormalPhase_CloseAction_UpperCancel_PriceTicks(int num)
    {
        if (num < 0) {
            return;
        }

        m_params.NormalPhase_CloseAction_UpperCancel_PriceTicks = num;
    }

    inline int get_NormalPhase_CloseAction_UpperCancel_PriceTicks() const
    {
        return m_params.NormalPhase_CloseAction_UpperCancel_PriceTicks;
    }

    void set_CatchPhase_LowerCancel_PriceTicks(int num)
    {
        if (num < 0) {
            return;
        }

        m_params.CatchPhase_LowerCancel_PriceTicks = num;
    }

    inline int get_CatchPhase_LowerCancel_PriceTicks() const
    {
        return m_params.CatchPhase_LowerCancel_PriceTicks;
    }

    void set_CatchPhase_UpperCancel_PriceTicks(int num)
    {
        if (num < 0) {
            return;
        }

        m_params.CatchPhase_UpperCancel_PriceTicks = num;
    }

    inline int get_CatchPhase_UpperCancel_PriceTicks() const
    {
        return m_params.CatchPhase_UpperCancel_PriceTicks;
    }

    void set_CatchPhase_CloseAction_LowerCancel_PriceTicks(int num)
    {
        if (num < 0) {
            return;
        }

        m_params.CatchPhase_CloseAction_LowerCancel_PriceTicks = num;
    }

    inline int get_CatchPhase_CloseAction_LowerCancel_PriceTicks() const
    {
        return m_params.CatchPhase_CloseAction_LowerCancel_PriceTicks;
    }

    void set_CatchPhase_CloseAction_UpperCancel_PriceTicks(int num)
    {
        if (num < 0) {
            return;
        }

        m_params.CatchPhase_CloseAction_UpperCancel_PriceTicks = num;
    }

    inline int get_CatchPhase_CloseAction_UpperCancel_PriceTicks() const
    {
        return m_params.CatchPhase_CloseAction_UpperCancel_PriceTicks;
    }

    void set_NormalPhase_CancelTime_Ms(int ms)
    {
        if (ms <= 0) {
            return;
        }

        m_params.NormalPhase_CancelTime_Ms = ms;
    }

    inline int get_NormalPhase_CancelTime_Ms() const
    {
        return m_params.NormalPhase_CancelTime_Ms;
    }

    void set_NormalPhase_CloseAction_CancelTime_Ms(int ms)
    {
        if (ms <= 0) {
            return;
        }

        m_params.NormalPhase_CloseAction_CancelTime_Ms = ms;
    }

    inline int get_NormalPhase_CloseAction_CancelTime_Ms() const
    {
        return m_params.NormalPhase_CloseAction_CancelTime_Ms;
    }

    void set_CatchPhase_CancelTime_Ms(int ms)
    {
        if (ms <= 0) {
            return;
        }

        m_params.CatchPhase_CancelTime_Ms = ms;
    }

    inline int get_CatchPhase_CancelTime_Ms() const
    {
        return m_params.CatchPhase_CancelTime_Ms;
    }

    void set_CatchPhase_CloseAction_CancelTime_Ms(int ms)
    {
        if (ms <= 0) {
            return;
        }

        m_params.CatchPhase_CloseAction_CancelTime_Ms = ms;
    }

    inline int get_CatchPhase_CloseAction_CancelTime_Ms() const
    {
        return m_params.CatchPhase_CloseAction_CancelTime_Ms;
    }

    void set_TimeToLive_Ms(int ms)
    {
        if (ms <= 0) {
            return;
        }

        m_params.TimeToLive_Ms = ms;
    }

    inline int get_TimeToLive_Ms() const
    {
        return m_params.TimeToLive_Ms;
    }

    void set_ClosePos_TimeToLive_Ms(int ms)
    {
        if (ms <= 0) {
            return;
        }

        m_params.CloseAction_TimeToLive_Ms = ms;
    }

    inline int get_ClosePos_TimeToLive_Ms() const
    {
        return m_params.CloseAction_TimeToLive_Ms;
    }

private:
    Params m_params;

} AlgoParams;

typedef struct {
    enum {
        Unknown = 0,
        PriceOutOfRange,
        TimeOut,
    };
} CancelationReason;

typedef struct {
    char          valid;               //��Ч��־[0-��Ч,1-��Ч]
    int           algoId;              //�㷨��ID(��AlgoTrader�ڲ�Ψһ��ʶ���㷨��)
    char          signalId[LEN_ID];    //�������㷨�����ź�ID
    int           algoType;            //�㷨����
    int           algoStatus;          //�㷨��״̬
    char          action;              //1=Buy��2=Sell��3=Short��4=Cover
    char          instrument[LEN_INSTRUMENT]; //��Լ��
    double        quantity;            //�㷨������
    double        price;               //���Ƽ�λ
    double        triggerPx;           //������
    double        execPx;              //ʵ��ִ�м�
    double        tickSize;            //��С����λ
    char          clOrdId[LEN_ID];     //�������ڵĵײ㱨�����
    volatile int  orderStatus;         //�ײ㱨��״̬
    double        cumQty;              //�ѳ�����
    double        avgTradedPx;         //�ѳɽ�����
    long          timeID;              //��ʱ�����
    unsigned long initTick;            //��ʼʱ���
    unsigned long lastTick;            //����ı���ʱ���
    unsigned long stopTick;            //�㷨����ֹʱ���
    unsigned int  execCount;           //ִ�м���
    unsigned int  cancelCount;         //��������
    int           cancelReason;        //����ԭ��
    int           execPhase;           //ִ�н׶�
    int           execSrvId;           //ʹ�õĶ���ִ�з���
    AlgoParams params;
} AlgoOrder;

} // namespace AlgoSE

#endif // ALGO_ORDER_H