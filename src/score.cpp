// author: Aryanthepain
#include "score.h"

// Function to load the high score from a file
void load_high_score(int &high_score)
{
    ifstream infile("high_score.txt");
    if (infile.is_open())
    {
        infile >> high_score;
        infile.close();
    }
}

// Function to save the high score to a file
void save_high_score(int high_score)
{
    ofstream outfile("high_score.txt");
    if (outfile.is_open())
    {
        outfile << high_score;
        outfile.close();
    }
}
