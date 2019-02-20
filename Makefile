all: test
	$(MAKE) -C ./src

test:
	$(MAKE) -C ./src
	mv ./src/testmain .

clean:
	$(MAKE) clean -C ./src
	rm -f testmain

new:
	make clean
	make
