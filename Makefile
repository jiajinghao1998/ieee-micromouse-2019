all: ./src
	$(MAKE) -C ./src

clean:
	$(MAKE) clean -C ./src

new:
	make clean
	make
