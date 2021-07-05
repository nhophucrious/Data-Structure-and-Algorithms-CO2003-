#include <iostream>
#include "opencv2/opencv.hpp"
#include "heap/Heap.h"
#include "hash/XHashMap.h"
#include "heap/huffman.h"
//using namespace cv;
using namespace std;

typedef unsigned char uint8;
typedef unsigned int  uint32;

/////////////////////////////////////////////////////////////////////////////////////////
// Command line parsing functions
/////////////////////////////////////////////////////////////////////////////////////////

int get_int(char** begin, char** end, const string& option, int _default){
    char** ptr = std::find(begin, end, option);
    if (ptr != end && ++ptr != end) return stoi(*ptr);
    else return _default;
}

string get_string(char** begin, char** end, const string& option, string _default){
    char** ptr = std::find(begin, end, option);
    if (ptr != end && ++ptr != end) return string(*ptr);
    else return _default;
}
bool option_exist(char** begin, char** end, const string& option){
    return std::find(begin, end, option) != end;
}

/////////////////////////////////////////////////////////////////////////////////////////
//Some demos
/////////////////////////////////////////////////////////////////////////////////////////

void demo_1(int argc, char** argv){
    cout << "DEMO 1:" << endl;
    cout << "files specified in filelist.csv" << endl;
    cout << "(you have to do Huffman coding for all files specifed in filelist.csv)" << endl;

    string input;
    string output;
    string filelist;

    input = get_string(argv, argv+argc, "-in", "input");
    output = get_string(argv, argv+argc, "-out", "output");
    filelist = get_string(argv, argv+argc, "-list", "input/filelist.csv");
    
    DataFrame master(filelist);
    vector<string> filenames = master["filename"];
    for(auto it=filenames.begin(); it != filenames.end(); it++)
      cout << *it << endl;
}

void demo_2(string input, string output){
    cout << "DEMO 2:  how to use bincount, and others"  << endl;
    cout << "(you have write huffman table with to a file with same name and extension CSV)" << endl;

    int size = 8;
    uint8 symbols[] = {0, 1, 2, 3, 4, 5, 6, 7};
    float freqs[8];

    int min=0, max=7;
    uint8 data[] = {5, 5, 0, 1, 6, \
                    7, 6, 6, 6, 2, \
                    2, 1, 1, 0, 1, \
                    7, 0, 0, 0, 0}; //20 data items;
    int nitems = 20;

    string huffman_table[size];
    //////////////////////////////////////////////

    bincount(data, nitems, freqs, min, max);
    demo_unit8_symbols(symbols, size, freqs, huffman_table);
    show_huffman_table(symbols, size, freqs, huffman_table);
    write_huffman_table(symbols, size, freqs, huffman_table, output + "/huffman_demo_1.csv");
}

void demo_3(string input, string output){
    cout << "DEMO 2:  how to use bincount, and others"  << endl;
    cout << "(you have write huffman table with to a file with same name and extension CSV)" << endl;

    string filename = input + "/board1.png";
    cv::Mat image = cv::imread(filename, cv::IMREAD_GRAYSCALE);

    if (image.empty()) cout << filename << ": not found!" << endl;
    
    //Here: valid image:
    cout << "rows: " << image.rows << endl;
    cout << "cols: " << image.cols << endl;
    cout << "channels: " << image.channels() << endl;
    cout << "number of pixels: " << image.rows* image.cols * image.channels() << endl;
    cout << endl;

    //Pointer to data in image: data
    uint8* data = image.ptr<uint8>(0, 0);
    int nitems = image.rows* image.cols * image.channels();
    
    int size = 256;
    uint8 symbols[256];
    for(int level=0; level < size; level++) symbols[level] = level;
    float freqs[256]; int min = 0, max = 255;
    string huffman_table[256];

    bincount(data, nitems, freqs, min, max);
    demo_unit8_symbols(symbols, size, freqs, huffman_table);
    show_huffman_table(symbols, size, freqs, huffman_table);
    write_huffman_table(symbols, size, freqs, huffman_table,  output + "/board1.csv");
}



int main(int argc, char** argv){
    if(option_exist(argv, argv+argc, "-h")){
        cout << "Show help" << endl;
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////////

    //YOUR CODE HERE: to generate csv files
    /*
    YOUR CODE HERE
    Guidelines:
    command line: ./main -in "input" -out "output" -list "/input/filelist.csv"
    Where, 
      > input: folder contains input images: *.png, *.jpeg
      > output: folder contains your output files (CSV)
      > filelist.csv: contains list of files will be processed with your program
      ??????FORMAT of your program output??????
      (Run the first cell in Grader section (5.) and see the samples)

    For examples:
      in input folder contains input/filelist.csv, and it contains
      board1.png 
      board2.png 

      => Your program:
      (1) read data in input/board1.png (see demo_2 above)
      (2) compute symbols frequency and huffman coding for each of symbols: 0,1,2,..., 255
      (3) write to output file (CSV) output/board1.csv: it has 3 columns as follows
        * symbols:
        * freqs: NORMALIZED  frequency (format: 6.2f)
        * bits: bit sequence coded for the corresponding symbol

      (4) Do similar things for board2.png and others in filelist.csv
    */

    //Replace the following code with your program
    
    string input = get_string(argv, argv+argc, "-in", "input");
    string output = get_string(argv, argv+argc, "-out", "output");

    demo_1(argc, argv);
    demo_2(input, output);
    //demo_3(input, output);

    return 0;
}