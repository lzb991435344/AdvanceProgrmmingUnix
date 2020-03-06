#include <unistd.h>
#include <fcntl.h>

int
lockfile(int fd)
{
	struct flock fl;

	//多个进程可以获得读锁F_RDLCK
	fl.l_type = F_WRLCK;//只有一个进程获得写锁
	fl.l_start = 0;//文件开始位置
	fl.l_whence = SEEK_SET;//start = 0
	fl.l_len = 0; //锁住整个文件大小
	//err return -1,errno is set
	return(fcntl(fd, F_SETLK, &fl)); 
}
