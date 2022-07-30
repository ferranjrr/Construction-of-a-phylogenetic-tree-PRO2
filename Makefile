OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 

program.exe: program.o Especie.o Cjt_Especies.o Cluster.o Cjt_Clusters.o
	g++ -o program.exe program.o Especie.o Cjt_Especies.o Cluster.o Cjt_Clusters.o

Especie.o: Especie.hh Especie.cc
	g++ -c Especie.cc $(OPCIONS)

Cjt_Especies.o: Cjt_Especies.hh Cjt_Especies.cc
	g++ -c Cjt_Especies.cc $(OPCIONS)

Cluster.o: Cluster.hh Cluster.cc
	g++ -c Cluster.cc $(OPCIONS)

Cjt_Clusters.o: Cjt_Clusters.hh Cjt_Clusters.cc
	g++ -c Cjt_Clusters.cc $(OPCIONS)

program.o: program.cc
	g++ -c program.cc $(OPCIONS) 

clean:
	rm -f *.o
	rm -f *.exe
	rm -f *.gch
