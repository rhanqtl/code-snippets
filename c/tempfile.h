#ifndef _TEMP_FILE_H_
#define _TEMP_FILE_H_

#include <stdlib.h>

int make_temp_file(const char *prefix, const size_t prefix_len, char *buf,
                   const size_t buf_len);

#endif // _TEMP_FILE_H_