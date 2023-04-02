#ifndef __BASICDATATYPES_H__
#define __BASICDATATYPES_H__



#define hal_DBL_POSITIVE_MAX 1.7976931348623158e+308
#define hal_DBL_POSITIVE_MIN 4.94065645841246544e-324

#define hal_DBL_NEGATIVE_MIN -1.79769313486231570E+308
#define hal_DBL_NEGATIVE_MAX -4.94065645841246544E-324

#define     _IN
#define     _OUT
#define     _LIMIT
#define     hal_FALSE			0
#define     hal_TRUE			1
// #define		hal_NULL				0
#define     hal_PI				3.141592653589793238462
#define     hal_e                (2.7182818284590452353602)
#define     hal_e2               (hal_e*hal_e)
#define     hal_RAND_MAX         (0xffffff)


#ifdef _DEBUG
#define hal_DEBUG_MODE _DEBUG
#endif


#define hal_COUNTOF(x) (sizeof(x)/sizeof(x[0]))





typedef		void				hal_void;
typedef		int					hal_bool;
typedef		unsigned int		hal_dword;
// typedef     uint32_t		       px_dword;
typedef     short               hal_short;
typedef     short				hal_int16;
typedef     unsigned short		hal_word; 
//typedef     uint16_t		       hal_word;
typedef		unsigned short		hal_ushort;
typedef     unsigned int		hal_uint;
typedef     unsigned int		hal_uint32;
//typedef     uint32_t		   hal_uint32;
typedef     int					hal_int;
typedef     int					hal_int32;
//typedef     int32_t			   hal_int32;
typedef		char				hal_char;
typedef		unsigned char		hal_byte;
typedef		unsigned char		hal_uchar;
typedef		unsigned long		hal_ulong;
typedef		long				hal_long;
typedef     float				hal_float;
typedef     float				hal_float32;
//IEEE 754 little-endian
typedef     double				hal_double;
typedef     double				hal_double64;
typedef     unsigned long long  hal_qword;
typedef     unsigned long long  hal_uint64;
//typedef     uint64_t			hal_uint64;
typedef     long long           hal_int64;
//typedef      int64_t				hal_int64;
typedef unsigned char	uint8_t;
typedef unsigned short	uint16_t;
typedef unsigned int	uint32_t;
typedef unsigned long	uint64_t;

#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions                 */
#else
  #define   __I     volatile const       /*!< Defines 'read only' permissions                 */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions                */
#define     __IO    volatile             /*!< Defines 'read / write' permissions              */

#ifndef hal_Null
#define hal_Null ((hal_void *)0)
#endif //定义NULL用于使用

#ifndef StateOK
#define StateOK ((hal_void *)1)
#endif

#ifndef StateNO
#define StateNO ((hal_void *)0)
#endif 

#endif
