#include <iostream>
#include <cstdlib>
#include <fcntl.h>
#include <cstring>
#include <cerrno>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>


using std::cout;
using std::endl;

int main(const int argc, const char *argv[]){

  if (argc < 2){
    cout << "Usage: " << argv[0] << " FILE ... " << endl;
    return EXIT_FAILURE;
  }

  for (int i = 1; i <= argc; i++){
    int fd = open(argv[i],O_RDWR);
    if (fd != -1){
      int n;
      char buffer [500];
      cout << "Printing file " << argv[i] << ": " << endl;
      while ((n = read(fd,buffer, 500)) > 0){
	cout << buffer;
      }
      cout << endl;
      int cr = close(fd);
      if (cr != -1) {
	cout << "Closed " << argv[i] << "; " << endl;
      }
      else {
	cout << "Could not close " << argv[i] << "; " 
	     << "error = " << strerror(errno) << endl;
      }
    }
    else{
      cout << "File " << argv[i] << " could not be opened. "
	   << strerror(errno) << endl;
    }
  } 

  return EXIT_SUCCESS;
}//main
