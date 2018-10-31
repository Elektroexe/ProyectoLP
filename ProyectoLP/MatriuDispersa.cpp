#include "MatriuDispersa.h"
#include <fstream>
#include <iostream>
#include <sstream>

MatriuDispersa::MatriuDispersa()
{
	maxRowCol = 0;
}

MatriuDispersa::MatriuDispersa(string fitxert)
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
	sortVectors();
}

void MatriuDispersa::setVal(const int & nFiles, const int & nColumnes, const int & valor)
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

			if (nFiles > maxRowCol + 1)
			{
				maxRowCol = nFiles + 1;
			}
			if (nColumnes > maxRowCol + 1)
			{
				maxRowCol = nColumnes + 1;
			}
		}
	}
}

bool MatriuDispersa::getVal(int nFiles, int nColumnes, float& valor)
{
	bool trobat = false;
	if (valor == 0)
	{
		trobat = true;
	}
	for (int i = 0; i < rowVector.size(); i++)
	{
		if (rowVector.at(i) == nFiles && colVector.at(i) == nColumnes)
		{
			valor = valVector.at(i);
			trobat = true;


		}
	}
	return trobat;
}

void MatriuDispersa::sortVectors() {
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

ostream & operator<<(ostream & out, const MatriuDispersa & md)
{
	int pos = 0;
	int posRow = md.rowVector.at(pos);
	int posCol = md.colVector.at(pos);
	int posVal = md.valVector.at(pos);
	for (int row = 0; row < md.maxRowCol; row++) {
		out << "\n ";
		for (int col = 0; col < md.maxRowCol; col++) {
			if (row == posRow && col == posCol) {
				out << md.valVector.at(pos) << "   ";
				if (pos < (md.rowVector.size() - 1)) {
					pos++;
					posRow = md.rowVector.at(pos);
					posCol = md.colVector.at(pos);
					posVal = md.valVector.at(pos);
				}
			}
			else {
				out << "0   ";
			}
		}
		out << "\n";
	}
	return out;
}
