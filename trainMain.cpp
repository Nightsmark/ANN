#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include "csvparse.h"
#include "neuralnet.h"

using namespace std;

int main(int argc, char * argv[])
{
	prmFile prm;

	prm.parsePrm(argv[1]);		

	vector<PDSI> csv_data;
	csv_data = parseCSV(prm.csvFileName.c_str());

	neuralNet net;

	net.buildNet(prm);

	net.trainNet(prm, csv_data);
	
	return 0;
}

