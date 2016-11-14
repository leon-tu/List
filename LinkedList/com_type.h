#ifndef __COM_TYPE__
#define __COM_TYPE__

#include "stdlib.h"

enum HRESULT_VALUE {
	SUCCESS = 0x0000,   /**< Success. */
	ERR_NOTIMPL = 0x0001,   /**< Function/feature not implementated. */
	ERR_ERRPARAM = 0x0002,   /**< Function parameter error. */
	ERR_NOMEM = 0x0003,   /**< Not enough memory. */
	ERR_NOSHM = 0x0004,   /**< Not enough share memory. */
	ERR_TIMEOUT = 0x0005,   /**< Operation timeout. */
	ERR_ERRSYSCALL = 0x0006,   /**< Syscall error. */
	ERR_IOFAIL = 0x0007,   /**< Perepheral IO fail. */
	ERR_EVENTFULL = 0x0008,   /**< Event queue full. */
	ERR_HWBUSY = 0x0009,   /**< Hardware busy. */
	ERR_HWFAIL = 0x000A,   /**< Hardware fail. */
	ERR_OSALFAIL = 0x000B,   /**< OSAL fail. */
	ERR_NOSWRSC = 0x000C,   /**< Not enough software resource. */
	ERR_NOHWRSC = 0x000D,   /**< Not enough hardware resource. */
	ERR_SWSTATEWRONG = 0x000E,   /**< Don't permit in current software state. */
	ERR_HWSTATEWRONG = 0x000F,   /**< Don't permit in current hardware state. */
	ERR_RCPERROR = 0x0010,   /**< RPC error. */
	ERR_SWMODEWRONG = 0x0011,   /**< Software mode wrong. */
	ERR_HWMODEWRONG = 0x0012,   /**< Hardware mode wrong. */
	ERR_CONNCLEARED = 0x0013,   /**< Connection has been cleared error. */
	ERR_RANGEPARAM = 0x0014,   /**< Parameter is out of range. */
	ERR_CANCELLED = 0x0015,   /**< Operation is cancelled. */
	ERR_BDERROR = 0x0016,   /**< BD data error. */
};


#define CHK_PARAM(param)		do {				\
	if (!(param)) {									\
		printf("Invalid param\n");					\
		return ERR_ERRPARAM;						\
	}												\
} while (0)										

#define CHK_RC(RC)			do {					\
	if (SUCCESS != (RC)) {							\
		printf("Return not OK, rc[0x%x]\n", (RC));	\
		return RC;									\
	}												\
} while (0)											

#define BUFAlloc malloc
#define BUFFree(p)			do {					\
	if (!(p)) {										\
		free(p);									\
		(p) = NULL;									\
	}												\
} while (0)											

typedef int INT;
typedef unsigned int UINT;
typedef unsigned char UCHAR;

typedef UINT HRESULT;
typedef UCHAR BOOL;

#endif
