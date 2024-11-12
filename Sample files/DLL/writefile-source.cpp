#include <windows.h>
#include <fstream>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH: {
            // Specify the file path
            const char* filePath = "C:\\Users\\Public\\testfile.txt";

            // Open the file in append mode (creates the file if it doesn't exist)
            std::ofstream file(filePath, std::ios::app);

            // Check if the file opened successfully
            if (file.is_open()) {
                file << "DLL loaded successfully! This is a test file.\n";
                file.close();
            } else {
                // If the file couldn't be opened, show an error message box
                MessageBox(NULL, "Failed to open or create the logfile.", "Error", MB_OK | MB_ICONERROR);
            }
            break;
        }
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}
