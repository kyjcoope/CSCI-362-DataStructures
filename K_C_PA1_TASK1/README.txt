To compile task1 make sure to move Makefile and all source files into the same directory
Type>> make


To run the files after they are compiled
Type>> make run


results.txt will be stored to same directory that program is run in.
To view results.txt enter.
Type>> head -n results.txt //where n is the integer you entered


To remove all .o files
Type>> make clean

run time evaluation:
f(n)=log(n) < g(n)=n < h(n)=n*log(n) < p(n)=n^2 < q(n)=n^3 < w(n)=2^n < d(n)=n!