#include <cstdlib> //atoi
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

const int ROWS = 100;
const int COLS = 80;
const int BUFFSIZE = 80;

int main() {
  // The array must be big enough to fit the input data.
  int array[ROWS][COLS] = {0};
  int row, col;
  char buff[BUFFSIZE]; // a buffer to temporarily park the data
  ifstream infile("input.txt");
  stringstream ss;
  // Read input into the buffer a line at a time, until
  //  end of file is reached (newlines are automatically
  //  discarded).  The buffer must be big enough to fit
  //  an entire line from the file.
  // Notice that while reading from the file we check how
  //  many rows have been read, to avoid writing beyond
  //  the end of the array.
  row = 0;
  while( infile.getline( buff,  BUFFSIZE ) && row < ROWS ) {
	// copy the entire buffered line into the stringstream
	ss << buff;
	// Read from ss back into the buffer.  Now, ',' is
	//  specified as the delimiter so it reads only until
	//  it reaches a comma (which is automatically
	//  discarded) or reaches the 'eof', but of course
	//  this 'eof' is really just the end of a line of the
	//  original input.  The "10" means this will handle
	//  input numbers of 9 digits or less.
	//  While reading from the stringstream, we check
	//  how many columns have been read to avoid
	//  writing past the end of the array.
	col = 0;
	while( ss.getline( buff, 10, ',' ) && col < COLS ) {
	  // Next, use the stdlib atoi function to convert the
	  //  input value that was just read from ss to an int,
	  //  and copy it into the array.
	  array[row][col] = atoi( buff );
	  ++col;
	}
	// This copies an empty string into ss, erasing the
	//  previous contents.
	ss << ""; 
	// This clears the 'eof' flag.  Otherwise, even after 
	//  writing new data to ss we wouldn't be able to
	//  read from it.
	ss.clear();
	++row;
  }
  // Now print the array to see the result
  for( int _row = 0; _row < 10; ++_row ) {
	for( int _col = 0; _col < 10; ++_col ) {
	  cout << array[_row][_col] << " ";
	}
	cout << endl;
  }
  infile.close();
}
