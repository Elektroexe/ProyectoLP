#pragma once
#include <string>
#include <vector>
using namespace std;
/*
class MatriuDispersa
{
public:
	MatriuDispersa();
	MatriuDispersa(string fitxert, int nFiles, int nColumnes);
	MatriuDispersa(string fitxert);
	MatriuDispersa(int nFiles, int nColumnes);
	MatriuDispersa(const MatriuDispersa& m);
	~MatriuDispersa() { delete[] m_matriuReals; };

	//void init(int nFiles, int nColumnes);
	void setVal(const int& nFiles, const  int& nColumnes, const int& valor);
	void setVal(const int& valor);
	//int getVal(int nFiles, int nColumnes);
	bool getVal(int nFiles, int nColumnes, float valor);
	//MatriuDispersa& operator=(const MatriuDispersa& m);
	//MatriuDispersa operator*(const MatriuDispersa& m);
	//MatriuDispersa operator*(float s);
	friend ostream& operator<<(ostream& out, const MatriuDispersa& md);
	//bool esBuida() const;
	//int getNFiles() const { return m_files; };
	//int getNColumnes() const { return m_columnes; };
	//float& operator()  (int fila, int columna);
	//const float& operator()  (int fila, int columna)const;
private:
	float** m_matriuReals;
	int m_files;
	int m_columnes;
};
*/

class MatriuDispersa {
public:
	MatriuDispersa();
	MatriuDispersa(string fitxert);
	~MatriuDispersa() {};
	void setVal(const int& nFiles, const  int& nColumnes, const int& valor);
	void setVal(const int& valor);
	void sortVectors();
	friend ostream& operator<<(ostream& out, const MatriuDispersa& md);
private:
	vector<int> colVector;
	vector<int> rowVector;
	vector<int> valVector;
	int maxRowCol;
};