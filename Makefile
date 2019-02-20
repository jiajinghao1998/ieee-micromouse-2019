testmain: ./src/*.cpp ./src/*.hpp
	$(MAKE) -C ./src
	mv ./src/testmain .

clean:
	$(MAKE) clean -C ./src
	rm -f testmain

new:
	make clean
	make
