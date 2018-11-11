#include "MatriuSparse.h"
#include <fstream>
#include <iostream>
#include <sstream>

MatriuSparse::MatriuSparse()
{
	maxRowCol = 0;
}

MatriuSparse::MatriuSparse(const MatriuSparse & ms)
{
	maxRowCol = ms.maxRowCol;
	for (int aux = 0; aux < ms.colVector.size(); aux++) {
		rowVector.emplace_back(ms.rowVector.at(aux));
		colVector.emplace_back(ms.colVector.at(aux));
		valVector.emplace_back(ms.valVector.at(aux));
	}
}

MatriuSparse::MatriuSparse(string fitxert)
{
	ifstream myReadFile;
	myReadFile.open(fitxert);
	string line = "";
	int sizeCount = 0;
	if (myReadFile.is_open())
	{
		if (!myReadFile.eof())
		{
			while (getline(myReadFile, line)) {
				stringstream ss(line);
				bool primerVec = true;
				while (getline(ss, line, '\t')) {
					if (line != "")
					{
						if (primerVec)
						{
							rowVector.emplace_back(stoi(line));
							primerVec = false;
							valVector.emplace_back(1);
							if (stoi(line) > maxRowCol + 1)
							{
								maxRowCol = stoi(line) + 1;
							}

						}
						else {
							colVector.emplace_back(stoi(line));
							if (stoi(line) > maxRowCol + 1)
							{
								maxRowCol = stoi(line) + 1;
							}
						}
					}


				}

			}
		}
	}
	myReadFile.close();
}

MatriuSparse::~MatriuSparse()
{
	rowVector.clear();
	colVector.clear();
	valVector.clear();
}

void MatriuSparse::setVal(const int & nFiles, const int & nColumnes, const int & valor)
{
	if (valor > 0)
	{
		bool trobat = false;
		for (int i = 0; i < rowVector.size(); i++)
		{
			if (rowVector.at(i) == nFiles && colVector.at(i) == nColumnes)
			{
				valVector.at(i) = valor;
				trobat = true;
			}
		}
		if (!trobat)
		{
			rowVector.emplace_back(nFiles);
			colVector.emplace_back(nColumnes);
			valVector.emplace_back(valor);

			if (nFiles > (maxRowCol - 1))
			{
				maxRowCol = nFiles + 1;
			}
			else {
				sortVectors();
			}
			if (nColumnes > (maxRowCol - 1))
			{
				maxRowCol = nColumnes + 1;
			}
		}
	}
}

bool MatriuSparse::getVal(int nFiles, int nColumnes, float& valor)
{
	if (nFiles < maxRowCol && nColumnes < maxRowCol) {
		bool found = false;
		for (int i = 0; i < rowVector.size(); i++)
		{
			if (rowVector.at(i) == nFiles && colVector.at(i) == nColumnes)
			{
				valor = valVector.at(i);
				found = true;
			}
		}
		if (!found) {
			valor = 0;
		}
		return true;
	}
	else {
		return false;
	}
}

void MatriuSparse::sortVectors() {
	int valorRow = 0;
	int valorCol = 0;
	int valorVal = 0;
	for (int a = 0; a < colVector.size() - 1; a++) {
		for (int b = 0; b < colVector.size() - (a + 1); b++) {
			if ((rowVector.at(b) > rowVector.at(b + 1)) ||
				(rowVector.at(b) == rowVector.at(b + 1) && colVector.at(b) > colVector.at(b + 1))) {
				valorRow = rowVector.at(b + 1);
				valorCol = colVector.at(b + 1);
				valorVal = valVector.at(b + 1);
				rowVector.at(b + 1) = rowVector.at(b);
				colVector.at(b + 1) = colVector.at(b);
				valVector.at(b + 1) = valVector.at(b);
				rowVector.at(b) = valorRow;
				colVector.at(b) = valorCol;
				valVector.at(b) = valorVal;
			}
		}
	}
}

MatriuSparse MatriuSparse::operator*(int n)
{
	MatriuSparse newMatriu(*this);
	for (int aux = 0; aux < newMatriu.valVector.size(); aux++) {
		newMatriu.valVector.at(aux) *= n;
	}
	return newMatriu;
}

MatriuSparse MatriuSparse::operator*(int& n)
{
	MatriuSparse newMatriu(*this);
	for (int aux = 0; aux < newMatriu.valVector.size(); aux++) {
		newMatriu.valVector.at(aux) *= n;
	}
	return newMatriu;
}

vector<float> MatriuSparse::operator*(vector<float> n)
{
	vector<float> newVector;
	float result = 0;
	int position = 0;
	for (int aux = 0; aux < maxRowCol; aux++) {
		for (int aux2 = position; aux2 < rowVector.size(); aux2++) {
			if (rowVector.at(aux2) == aux) {
				result += n.at(colVector.at(aux2)) * valVector.at(aux2);
			}
			if (rowVector.at(aux2) > aux) {
				position = aux2;
				aux2 = rowVector.size();
			}
		}
		newVector.emplace_back(result);
		result = 0;
	}
	return newVector;
}

MatriuSparse MatriuSparse::operator/(int  n)
{
	MatriuSparse newMatriu(*this);
	for (int aux = 0; aux < newMatriu.valVector.size(); aux++) {
		newMatriu.valVector.at(aux) /= n;
	}
	return newMatriu;
}

ostream & operator<<(ostream & out, const MatriuSparse & md)
{
	out << "MATRIU DE (FILES: " << md.maxRowCol << "  COLUMNES: " << md.maxRowCol << " )" << endl;
	out << "VALORS (FILA::COL::VALOR)" << endl;
	for (int aux = 0; aux < md.rowVector.size(); aux++) {
		out << "( " << md.rowVector.at(aux) << " :: " << md.colVector.at(aux) << " :: " << md.valVector.at(aux) << " ) " << endl;
	}
	return out;
}
