main: main.o ETL.o LabelEncoder.o
	g++ -o main main.o ETL.o LabelEncoder.o

main.o: main.cpp ETL.h LabelEncoder.h 
	g++ -c main.cpp


LabelEncoder.o: LabelEncoder.cpp LabelEncoder.h
	g++ -c LabelEncoder.cpp

ETL.o: ETL.cpp ETL.h
	g++ -c ETL.cpp



clean:
	rm main *.o