#ifndef _MYLOG_H_
#define _MYLOG_H_

#include <stdio.h>
#include <time.h>

#define myerr(fmt, args...) \
do \
{ \
	fprintf(stderr, fmt, ##args); \
} while (0)

#define assert_or_goto(cond, label, fmt, args...) \
do \
{ \
	if (!(cond)) \
	{ \
		myerr(fmt, ##args); \
		goto label; \
	} \
} while (0)

#define assert_or_return(cond, retval, fmt, args...) \
do \
{ \
	if (!(cond)) \
	{ \
		myerr(fmt, ##args); \
		return retval; \
	} \
} while (0)

#ifdef MYLOG

#define mylog(fmt, args...) \
do \
{ \
	fprintf(stdout, fmt, ##args); \
} while (0)

#define mytrace(fmt, args...) \
do \
{ \
	fprintf(stdout, "%s:%d: "fmt, __func__, __LINE__, ##args); \
} while (0)

#define mytrace_ts(fmt, args...) \
do \
{ \
	struct timespec tp; \
	int rc; \
	rc = clock_gettime(CLOCK_MONOTONIC, &tp); \
	if (rc == 0) \
	{ \
		mytrace("%ld.%ld: "fmt, tp.tv_sec, tp.tv_nsec, ##args); \
	} \
	else \
	{ \
		mytrace("0.0: "fmt, ##args); \
	} \
} while (0)

#else

#define mylog(fmt, args...)
#define mytrace(fmt, args...)
#define mytrace_ts(fmt, args...)

#endif

#endif
