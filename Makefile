stog:
	gcc stog.c -o stog

clean:
	rm -f stog

install: stog
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f stog $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/stog

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/stog
