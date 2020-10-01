// Normal2Xvec.cpp : Defines the entry point for the application.
//

#include "Normal2Xvec.h"
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 3) {
		cout << "Normal2Xvec inName out" << endl;
		cout << "PS: only supports int8 to float" << endl;
		return 0;
	}

	string inName = argv[1];
	string outName = argv[2];
	
	ifstream inFile(inName, ifstream::binary);
	ofstream outFile(outName, ifstream::binary);

	if (!inFile) {
		cout << "File: " << inName << " can't be opened" << endl;
		return 1;
	}

	if (!outFile) {
		cout << "File: " << outName << " can't be opened" << endl;
		return 1;
	}

	
	int rowNum, colNum;
	inFile.read(reinterpret_cast<char*>(&rowNum), 4);
	inFile.read(reinterpret_cast<char*>(&colNum), 4);

	cout << "File row: " << rowNum << ", col: " << colNum << endl;
	
	vector<int8_t> vec(colNum);

	for (int i = 0; i < rowNum; i++) {
		inFile.read(reinterpret_cast<char*>(vec.data()), colNum * sizeof(int8_t));

		outFile.write(reinterpret_cast<char*>(&colNum), 4);
		vector<float> floatVec(vec.begin(), vec.end());
		outFile.write(reinterpret_cast<char*>(floatVec.data()), colNum * sizeof(float));

		if (i < 3) {
			cout << "Before: " << i << " row:";
			for (auto& ele : vec) {
				cout << " " << ele;
			}
			cout << endl;
			cout << "After: " << i << " row:";
			for (auto& ele : floatVec) {
				cout << " " << ele;
			}
			cout << endl;
		}
	}
	
	return 0;
}
