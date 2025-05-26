#ifndef _CSVREADER_H
#define _CSVREADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

/// <summary>
/// Class used to load file
/// </summary>
class CSVReader
{
private :
	std::string m_filename;
	char m_delimiter;

public :
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="filename">Filename to read</param>
	/// <param name="delimiter">The delimiter of the csv file</param>
	CSVReader(std::string filename, char delimiter = ' ') :
		m_filename(filename), m_delimiter(delimiter)
	{}

	/// <summary>
	/// Function to fetch data from a CSV File
	/// </summary>
	/// <returns>The data</returns>
	std::vector<std::vector<int>> getData() {
		std::ifstream file(m_filename);
		if (!file.is_open()) {
			std::cerr << "Could not open the file - '"
				<< m_filename << "'" << std::endl;
			exit(EXIT_FAILURE);
		}
		std::vector<std::vector<int> > dataList;
		std::vector<int> row;
		std::string line, word;

		// Iterate through each line and split the content using delimeter
		while (getline(file, line))
		{
			row.clear();
			std::stringstream ss(line); 
			while (getline(ss, word, m_delimiter)) {
				row.push_back(std::stoi(word));
			}
			dataList.push_back(row);
		}
		// Close the file
		file.close();
		return dataList;
	}

};

#endif //_CSVREADER_H
