/* ThreadQueMsg.hpp */
#ifndef THREADQUEMSG_H
#define THREADQUEMSG_H
#include <string>

#define    MSG_POST_USER_DATA 1
#define    MSG_TIMER 2
#define    MSG_EXIT_THREAD 3


struct ThreadMsg
{
	ThreadMsg(int i, const void* m) { id = i; msg = m; }
	int id;
	const void* msg;
};

struct UserData
{
	std::string msg;
	int year;
};

#endif
#ifndef _FAULT_H
#define _FAULT_H

#ifdef __cplusplus
extern "C" {
#endif

#define ASSERT() \
	FaultHandler(__FILE__, (unsigned short) __LINE__)

#define ASSERT_TRUE(condition) \
	do {if (!(condition)) FaultHandler(__FILE__, (unsigned short) __LINE__);} while (0)

	/// Handles all software assertions in the system.
	/// @param[in] file - the file name that the software assertion occurred on
	/// @param[in] line - the line number that the software assertion occurred on
	void FaultHandler(const char* file, unsigned short line);

#ifdef __cplusplus
}
#endif

#endif 