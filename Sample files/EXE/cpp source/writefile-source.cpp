#include <fstream>
#include <iostream>

int main() {
    // Define the file path
    const char* filePath = "C:\\Users\\Public\\testfile.txt";

    // Create and open the file
    std::ofstream file(filePath);

    // Check if the file was successfully created
    if (file.is_open()) {
        file << "This is a test file created in C:\\Users\\Public.\n";
        file.close();
        std::cout << "File created successfully at " << filePath << std::endl;
    } else {
        std::cerr << "Error: Could not create the file at " << filePath << std::endl;
    }

    return 0;
}
