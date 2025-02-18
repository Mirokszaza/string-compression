#include <iostream>
#include <string>

using namespace std;

// Function to compress the string
string compress(const string &s) {
    if (s.empty()) return "";

    string compressed;
    int count = 1;

    for (size_t i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) { 
            count++;
        } else {
            compressed += s[i - 1] + to_string(count); // Append char and count
            count = 1; // Reset count for new character
        }
    }

    // Append the last character and its count
    compressed += s.back() + to_string(count);

    return compressed;
}

// Function to decompress the string
string decompress(const string &s) {
    if (s.empty()) return "";

    string decompressed;
    for (size_t i = 0; i < s.length(); i++) {
        char ch = s[i]; // Extract character
        string num = "";

        // Extract the number that follows the character
        while (i + 1 < s.length() && isdigit(s[i + 1])) {
            num += s[i + 1];
            i++;
        }

        int count = stoi(num); // Convert extracted number to int
        decompressed.append(count, ch); // Append character count times
    }

    return decompressed;
}

// Main function to test the implementation
int main() {
    // Test cases for compression
    cout << "Compressed: " << compress("aaabb") << endl;  // Output: "a3b2"
    cout << "Compressed: " << compress("abc") << endl;    // Output: "a1b1c1"
    cout << "Compressed: " << compress("") << endl;       // Output: ""

    // Test cases for decompression
    cout << "Decompressed: " << decompress("a3b2") << endl;  // Output: "aaabb"
    cout << "Decompressed: " << decompress("a1b1c1") << endl; // Output: "abc"
    cout << "Decompressed: " << decompress("") << endl;      // Output: ""

    return 0;
}
