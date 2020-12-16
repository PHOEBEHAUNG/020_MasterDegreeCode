#include "Global.h"

// float PRandom()
// {
// 	float result = 0.0;
// 	struct timespec ts;
// 	usleep(1000);
// 	clock_gettime(CLOCK_MONOTONIC, &ts);
//   srand((time_t)ts.tv_nsec);
	
// 	while(result == 0)
// 	{
// 		result = (rand() % 1000) / 1000.0f;
// 		if((rand() % 2) == 0)
// 		{
// 			result = result * (-1);
// 		}
// 		usleep(1000);
// 	}
// 	return result;
// }

// int UtilMsSleep(long ms)
// {
// 	/// Setup timespec
// 	struct timespec req;
// 	req.tv_sec  = 0;
// 	req.tv_nsec = ms * 1000000;
// 	nanosleep( &req, &req ); 
// 	return 0;
// }