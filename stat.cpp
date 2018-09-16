#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cerrno>
#include <ctime>
#include <cstring>

using std::cout;
using std::endl;

int main(const int argc,const char * argv[]){

  if (argc != 2)
    {
      cout << "Correct usage: " << argv[0] << " FILE " << endl;
      return EXIT_FAILURE;
    }
     const char * file = argv[1];
      int filed = open(file, O_RDONLY);

      if (filed != -1)
	{
	  cout << "File: " << file << "; " << endl;
	}
      else
	{
	  cout << "Could not open " << file << "; " << strerror(errno)
	       << endl;
	  return EXIT_FAILURE;
	}

  struct stat buffer;
  fstat(filed, &buffer);

  cout << "File permission: "
       << (((buffer.st_mode & S_IRUSR) != 0) ? "r" : "-")
       << (((buffer.st_mode & S_IWUSR) != 0) ? "w" : "-")
       << (((buffer.st_mode & S_IXUSR) != 0) ? "x" : "-")
       << (((buffer.st_mode & S_IRGRP) != 0) ? "r" : "-")
       << (((buffer.st_mode & S_IWGRP) != 0) ? "w" : "-")
       << (((buffer.st_mode & S_IXGRP) != 0) ? "x" : "-")
       << (((buffer.st_mode & S_IROTH) != 0) ? "r" : "-")
       << (((buffer.st_mode & S_IWOTH) != 0) ? "w" : "-")
       << (((buffer.st_mode & S_IXOTH) != 0) ? "x" : "-")
       << endl;

  cout << "Access: " << ctime(&buffer.st_atim.tv_sec);
  cout << "Modification: " << ctime(&buffer.st_mtim.tv_sec);
  cout << "Status Change: " << ctime(&buffer.st_ctim.tv_sec);

  if (S_ISREG(buffer.st_mode))
    cout << "Regular File" << endl;

  if ((buffer.st_mode & S_IFMT) == S_IFDIR)
      cout << "Directory File" << endl;

      int cv = close(filed);

      if (cv != -1)
	{
	  cout << "Closed " << file << "; " << endl;
	}
      else
	{
	  cout << "Could not close " << file << "; "
	       << strerror(errno) << endl;
	}

      return EXIT_SUCCESS;
}
