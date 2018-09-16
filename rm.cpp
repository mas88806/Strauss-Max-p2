#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

using std::cout;
using std::endl;
using std::cin;

int main(const int argc, const char * argv[]){
  int choice;
  int opt;

  if (argc < 2){
    cout << "Usage: " << argv[0] << " [-R] FILE ... "
	 << strerror(errno)
	 << endl;
    return EXIT_FAILURE;
  }

  // if ((opt = getopt(argc, argv, "R:")) != -1){

  // }//with option
// else{
    for (int i = 1; i <= argc; i++){
      
      if ((open(argv[i],O_RDONLY != -1)) && (open(argv[i],O_WRONLY) == -1)){
	cout << "Are you sure you want to delete file " << argv[i] << " ?"
	     << " (Enter 1 for yes or 2 for no) ";
	cin >> choice;
	if (choice == 1){
	  if ((unlink(argv[i]) != -1)){
	    cout << "File " << argv[i] << " has been deleted! ";
	    }
	  else {
	    cout << "File " << argv[i] << " could not be deleted! "
		 << strerror(errno) << endl;
	  }
	}//user input yes
	else if (choice == 2){
	  cout << "You chose not to delete the file." << endl;
	}//user input no
	else{
	  cout << "You're a dummy.  I'm just not going to delete this file."
	       << endl;
	}//user is a dummy 
      }//In this instance we have to check with the user because we dont have write permission
      else if ((open(argv[i],O_RDWR) != -1)){
	if (unlink(argv[i]) != -1){
	  cout << "File " << argv[i] << " has been deleted!" << endl;
	  }
	else {
	  cout << "File " << argv[i] << " could not be deleted! "
	       << strerror(errno) << endl;
	}
      }//We had write permission so we tried to delete
      else {
	cout << "This file could not be deleted/does not exist." << endl;
      }//We cant read or write? must not exist
    }//for loop
  //without option
  return EXIT_SUCCESS;
}//main
