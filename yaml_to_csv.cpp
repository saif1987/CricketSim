#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <yaml-cpp/yaml.h>

void convertYamlToCsv(const std::string& yamlFilePath, const std::string& csvFilePath) {
    // Load YAML file
    YAML::Node yamlData = YAML::LoadFile(yamlFilePath);

    if (yamlData.IsNull() || !yamlData.IsSequence()) {
        std::cerr << "Error: Invalid YAML format." << std::endl;
        return;
    }

    // Open CSV file for writing
    std::ofstream csvFile(csvFilePath);
    if (!csvFile.is_open()) {
        std::cerr << "Error: Unable to open CSV file for writing." << std::endl;
        return;
    }

    // Write header
    if (yamlData.size() > 0 && yamlData[0].IsMap()) {
        for (const auto& entry : yamlData[0]) {
            csvFile << entry.first.as<std::string>() << ",";
        }
        csvFile << "\n";
    }

    // Write data
    for (const auto& row : yamlData) {
        if (row.IsMap()) {
            for (const auto& entry : row) {
                csvFile << entry.second.as<std::string>() << ",";
            }
            csvFile << "\n";
        }
    }

    // Close CSV file
    csvFile.close();
}

int main() {
    std::string yamlFilePath = "example.yaml";
    std::string csvFilePath = "output.csv";

    convertYamlToCsv(yamlFilePath, csvFilePath);

    std::cout << "Conversion completed." << std::endl;

    return 0;
}
