*libllcp is forked from <https://code.google.com/p/libllcp/>*

##Change

+ Fix compile error of enable debug. 
+ Add C++ support.
+ Add snep examples. (Test with Nexus 4 (Android 4.4)).
+ 

## Usage

	***libnfc is needed.***

### Download

	git clone https://github.com/JiapengLi/libllcp.git

### Compile

	cd libllcp
	autoreconf -vis
	./configure --prefix=/usr --enable-debug           // --enable-debug is optional
	make

### Clean
	
	make clean 		// clean objects
	make distclean  // clean all

### Installation

	sudo make install

### Uninstall

	sudo make uninstall

### Test

#### Push NDEF(url) to Android

	cd libllcp
	./examples/snep-client/snep-client

#### Pull NDEF Message from Android

	./examples/snep-server/snep-server -o ndef

	// make Adroid phone approach to PN532 device.
	// Touch the screen when it comes "Touch to beam" 
	// ndef file saves the NDEF message, it can be 
	// decode by ndef-decode(a tool of libndef)
