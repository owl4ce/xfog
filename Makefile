.POSIX:

PREFIX   = /usr/local
LIBDIR   = $(PREFIX)/lib
CFLAGS  += -fPIC -Wall
LDFLAGS += -shared
LDLIBS   = -ldl

xfog.so:
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o xfog.so

install: xfog.so
	mkdir -p $(DESTDIR)$(LIBDIR)
	cp -f xfog.so $(DESTDIR)$(LIBDIR)/xfog.so

uninstall:
	rm -f $(DESTDIR)$(LIBDIR)/xfog.so

clean:
	rm -f xfog.so
