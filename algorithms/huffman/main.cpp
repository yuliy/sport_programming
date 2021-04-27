#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

long long GetTickCount() {
    return clock() * 1000 / CLOCKS_PER_SEC;
}

class THuffmanCompressor {
private:
    THuffmanCompressor();
    THuffmanCompressor(const THuffmanCompressor &);
    THuffmanCompressor &operator=(const THuffmanCompressor &);
private:
    string InputFileName;
    string OutputFileName;

    typedef map<char, int> TSymbol2FrequencyMap;
    TSymbol2FrequencyMap Symbol2freq;
private:
    void CalcSymbol2Frequency() {
        Symbol2freq.clear();

        ifstream ifile(InputFileName.c_str());
        if (ifile.is_open()) {
            char ch;
            while (ifile.good()) {
                ifile >> ch;
                ++Symbol2freq[ch];
            }
        }
    }

    void PrintSymbol2Frequency() const {
        for (TSymbol2FrequencyMap::const_iterator iter = Symbol2freq.begin(), end = Symbol2freq.end(); iter != end; ++iter)
            cout << iter->first << "(" << (int)(iter->first) << ")\t-\t" << iter->second << endl;
    }
public:
    THuffmanCompressor(string inputFileName, string outputFileName)
        : InputFileName(inputFileName)
        , OutputFileName(outputFileName) {
    }

    void Compress() {
        CalcSymbol2Frequency();
        PrintSymbol2Frequency();
    }
};

int main() {
    const long long start = GetTickCount();
    THuffmanCompressor hc("book_large.fb2", "book_large.fb2.zip");
    hc.Compress();
    const long long timeDelta = GetTickCount() - start;
    cout << "Compression time = " << timeDelta << " ms" << endl;
    /*
    fopen() Открывает файл
    fclose()    Закрывает файл
    putc()  Записывает символ в файл
    fputc() То же, что и putc()
    getc()  Читает символ из файла
    fgetc() То же, что и getc()
    fgets() Читает строку из файла
    fputs() Записывает строку в файл
    fseek() Устанавливает указатель текущей позиции на определенный байт файла
    ftell() Возвращает текущее значение указателя текущей позиции в файле
    fprintf()   Для файла то же, что printf() для консоли
    fscanf()    Для файла то же, что scanf() для консоли
    feof()  Возвращает значение true (истина), если достигнут конец файла
    ferror()    Возвращает значение true (истина), если произошла ошибка
    rewind()    Устанавливает указатель текущей позиции в начало файла
    remove()    Стирает файл
    fflush()    Дозапись потока в файл
    */
    /*
    FILE *fp = fopen("./f.txt", "w");
    fputc('q', fp);
    fputc('\n', fp);
    fputs("hello\n", fp);
    fprintf(fp, "Some number: %d\n", 777);
    fclose(fp);

    fp = fopen("./f.txt", "r");
    //int c;
    //while ((c = fgetc(fp)) != EOF) {
    const size_t BUF_SIZE = 1024;
    char buf[BUF_SIZE];
    while (fgets(buf, BUF_SIZE, fp)) {
        cout << buf;
    }
    fclose(fp);
    */

    //
    /*ofstream ofile("f.txt");
    if (ofile.is_open()) {
        ofile << "hello"
                << "123" << endl
                << "qwerty" << endl;
        ofile.close();
    }

    ifstream ifile("f.txt");
    string line;
    if (ifile.is_open()) {
        while (ifile.good()) {
            getline(ifile, line);
            cout << line << endl;
        }
        ifile.close();
    }*/

    return 0;
}
