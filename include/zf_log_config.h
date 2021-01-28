#ifndef ZF_LOG_CONFIG_H_
#define ZF_LOG_CONFIG_H_

#ifdef __cplusplus
extern "C"
{
#endif // #ifdef __cplusplus

#define ZF_LOG_BUF_SZ 128

#if 1
#define ZF_LOG_MESSAGE_CTX_FORMAT ()
#endif

#if 0
#define ZF_LOG_MESSAGE_CTX_FORMAT \
     (F_INIT((unsigned app_get_sys_tick(); )), \
      F_UINT(5, app_get_sys_tick()), S(ZF_LOG_DEF_DELIMITER), LEVEL, S(" "))
#endif

#if 0
#define ZF_LOG_MESSAGE_CTX_FORMAT \
     (F_INIT((unsigned app_get_sys_tick(); )), \
      F_UINT(5, app_get_sys_tick()), S(ZF_LOG_DEF_DELIMITER))

//#define ZF_LOG_MESSAGE_SRC_FORMAT	(FUNCTION, S(ZF_LOG_DEF_DELIMITER))
//#define ZF_LOG_MESSAGE_SRC_FORMAT	(FUNCTION, S("@"), FILENAME, S(":"), FILELINE, S(ZF_LOG_DEF_DELIMITER))
#endif

#if 1
#define ZF_LOG_MESSAGE_SRC_FORMAT (S(ZF_LOG_DEF_DELIMITER))
#endif

#if 0
#define ZF_LOG_MESSAGE_SRC_FORMAT	(FUNCTION, S(ZF_LOG_DEF_DELIMITER))
#endif

#include "printf.h"
#define ZF_LOG_CUSTOM_VSNPRINTF vsnprintf
#define ZF_LOG_CUSTOM_SNPRINTF snprintf

#ifdef __cplusplus
}// closing brace for extern "C"
#endif // #ifdef __cplusplus

#endif // #ifndef ZF_LOG_CONFIG_H_
