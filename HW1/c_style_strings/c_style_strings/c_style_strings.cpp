#include <iostream>


char* strdup(const char* str)
{
    int size = 0;
    while (str[size]) //gets size of str
       size++;
    char* newstr = new char [size+1];
    for (int i = 0; i < size; i++) // makes a copy of str into newstr
        newstr[i] = str[i];
    newstr[size] = '\0';
     return newstr;   
}
char* findstr(const char* str, const char* toFind) {

    int sizeStr = 0;
    while (str[sizeStr]) //Gets size of str;
        sizeStr++;

    int sizeToFind = 0; 
    while (toFind[sizeToFind]) // gets size of toFind
        sizeToFind++;
  
    return nullptr;
}
int main()
{
    char word[] = "According to the belief of the Teutons these wicked giants will\n"
        "some day destroy the beautiful world.Even the gods themselves\n"
        "will be killed in a dreadful battle with them.\n";
    
    findstr(word, "beautiful");

    char* newstr = strdup(word);
    std::cout << newstr;

}