#include "Number.h"
#include "Multiplicator.h"
#include <ctime>
#include <fstream>


int main()
{
    std::ofstream fout;
    double start_time, end_time, search_time;
    unsigned short timesChecked = 1;
    std::srand(time(nullptr));
    fout.open("../ResultsTable.csv");
    for (int i = 1; i <= 10000; (i < 5000) ? (i += 100) : (i += 500))
    {
        fout << i << '\t';

        search_time = 0;
        for (unsigned short j = 0; j < timesChecked; j++)
        {
            Multiplicator mult(i);
            start_time = clock();
            mult.SchoolMultiply(mult.getNumbers().first, mult.getNumbers().second);
            end_time = clock();
            search_time += end_time - start_time;
        }
        fout << (search_time / timesChecked) / CLOCKS_PER_SEC << '\t';


        search_time = 0;
        for (unsigned short j = 0; j < timesChecked; j++)
        {
            Multiplicator mult(i);
            start_time = clock();
            mult.DivideAndConquerMultiply(mult.getNumbers().first, mult.getNumbers().second);
            end_time = clock();
            search_time += end_time - start_time;
        }
        fout << (search_time / timesChecked) / CLOCKS_PER_SEC << '\t';


        search_time = 0;
        for (unsigned short j = 0; j < timesChecked; j++)
        {
            Multiplicator mult(i);
            start_time = clock();
            mult.KaratsubasMultiply(mult.getNumbers().first, mult.getNumbers().second);
            end_time = clock();
            search_time += end_time - start_time;
        }
        fout << (search_time / timesChecked) / CLOCKS_PER_SEC << '\t';


        fout << '\n';
    }

    fout.close();
    return 0;
}