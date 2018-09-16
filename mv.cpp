#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

using std::cout;
using std::endl;

int main(const int argc, const char * argv[]){

  if (argc != 3){
    cout << "Usage: " << endl;
    cout << argv[0] << " SOURCE-FILE TARGET-FILE" << endl;
    cout << argv[0] << " SOURCE-FILE TARGET-DIR/" << endl;
    return EXIT_FAILURE;
  }

  const char * oldfile = argv[1];
  const char * newloc = argv[2];

  struct stat buf;
  if (stat(newloc, &buf) != -1){

    if((buf.st_mode & S_IFDIR) != 0){
      char str[80];
      strcpy(str, newloc);
      strcat(str, oldfile);
      if ((rename(oldfile, str) != -1)){
      cout << "File moved. " << endl;
    }
    else{
      cout << "An error occured. " << strerror(errno);
    }
     }//if it's a directory
     else if ((buf.st_mode & S_IFREG) != 0){
       if (((rename(oldfile, newloc) != -1)))
	   cout << "The move was successful." << endl;
	   else
	     cout << "Error occured: " << strerror(errno) << endl;
     }//if it's a file
     else {
       cout << "Improper input. " << strerror(errno) << endl;
     }//it's something else?
  }
  else{
    if (rename(oldfile,newloc) != -1){
      cout << "The move was successful." << endl;
    }
    else {
      cout << "An error has occured: " << strerror(errno) << endl;
    }
  }
	   return EXIT_SUCCESS;
}//main
