#include <gtest/gtest.h>
#include <fstream>
#include "../Regular.h"
//#include <iostream>

TEST(Regular, vowelsError)
{

    std::string fileName = "needToError";
    try
    {
        vowelsCounting(fileName);
    }
    catch (const std::exception & error)
    {
        ASSERT_EQ (std::string(error.what()), "File with name \"" + fileName + "\" does not exist");
    }
}

TEST(Regular, oneLetterError)
{
    std::string fileName = "needToError";
    try
    {
        oneLetterCounting(fileName);
    }
    catch (const std::exception & error)
    {
        ASSERT_EQ(std::string(error.what()), "File with name \"" + fileName + "\" does not exist");
    }
}


TEST(Regular, vowelsTest)
{
    std::string fileName = "vowelsTest.txt";
    std::fstream file(fileName, std::fstream::out);
    file << "Hello World" << std::endl;
    file.close();
    int correctAnswer = 3;
    ASSERT_EQ(vowelsCounting(fileName), correctAnswer);
    remove(fileName.c_str());
}


TEST(Regular, oneLetterTest)
{
    std::string fileName = "oneLetterTest.txt";
    std::fstream file(fileName, std::fstream::out);
    file << "Hell o w o r ld" << std::endl;
    file.close();
    int correctAnswer = 4;
    ASSERT_EQ(oneLetterCounting(fileName), correctAnswer);
    remove(fileName.c_str());
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

