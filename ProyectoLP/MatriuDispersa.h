#pragma once
#include <string>
#include <vector>
using namespace std;
class MatriuDispersa {
public:
	MatriuDispersa();
	MatriuDispersa(string fitxert);
	~MatriuDispersa() {};
	void setVal(const int& nFiles, const  int& nColumnes, const int& valor);
	void setVal(const int& valor);
	bool getVal(int nFiles, int nColumnes, float &valor);
	void sortVectors();
	friend ostream& operator<<(ostream& out, const MatriuDispersa& md);
private:
	vector<int> colVector;
	vector<int> rowVector;
	vector<int> valVector;
	int maxRowCol;
};