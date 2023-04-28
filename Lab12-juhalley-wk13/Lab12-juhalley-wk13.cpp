// Lab12-juhalley-wk13.cpp 
// Jake Uhalley
// Week 13 PigLatin exercise

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Checks if input character is a vowel
bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
// Converts a single word to pig latin
string pigLatinWord(string word) {
    if (isVowel(word[0])) {
        // if starts with a vowel add "way" to the end
        return word + "way";
    }
    else {
        // if first letter is not a vowel, split and move to the end of the word, then add "ay"
        return word.substr(1) + word[0] + "ay";
    }
}

// Converts the whole sentence into pig latin
string pigLatinSentence(string sentence) {
    stringstream ss(sentence);
    string word;
    string result = "";
    while (ss >> word) {
        // splits the sentence into individual words, then calls pigLatinWord 
        result += pigLatinWord(word) + " ";
    }
    return result;
}


int main()
{
    string sentence;
    cout << "Please enter a sentence: ";
    getline(cin, sentence);
    // convert and print results to end user
    cout << "Pig Latin Version: " << pigLatinSentence(sentence) << endl;
    return 0;
}


