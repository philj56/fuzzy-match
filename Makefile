SOURCES=fuzzy_match.c main.c

fuzzy_match: $(SOURCES)
	$(CC) -o $@ $(CFLAGS) $(SOURCES)

clean:
	rm fuzzy_match
