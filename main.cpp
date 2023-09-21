	#include <iostream>
	#include "Header.h"
	#include <fstream>
	#include <string>
	#include <iomanip>

	const int MAX_RECORDS = 10;

	// Separate arrays for names, years, and tuition
	std::string names[MAX_RECORDS];
	int years[MAX_RECORDS];
	double tuitions[MAX_RECORDS];

	//function declarations
	void readData();
	void printData(int start, int end);
	void bubbleSortByYear();
	void linearSearchAndPrint(int year);

	int main() {
		head();

		readData();

		std::cout << "ORIGINAL DATA" << std::endl;
		std::cout << std::left << std::setw(8) << "NAME"
			<< std::setw(5) << "YEAR"
			<< "TUITION" << std::endl;
		printData(0, MAX_RECORDS);
		std::cout << std::endl;

		bubbleSortByYear();

		std::cout << "SORTED DATA" << std::endl;
		std::cout << std::left << std::setw(8) << "NAME"
			<< std::setw(5) << "YEAR"
			<< "TUITION" << std::endl;
		printData(0, MAX_RECORDS);
		std::cout << std::endl;

		int year;
		std::cout << "Enter a year: ";
		std::cin >> year;
		linearSearchAndPrint(year);
	}

	void readData() {
		std::ifstream dataFile("index.txt");
		if (!dataFile) {
			std::cerr << "Error opening file!!!!" << std::endl;
			exit(5);
		}

		int i = 0;

		//instead of doing dataFile.eof() 
		while (dataFile >> names[i] >> years[i] >> tuitions[i] && i < MAX_RECORDS) {
			i++;
		}
		dataFile.close();
	}

	void printData(int start = 0, int end = MAX_RECORDS) {
		for (int i = start; i < end && i < MAX_RECORDS; i++) {
			std::cout << std::endl;
			std::cout << std::left << std::setw(8) << names[i]
				<< std::setw(5) << years[i]
				<< tuitions[i] << std::endl;
		}
	}

	void bubbleSortByYear() {
		for (int i = 0; i < MAX_RECORDS - 1; i++) {
			for (int j = 0; j < MAX_RECORDS - i - 1; j++) {
				if (years[j] > years[j + 1]) {
					// Swap names
					std::string tempName = names[j];
					names[j] = names[j + 1];
					names[j + 1] = tempName;

					// Swap years
					int tempYear = years[j];
					years[j] = years[j + 1];
					years[j + 1] = tempYear;

					// Swap tuitions
					double tempTuition = tuitions[j];
					tuitions[j] = tuitions[j + 1];
					tuitions[j + 1] = tempTuition;
				}
			}
		}
	}

	void linearSearchAndPrint(int year) {
		bool found = false;
		for (int i = 0; i < MAX_RECORDS; i++) {
			if (years[i] == year) {
				std::cout << std::endl;
				std::cout << "Record Found ";
				printData(i, i + 1);
				found = true;
			}
		}
		if (!found) {
			std::cout << "Not Found" << std::endl;
		}
	}




/*
#include <iostream>
#include "Header.h"
#include <fstream>
#include <string>
#include <vector>
const int MAX_RECORDS = 10;

struct Record {
	std::string name;
	int year;
	double tuition;
	friend std::ostream& operator<<(std::ostream& os, const Record& record) {
		os << record.name << " " << record.year << " " << record.tuition;
		return os;
	}
};


void readData(std::vector<Record>& records);
void printData(const std::vector<Record>& records);
void bubbleSortByYear(std::vector<Record>& records);
void linearSearchAndPrint(const std::vector<Record>& records, int year);

int main() {
	std::vector<Record> records;

	readData(records);

	std::cout << "Original Data\n";
	std::cout << "Name Year Tuition\n";
	printData(records);

	bubbleSortByYear(records);

	std::cout << "Sorted Data\n";
	std::cout << "Name Year Tuition\n";
	printData(records);

	int year;
	std::cout << "Enter a year: " << endl;
	std::cin >> year;
	linearSearchAndPrint(records, year);
}


void readData(std::vector<Record>& records) {
	std::ifstream dataFile("index.txt");
	if (!dataFile) {
		std::cerr << "Error opening file!!!!" << endl;
		exit(5);
	}
	Record temp;
	while (dataFile >> temp.name >> temp.year >> temp.tuition) {
		records.push_back(temp);
	}
	dataFile.close();
}

void printData(const std::vector<Record>& records) {
	for (const auto& record : records) {
		std::cout << record << std::endl;
	}
}

void bubbleSortByYear(std::vector<Record>& records) {
	for (int i = 0; i < MAX_RECORDS - 1; i++) {
		//cout << "outer loop" << endl;
		//cout << "records[i]: " << records[i] << endl;
		for (int j = 0; j < MAX_RECORDS - i - 1; j++) {
			//cout << "inner loop" << endl;
			//cout << "records[j]" << records[j] << endl;
			if (records[j].year > records[j + 1].year) {
				Record temp = records[j];
				records[j] = records[j + 1];
				records[j + 1] = temp;
			}
		}
	}
}

void linearSearchAndPrint(const std::vector<Record>& records, int year) {
	bool found = false;
	for (int i = 0; i < MAX_RECORDS; i++) {
		if (records[i].year == year){
			std::cout << "Found Record: " << records[i] << endl;
			found = true;
		}
		else {
			continue;
		}
	}
	if (!found) {
		std::cout << "Not Found";
	} 
}
*/