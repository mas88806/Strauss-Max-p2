#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <unistd.h>

using std::cout;
using std::endl;

int main(const int argc, const char * argv[]){

  if (argc > 4 || argc < 3) {
    cout << "Usage: " << argv[0] << " [-S] OLD-FILE NEW-FILE" << endl;
    return EXIT_FAILURE;
  }

  if (argc == 4) {
   const  char * oldfile = argv[2];
   const char * newfile = argv[3];

   if ((symlink(oldfile, newfile) != -1)){
    cout << "File " << oldfile
	 << " has been made a symbolic link called "
	 << newfile
	 << endl;
   }
   else{
     cout << "An error has occured: "
	  << strerror(errno)
	  << endl;
     return EXIT_FAILURE;
   }

  }//with [-S] option

  else {

    const char * oldfile = argv[1];
    const char * newfile = argv[2];

    if ((link(oldfile, newfile) != -1)){
      cout << "Files " << oldfile << " and "
	   << newfile << " linked successfully."
	   << endl;
    }
    else {
      cout << "Files " << oldfile << " and "
	   << newfile << " were not able to be linked. "
	   << "error = " << strerror(errno)
	   << endl;
      return EXIT_FAILURE;
    }

  }//no option

  return EXIT_SUCCESS;

}//main
