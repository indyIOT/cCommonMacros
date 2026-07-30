/** ***********************************************
 * @file commonMacros.h
 * @brief Common project-wide macros
 * @author Anthony Garza
 * @copyright All rights reserved 2026
*************************************************/
#include <stddef.h>
#ifndef COMMON_MACROS_H
#define COMMON_MACROS_H



#ifdef __cplusplus
extern "C" {
#endif

/* Macro Name as a string */
#ifndef STR
#define STR(x) #x
#endif
/* Macro value as a string */
#ifndef XSTR
#define XSTR(x) STR(x)
#endif
/**
 * @brief Forward declearation of the debug assert spin function.
 */
extern void cErrorDriverDebugAssertSpin( char const * const expression,
                                         char const * const fileName,
                                         unsigned int lineNumber );


#ifndef TRUE
/**
 * Ensure that TRUE is defined as true
*/
#define TRUE                                                                true
#endif

#ifndef FALSE  
/**
 * Ensure that FALSE is defined as false*/     
#define FALSE                                                              false
#endif

#ifndef DEF_TRUE
    #define DEF_TRUE                                                        0x01
#endif

#ifndef DEF_FALSE
    #define DEF_FALSE                                                       0x00
#endif

/**
 * @brief Macro to give an array length.
 */
#ifndef ARRAY_LENGTH
#define ARRAY_LENGTH(X)                               (sizeof(X)/sizeof((X)[0]))
#endif

#ifndef ERROR_NONE
#define ERROR_NONE                                                          0x00
#endif

#define AG_UNUSED(x) ((void)(x))
#define AG_ARRAY_LEN(arr) (sizeof(arr) / sizeof((arr)[0]))
#define AG_BIT(pos) (1UL << (pos))

#if defined(__NOP)
#define AG_NOP() __NOP()
#else
#define AG_NOP() ((void)0)
#endif

#if defined(__cplusplus)
#define AG_STATIC_ASSERT(expr, msg) static_assert((expr), msg)
#else
#define AG_STATIC_ASSERT(expr, msg) _Static_assert((expr), msg)
#endif

#if defined(_DEBUG) || !defined(NDEBUG)
#define AG_DEBUG_ASSERT(expr)                                                   \
    do                                                                          \
    {                                                                           \
        if( !(expr) )                                                           \
        {                                                                       \
            cErrorDriverDebugAssertSpin( #expr, __FILE__, (unsigned int)__LINE__ ); \
        }                                                                       \
    } while( 0 )
#else
#define AG_DEBUG_ASSERT(expr) ((void)0)
#endif
#ifdef __cplusplus
}
#endif
#endif /* COMMON_MACROS_H */
