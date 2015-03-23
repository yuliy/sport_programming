g++-4.8 -Wall -O3 -std=c++11 -o x main.cpp && \
    ./x < sample_input.txt > tmp.txt && \
    diff sample_output.txt tmp.txt
