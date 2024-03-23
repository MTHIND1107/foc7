/*
 FILE :f7.cpp
 PROJECT : FOCUSSED ASSIGNMENT-7
 PROGRAMMER :MANREET THIND (STUDENT ID- 8982315)
 FIRSTVERSION :22/03/24
 DESCRIPTION :
 The functions in this file give you practice at creating text and binary files.
*/
#include <stdio.h>

/*
 Function: writeTextFile()
 Parameters: None
 Return Value: Returns an integer.
 Description: Writes content to a text file named "myTextFile.txt".
 The text file contains exactly two lines of content:
 1. "This is line 1."
 2. "This is line 2."
 Both lines end with the '\n' character.
 Returns 0 upon successful file creation and writing,otherwise returns -1 if there
 is an error creating or writing to the file.
*/
int writeTextFile()
{
    FILE* textFile = NULL;
    FILE* binaryFile = NULL;

    // Writing text file
    if (fopen_s(&textFile, "myTextFile.txt", "w") != 0 || textFile == NULL)
    {
        printf("Error creating text file\n");
        return -1;
    }

    fprintf(textFile, "This is line 1.\n");
    fprintf(textFile, "This is line 2.\n");

    fclose(textFile);
    return 0;
}

/*
 Function: writeBinaryFile()
 Parameters: None
 Return Value: None
 Description: Writes even numbers from a given array to a binary file named "myEvenDataList.data".
             The binary file contains only even numbers from the given array.
             It uses binary file I/O functions to create and write to the binary file.
*/
void writeBinaryFile()
{
    const unsigned short kBinaryData[] = { 26946, 24942, 31090, 25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308 };

    FILE* binaryFile = NULL;

    // Writing binary file
    if (fopen_s(&binaryFile, "myEvenDataList.data", "wb") != 0 || binaryFile == NULL)
    {
        printf("Error creating binary file\n");
        return;
    }

    for (int i = 0; i < sizeof(kBinaryData) / sizeof(kBinaryData[0]); i++)
    {
        if (kBinaryData[i] % 2 == 0)
        {
            fwrite(&kBinaryData[i], sizeof(unsigned short), 1, binaryFile);
        }
    }

    fclose(binaryFile);
}
int main()
{
    // Writing text file
    if (writeTextFile() != 0)
    {
        printf("Failed to write text file\n");
        return -1;
    }

    // Writing binary file
    writeBinaryFile();

    return 0;
}