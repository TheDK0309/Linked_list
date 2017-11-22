export GTEST_DIR=/u/g/e1400476/linked_list/googletest/googletest
my_test: libgtest.a test_case.c linkedlist.c Gtest_main.c
	
	g++ -isystem ${GTEST_DIR}/include -pthread test_case.c linkedlist.c Gtest_main.c libgtest.a -o my_test -g
	

libgtest.a:
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc 
	ar -rv libgtest.a gtest-all.o

clean:
	rm -rf *.o my_test
	
